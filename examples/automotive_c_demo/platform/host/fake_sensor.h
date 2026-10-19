#ifndef AUTOMOTIVE_C_DEMO_FAKE_SENSOR_H
#define AUTOMOTIVE_C_DEMO_FAKE_SENSOR_H
#include <stdbool.h>
#include <stdint.h>
#include "sensor_port.h"
typedef struct { uint16_t next_raw; bool fail_reads; uint32_t read_count; } fake_sensor_t;
void fake_sensor_init(fake_sensor_t *fake, uint16_t raw);
sensor_port_t fake_sensor_port(fake_sensor_t *fake);
#endif
