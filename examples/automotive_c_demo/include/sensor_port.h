#ifndef AUTOMOTIVE_C_DEMO_SENSOR_PORT_H
#define AUTOMOTIVE_C_DEMO_SENSOR_PORT_H
#include <stdint.h>
typedef enum { SENSOR_PORT_OK = 0, SENSOR_PORT_INVALID_ARGUMENT, SENSOR_PORT_IO_ERROR } sensor_port_status_t;
/* On success write one new sample to *raw. On failure leave *raw unchanged. */
typedef sensor_port_status_t (*sensor_read_raw_fn)(void *ctx, uint16_t *raw);
typedef struct { sensor_read_raw_fn read_raw; void *ctx; } sensor_port_t;
#endif
