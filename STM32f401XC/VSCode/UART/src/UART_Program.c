#include"STD_TYPES.h"
#include"UART_Interface.h"
#include"UART_Private.h"

volatile UART_strRegisters_t *const USART[3] = {UART1, UART2, UART6};
static TXRequest_t* TransmitBuffer[3] ;
RXRequest_t* ReciveBuffer[3] ;
static u8 Uart_u8DataReceived = 0 ;




/**
 *@ breif: 		        UART_vidInit
 *@ Description:		function to Configure  Uart channels
 *@ Param:			    const Uart_ConfigType* ConfigPtr
 * 						(there is structure created for initialization)
 * 						(to Initialize each mode required)
 *
 *@ return:				Error Status
 */
extern UART_enuErrorStatus_t UART_enudInit(const UART_strConfigType_t * Copy_addCFG)
{
    UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;
    /*baud rate calculations based on 16 over sampling*/
    /*baud_rate = F_CLK/(16 * REG_VAL)*/
    /*REG_VAL = F_CLK / (16 * baud_rate)*/
    /*then parse the fraction and matissa*/

    /*
    f32 Loc_u32TempValue;
	u16	Loc_u16TempMantissa;
	u8 Loc_u16TempFraction;
    */
   // common method to calculate baud rate
    u32 Loc_u32TempValue;
	u16	Loc_u16TempMantissa;
	u16 Loc_u16TempFraction;

    u32   Loc_u32CR1_Val = 0 ;
    u32   Loc_u32CBaudRate_Val = 0 ;


    if(Copy_addCFG == NULL)
    {
        Local_enuRetSatus = UART_enuNOK  ;

    }
    else
    {
        /*another way to calculate baud rate*/
        /*
         Loc_u32TempValue = (F_CLK / (16 * Copy_addCFG->BaudRate));
         Loc_u16TempMantissa = (u16)Loc_u32TempValue ;
         Loc_u16TempFraction = (u8)((Loc_u32TempValue - ((f32)Loc_u16TempMantissa)) * 16);
         Loc_u16TempFraction +=1 ; //ceiling
        
         if(Loc_u16TempFraction > 15)
         {
            Loc_u16TempMantissa += 1;
            Loc_u16TempFraction = 0 ;
         }   
        */
       //common method to calculate baud rate
        Loc_u32TempValue = ((u64)F_CLK * 1000) / (Copy_addCFG->BaudRate * (8 * (2 - Copy_addCFG->OverSampling)));
		Loc_u16TempFraction = (Loc_u32TempValue % 1000) * (8 * (2 - Copy_addCFG->OverSampling));
		Loc_u16TempMantissa = Loc_u16TempFraction / 1000;

		// Check if the fraction part needs celing
        if ((Loc_u16TempFraction % 1000) >= 500)
        {
            // Round up the fraction part
            Loc_u16TempFraction = (Loc_u16TempFraction / 1000) + 1;
        }
        else
        {
            Loc_u16TempFraction = Loc_u16TempFraction / 1000;
        }
        // check if there is any carry from the fraction
        if (Loc_u16TempFraction >= 0x10)
        {
            Loc_u16TempMantissa += Loc_u16TempFraction & 0xF0;
        }
        // baud rate register value
        Loc_u32CBaudRate_Val = (Loc_u16TempMantissa << 4 ) | (Loc_u16TempFraction & 0x0F) ;

        // check which UART channel
       switch(Copy_addCFG -> Channel)
		    {

		    case UART_1:
		    	/*Store the Baudrate*/
		    	//UART1->BRR = (Loc_u16TempMantissa << 4) | (Loc_u16TempFraction & 0x0F);

		    	/*Clear Control register for UART*/
		    	UART1->CR1 = 0;

		    	/* OVERSAMPLING MODE*/
		    	UART1->CR1 |= (Copy_addCFG->OverSampling << 15);
                
                /*TRANSMIT EMPTY REGISTER ENABLE*/

		    	UART1->CR1 |= Copy_addCFG->WordLength    << 12;
		    	UART1->CR1 |= Copy_addCFG->ParityControl << 10;
                UART1->CR1 |= Copy_addCFG->ParityType    << 9;
                /*PEIE: PE interrupt enable*/
               // UART1->CR1 |= ENABLE << 8;
                /*TXEIE: TXE interrupt enable*/
		    	//UART1->CR1 |= ENABLE << 7;
                /*TCIE: Transmission complete interrupt enable*/
                //UART1->CR1 |= ENABLE << 6;
                /*RXNEIE: RXNE interrupt enable*/
                //UART1->CR1 |= ENABLE << 5;
                /*TE: Transmitter enable*/
                UART1->CR1 |= ENABLE << 3;
                /*RE: Receiver enable*/
                UART1->CR1 |= ENABLE << 2;

                /*set baud rate*/
                //UART1->BRR =  Loc_u32CBaudRate_Val ;
                
                //only for test
                UART1->BRR = 0x683 ; // 9600 baud rate
                // one stop bit
                UART1->CR2  = 0 ;
                UART1->SR =0 ;
                /*USART ENABLE*/
                UART1->CR1 |= ENABLE << 13 ;

		    	break;

		    case UART_2:

		    /*Store the Baudrate*/
		    	//UART1->BRR = (Loc_u16TempMantissa << 4) | (Loc_u16TempFraction & 0x0F);

		    	/*Clear Control register for UART*/
		    	UART2->CR1 = 0;

		    	/* OVERSAMPLING MODE*/
		    	UART2->CR1 |= (Copy_addCFG->OverSampling << 15);
                
                /*TRANSMIT EMPTY REGISTER ENABLE*/

		    	UART2->CR1 |= Copy_addCFG->WordLength    << 12;
		    	UART2->CR1 |= Copy_addCFG->ParityControl << 10;
                UART2->CR1 |= Copy_addCFG->ParityType    << 9;
                /*PEIE: PE interrupt enable*/
               // UART1->CR1 |= ENABLE << 8;
                /*TXEIE: TXE interrupt enable*/
		    	//UART1->CR1 |= ENABLE << 7;
                /*TCIE: Transmission complete interrupt enable*/
                //UART1->CR1 |= ENABLE << 6;
                /*RXNEIE: RXNE interrupt enable*/
               // UART1->CR1 |= ENABLE << 5;
                 /*TE: Transmitter enable*/
                UART2->CR1 |= ENABLE << 3;
                /*RE: Receiver enable*/
                UART2->CR1 |= ENABLE << 2;

                /*set baud rate*/
                UART2->BRR =  Loc_u32CBaudRate_Val ;
                
                //only for test
               // UART1->BRR = 0x683 ; // 9600 baud rate
                // one stop bit
                UART2->CR2  = 0 ;
                /*USART ENABLE*/
                UART2->CR1 |= ENABLE << 13 ;

            break;

		    case UART_6:

		    	/*Store the Baudrate*/
		    	//UART1->BRR = (Loc_u16TempMantissa << 4) | (Loc_u16TempFraction & 0x0F);

		    	/*Clear Control register for UART*/
		    	UART6->CR1 = 0;

		    	/* OVERSAMPLING MODE*/
		    	UART6->CR1 |= (Copy_addCFG->OverSampling << 15);
                
                /*TRANSMIT EMPTY REGISTER ENABLE*/

		    	UART6->CR1 |= Copy_addCFG->WordLength    << 12;
		    	UART6->CR1 |= Copy_addCFG->ParityControl << 10;
                UART6->CR1 |= Copy_addCFG->ParityType    << 9;
                /*PEIE: PE interrupt enable*/
               // UART1->CR1 |= ENABLE << 8;
                /*TXEIE: TXE interrupt enable*/
		    	//UART1->CR1 |= ENABLE << 7;
                /*TCIE: Transmission complete interrupt enable*/
                //UART1->CR1 |= ENABLE << 6;
                /*RXNEIE: RXNE interrupt enable*/
               // UART1->CR1 |= ENABLE << 5;
                /*TE: Transmitter enable*/
                UART6->CR1 |= ENABLE << 3;
                /*RE: Receiver enable*/
                UART6->CR1 |= ENABLE << 2;

                /*set baud rate*/
                UART6->BRR =  Loc_u32CBaudRate_Val ;
                
                //only for test
               // UART1->BRR = 0x683 ; // 9600 baud rate
                // one stop bit
                UART6->CR2  = 0 ;
                /*USART ENABLE*/
                UART6->CR1 |= ENABLE << 13 ;

                //only for test
                               UART6->BRR = 0x683 ; // 9600 baud rate
                               // one stop bit
                               UART6->CR2  = 0 ;
                               /*USART ENABLE*/
                               UART6->CR1 |= ENABLE << 13 ;
                               UART6->SR =0 ;
		    break;

		    }/*end of switch*/

    }



return Local_enuRetSatus; 
}/*UART_vidInit*/

