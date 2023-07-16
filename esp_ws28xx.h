#ifndef MAIN_ESP_WS28XX_H_
#define MAIN_ESP_WS28XX_H_
#include <stdio.h>
#include <string.h>
#include "driver/spi_master.h"
#include "driver/gpio.h"

typedef struct {
	union {
		struct {
            union {
                uint8_t r;
                uint8_t red;
            };
            union {
                uint8_t g;
                uint8_t green;
            };
            union {
                uint8_t b;
                uint8_t blue;
            };
        };
		uint8_t raw[3];
		uint32_t num;
	};
} CRGB;

typedef struct {
	spi_host_device_t host;
	spi_device_handle_t spi;
	int dma_chan;
	spi_device_interface_config_t devcfg;
	spi_bus_config_t buscfg;
} spi_settings_t;

typedef enum {
    WS2812B = 0,
    WS2815,
} led_strip_model_t;

extern CRGB* ws28xx_pixels;

void ws28xx_init(int pin, led_strip_model_t model, int led_number);
void ws28xx_fill_color(CRGB color);
void ws28xx_update();


#endif /* MAIN_ESP_WS28XX_H_ */