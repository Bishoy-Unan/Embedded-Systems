/**********************************************************************************************************************/
/* Author        : Bishoy Unan                                          
/* Version       : V0.0.0                                               
/* Date          : 5 Feb 2024                                           
/* Description   :            
/* Module Features  :                                                   
/*                 01- RCC_enuControlClk (RCC_enuSysClk_t Copy_enuClockSystem,RCC_enuClkStatus_t Copy_enuClkStatus)(); 
/*                 02- RCC_enuSelectSystemClk (RCC_enuSysClk_t Copy_enuSystemClock)();            					    
/*                 03- RCC_enuEnablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();    
/*                 04- RCC_enuDisablePeripheralClock (RCC_Bus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)();   
/*                 05- RCC_enuConfigPLL (RCC_structCLKPLL_t * Copy_structPLLCongif)();  							
/*                 06- RCC_enuControlBusesPrescaler  (RCC_Bus_t Copy_enuBus ,u8 Copy_u32APB2Prescaler)();  				
/************************************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/MRCC_Interface.h"
#include "../include/MRCC_Private.h"

RCC_enuErrorStatus_t RCC_enuControlClk (RCC_enuSysClk_t Copy_enuClockSystem,RCC_enuClkStatus_t Copy_enuClkStatus)
{
    RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;
    /**
    *@ get the runiung clock of system
    */
    u32 Loc_u32CurrSystemCLOCK = ((RCC_CFGR & MASK_GET_SYSCLK)>>2);
    /**
    *@ timout variable used in while loops
    */
    u32 Loc_u32TimeOut = 0;

    /**
    *@ validate the input clock
    */
    if((Copy_enuClockSystem > RCC_PLL) ||  (Copy_enuClockSystem < RCC_HSI))
      {
            Ret_enuErrorStatus = RCC_enuNOK;
      }
    /**
    *@ cannot control the clock if it the runing clock for the system
    */
    else if(Loc_u32CurrSystemCLOCK == Copy_enuClockSystem)
      {
            Ret_enuErrorStatus = RCC_enuNOK;
      }
    else 
    {
        switch(Copy_enuClockSystem)
        {
            /**
            *@ contrl HSI Clock ON/OFF
            */
            case RCC_HSI :
                    /**
                    *@ HSI ON
                    */
                    if(Copy_enuClkStatus == RCC_CLK_ON)
                        {
                            RCC_CR |= (MASK_HSI_ON);
                        }
                    /**
                    *@ HSI OFF
                    */
                    else if(Copy_enuClkStatus == RCC_CLK_OFF)
                        {
                            RCC_CR &= (~MASK_HSI_ON);
                        }   
                    else
                         Ret_enuErrorStatus = RCC_enuNOK;
                    /**
                    *@ Waiting for the clock to be ready
                    */
                    while(((RCC_CR & MASK_HSI_RDY) == 0) && Loc_u32TimeOut < 10000)
                    {
                        Loc_u32TimeOut ++ ;
                    }   
                    /**
                    *@ TIME OUT
                    */ 
                    if(Loc_u32TimeOut >= 10000)
                    {
                         Ret_enuErrorStatus = RCC_enuNOK;
                    }
            break ;
            /**
            *@ contrl HSE Clock ON/OFF
            */
            case RCC_HSE :
                    /**
                    *@ HSE ON
                    */
                    if(Copy_enuClkStatus == RCC_CLK_ON)
                        {
                            RCC_CR |= (MASK_HSE_ON);
                        }
                    /**
                    *@ HSE OFF
                    */
                    else if(Copy_enuClkStatus == RCC_CLK_OFF)
                        {
                            RCC_CR &= (~MASK_HSE_ON);
                        }   
                    else
                         Ret_enuErrorStatus = RCC_enuNOK;
                    /**
                    *@ Waiting for the clock to be ready
                    */
                    while(((RCC_CR & MASK_HSE_RDY) == 0) && Loc_u32TimeOut < 10000)
                    {
                        Loc_u32TimeOut ++ ;
                    }   
                    /**
                    *@ TIME OUT
                    */ 
                    if(Loc_u32TimeOut >= 10000)
                    {
                         Ret_enuErrorStatus = RCC_enuNOK;
                    }
            break ;
            /**
            *@ contrl PLL Clock ON/OFF
            */
            case RCC_PLL :
                     /**
                    *@  PLL ON
                    */
                    if(Copy_enuClkStatus == RCC_CLK_ON)
                        {
                            RCC_CR |= (MASK_PLL_ON);
                        }
                    /**
                    *@ HSE OFF
                    */
                    else if(Copy_enuClkStatus == RCC_CLK_OFF)
                        {
                            RCC_CR &= (~MASK_PLL_ON);
                        }   
                    else
                         Ret_enuErrorStatus = RCC_enuNOK;
                    /**
                    *@ Waiting for the clock to be ready
                    */
                    while(((RCC_CR & MASK_PLL_RDY) == 0) && Loc_u32TimeOut < 10000)
                    {
                        Loc_u32TimeOut ++ ;
                    }   
                    /**
                    *@ TIME OUT
                    */ 
                    if(Loc_u32TimeOut >= 10000)
                    {
                         Ret_enuErrorStatus = RCC_enuNOK;
                    }
            break ;
            default :
            break ;
        }/*switch*/
    }/*else*/