extern UART_enuErrorStatus_t UART_SendByteAsynchronous(UART_enuChannels_t Copy_enuChannel, u8 Copy_u8Data)
{
	UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;

	if(Copy_enuChannel != UART_1 && Copy_enuChannel != UART_2 && Copy_enuChannel != UART_6 )
	{
		Local_enuRetSatus = UART_enuNOK  ;
	}
	else
	{
		switch(Copy_enuChannel)
		{
		case UART_1:

			/*PEIE: PE interrupt enable*/
           // UART1->CR1 |= (1 << 8);
			UART1->DR = Copy_u8Data;
            /*TE: Transmitter enable*/
           // UART1->CR1 |= ENABLE << 3;
            /*PEIE: PE interrupt enable clear*/
           // UART1->CR1 &= ~(ENABLE << 8);
			break;

		case UART_2:

			/*PEIE: PE interrupt enable*/
            UART2->CR1 |= ENABLE << 8;
			UART2->DR = Copy_u8Data;
            /*TE: Transmitter enable*/
            UART2->CR1 |= ENABLE << 3;
            /*PEIE: PE interrupt enable clear*/
            UART2->CR1 &= ~(ENABLE << 8);
			break;

		case UART_6:
            /*PEIE: PE interrupt enable*/
            UART6->CR1 |= ENABLE << 8;
			UART6->DR = Copy_u8Data;
            /*TE: Transmitter enable*/
            UART6->CR1 |= ENABLE << 3;
            /*PEIE: PE interrupt enable clear*/
            UART6->CR1 &= ~(ENABLE << 8);
			break;

		}/*end of switch*/

	}/*end of else*/

	return Local_enuRetSatus;

}/*UART_SendByteAsynchronous*/


