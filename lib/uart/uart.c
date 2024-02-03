#include "uart.h"


int uart_init(int baud_rate, gpio_num_t tx, gpio_num_t rx)
{
    int default_tx = 1,  default_rx = 3;
  
    uart_config_t my_uart_config = 
    {
        .baud_rate = baud_rate,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT
    };
    esp_err_t get_ret;
    get_ret = uart_driver_install(UART_NUM_0, BUFF_RX_PIN, BUFF_TX_PIN, QUEUE_SIZE, NULL, INTR_ALLOC_FLAGS);
        if(get_ret != ESP_OK) return ESP_FAIL;
    get_ret = uart_param_config(UART_NUM_0, &my_uart_config);
        if(get_ret != ESP_OK) return ESP_FAIL;

    if( tx < 0 || rx < 0)
    {
        get_ret = uart_set_pin(UART_NUM_0, default_tx, default_rx, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
        if(get_ret != ESP_OK) return ESP_FAIL;
    }
    else
    {
        get_ret = uart_set_pin(UART_NUM_0, tx, rx, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
        if(get_ret != ESP_OK) return ESP_FAIL;
    }
    
    return ESP_OK;

}

// Função esta aceitando valores diferentes de inteiros, favor corrigir
int uart_write_num(int num)
{
    int dado[BUFF_WRITE_NUM] = {num};
    int get_ret = uart_write_bytes(UART_NUM_0, (const void*)dado, BUFF_WRITE_NUM);
    return get_ret == WRITE_PARAM_ERROR ? WRITE_PARAM_ERROR : WRITE_PARAM_SUCESS;
}

int8_t uart_write_caracter(char msg)
{
    char dado[BUFF_WRITE_CARACTER] = {msg};
    int get_ret = uart_write_bytes(UART_NUM_0, dado, BUFF_WRITE_CARACTER);
    return get_ret == WRITE_PARAM_ERROR ? WRITE_PARAM_ERROR : WRITE_PARAM_SUCESS;
}

int uart_write_strng(char *strng)
{
    int get_ret = uart_write_bytes(UART_NUM_0, strng, BUFF_WRITE_STRNG);
    return get_ret == WRITE_PARAM_ERROR ? WRITE_PARAM_ERROR : WRITE_PARAM_SUCESS;
}

int uart_read(int *storage, size_t msg_size)
{
    return uart_read_bytes(UART_NUM_0, storage, msg_size, portMAX_DELAY);
}