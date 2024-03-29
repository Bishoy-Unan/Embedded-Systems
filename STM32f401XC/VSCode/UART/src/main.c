

#include"STD_TYPES.h"
#include"MRCC_Interface.h"
#include"SysTick_Interface.h"
#include"NVIC_Interface.h"
#include"UART_Interface.h"
#include"GPIO_Interface.h"
#include"SCHED_Interface.h"
#include"app.h"
#include"LED.h"
#include"LED_Config.h"
#include "SWITCH.h"
#include"SWITCH_Config.h"







;
int
main(int argc, char* argv[])
{
	
	//u8 LOCAL_u8Button1 = 1 ;
	//u8 LOCAL_u8Button2 = 1 ;


	/*============================RCC Configuration for UART=============================================*/
	RCC_enuControlClk(RCC_HSE,RCC_CLK_ON);
	RCC_enuSelectSystemClk(RCC_HSE);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOA_RCC);
	RCC_enuEnablePeripheralClock(RCC_AHB1,GPIOB_RCC);
	RCC_enuEnablePeripheralClock(RCC_APB2,USART1_RCC);
	/*======================================================================================================*/

	
	/*==================================configure uart1 transmiiter pin B6============================*/
	GPIO_strPinConfg_t UART_TX_PIN ;
	UART_TX_PIN.GPIOPort= GPIOB ;
	UART_TX_PIN.GPIOPin= GPIO_PIN6;
	UART_TX_PIN.GPIOMode = GPIO_MODE_AF_PP;
	UART_TX_PIN.GPIOSpeed = GPIO_OUTPUT_SPEED_LOW ;
	UART_TX_PIN.AF_Num = 7;
	GPIO_enuInit( & UART_TX_PIN );
	/*configure uart1 receiving pin B7*/
	GPIO_strPinConfg_t UART_RX_PIN ;
	UART_RX_PIN.GPIOPort= GPIOB ;
	UART_RX_PIN.GPIOPin= GPIO_PIN7;
	UART_RX_PIN.GPIOMode = GPIO_MODE_AF_PP;
	UART_RX_PIN.GPIOSpeed = GPIO_OUTPUT_SPEED_LOW ;
	UART_RX_PIN.AF_Num = 7 ;
	GPIO_enuInit( & UART_RX_PIN );
	/*==================================================================================================*/


	
	/*======================================NVIC configuration for UART========================================*/
	NVIC_enuEnableInterrupt(NVIC_USART1_INTERRUPT);
	/*====================================================================================================*/


	/*========================UART priphral configurations================================================*/
	UART_strConfigType_t UART1_CFG;
	UART1_CFG.BaudRate = 9600 ;
	UART1_CFG.Channel = UART_1;
	UART1_CFG.ParityControl = UART_enuDisable_Parity ;
	UART1_CFG.ParityType = UART_enuEvenParity ;
	UART1_CFG.UartEnable = UART_enuEnable ;
	UART1_CFG.WordLength = UART_enu_1_Start_8_Data_N_Stop_Bits ;
	UART_enudInit( & UART1_CFG);
	/*====================================================================================================*/

	/*====================configure transmitting and receiving buffers===================================*/
	TXRequest_t Transmiiting_Request ;
	u8  data[6] = {1,2,3,4,5,6};
	Transmiiting_Request.CBF = app ;
	Transmiiting_Request.Channel = UART_1 ;
	Transmiiting_Request.State = UART_enuReady ;
	Transmiiting_Request.TXBuffer.Data = data ;
	Transmiiting_Request.TXBuffer.Pos = 0 ;
	Transmiiting_Request.TXBuffer.Size = 6 ;
	UART_SendBufferZeroCopy( & Transmiiting_Request );

	RXRequest_t Receiving_Request ;
	u8  d[10] = {0};
	Receiving_Request.CBF = app1 ;
	Receiving_Request.Channel = UART_1 ;
	Receiving_Request.State = UART_enuReady ;
	Receiving_Request.TXBuffer.Data = d ;
	Receiving_Request.TXBuffer.Pos = 0 ;
	Receiving_Request.TXBuffer.Size = 10 ;
	UART_ReceiveBuffer( & Receiving_Request );


	/*====================================================================================================*/

	//LED_enumdInit();
	//SWITCH_enumdInit();
	/*
	SYSTICK_enuInit();
	SYSTICK_enuSetTime_mS(1000);
	SYSTICK_enuSetCallback(app);
	SYSTICK_enuStart();
	*/
	//SCHED_vidInit();
    //SCHED_vidStart();
	

  while (1)
    {
		UART_SendByteAsynchronous(UART_1,12);
		// any code to avoid optimization
		for(u16 rx=0;rx<1000;rx++){
			u16 x = 2;
			x++;
			NVIC_enuEnableInterrupt(NVIC_EXTI18_INTERRUPT);
		}
		/*
		SWITCH_enuGetSwitchState( SWITCH2 , & LOCAL_u8Button1 ) ;
		SWITCH_enuGetSwitchState( SWITCH1 , & LOCAL_u8Button2 ) ;

		if(LOCAL_u8Button1 == PRESSED)
		{
		
			LED_enuSetLedState(LED_RED,LED_STATE_ON);
			LED_enuSetLedState(LED_BLUE,LED_STATE_OFF);

		}
		if(LOCAL_u8Button2 == PRESSED)
		{
		
			LED_enuSetLedState(LED_BLUE,LED_STATE_ON);
			LED_enuSetLedState(LED_RED,LED_STATE_OFF);
		}
		*/
    }



    return 0;
}