return Ret_enuErrorStatus ;
}/*RCC_enuControlClk*/

RCC_enuErrorStatus_t RCC_enuSelectSystemClk (RCC_enuSysClk_t Copy_enuSystemClock)
{
     RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;

     u32 Loc_u32CFGR_TempRegister;
     /**
     *@ timout variable used in while loops
     */
     u32 Loc_u32TimeOut = 0;
    /**
    *@ validate the input clock
    */
    if(!(Copy_enuSystemClock >= RCC_HSI) &&  (Copy_enuSystemClock <= RCC_PLL))
      {
            Ret_enuErrorStatus = RCC_enuNOK;
      }
    else 
    {
        switch(Copy_enuSystemClock)
        {
            /**
            *@ select HSI Clock 
            */
            case RCC_HSI :
                         /* CHECK ON */
                      if( ((RCC_CR & MASK_HSI_ON) == MASK_HSI_ON) )
                      {
                          /* CHECK READY FLAG */
                          if((RCC_CR & MASK_HSI_RDY) == MASK_HSI_RDY)
                          {
                            Loc_u32CFGR_TempRegister = RCC_CFGR ;
                            Loc_u32CFGR_TempRegister &= (~MASK_SW) ;
                            Loc_u32CFGR_TempRegister |= RCC_HSI ;
                            RCC_CFGR = Loc_u32CFGR_TempRegister ;
							
                            while( ((RCC_CFGR & MASK_GET_SWS) != MASK_SWS_HSI) && (Loc_u32TimeOut<100000))
                            {
						        Loc_u32TimeOut++;
					        }
                            if( Loc_u32TimeOut >= 100000 )
                            {
						        /* TIMEOUT */
						        Ret_enuErrorStatus = RCC_enuNOK; 
					        }

                          }/*if2*/
                          else
                              Ret_enuErrorStatus = RCC_enuNOK;  
                      }/*if1*/
                      else
                              Ret_enuErrorStatus = RCC_enuNOK;  
            break;
            case RCC_HSE :
                            /* CHECK ON */
                      if( ((RCC_CR & MASK_HSE_ON) == MASK_HSE_ON) )
                      {
                          /* CHECK READY FLAG */
                          if((RCC_CR & MASK_HSE_RDY) == MASK_HSE_RDY)
                          {
                            Loc_u32CFGR_TempRegister = RCC_CFGR ;
                            Loc_u32CFGR_TempRegister &= (~MASK_SW) ;
                            Loc_u32CFGR_TempRegister |= RCC_HSE ;
                            RCC_CFGR = Loc_u32CFGR_TempRegister ;

                            while( ((RCC_CFGR & MASK_GET_SWS) != MASK_SWS_HSE) && (Loc_u32TimeOut<100000))
                            {
						        Loc_u32TimeOut++;
					        }
                            if( Loc_u32TimeOut >= 100000 )
                            {
						        /* TIMEOUT */
						        Ret_enuErrorStatus = RCC_enuNOK; 
					        }


                          }/*if2*/
                          else
                              Ret_enuErrorStatus = RCC_enuNOK;  
                      }/*if1*/
                      else
                              Ret_enuErrorStatus = RCC_enuNOK;  
            break;
            case RCC_PLL :
                               /* CHECK ON */
                      if( ((RCC_CR & MASK_PLL_ON) == MASK_PLL_ON) )
                      {
                          /* CHECK READY FLAG */
                          if((RCC_CR & MASK_PLL_RDY) == MASK_PLL_RDY)
                          {
                            Loc_u32CFGR_TempRegister = RCC_CFGR ;
                            Loc_u32CFGR_TempRegister &= (~MASK_SW) ;
                            Loc_u32CFGR_TempRegister |= RCC_PLL ;
                            RCC_CFGR = Loc_u32CFGR_TempRegister ;

                            while( ((RCC_CFGR & MASK_GET_SWS) != MASK_SWS_PLL) && (Loc_u32TimeOut<100000))
                            {
						        Loc_u32TimeOut++;
					        }
                            if( Loc_u32TimeOut >= 100000 )
                            {
						        /* TIMEOUT */
						        Ret_enuErrorStatus = RCC_enuNOK; 
					        }


                          }/*if2*/
                          else
                              Ret_enuErrorStatus = RCC_enuNOK;  
                      }/*if1*/
                      else
                              Ret_enuErrorStatus = RCC_enuNOK;  
            break;
            default :
            break;
        }/*SWITCH*/
    }/*else*/    

return Ret_enuErrorStatus ;
}/*RCC_enuSelectSystemClk*/

