#pragma once

#include "board_common.h"
#include "sdkconfig.h"

#define BOARD_NAME        "ESP32-S3 Generic"
#define BOARD_DESCRIPTION "Generic ESP32-S3 dev board with external I2S DAC"

// I2S configuration
#define BOARD_I2S_BCK_GPIO 4
#define BOARD_I2S_WS_GPIO  5
#define BOARD_I2S_DO_GPIO  6

// SPDIF configuration
#define BOARD_SPDIF_BCK_GPIO CONFIG_SPDIF_BCK_IO
#define BOARD_SPDIF_WS_GPIO  CONFIG_SPDIF_WS_IO
#define BOARD_SPDIF_DO_GPIO  CONFIG_SPDIF_DO_IO

// LED configuration
#define BOARD_LED_STATUS_GPIO CONFIG_LED_STATUS_GPIO
#define BOARD_LED_ERROR_GPIO  CONFIG_LED_ERROR_GPIO
#define BOARD_LED_RGB_GPIO    CONFIG_LED_RGB_GPIO

// Control GPIOs (optional on generic boards)
#define BOARD_JACK_GPIO       CONFIG_JACK_GPIO
#define BOARD_SPKFAULT_GPIO   CONFIG_SPKFAULT_GPIO
#define BOARD_MUTE_GPIO 7
#define BOARD_MUTE_GPIO_LEVEL 1 

// DAC I2C (optional)
#define BOARD_I2C_SDA_GPIO 1
#define BOARD_I2C_SCL_GPIO 2

// Battery monitoring
#define BOARD_BAT_CHANNEL CONFIG_BAT_CHANNEL

#define BOARD_MUTE_GPIO 7
#define BOARD_MUTE_GPIO_LEVEL 1 // 1 pour "On"