extern UART_enuErrorStatus_t UART_ReceiveByteAsync(UART_enuChannels_t Copy_enuChannel, u8  * Copy_addData)
{
      UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;


	if(Copy_enuChannel != UART_1 && Copy_enuChannel != UART_2 && Copy_enuChannel != UART_6 )
	{
		Local_enuRetSatus = UART_enuNOK  ;
	}
    else if( Copy_addData == NULL)
    {
        Local_enuRetSatus = UART_enuNOK  ;
    }
	else
	{
		switch(Copy_enuChannel)
		{
		case UART_1:

                    if(UART1->SR & (1<<5))
                    {
                        *(Copy_addData) = UART1->DR;
                    }
			break;

		case UART_2:

                    if(UART2->SR & (1<<5))
                    {
                        *(Copy_addData) = UART2->DR;
                    }
			
			break;

		case UART_6:

                    if(UART6->SR & (1<<5))
                    {
                        *(Copy_addData) = UART6->DR;
                    }
			break;

		}/*end of switch*/

	}/*end of else*/

	return Local_enuRetSatus;

}


extern UART_enuErrorStatus_t UART_ReceiveByteSynchronous(UART_enuChannels_t Copy_enuChannel, u8  * Copy_addData)
{
    UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;


	if(Copy_enuChannel != UART_1 && Copy_enuChannel != UART_2 && Copy_enuChannel != UART_6 )
	{
		Local_enuRetSatus = UART_enuNOK  ;
	}
    else if( Copy_addData == NULL)
    {
        Local_enuRetSatus = UART_enuNOK  ;
    }
	else
	{
		switch(Copy_enuChannel)
		{
		case UART_1:

                    while ( !(UART1->SR & (1<<5))){}

                    *(Copy_addData) = UART1->DR;
			break;

		case UART_2:

            while ( !(UART2->SR & (1<<5))){}

            *(Copy_addData) = UART2->DR;
			
			break;

		case UART_6:

            while ( !(UART6->SR & (1<<5))){}

            *(Copy_addData) = UART6->DR;
           
			break;

		}/*end of switch*/

	}/*end of else*/

	return Local_enuRetSatus;

}

