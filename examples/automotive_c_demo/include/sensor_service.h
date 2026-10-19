#ifndef AUTOMOTIVE_C_DEMO_SENSOR_SERVICE_H
#define AUTOMOTIVE_C_DEMO_SENSOR_SERVICE_H
#include <stdbool.h>
#include <stdint.h>
#include "sensor_port.h"
typedef enum { SENSOR_QUALITY_UNINITIALIZED = 0, SENSOR_QUALITY_VALID, SENSOR_QUALITY_IO_ERROR, SENSOR_QUALITY_STALE } sensor_quality_t;
typedef struct { int32_t value_milli_units; uint32_t sample_tick_ms; sensor_quality_t quality; bool valid; } sensor_sample_t;
typedef struct { sensor_port_t port; uint16_t raw_min; uint16_t raw_max; uint32_t max_age_ms; sensor_sample_t sample; } sensor_service_t;
bool sensor_service_init(sensor_service_t *service, sensor_port_t port, uint16_t raw_min, uint16_t raw_max, uint32_t max_age_ms);
bool sensor_service_update(sensor_service_t *service, uint32_t now_ms);
bool sensor_service_get(const sensor_service_t *service, uint32_t now_ms, sensor_sample_t *out_sample);
#endif
