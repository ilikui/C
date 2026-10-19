#include "app.h"
#include "fake_sensor.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
static void test_valid_sample(void)
{
    fake_sensor_t fake; sensor_service_t service; sensor_sample_t sample;
    fake_sensor_init(&fake, 123U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 50U));
    assert(sensor_service_update(&service, 100U));
    assert(sensor_service_get(&service, 150U, &sample));
    assert(sample.value_milli_units == 1230);
    assert(sample.sample_tick_ms == 100U);
    assert(sample.quality == SENSOR_QUALITY_VALID);
}
static void test_stale_sample(void)
{
    fake_sensor_t fake; sensor_service_t service; sensor_sample_t sample;
    fake_sensor_init(&fake, 20U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 10U));
    assert(sensor_service_update(&service, 100U));
    assert(!sensor_service_get(&service, 111U, &sample));
}
static void test_tick_wraparound(void)
{
    fake_sensor_t fake; sensor_service_t service; sensor_sample_t sample;
    fake_sensor_init(&fake, 20U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 10U));
    assert(sensor_service_update(&service, UINT32_MAX - 4U));
    assert(sensor_service_get(&service, 3U, &sample));
}
static void test_io_failure_invalidates_sample(void)
{
    fake_sensor_t fake; sensor_service_t service; sensor_sample_t sample;
    fake_sensor_init(&fake, 20U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 50U));
    assert(sensor_service_update(&service, 100U));
    fake.fail_reads = true;
    assert(!sensor_service_update(&service, 110U));
    assert(!service.sample.valid);
    assert(service.sample.quality == SENSOR_QUALITY_IO_ERROR);
    assert(!sensor_service_get(&service, 110U, &sample));
}
static void test_out_of_range_sample(void)
{
    fake_sensor_t fake; sensor_service_t service;
    fake_sensor_init(&fake, 1001U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 50U));
    assert(!sensor_service_update(&service, 100U));
    assert(!service.sample.valid);
}
static void test_app_degrades_on_failure(void)
{
    fake_sensor_t fake; sensor_service_t service; app_t app;
    fake_sensor_init(&fake, 20U);
    assert(sensor_service_init(&service, fake_sensor_port(&fake), 10U, 1000U, 50U));
    app_init(&app, &service);
    app_step(&app, 100U);
    assert(app.state == APP_STATE_NORMAL);
    fake.fail_reads = true;
    app_step(&app, 110U);
    assert(app.state == APP_STATE_DEGRADED);
    assert(app.update_count == 2U);
    assert(app.failure_count == 1U);
}
int main(void)
{
    test_valid_sample(); test_stale_sample(); test_tick_wraparound();
    test_io_failure_invalidates_sample(); test_out_of_range_sample();
    test_app_degrades_on_failure();
    puts("All automotive_c_demo tests passed.");
    return 0;
}
