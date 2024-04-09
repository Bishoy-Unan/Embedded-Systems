
#ifndef APP_H
#define APP_H

#define PERIODICITY_SECONDS     2


typedef enum 
{
    Green   ,
    Yellow  ,
    Red

}Traffic_Lights_t;

void app(void);
void app1(void);
void app2(void);
void app3(void);
void app4(void);
void app5(void);
void DisplayWatch_Runnable(void);
void Watch_Runnable(void);
void UART_vidRunnable(void);

void TrafficLight(void);





#endif