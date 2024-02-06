#include "main.h"


uint8_t data[MNSG_SIZE] = {DATA_REQUEST, DATA_CONTROL_LED, DATA_COMMAND_LED_ON, CHECKSUM, DATA_PACKAGE_END};

void app_main() 
{
    uart_init(BAUD_RATE, TX_PIN, RX_PIN);
    while (1)
    {
        int len = uart_read(data, MNSG_SIZE);

        if(len > NO_DATA)
        {
            if (data[0] == DATA_REQUEST && data[1] == DATA_CONTROL_LED && data[2] == DATA_COMMAND_LED_ON )
            {
                gpio_set_level(GPIO_NUM_2, HIGH);
                uart_write_num(CHECKSUM);
                uart_read(data, MNSG_SIZE);
            }
            
        }
    }
    
}