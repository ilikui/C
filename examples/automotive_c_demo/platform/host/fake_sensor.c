#include "fake_sensor.h"
#include <stddef.h>
static sensor_port_status_t fake_read_raw(void *ctx, uint16_t *raw)
{
    fake_sensor_t *fake = (fake_sensor_t *)ctx;
    if ((fake == NULL) || (raw == NULL)) return SENSOR_PORT_INVALID_ARGUMENT;
    fake->read_count++;
    if (fake->fail_reads) return SENSOR_PORT_IO_ERROR;
    *raw = fake->next_raw;
    return SENSOR_PORT_OK;
}
void fake_sensor_init(fake_sensor_t *fake, uint16_t raw)
{
    if (fake == NULL) return;
    fake->next_raw = raw; fake->fail_reads = false; fake->read_count = 0U;
}
sensor_port_t fake_sensor_port(fake_sensor_t *fake)
{
    sensor_port_t port;
    port.read_raw = fake_read_raw; port.ctx = fake;
    return port;
}
