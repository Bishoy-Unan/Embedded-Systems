
#ifndef APP_H
#define APP_H

#define PERIODICITY_SECONDS     2


typedef enum 
{
    Green   ,
    Yellow  ,
    Red

}Traffic_Lights_t;

void TestUART(void);

void Modes_Runnable(void);

void SelectMode(void);

void EditTime(void);

void EditDate(void);

void DisplayWatch(void);

void StopWatch(void);

void DisplayDate(void);

void Watch_Runnable(void);

void SwitchsState_Runnable(void);

void UART_vidRunnable(void);



/*============================================= Amal Code ================================*/

#endif