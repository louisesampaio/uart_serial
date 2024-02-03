#include "uart.h"
#include "unity.h"
#include "esp_log.h"

void test_case_init_sucess(void)
{
   esp_err_t get_ret = uart_init(BAUD_RATE,TX_PIN,RX_PIN);
   ESP_LOGI( LOG_COLOR(LOG_COLOR_GREEN) "INIT SUCESS", LOG_COLOR(LOG_COLOR_GREEN) "FAZENDO TESTE DE INICIALIZAÇÃO COM SUCESSO");
   TEST_ASSERT_EQUAL(ESP_OK,get_ret);
}

void test_case_init_error(void)
{
    ESP_LOGI( LOG_COLOR(LOG_COLOR_GREEN) "INIT ERROR", LOG_COLOR(LOG_COLOR_GREEN) "FAZENDO TESTE DE INICIALIZAÇÃO COM ERRO COM VALORES DE PINOS QUE NAO EXISTEM");
    esp_err_t get_ret = uart_init(BAUD_RATE,60,50);
    //esp_err_t get_ret = uart_init(BAUD_RATE,-1,-1);
    TEST_ASSERT_EQUAL(ESP_FAIL,get_ret);
}

void test_case_write_sucess(void)
{
    int get_ret = uart_write_num(64);
    ESP_LOGI( LOG_COLOR(LOG_COLOR_GREEN) "WRITE SUCESS", LOG_COLOR(LOG_COLOR_GREEN) "FAZENDO TESTE DE ESCRITA COM SUCESSO");
    TEST_ASSERT_EQUAL(0,get_ret);
}


void test_case_write_error(void)
{
    int get_ret = uart_write_num("hello");
    ESP_LOGI( LOG_COLOR(LOG_COLOR_RED) "WRITE ERROR", LOG_COLOR(LOG_COLOR_RED) "FAZENDO TESTE DE ESCRITA COM ERRO");
    TEST_ASSERT_EQUAL(-1,get_ret);
}


int app_main()
{
    UNITY_BEGIN();
        RUN_TEST(test_case_init_sucess);
        RUN_TEST(test_case_write_error);
    return UNITY_END();
}