RCC_enuErrorStatus_t RCC_enuEnablePeripheralClock (RCC_enuBus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)
{
     RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;
     /**
     *@ Validate input Bus
     */
     if( Copy_enuPeripheralBus < RCC_AHB1 || Copy_enuPeripheralBus > RCC_APB2 )
     {
         Ret_enuErrorStatus = RCC_enuNOK ;
     }/*if1*/
     else
     {
        switch(Copy_enuPeripheralBus)
        {
            case RCC_AHB1 :
                         RCC_AHB1ENR |= (1<<Copy_u8PeripheralNumber);
            break;
            case RCC_AHB2 :
                         RCC_AHB2ENR |= (1<<Copy_u8PeripheralNumber);
            break;
            case RCC_APB1 :
                         RCC_APB1ENR |= (1<<Copy_u8PeripheralNumber);
            break;
            case RCC_APB2 :
                         RCC_APB2ENR |= (1<<Copy_u8PeripheralNumber);
            break;
            default :
            break;
        }/*switch*/

     }/*else*/
       


return Ret_enuErrorStatus ;
}/*RCC_enuEnablePeripheralClock*/

RCC_enuErrorStatus_t RCC_enuDisablePeripheralClock (RCC_enuBus_t Copy_enuPeripheralBus, u8 Copy_u8PeripheralNumber)
{
     RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;

      /**
     *@ Validate input Bus
     */
     if( Copy_enuPeripheralBus < RCC_AHB1 || Copy_enuPeripheralBus > RCC_APB2 )
     {
         Ret_enuErrorStatus = RCC_enuNOK ;
     }/*if1*/
     else
     {
        switch(Copy_enuPeripheralBus)
        {
            case RCC_AHB1 :
                         RCC_AHB1ENR &= (~(1<<Copy_u8PeripheralNumber));
            break;
            case RCC_AHB2 :
                         RCC_AHB2ENR &= (~(1<<Copy_u8PeripheralNumber));
            break;
            case RCC_APB1 :
                         RCC_APB1ENR &= (~(1<<Copy_u8PeripheralNumber));
            break;
            case RCC_APB2 :
                         RCC_APB2ENR &= (~(1<<Copy_u8PeripheralNumber));
            break;
            default :
            break;
        }/*switch*/

     }/*else*/


return Ret_enuErrorStatus ;
}/*RCC_enuDisablePeripheralClock*/