extern UART_enuErrorStatus_t UART_ReceiveByteAsynchronous(const RXRequest_t * Copy_addRequest)
{
    UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;
/*
    if( Copy_addRequest == NULL)
    {
        Local_enuRetSatus = UART_enuNOK  ;
    }
	else if(Copy_addRequest->Channel != UART_1 && Copy_addRequest->Channel != UART_2 && Copy_addRequest->Channel != UART_6 )
	{
		Local_enuRetSatus = UART_enuNOK  ;
	}
     else if(Copy_addRequest->TXBuffer.Size > 1)
    {
        Local_enuRetSatus = UART_enuNOK  ;
    }
    else if(ReciveBuffer[Copy_addRequest->Channel]->State == UART_enuReady)
    {
         volatile u16 Loc_u16TimeOut = 1000;

        ReciveBuffer[Copy_addRequest->Channel]->State = UART_enuBuzy;
        //UART_RX_ENABLE_MASK
       (USART[Copy_addRequest->Channel])->CR1 |= 0X00000004;
        while (((((USART[Copy_addRequest->Channel])->SR) & UART_RX_NOT_EMPTY_FLAG) == 0) && Loc_u16TimeOut)
        {
            Loc_u16TimeOut--;
        }
        if (Loc_u16TimeOut == 0)
        {
            if ((((USART[Copy_addRequest->Channel])->SR) & UART_RX_NOT_EMPTY_FLAG) == 0)
            {
                Local_enuRetSatus = UART_enuNOK  ;
            }
            else
            {
                *(Copy_addRequest->TXBuffer.Data) = (USART[Copy_addRequest->Channel])->DR;
            }
        }
        else
        {
            *(Copy_addRequest->TXBuffer.Data) = (USART[Copy_addRequest->Channel])->DR;
        }
        //UART_RX_ENABLE_MASK
        (USART[Copy_addRequest->Channel])->CR1 &= ~0X00000004;
        ReciveBuffer[Copy_addRequest->Channel]->State = UART_enuReady;
    }
	else
    {
        Local_enuRetSatus = UART_enuNOK ;
    }
*/
	return Local_enuRetSatus;

}

