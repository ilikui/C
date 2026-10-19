#include "app.h"
#include <stddef.h>
void app_init(app_t *app, sensor_service_t *sensor)
{
    if (app == NULL) return;
    app->sensor = sensor; app->state = APP_STATE_STARTING; app->update_count = 0U; app->failure_count = 0U;
}
void app_step(app_t *app, uint32_t now_ms)
{
    if ((app == NULL) || (app->sensor == NULL)) return;
    app->update_count++;
    if (sensor_service_update(app->sensor, now_ms)) app->state = APP_STATE_NORMAL;
    else { app->failure_count++; app->state = APP_STATE_DEGRADED; }
}
