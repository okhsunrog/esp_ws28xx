idf_component_register(
    INCLUDE_DIRS .
    SRCS esp_ws28xx.c
    REQUIRES driver esp_driver_gpio esp_driver_spi
    PRIV_REQUIRES heap
)