RCC_enuErrorStatus_t  RCC_enuConfigPLL (RCC_structCLKPLL_t * Copy_structPLLCongif)
{
     RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;

       u32 Loc_u32PLLCFGR_TempRegister;

       /* CHICKING ERROR : PLL ON */
         if(( RCC_CR & MASK_GET_ON_PLL) == ON)
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }
         /* CHECKING ERROR : CLOCK SOURCE */
         else if(Copy_structPLLCongif->RCC_strPLLSCR > PLL_HSE_SRC ||  Copy_structPLLCongif->RCC_strPLLSCR  < PLL_HSI_SRC)
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }
         /* CHECKING ERROR : M CONFIGURATION */
         else if(Copy_structPLLCongif->RCC_strPLL_M < 2 || Copy_structPLLCongif->RCC_strPLL_M > 63)
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }
         /* CHECKING ERROR : N CONFIGURATION */
         else if(Copy_structPLLCongif->RCC_strPLL_N < 192 || Copy_structPLLCongif->RCC_strPLL_N > 432)
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }
         /* CHECKING ERROR : P CONFIGURATION */
         else if((Copy_structPLLCongif->RCC_strPLL_P != 2) && (Copy_structPLLCongif->RCC_strPLL_P != 4) && (Copy_structPLLCongif->RCC_strPLL_P != 6) && (Copy_structPLLCongif->RCC_strPLL_P != 8))
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }

         /* CHECKING ERROR : Q CONFIGURATION */
         else if(Copy_structPLLCongif->RCC_strPLL_P < 2 || Copy_structPLLCongif->RCC_strPLL_P > 15)
         {
                Ret_enuErrorStatus = RCC_enuNOK ;
         }
         else 
         {
                 /* Configure PPL parameters */
				/*  CONFIGURE M */
				Loc_u32PLLCFGR_TempRegister = RCC_PLLCFGR ;
				Loc_u32PLLCFGR_TempRegister &= ~MASK_SET_PPL_M ;
				Loc_u32PLLCFGR_TempRegister |= ( Copy_structPLLCongif->RCC_strPLL_M << SHIFT_PLL_M ) ;
				RCC_PLLCFGR = Loc_u32PLLCFGR_TempRegister ;
			
				/* 2: CONFIGURE N */
				Loc_u32PLLCFGR_TempRegister = RCC_PLLCFGR ;
				Loc_u32PLLCFGR_TempRegister &= ~MASK_SET_PPL_N ;
				Loc_u32PLLCFGR_TempRegister |= ( Copy_structPLLCongif->RCC_strPLL_N << SHIFT_PLL_N ) ;
				RCC_PLLCFGR = Loc_u32PLLCFGR_TempRegister ;
			
				/* 3: CONFIGURE P */
				Loc_u32PLLCFGR_TempRegister = RCC_PLLCFGR ;
				Loc_u32PLLCFGR_TempRegister &= ~MASK_SET_PPL_P ;
				Loc_u32PLLCFGR_TempRegister |= ( Copy_structPLLCongif->RCC_strPLL_P << SHIFT_PLL_P ) ;
				RCC_PLLCFGR = Loc_u32PLLCFGR_TempRegister ;
			
				/* 4: CONFIGURE Q */
				Loc_u32PLLCFGR_TempRegister = RCC_PLLCFGR ;
				Loc_u32PLLCFGR_TempRegister &= ~ MASK_SET_PPL_Q ;
				Loc_u32PLLCFGR_TempRegister |= ( Copy_structPLLCongif->RCC_strPLL_Q << SHIFT_PLL_Q ) ;
				RCC_PLLCFGR = Loc_u32PLLCFGR_TempRegister ;
			
				/* 5: CONFIGURE CLOCK SOURCE */
				Loc_u32PLLCFGR_TempRegister = RCC_PLLCFGR ;
				Loc_u32PLLCFGR_TempRegister &= ~MASK_SET_PPL_SRC ;
				Loc_u32PLLCFGR_TempRegister |= ( Copy_structPLLCongif->RCC_strPLLSCR << SHIFT_PLL_SRC ) ;
				RCC_PLLCFGR = Loc_u32PLLCFGR_TempRegister ;
         }




return Ret_enuErrorStatus ;
}/*RCC_enuConfigPLL*/

