#include "sensor_service.h"
#include <stddef.h>
bool sensor_service_init(sensor_service_t *service, sensor_port_t port, uint16_t raw_min, uint16_t raw_max, uint32_t max_age_ms)
{
    if ((service == NULL) || (port.read_raw == NULL) || (raw_min > raw_max)) return false;
    service->port = port; service->raw_min = raw_min; service->raw_max = raw_max; service->max_age_ms = max_age_ms;
    service->sample.value_milli_units = 0; service->sample.sample_tick_ms = 0U;
    service->sample.quality = SENSOR_QUALITY_UNINITIALIZED; service->sample.valid = false;
    return true;
}
bool sensor_service_update(sensor_service_t *service, uint32_t now_ms)
{
    uint16_t raw = 0U;
    sensor_port_status_t status;
    if ((service == NULL) || (service->port.read_raw == NULL)) return false;
    status = service->port.read_raw(service->port.ctx, &raw);
    if (status != SENSOR_PORT_OK) { service->sample.quality = SENSOR_QUALITY_IO_ERROR; service->sample.valid = false; return false; }
    if ((raw < service->raw_min) || (raw > service->raw_max)) { service->sample.quality = SENSOR_QUALITY_IO_ERROR; service->sample.valid = false; return false; }
    service->sample.value_milli_units = (int32_t)raw * 10;
    service->sample.sample_tick_ms = now_ms; service->sample.quality = SENSOR_QUALITY_VALID; service->sample.valid = true;
    return true;
}
bool sensor_service_get(const sensor_service_t *service, uint32_t now_ms, sensor_sample_t *out_sample)
{
    uint32_t age_ms;
    if ((service == NULL) || (out_sample == NULL)) return false;
    if ((!service->sample.valid) || (service->sample.quality != SENSOR_QUALITY_VALID)) return false;
    age_ms = (uint32_t)(now_ms - service->sample.sample_tick_ms);
    if (age_ms > service->max_age_ms) return false;
    *out_sample = service->sample;
    return true;
}
