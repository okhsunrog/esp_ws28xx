# esp_ws28xx
A light and simple ESP-IDF lib for WS2812B/WS2815 led strips. Works via SPI with DMA. 
A fork of https://github.com/8-DK/ESP32_SPI_WS2812_idf/ with a lot of fixes, refactoring, improvements, and higher flexibility. Fixed bit format, added correct reset pulses, and support of WS2815.
Tested with esp-idf v5.1 and esp32-c3.

# Example of usage

Just create folder `components` in the root of your project and clone this repo to the created folder.

Minimal working example (blink):
```
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_ws28xx.h"

#define LED_GPIO 13
#define LED_NUM 10

static const char *TAG = "example";
static uint8_t led_state_off = 0;
CRGB* ws2812_buffer;


void blink_led(void) {
    for(int i = 0; i < LED_NUM; i++) {
        if (led_state_off) ws2812_buffer[i] = (CRGB){.r=0, .g=0, .b=0};
        else ws2812_buffer[i] = (CRGB){.r=50, .g=0, .b=0};
    }
    ESP_ERROR_CHECK_WITHOUT_ABORT(ws28xx_update());
}


void app_main(void) {
    ESP_ERROR_CHECK_WITHOUT_ABORT(ws28xx_init(LED_GPIO, WS2812B, LED_NUM, &ws2812_buffer));
    while (1) {
        ESP_LOGI(TAG, "Turning the LED strip %s!", led_state_off == true ? "ON" : "OFF");
        blink_led();
        led_state_off = !led_state_off;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
```