RCC_enuErrorStatus_t  RCC_enuControlBusesPrescaler  (RCC_enuBus_t Copy_enuPeripheralBus ,u8 Copy_u32APB2Prescaler)
{
     RCC_enuErrorStatus_t Ret_enuErrorStatus = RCC_enuOK ;

      u32 Loc_u32CFGR_TempRegister;
     /**
     *@ validate input bus
     */
     if( Copy_enuPeripheralBus < RCC_AHB1 || Copy_enuPeripheralBus > RCC_APB2 )
     {
         Ret_enuErrorStatus = RCC_enuNOK ;
     }/*if1*/
     else
     {
        switch(Copy_enuPeripheralBus)
        {
            case RCC_AHB1 :

                            Loc_u32CFGR_TempRegister  = RCC_CFGR;
                            Loc_u32CFGR_TempRegister &= MASK_AHB_PRESCALER ;

                            switch(Copy_u32APB2Prescaler)
                            {
                                case AHB_SYSTEM_CLOCK_NOT_DIVIDED  : 
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_NOT_DIVIDED ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_2 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_2 ;   
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_4 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_4 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_8 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_8 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_16 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_16 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_64 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_64 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_128 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_128 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_256 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_256 ;
                                break;
                                case AHB_SYSTEM_CLOCK_DIVIDED_BY_512 :
                                                    Loc_u32CFGR_TempRegister |= AHB_SYSTEM_CLOCK_DIVIDED_BY_512 ;
                                break;
                                default :
                                        Ret_enuErrorStatus = RCC_enuNOK ;
                                break;

                            }/*switch2*/
                         RCC_CFGR = Loc_u32CFGR_TempRegister;    
                         
            break;
            case RCC_APB1 :
                            Loc_u32CFGR_TempRegister  = RCC_CFGR;
                            Loc_u32CFGR_TempRegister &= MASK_APB1_PRESCALER ;

                            switch(Copy_u32APB2Prescaler)
                            {
                                case APB1_AHB_CLOCK_NOT_DIVIDED  : 
                                                    Loc_u32CFGR_TempRegister |= APB1_AHB_CLOCK_NOT_DIVIDED ;
                                break;
                                case APB1_AHB__CLOCK_DIVIDED_BY_2 :
                                                    Loc_u32CFGR_TempRegister |= APB1_AHB__CLOCK_DIVIDED_BY_2 ;   
                                break;
                                case APB1_AHB__CLOCK_DIVIDED_BY_4 :
                                                    Loc_u32CFGR_TempRegister |= APB1_AHB__CLOCK_DIVIDED_BY_4 ;
                                break;
                                case APB1_AHB__CLOCK_DIVIDED_BY_8 :
                                                    Loc_u32CFGR_TempRegister |= APB1_AHB__CLOCK_DIVIDED_BY_8 ;
                                break;
                                case APB1_AHB__CLOCK_DIVIDED_BY_16:
                                                    Loc_u32CFGR_TempRegister |= APB1_AHB__CLOCK_DIVIDED_BY_16 ;
                                break;
                                default :
                                        Ret_enuErrorStatus = RCC_enuNOK ;
                                break;

                            }/*switch2*/
                         RCC_CFGR = Loc_u32CFGR_TempRegister;    
                         
                         
            break;
            case RCC_APB2 :
                            Loc_u32CFGR_TempRegister  = RCC_CFGR;
                            Loc_u32CFGR_TempRegister &= MASK_APB2_PRESCALER ;

                            switch(Copy_u32APB2Prescaler)
                            {
                                case APB2_AHB_CLOCK_NOT_DIVIDED   : 
                                                    Loc_u32CFGR_TempRegister |= APB2_AHB_CLOCK_NOT_DIVIDED ;
                                break;
                                case APB2_AHB__CLOCK_DIVIDED_BY_2 :
                                                    Loc_u32CFGR_TempRegister |= APB2_AHB__CLOCK_DIVIDED_BY_2 ;   
                                break;
                                case APB2_AHB__CLOCK_DIVIDED_BY_4 :
                                                    Loc_u32CFGR_TempRegister |= APB2_AHB__CLOCK_DIVIDED_BY_4 ;
                                break;
                                case APB2_AHB__CLOCK_DIVIDED_BY_8 :
                                                    Loc_u32CFGR_TempRegister |= APB2_AHB__CLOCK_DIVIDED_BY_8 ;
                                break;
                                case APB2_AHB__CLOCK_DIVIDED_BY_16:
                                                    Loc_u32CFGR_TempRegister |= APB2_AHB__CLOCK_DIVIDED_BY_16 ;
                                break;
                                default :
                                                    Ret_enuErrorStatus = RCC_enuNOK ;
                                break;

                            }/*switch2*/
                         RCC_CFGR = Loc_u32CFGR_TempRegister;    
                         
            break;
            default :
            break;
        }/*switch*/

     }/*else*/



return Ret_enuErrorStatus ;
}/*RCC_enuControlBusesPrescaler*/