extern UART_enuErrorStatus_t UART_SendBufferZeroCopy(const TXRequest_t * Copy_addRequest)
{
	UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;

	if(Copy_addRequest == NULL)
	{
		Local_enuRetSatus = UART_enuNOK  ;

	}
	else
	{
		switch(Copy_addRequest->Channel)
		{
		case UART_1:
                    if(Copy_addRequest ->State == UART_enuReady )
                    {
                        TransmitBuffer[0]->State = UART_enuBuzzy ;
                        TransmitBuffer[0]->TXBuffer.Data = Copy_addRequest->TXBuffer.Data ;
                        TransmitBuffer[0]->TXBuffer.Size = Copy_addRequest->TXBuffer.Size ;
                        TransmitBuffer[0]->TXBuffer.Pos = 0;
                        TransmitBuffer[0]->CBF = Copy_addRequest->CBF;
                        /* first triggring to enter handler mode*/
                        UART1->DR = TransmitBuffer[0]->TXBuffer.Data[0] ;
                        TransmitBuffer[0]->TXBuffer.Pos ++ ;
                        /*TCIE: Transmission complete interrupt enable*/
                       // UART1->CR1 |= ENABLE << 6;
                        /*TE: Transmitter enable*/
                        UART1->CR1 |= ENABLE << 3;
                        /*TXEIE: TXE interrupt enable*/
		    	        UART1->CR1 |= ENABLE << 7;
                    }
			break;

		case UART_2:
                    if(Copy_addRequest ->State == UART_enuReady )
                    {
                        TransmitBuffer[1]->TXBuffer.Data = Copy_addRequest->TXBuffer.Data ;
                        TransmitBuffer[1]->TXBuffer.Size = Copy_addRequest->TXBuffer.Size ;
                        TransmitBuffer[1]->TXBuffer.Pos = 0;
                        TransmitBuffer[1]->State = UART_enuBuzzy ;
                        TransmitBuffer[1]->CBF = Copy_addRequest->CBF;
                        /*TXEIE: TXE interrupt enable*/
		    	        UART2->CR1 |= ENABLE << 7;
                        /*TCIE: Transmission complete interrupt enable*/
                        UART2->CR1 |= ENABLE << 6;
                        /* first triggring to enter handler mode*/
                        UART2->DR = TransmitBuffer[1]->TXBuffer.Data[0] ;
                        TransmitBuffer[1]->TXBuffer.Pos ++ ;
                        /*TE: Transmitter enable*/
                         UART2->CR1 |= ENABLE << 3;
                    }

			
			break;

		case UART_6:
                    if(Copy_addRequest ->State == UART_enuReady )
                    {
                        TransmitBuffer[2]->TXBuffer.Data = Copy_addRequest->TXBuffer.Data ;
                        TransmitBuffer[2]->TXBuffer.Size = Copy_addRequest->TXBuffer.Size ;
                        TransmitBuffer[2]->TXBuffer.Pos = 0;
                        TransmitBuffer[2]->State = UART_enuBuzzy ;
                        TransmitBuffer[2]->CBF = Copy_addRequest->CBF;
                        /*TXEIE: TXE interrupt enable*/
		    	        UART6->CR1 |= ENABLE << 7;
                        /*TCIE: Transmission complete interrupt enable*/
                        UART6->CR1 |= ENABLE << 6;
                        /* first triggring to enter handler mode*/
                        UART6->DR = TransmitBuffer[2]->TXBuffer.Data[0] ;
                        TransmitBuffer[2]->TXBuffer.Pos ++ ;
                        /*TE: Transmitter enable*/
                        UART6->CR1 |= ENABLE << 3;
                    }

			
			break;

		}/*end of switch*/


	}/*end of else*/

	return Local_enuRetSatus;

}/*end of Uart_SendBufferZeroCopy*/

