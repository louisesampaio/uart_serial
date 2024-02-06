#ifndef UART_H
#define UART_H

#include "driver/uart.h"
#include "driver/gpio.h"

#define BUFF_WRITE_NUM (5)
#define BUFF_WRITE_CARACTER (1)
#define BUFF_WRITE_STRNG (30)
#define BUFF_RX_PIN (1024)
#define BUFF_TX_PIN (1024)

#define WRITE_PARAM_ERROR (-1)
#define WRITE_PARAM_SUCESS (0)

#define BAUD_RATE (115200)
#define TX_PIN (1)
#define RX_PIN (3)

#define QUEUE_SIZE (0)
#define INTR_ALLOC_FLAGS (0)

#define MNSG_SIZE (5)

/*! @brief essa função inicializa a uart
* @param[in] baud_rate taxa de transmissão de bits
* @param[in] tx trasmissor
* @param[in] rx receptor
* @return retorna ESP_OK se sucesso, retorna ESP_FAIL se erro
*/
int uart_init(int baud_rate, gpio_num_t tx, gpio_num_t rx);

/*! @brief essa função escreve um número
* @param[in] num numero a escrever
* @return retorna WRITE_PARAM_SUCESS se sucesso, retorna WRITE_PARAM_ERROR se erro
*/
int uart_write_num(int num);


/*! @brief essa função envia um char 
* @param[in] msg char a escrever
* @return retorna WRITE_PARAM_SUCESS se sucesso, retorna WRITE_PARAM_ERROR se erro
*/
int8_t uart_write_caracter(char msg);


/*! @brief essa função envia uma string
* @param[in] strng mensagem a escrever
* @return retorna WRITE_PARAM_SUCESS se sucesso, retorna WRITE_PARAM_ERROR se erro
*/
int uart_write_strng(char *strng);

/*! @brief essa função envia uma msg via serial
* @param[in] storage mensagem a escrever
* @param[in] msg_size tamanho da msg
* @return retorna WRITE_PARAM_SUCESS se sucesso, retorna WRITE_PARAM_ERROR se erro
*/
int uart_read(int *storage, size_t msg_size);




#endif