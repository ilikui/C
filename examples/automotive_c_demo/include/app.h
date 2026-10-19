#ifndef AUTOMOTIVE_C_DEMO_APP_H
#define AUTOMOTIVE_C_DEMO_APP_H
#include <stdint.h>
#include "sensor_service.h"
typedef enum { APP_STATE_STARTING = 0, APP_STATE_NORMAL, APP_STATE_DEGRADED } app_state_t;
typedef struct { sensor_service_t *sensor; app_state_t state; uint32_t update_count; uint32_t failure_count; } app_t;
void app_init(app_t *app, sensor_service_t *sensor);
void app_step(app_t *app, uint32_t now_ms);
#endif
