
#include "main.h"

#include "uart_printf.h"

#include "math.h"


int main(void){
HAL_Init();
SystemClock_Config();


MX_GPIO_Init();
MX_USART3_UART_Init();
MX_USART2_UART_Init();
if(printfInit(&huart2) != 0)
{
    wile(1);
}
// Grab the starting time
uint32_t t_start = HAL_GetTick(); // increment every 1 ms

// The code to be executed
for(uint32_t i = 0; i < 100000; i++){
    calc_func();
}


// Grab the stop time
uint32_t t_stop = HAL_GetTick();

// Print the time taken to execute - stop time - start time
printf("Processing speed = %ld [MHz] Execution time = %d [ms]\r\n",HAL_RCC_GetSysClockFreq()/1000000, t_stop - t_start);
}


void calc_func(){
    float pi = 3.1412;
    float pi2 = pi * pi;
    float pi_add = pi + pi;
    float pi2_add = pi2 + pi_add;
    float pi_sqrt = sqrt(pi2);

    pi = 3.1412;
    pi2 = pi * pi;
    pi_add = pi + pi;
    pi2_add = pi2 + pi_add;
    pi_sqrt = sqrt(pi2);
}
