#include "uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include "driver/gpio.h"

/*comentarios devem ser feitos dessa maneira*/
#define DATA_REQUEST 50 /*0*/
#define DATA_CONTROL_LED 67 /*C*/
#define DATA_COMMAND_LED_ON 79 /*O*/
#define CHECKSUM 83 /*S*/
#define DATA_PACKAGE_END 69 /*E*/
#define NO_DATA 0
#define HIGH 1
#define LOW 0