extern UART_enuErrorStatus_t UART_ReceiveBuffer(const RXRequest_t * Copy_addRequest)
{
		UART_enuErrorStatus_t Local_enuRetSatus = UART_enuOK  ;


    if(Copy_addRequest == NULL)
	{
		Local_enuRetSatus = UART_enuNOK  ;
	}
	else
	{
	        if(ReciveBuffer[Copy_addRequest->Channel]->State == UART_enuReady)
	        {
                /*clear not empty flag */
	        	/*initizalize the receiving buffer*/
	        	ReciveBuffer[Copy_addRequest->Channel]->State = UART_enuBuzzy;
                ReciveBuffer[Copy_addRequest->Channel]->TXBuffer.Data = Copy_addRequest->TXBuffer.Data;
	        	ReciveBuffer[Copy_addRequest->Channel]->TXBuffer.Pos = 0 ; //Copy_addRequest->TXBuffer.Pos; 
	        	ReciveBuffer[Copy_addRequest->Channel]->TXBuffer.Size =  Copy_addRequest->TXBuffer.Size;
	        	ReciveBuffer[Copy_addRequest->Channel]->CBF = Copy_addRequest->CBF;

	        	switch(Copy_addRequest->Channel)
	        	{
                
	        	case UART_1:
                    /*clear not empty flag*/
                    UART1->SR & ~(1<<5);
	        		/*RXNEIE: RXNE interrupt enable*/
                     UART1->CR1 |= ENABLE << 5;
                     /*RE: Receiver enable*/
                    UART1->CR1 |= ENABLE << 2;

	        		break;

	        	case UART_2:
	        		/*clear not empty flag*/
                    UART2->SR & ~(1<<5);
	        		/*RXNEIE: RXNE interrupt enable*/
                    UART2->CR1 |= ENABLE << 5;
                    /*RE: Receiver enable*/
                    UART2->CR1 |= ENABLE << 2;


	        		break;

	        	case UART_6:
	        		/*clear not empty flag*/
                    UART6->SR & ~(1<<5);
	        		/*RXNEIE: RXNE interrupt enable*/
                    UART6->CR1 |= ENABLE << 5;
                    /*RE: Receiver enable*/
                    UART6->CR1 |= ENABLE << 2;
	        		break;
	        	}
	        }
    }/*else*/

	return Local_enuRetSatus;
}

UART_enuErrorStatus_t UART_enuSendBuffer_DMA(void)
{
	UART_enuErrorStatus_t Loc_enuErroStatus = UART_enuOK;

	/*enable DMA Transmitting in Uart*/
	UART1->CR3 |= 1 << 7;


	return Loc_enuErroStatus;
}

UART_enuErrorStatus_t UART_enuReceiveBuffer_DMA(void)
{
	UART_enuErrorStatus_t Loc_enuErroStatus = UART_enuOK;

	/*enable DMA receiving in Uart*/
	UART1->CR3 |= 1 << 6;


	return Loc_enuErroStatus;
}

/**
 *@ UART1 Interupt Handler  
*/
void USART1_IRQHandler(void)
{
    /*Check transmit empt flag*/
	if((UART1->SR & (1<<7)) == 1)
	{
		
		if(TransmitBuffer[0]->TXBuffer.Pos < TransmitBuffer[0]->TXBuffer.Size)
		{
            UART1->DR = TransmitBuffer[0]->TXBuffer.Data[TransmitBuffer[0]->TXBuffer.Pos] ;
            TransmitBuffer[0]->TXBuffer.Pos ++ ;
		}
		else
		{
             TransmitBuffer[0]->State = UART_enuReady ;
             if(TransmitBuffer[0]->CBF)
             {
                TransmitBuffer[0]->CBF();
             }
             /*clear transmit flag*/
             UART1->SR & ~(1<<7);
			
		}/*end of else*/
    }

		
	
    /*Check recive not empty flag*/
	if((ReciveBuffer[0]->State==UART_enuBuzzy) && ((UART1->SR & (1<<5)) == 1))
	{
		if(ReciveBuffer[0]->TXBuffer.Pos < ReciveBuffer[0]->TXBuffer.Size)
		{
            ReciveBuffer[0]->TXBuffer.Data[ReciveBuffer[0]->TXBuffer.Pos] =  UART1->DR ;
            ReciveBuffer[0]->TXBuffer.Pos ++ ;
		}
        else
		{
             ReciveBuffer[0]->State = UART_enuReady ;
             ReciveBuffer[0]->TXBuffer.Pos=0;
             if(ReciveBuffer[0]->CBF)
             {
                ReciveBuffer[0]->CBF();
             }
             /*clear transmit flag*/
             UART1->SR & ~(1<<5);
			
		}/*end of else*/
	}
}/*end of function USART1_IRQHandler*/

