#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_log.h"

// cppcheck-suppress unusedFunction
void app_main()
{
    ESP_LOGI("MAIN", "INIT");

    adc_unit_t ntc_unit = ADC_UNIT_1;
    gpio_num_t ntc_pin = GPIO_NUM_34;
    adc_channel_t ntc_channel;

    ESP_ERROR_CHECK(adc_oneshot_io_to_channel(ntc_pin, &ntc_unit, &ntc_channel));

    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    adc_oneshot_chan_cfg_t config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_11,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1_handle, ntc_channel, &config));

    int ntc_raw = 0;
    const float BETA = 3950;

    while (true)
    {
        ESP_ERROR_CHECK(adc_oneshot_read(adc1_handle, ntc_channel, &ntc_raw));
        float celsius = 1.f / (log(1.f / (4095.f / ntc_raw - 1.f)) / BETA + 1.f / 298.15f) - 273.15f;

        ESP_LOGI("MAIN", "Temperature is %.3fC*", celsius);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
