

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



#define F_CLK   25000000U


/**
 *@ Call Back Function (New Data Type) 
*/
typedef void(*CallBackFunction_t)(void);

/**
 *@ UART error status 
*/
typedef enum
{
    UART_enuOK   ,
    UART_enuNOK  ,
    UART_enuBuzy
}UART_enuErrorStatus_t;



/*========================== UART Configurations===================================================*/
/**
 *@ STM32F401CC Uart Channels
 */
typedef enum
{
	UART_1 = 0 ,
	UART_2     ,
	UART_6

}UART_enuChannels_t;


typedef enum
{
    UART_enuDisable_t    ,
    UART_enuEnable_t    
}UART_enuEnableMode_t ;

typedef enum 
{
    UART_enu_1_Start_8_Data_N_Stop_Bits     ,
    UART_enu_1_Start_9_Data_N_Stop_Bits
}UART_enuDataFrame_t ;

typedef enum 
{
    UART_enuDisable_Parity      ,
    UART_enuEnable_Parity
}UART_enuParityControl_t ;

typedef enum 
{
    UART_enuEvenParity    ,
    UART_enuOddParity 
}UART_enuParityType_t ;

typedef enum 
{
    UART_enuDisable  ,
    UART_enuEnable
}UART_enuInterruptEnable_t ;

typedef enum 
{
    UART_enuBuzzy    ,
    UART_enuReady
}UART_enuState_t;


/**
 *@ Uart Configuration
*/
typedef struct
{
	UART_enuChannels_t           Channel ;
	UART_enuEnableMode_t         UartEnable;
	UART_enuDataFrame_t          WordLength;
	UART_enuParityControl_t      ParityControl;
    UART_enuParityType_t         ParityType  ;
	u16                          BaudRate;

}UART_strConfigType_t;


/**
 *@ UART Send Buffer
 */
typedef struct
{
	u8 * Data;
	u32  Size;
	u32  Pos ;

}UART_Buffer_t;

/**
 *@ transmitting request 
*/
typedef struct 
{
    UART_enuChannels_t Channel;
    UART_Buffer_t TXBuffer ;
    UART_enuState_t State ;
    CallBackFunction_t CBF ;

}TXRequest_t;


/**
 *@ transmitting request 
*/
typedef struct 
{
    UART_enuChannels_t Channel;
    UART_Buffer_t TXBuffer ;
    UART_enuState_t State ;
    CallBackFunction_t CBF ;
   
}RXRequest_t;



/**
 *@ breif: 		        UART_vidInit
 *@ Description:		function to Configure  Uart channels
 *@ Param:			    const Uart_ConfigType* ConfigPtr
 * 						(there is structure created for initialization)
 * 						(to Initialize each mode required)
 *
 *@ return:				Error Status
 **/
extern UART_enuErrorStatus_t UART_enudInit(const UART_strConfigType_t * Copy_addCFG);

extern UART_enuErrorStatus_t UART_SendByteAsynchronous(UART_enuChannels_t Copy_enuChannel, u8 Copy_u8Data);

extern UART_enuErrorStatus_t UART_SendBufferZeroCopy(const TXRequest_t * Copy_addRequest);

extern UART_enuErrorStatus_t UART_ReceiveBuffer(const RXRequest_t * Copy_addRequest);



#endif