/**
 *@ UART2 Interupt Handler  
*/
void USART2_IRQHandler(void)
{
	 /*Check transmit empt flag*/
	if(((UART2->SR & (1<<7)) == 1))
	{
		
		if(TransmitBuffer[1]->TXBuffer.Pos < TransmitBuffer[1]->TXBuffer.Size)
		{
            UART2->DR = TransmitBuffer[1]->TXBuffer.Data[TransmitBuffer[1]->TXBuffer.Pos] ;
            TransmitBuffer[1]->TXBuffer.Pos ++ ;
		}
		else
		{
             TransmitBuffer[1]->State = UART_enuReady ;
             if(TransmitBuffer[1]->CBF)
             {
                TransmitBuffer[1]->CBF();
             }
             /*clear transmit flag*/
             UART2->SR & ~(1<<7);
			
		}/*end of else*/
    }

		
	
    /*Check recive not empty flag*/
	if((ReciveBuffer[1]->State==UART_enuBuzzy) && ((UART2->SR & (1<<5)) == 1))
	{
		if(ReciveBuffer[1]->TXBuffer.Pos < ReciveBuffer[1]->TXBuffer.Size)
		{
            ReciveBuffer[1]->TXBuffer.Data[ReciveBuffer[1]->TXBuffer.Pos] =  UART1->DR ;
            ReciveBuffer[1]->TXBuffer.Pos ++ ;
		}
        else
		{
             ReciveBuffer[1]->State = UART_enuReady ;
             if(ReciveBuffer[1]->CBF)
             {
                ReciveBuffer[1]->CBF();
             }
             /*clear transmit flag*/
             UART2->SR & ~(1<<5);
			
		}/*end of else*/
	}
}/*end of function USART2_IRQHandler*/

/**
 *@ UART6 Interupt Handler  
*/
void USART6_IRQHandler(void)
{
	 /*Check transmit empt flag*/
	if((UART6->SR & (1<<7)) == 1)
	{
		
		if(TransmitBuffer[2]->TXBuffer.Pos < TransmitBuffer[2]->TXBuffer.Size)
		{
            UART6->DR = TransmitBuffer[2]->TXBuffer.Data[TransmitBuffer[2]->TXBuffer.Pos] ;
            TransmitBuffer[2]->TXBuffer.Pos ++ ;
		}
		else
		{
             TransmitBuffer[2]->State = UART_enuReady ;
             if(TransmitBuffer[2]->CBF)
             {
                TransmitBuffer[2]->CBF();
             }
             /*clear transmit flag*/
             UART6->SR & ~(1<<7);
			
		}/*end of else*/
    }

		
	
    /*Check recive not empty flag*/
	if((ReciveBuffer[2]->State==UART_enuBuzzy) && ((UART6->SR & (1<<5)) == 1))
	{
		if(ReciveBuffer[2]->TXBuffer.Pos < ReciveBuffer[2]->TXBuffer.Size)
		{
            ReciveBuffer[2]->TXBuffer.Data[ReciveBuffer[2]->TXBuffer.Pos] =  UART1->DR ;
            ReciveBuffer[2]->TXBuffer.Pos ++ ;
		}
        else
		{
             ReciveBuffer[2]->State = UART_enuReady ;
             ReciveBuffer[2]->TXBuffer.Pos = 0 ;
             if(ReciveBuffer[2]->CBF)
             {
                ReciveBuffer[2]->CBF();
             }
             /*clear transmit flag*/
             UART6->SR & ~(1<<5);
			
		}/*end of else*/
	}
}/*end of function USART2_IRQHandler*/
