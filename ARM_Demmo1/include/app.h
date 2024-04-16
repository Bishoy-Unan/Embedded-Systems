
#ifndef APP_H
#define APP_H

#define PERIODICITY_SECONDS     2


typedef enum 
{
    Green   ,
    Yellow  ,
    Red

}Traffic_Lights_t;

void app5(void);

void SelectMode_Runnable(void);

void EditTime_Runnable(void);

void EditDate_Runnable(void);

void DisplayWatch_Runnable(void);

void StopWatch_Runnable(void);

void DisplayDate_Runnable(void);

void Watch_Runnable(void);

void SwitchsState_Runnable(void);

void UART_vidRunnable(void);




#endif