
	/**
	*@bief : Timer0_enumInit function to set configration of timer0(prebuild configration)
	*@inp: NOTHIGN
	*@ret: ERROR STATUS
	*/
	Timers_ErrorSTATUS_t Timer0_enumInit(void)
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
		
		/******************************************************
		* 	Default intialization(prebuild intialization)     *
		******************************************************/
	
		#if (TIMER0_OPERATION_MODE == TIMER0_MODE_NORMAL)	
				/**
				*@ NON PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE
				*/
				SET_BIT(TCCR0,BIT_7);
				/**
				*@ NORMAL MODE
				*@ P3,P6
				*@  0 0 --> NORMAL MODE
				*@  0 1 --> PWM PHASE CORRECT MODE
				*@  1 0 --> CTC MODE
				*@  1 1 --> FAST PWM MODE
				*/
				CLR_BIT(TCCR0,BIT_6);
				CLR_BIT(TCCR0,BIT_3);
							
				/**
				*@ Hardware behavior OC0 pin
				*@ NON PWM MODE
				*@ 00 --> Normal port operation, OC0 disconnected.
				*@ 01 --> Toggle OC0 on compare match
				*@ 10 --> Clear OC0 on compare match
				*@ 11 --> Set OC0 on compare match
				*/
				#if (TIMER0_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED)
						/**
						*@ NON PWM Mode , OC0 DISCONNECTED NORMAL PORT OPERATION
						*/
						CLR_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_TOGGLE)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_TOGGLE
						*/
						CLR_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_CLEAR)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_CLEAR
						*/
						SET_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_SET)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_SET
						*/
						SET_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#else 
					Local_enuReturnStatus = Timers_enuNOK ;
				#endif   
				/**
				*@ ENABLE OVERFLOW INTERRUPT
				*/
				#if ( TIMER0_OVF_INT == ENABLE )
					
					SET_BIT(TIMSK,BIT_0);
				#elif ( TIMER0_OVF_INT == DISABLE )
					CLR_BIT(TIMSK,BIT_0);
				#else
					Local_enuReturnStatus = Timers_enuNOK ;
				#endif	
		#elif (TIMER0_OPERATION_MODE == TIMER0_MODE_PWM_PC)
				/**
				*@  PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE			
				*/
				CLR_BIT(TCCR0,BIT_7);
				/**
				*@ TIMER0_MODE_PWM_PC
				*@
				*@ P3,P6			
				*@ 0 0 --> NORMAL MODE
				*@ 0 1 --> PWM PHASE CORRECT MODE
				*@ 1 0 --> CTC MODE
				*@ 1 1 --> FAST PWM MODE
				*/
				SET_BIT(TCCR0,BIT_6);
				CLR_BIT(TCCR0,BIT_3);	
				/**
				*@ Hardware behavior OC0 pin
				*@  FAST PWM MODE 
				*@ 00 --> Normal port operation, OC0 disconnected.
				*@ 01 --> reserved
				*@ 10 --> TIMER0_OC0_PWM_PC_NON_INVERTING
				*@ 11 --> TIMER0_OC0_PWM_PC_INVERTING
				*/
				#if (TIMER0_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED)
						/**
						*@  PWM Mode , OC0 DISCONNECTED NORMAL PORT OPERATION
						*/
						CLR_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_PWM_PC_NON_INVERTING)
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
						/**
						*@ FAST PWM Mode 
						*/
						SET_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_PWM_PC_INVERTING)
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
						/**
						*@  FAST PWM Mode 
						*/
						SET_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						
				
				#else 
					Local_enuReturnStatus = Timers_enuNOK ;	
				#endif   
		
		#elif (TIMER0_OPERATION_MODE == TIMER0_MODE_CTC) 
				/**
				*@ NON PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE			
				*/
				SET_BIT(TCCR0,BIT_7);
				/**
				*@ TIMER0_MODE_CTC
				*@
				*@ P3,P6			
				*@ 0 0 --> NORMAL MODE
				*@ 0 1 --> PWM PHASE CORRECT MODE
				*@ 1 0 --> CTC MODE
				*@ 1 1 --> FAST PWM MODE
				*/
				SET_BIT(TCCR0,BIT_3);
				CLR_BIT(TCCR0,BIT_6);	
				
				
				/**
				*@ Hardware behavior OC0 pin
				*@ NON PWM MODE
				*@ 00 --> Normal port operation, OC0 disconnected.
				*@ 01 --> Toggle OC0 on compare match
				*@ 10 --> Clear OC0 on compare match
				*@ 11 --> Set OC0 on compare match
				*/
				#if (TIMER0_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED)
						/**
						*@ NON PWM Mode , OC0 DISCONNECTED NORMAL PORT OPERATION
						*/
						CLR_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_TOGGLE)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_TOGGLE
						*/
						CLR_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_CLEAR)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_CLEAR
						*/
						SET_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_SET)
						/**
						*@ NON PWM Mode , OC0 TIMER0_OC0_SET
						*/
						SET_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
	
				#else 
					Local_enuReturnStatus = Timers_enuNOK ;
				#endif   
				
				/**
				*@ ENABLE CTC INTERRUPT
				*/
				#if ( TIMER0_OVF_INT == ENABLE )
					
					SET_BIT(TIMSK,BIT_1);
				#elis ( TIMER0_OVF_INT == DISABLE )
					CLR_BIT(TIMSK,BIT_1);
				#else
					Local_enuReturnStatus = Timers_enuNOK ;
				#endif	
			
		#elif (TIMER0_OPERATION_MODE == TIMER0_MODE_PWM_F) 
				/**
				*@  PWM Mode
				*@ 0 --> PWM MODE
				*@ 1 --> NON PWM MODE			
				*/
				CLR_BIT(TCCR0,BIT_7);
				/**
				*@ TIMER0_MODE_CTC
				*@
				*@ P3,P6			
				*@ 0 0 --> NORMAL MODE
				*@ 0 1 --> PWM PHASE CORRECT MODE
				*@ 1 0 --> CTC MODE
				*@ 1 1 --> FAST PWM MODE
				*/
				SET_BIT(TCCR0,BIT_3);
				SET_BIT(TCCR0,BIT_6);
				/**
				*@ Hardware behavior OC0 pin
				*@  FAST PWM MODE 
				*@ 00 --> Normal port operation, OC0 disconnected.
				*@ 01 --> reserved
				*@ 10 --> TIMER0_OC0_PWM_F_CLR_NON_INVERTING
				*@ 11 --> TIMER0_OC0_PWM_F_INVERTING
				*/
				#if (TIMER0_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED)
						/**
						*@  PWM Mode , OC0 DISCONNECTED NORMAL PORT OPERATION
						*/
						CLR_BIT(TCCR0,BIT_5);
						CLR_BIT(TCCR0,BIT_4);
						
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_PWM_F_CLR_NON_INVERTING)
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
						/**
						*@ FAST PWM Mode 
						*/
						CLR_BIT(TCCR0,BIT_4);
						SET_BIT(TCCR0,BIT_5);
						
	
				#elif (TIMER0_OUTPUT_MODE == TIMER0_OC0_PWM_F_INVERTING)
						/**
						*@ SET PIN3 AT PORTB (OC0) AS OUTPUT
						*/
						SET_BIT(DDRB,BIT_3);
						/**
						*@  FAST PWM Mode 
						*/
						SET_BIT(TCCR0,BIT_5);
						SET_BIT(TCCR0,BIT_4);
						
	
				
				#else 
					Local_enuReturnStatus = Timers_enuNOK ;	
				#endif		
			
		#else
				Local_enuReturnStatus = Timers_enuNOK ;
		#endif	
	
		
		/**
		*@	Clock Selection (prescaler)      		
		*@ OPTIONS :
		*@
		*@ 0 0 0 --> No clock source (Timer/Counter stopped).
		*@ 0 0 1 --> clkI/O/(No prescaling)
		*@ 0 1 0 --> clkI/O/8 (From prescaler)
		*@ 0 1 1 --> clkI/O/64 (From prescaler)
		*@ 1 0 0 --> clkI/O/256 (From prescaler)
		*@ 1 0 1 --> clkI/O/1024 (From prescaler)
		*@ 1 1 0 --> External clock source on T0 pin. Clock on falling edge.
		*@ 1 1 1 --> External clock source on T0 pin. Clock on rising edge.
		*/
				
		#if (TIMER0_CLK_SEL == TIMER0_NO_CLK)
			/**
			*@ 0 0 0 --> No clock source (Timer/Counter stopped).
			*/
			CLR_BIT(TCCR0,BIT_2);
			CLR_BIT(TCCR0,BIT_1);
			CLR_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_PRESCALER_DIV_1)
			/**
			*@ 0 0 1 --> clkI/O/(No prescaling)
			*/
			CLR_BIT(TCCR0,BIT_2);
			CLR_BIT(TCCR0,BIT_1);
			SET_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_PRESCALER_DIV_8)
			/**
			*@ 0 1 0 --> clkI/O/8 (From prescaler)
			*/
			CLR_BIT(TCCR0,BIT_2);
			SET_BIT(TCCR0,BIT_1);
			CLR_BIT(TCCR0,BIT_0);
	
		#elif (TIMER0_CLK_SEL == TIMER0_PRESCALER_DIV_64)
			/**
			*@ 0 1 1 --> clkI/O/64 (From prescaler)
			*/
			CLR_BIT(TCCR0,BIT_2);
			CLR_BIT(TCCR0,BIT_1);
			CLR_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_PRESCALER_DIV_256)
			/**
			*@ 1 0 0 --> clkI/O/256 (From prescaler)
			*/
			SET_BIT(TCCR0,BIT_2);
			CLR_BIT(TCCR0,BIT_1);
			CLR_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_PRESCALER_DIV_1024)
			/**
			*@ 1 0 1 --> clkI/O/1024 (From prescaler)
			*/
			SET_BIT(TCCR0,BIT_2);
			CLR_BIT(TCCR0,BIT_1);
			SET_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_EXT_CLK_FALLING_EDGE)
			/**
			*@ 1 1 0 --> External clock source on T0 pin. Clock on falling edge.
			*/
			SET_BIT(TCCR0,BIT_2);
			SET_BIT(TCCR0,BIT_1);
			CLR_BIT(TCCR0,BIT_0);
		#elif (TIMER0_CLK_SEL == TIMER0_EXT_CLK_FALLING_RISING)
			/**
			*@ 1 1 1 --> External clock source on T0 pin. Clock on rising edge.
			*/
			SET_BIT(TCCR0,BIT_2);
			SET_BIT(TCCR0,BIT_1);
			SET_BIT(TCCR0,BIT_0);
		#else
				Local_enuReturnStatus = Timers_enuNOK ;
		#endif	
		
		
		/**
		*@ RESET TCNT0 REGISTER,COUNTING VALUE TO BE SET USING Timer0_enumSetTimer() FUNCTION
		*/
		TCNT0 = 0X00;
		/**
		*@ ENABLE GLOBAL INTERRUPT
		*/
		//SET_BIT(SREG,BIT_7);
	
	
		
		
	return Local_enuReturnStatus ;
	}  /* Timer0_enumInit Function*/
	
	
	
	/**
	*@bief : Timer1_enumInit function to set configration of timer1(prebuild configration)
	*@inp: NOTHIGN
	*@ret: ERROR STATUS
	*/
	Timers_ErrorSTATUS_t Timer1_enumInit(void)
	{
		Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
		
		
		/******************************************************
		* 	Default intialization(prebuild intialization)     *
		******************************************************/
			
				
				
				/**
				*@ Timer1 Waveform Generation Mode
				*@
				*@ Options:
				*@
				*@  	TCCR1B	TCCR1A	
				*@  	P4  P3  P1  P0
				*@ 		0   0   0    0  	TIMER1_MODE_NORMAL
				*@ 		0   0   0    1  	TIMER1_MODE_PWM_PC_8BIT
				*@ 		0	0	1    0		TIMER1_MODE_PWM_PC_9BIT
				*@ 		0  	0	1	 1 		TIMER1_MODE_PWM_PC_10BIT
				*@  	0  	1	0	 0      TIMER1_MODE_CTC_OCR1A
				*@  	0  	1	0	 1      TIMER1_MODE_PWM_F_8BIT
				*@  	0  	1	1	 0      TIMER1_MODE_PWM_F_9BIT
				*@  	0  	1	1	 1      TIMER1_MODE_PWM_F_10BIT
				*@  	1  	0	0	 0      TIMER1_MODE_PWM_PC__FC_ICR1
				*@  	1  	0	0	 1      TIMER1_MODE_PWM_PC__FC_OCR1A
				*@  	1  	0	1	 0      TIMER1_MODE_PWM_PC_ICR1
				*@  	1  	0	1	 1      TIMER1_MODE_PWM_PC_OCR1A
				*@  	1  	1	0	 0      TIMER1_MODE_CTC_ICR1
				*@  	1  	1	1	 0      TIMER1_MODE_PWM_F_ICR1
				*@  	1  	1	1	 1  	TIMER1_MODE_PWM_F_OCR1A
				*@	
				*/
				
				#if (TIMER1_OPERATION_MODE == TIMER1_MODE_NORMAL)	
						/**
						*@ NON PWM Mode
						*@
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   0   0    0  	TIMER1_MODE_NORMAL
						*@ 		   P3  P2
						*@			1  1	NORMAL MODE
						*/
						CLR_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);
						
						SET_BIT(TCCR1A,BIT_3);
						SET_BIT(TCCR1A,BIT_2);
					
						
				/**
				*@ ALL PHASE CORRECT MODES
				*/
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_8BIT)  		  
					
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   0   0    1  	TIMER1_MODE_PWM_PC_8BIT	
						*@ 		   P3  P2
						*@			0  0	PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);
	
											
				
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_9BIT)  		  
								
																		
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   0   1    0  	TIMER1_MODE_PWM_PC_9BIT	
						*@ 		   P3  P2
						*@			0  0	PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);	
					
					
					
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_10BIT)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   0   1    1  	TIMER1_MODE_PWM_PC_9BIT	
						*@ 		   P3  P2
						*@			0  0	PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);	
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_CTC_OCR1A)
						/**
						*@ NON PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   1   0    0  	TIMER1_MODE_PWM_PC_9BIT	
						*@ 		   P3  P2
						*@			1  1	NON PWM CTC MODE
						*/
						SET_BIT(TCCR1A,BIT_3);
						SET_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);	
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_8BIT)	
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   1   0    1  	TIMER1_MODE_PWM_PC_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM FAST MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);	
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_9BIT)	
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   1   1    0  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM FAST MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);	
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_10BIT)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 0   1   1    1  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM FAST MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						CLR_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC__FC_ICR1)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   0   0    0  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC__FC_OCR1A)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   0   0    1  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_ICR1)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   0   1    0  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_OCR1A)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   0   1    1  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						CLR_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_CTC_ICR1)
						/**
						*@ NON PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   1   0    0  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			1  1	 NON PWM CTC MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						CLR_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_ICR1)	
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   1   1    0  	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM FAST MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						CLR_BIT(TCCR1A,BIT_0);
				#elif (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_OCR1A)
						/**
						*@ PWM MODE
						*@ TCCR1B	TCCR1A	
						*@ P4  P3  P1  P0
						*@ 1   1   1    1 	TIMER1_MODE_PWM_F_9BIT	
						*@ 		   P3  P2
						*@			0  0	 PWM PHASE CORRECT MODE
						*/
						CLR_BIT(TCCR1A,BIT_3);
						CLR_BIT(TCCR1A,BIT_2);
						
						SET_BIT(TCCR1B,BIT_4);
						SET_BIT(TCCR1B,BIT_3);
						SET_BIT(TCCR1A,BIT_1);
						SET_BIT(TCCR1A,BIT_0);
				#else
						Local_enuReturnStatus = Timers_enuNOK ;
				#endif
	
				/**
				*@ HARD WARE MODE OC1A AND OC1B
				*/
				#if (  (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_8BIT)  		  ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_9BIT)  		  ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_10BIT) 		  ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC__FC_ICR1)  	  ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC__FC_OCR1A)    ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_ICR1)  		  ||  \
					(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_PC_OCR1A)    )	
					
							
							/**
							*@ Hardware behavior OC1A(PORTD PIN 5) AND OC1B pin(PORTD PIN4)
							*@  PHASE CORRECT  PWM MODE 
							*@ 	    TCCR1A	
							*@  P7&P5  P6&P4
							*@  (OC1A) & (OC1B)
							*@    0      0   	   		
							*@    0      1      
							*@    1      0      
							*@    1      1      
							*/
							
							/**
							*@ CHANNEL A PWM PHASE CORRECT
							*/
							#if (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_OC1A_DISCONNECTED)
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									CLR_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									
							#elif (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_PWM_PC_TOGGLE_OC1A_ON_COM_MATCH)
									
									CLR_BIT(TCCR1A,BIT_7);
									SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1A_NON_INVERTING)
									
									SET_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1A_INVERTING)
										SET_BIT(TCCR1A,BIT_7);
										SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
		
							/**
							*@ CHANNEL B PWM PHASE CORRECT
							*/
							#if (TIMER1_OUTPUT_CHANNELB_HW_MODE == TIMER1_OC1B_DISCONNECTED)
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									CLR_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									
							#elif (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_PWM_PC_OC1B_DISCONNECTED)
									
									CLR_BIT(TCCR1A,BIT_7);
									SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_NON_INVERTING)
									
									SET_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_INVERTING)
										SET_BIT(TCCR1A,BIT_7);
										SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
					
				#elif ( (TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_8BIT)	|| \
						(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_9BIT)	|| \
						(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_10BIT)	|| \
						(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_ICR1)	|| \
						(TIMER1_OPERATION_MODE == TIMER1_MODE_PWM_F_OCR1A)	)
						
															
							/**
							*@ CHANNEL A PWM FAST MODE
							*/
							#if (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_OC1A_DISCONNECTED)
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									CLR_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									
							#elif (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_PWM_PC_TOGGLE_OC1A_ON_COM_MATCH)
									
									CLR_BIT(TCCR1A,BIT_7);
									SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1A_NON_INVERTING)
									
									SET_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1A_INVERTING)
										SET_BIT(TCCR1A,BIT_7);
										SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
		
							/**
							*@ CHANNEL B PWM FASE CORRECT
							*/
							#if (TIMER1_OUTPUT_CHANNELB_HW_MODE == TIMER1_OC1B_DISCONNECTED)
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									CLR_BIT(TCCR1A,BIT_5);
									CLR_BIT(TCCR1A,BIT_4);
									
							#elif (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_PWM_PC_OC1B_DISCONNECTED)
									
									CLR_BIT(TCCR1A,BIT_5);
									SET_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_NON_INVERTING)
									
									SET_BIT(TCCR1A,BIT_5);
									CLR_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_INVERTING)
										SET_BIT(TCCR1A,BIT_5);
										SET_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
		
							
				#elif ( (TIMER1_OPERATION_MODE == TIMER1_MODE_CTC_ICR1)		|| \
						(TIMER1_OPERATION_MODE == TIMER1_MODE_CTC_OCR1A)		)
						
							/**
							*@ NON PWM MODE CTC MODE
							*/
							SET_BIT(TCCR1A,BIT_3);
							SET_BIT(TCCR1A,BIT_2);
							
							/**
							*@ CHANNEL A CTC MODE
							*/
							#if  (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_OC1A_DISCONNECTED)		
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									
									CLR_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									
									
							#elif  (TIMER1_OUTPUT_CHANNELA_HW_MODE == TOGGLE_OC1A_ON_COMPARE_MATCH) 
								
									CLR_BIT(TCCR1A,BIT_7);
									SET_BIT(TCCR1A,BIT_6);
									
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
								
				
							#elif  (TIMER1_OUTPUT_CHANNELA_HW_MODE == CLEAR_OC1A_ON_COMPARE_MATCH) 
									
									SET_BIT(TCCR1A,BIT_7);
									CLR_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#elif (TIMER2_OUTPUT_MODE == SET_OC1A_ON_COMPARE_MATCH)
										SET_BIT(TCCR1A,BIT_7);
										SET_BIT(TCCR1A,BIT_6);
									/**
									*@ SET PIN5 AT PORTD (OC1A) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_5);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
		
							/**
							*@ CHANNEL B CTC MODE
							*/
							#if (TIMER1_OUTPUT_CHANNELB_HW_MODE == TIMER1_OC1B_DISCONNECTED)
									/**
									*@  PWM Mode , TIMER1_OC1A_DISCONNECTED & TIMER1_OC1B_DISCONNECTED 
									*/
									CLR_BIT(TCCR1A,BIT_5);
									CLR_BIT(TCCR1A,BIT_4);
									
							#elif (TIMER1_OUTPUT_CHANNELA_HW_MODE == TIMER1_PWM_PC_OC1B_DISCONNECTED)
									
									CLR_BIT(TCCR1A,BIT_5);
									SET_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_NON_INVERTING)
									
									SET_BIT(TCCR1A,BIT_5);
									CLR_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#elif (TIMER2_OUTPUT_MODE == TIMER1_PWM_PC_OC1B_INVERTING)
										SET_BIT(TCCR1A,BIT_5);
										SET_BIT(TCCR1A,BIT_4);
									/**
									*@ SET PIN4 AT PORTD (OC1B) AS OUTPUT
									*/
									SET_BIT(DDRD,BIT_4);
				
							#else 
								Local_enuReturnStatus = Timers_enuNOK ;	
							#endif  
		
				#else
					Local_enuReturnStatus = Timers_enuNOK ;
				#endif	
		/**
		*@	Clock Selection (prescaler)      		
		*@ OPTIONS :
		*@
		*@ 0 0 0 -->  TIMER1_NO_CLK
		*@ 0 0 1 -->  TIMER1_PRESCALER_DIV_1
		*@ 0 1 0 -->  TIMER1_PRESCALER_DIV_8
		*@ 0 1 1 -->  TIMER1_PRESCALER_DIV_64
		*@ 1 0 0 -->  TIMER1_PRESCALER_DIV_256
		*@ 1 0 1 -->  TIMER1_PRESCALER_DIV_1024
		*@ 1 1 0 -->  TIMER1_EXT_CLK_FALLING_EDGE
		*@ 1 1 1 -->  TIMER1_EXT_CLK_FALLING_RISING
		*/
				
		#if (TIMER1_CLK_SEL == TIMER1_NO_CLK)
			/**
			*@ 0 0 0 --> No clock source (Timer/Counter stopped).
			*/
			CLR_BIT(TCCR1B,BIT_2);
			CLR_BIT(TCCR1B,BIT_1);
			CLR_BIT(TCCR1B,BIT_0);
		#elif (TIMER1_CLK_SEL == TIMER1_PRESCALER_DIV_1)
			/**
			*@ 0 0 1 --> clkI/O/(No prescaling)
			*/
			CLR_BIT(TCCR1B,BIT_2);
			CLR_BIT(TCCR1B,BIT_1);
			SET_BIT(TCCR1B,BIT_0);
		#elif (TIMER2_CLK_SEL == TIMER1_PRESCALER_DIV_8)
			/**
			*@ 0 1 0 --> clkI/O/8 (From prescaler)
			*/
			CLR_BIT(TCCR1B,BIT_2);
			SET_BIT(TCCR1B,BIT_1);
			CLR_BIT(TCCR1B,BIT_0);
	
		#elif (TIMER1_CLK_SEL == TIMER1_PRESCALER_DIV_64)
			/**
			*@ 0 1 1 --> clkI/O/32 (From prescaler)
			*/
			CLR_BIT(TCCR1B,BIT_2);
			CLR_BIT(TCCR1B,BIT_1);
			CLR_BIT(TCCR1B,BIT_0);
		#elif (TIMER1_CLK_SEL == TIMER1_PRESCALER_DIV_256)
			/**
			*@ 1 0 0 --> clkI/O/64 (From prescaler)
			*/
			SET_BIT(TCCR1B,BIT_2);
			CLR_BIT(TCCR1B,BIT_1);
			CLR_BIT(TCCR1B,BIT_0);
		#elif (TIMER1_CLK_SEL == TIMER1_PRESCALER_DIV_1024)
			/**
			*@ 1 0 1 --> clkI/O/128 (From prescaler)
			*/
			SET_BIT(TCCR1B,BIT_2);
			CLR_BIT(TCCR1B,BIT_1);
			SET_BIT(TCCR1B,BIT_0);
		#elif (TIMER1_CLK_SEL == TIMER1_EXT_CLK_FALLING_EDGE)
			/**
			*@ 1 1 0 --> TIMER2_PRESCALER_DIV_256
			*/
			SET_BIT(TCCR1B,BIT_2);
			SET_BIT(TCCR1B,BIT_1);
			CLR_BIT(TCCR1B,BIT_0);
		#elif (TIMER1_CLK_SEL == TIMER1_EXT_CLK_FALLING_RISING)
			/**
			*@ 1 1 1 --> TIMER2_PRESCALER_DIV_1024
			*/
			SET_BIT(TCCR1B,BIT_2);
			SET_BIT(TCCR1B,BIT_1);
			SET_BIT(TCCR1B,BIT_0);
		#else
				Local_enuReturnStatus = Timers_enuNOK ;
		#endif	
		
		/**
		*@ Input Capture Edge Select
		*@
		*@ Options:
		*@ 	1-	CAPTURE_EDGE_DETECTION_FALLING
		*@ 	2-	CAPTURE_EDGE_DETECTION_RISING
		*/
	
		#if (INPUT_CAPTURE_EDGE  == CAPTURE_EDGE_DETECTION_RISING)
					SET_BIT(TCCR1B,BIT_6);
		#elif (INPUT_CAPTURE_EDGE  == CAPTURE_EDGE_DETECTION_FALLING)
					CLR_BIT(TCCR1B,BIT_6);
		#else	
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif	
		
		
		
		
		/**
		*@ RESET TCNT2 REGISTER,COUNTING VALUE TO BE SET USING Timer_enumSetTimer() FUNCTION
		*/
		TCNT1H = 0X00;
		TCNT1L = 0X00;
		
		
		/**
		*@ INTERRUPS ENABLE AND DISABLE
		*@ OVER FLOW INTERRUPT
		*/
		#if (TIMER1_OVF_INT  == ENABLE)
					SET_BIT(TIMSK,BIT_2);
		#elif (TIMER1_OVF_INT  == DISABLE)
					CLR_BIT(TIMSK,BIT_2);
		#else	
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif
		/**
		*@ CTC MODE CHANNEL A ENABLE
		*/
		#if (TIMER1_CTC_CHANNELA_INT  == ENABLE)
					SET_BIT(TIMSK,BIT_4);
		#elif (TIMER1_CTC_CHANNELA_INT  == DISABLE)
					CLR_BIT(TIMSK,BIT_4);
		#else	
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif
		/**
		*@ CTC MODE CHANNEL A ENABLE
		*/
		#if (TIMER1_CTC_CHANNELB_INT  == ENABLE)
					SET_BIT(TIMSK,BIT_3);
		#elif (TIMER1_CTC_CHANNELB_INT  == DISABLE)
					CLR_BIT(TIMSK,BIT_3);
		#else	
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif
		/**
		*@ INPUT CAPTURE INTERRUPT ENABLE
		*/
		#if (TIMER1_CAPTURE_INT  == ENABLE)
					SET_BIT(TIMSK,BIT_5);
		#elif (TIMER1_CAPTURE_INT  == DISABLE)
					CLR_BIT(TIMSK,BIT_5);
		#else	
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif
		/**
		*@ ENABLE GLOBAL INTERRUPT
		*/
		SET_BIT(SREG,BIT_7);
	
	
		
		
	return Local_enuReturnStatus ;
	}  /* Timer1_enumInit Function*/
	
	
	
	/**
	*@bief : Timer2_enumInit function to set configration of timer2(prebuild configration)
	*@inp: NOTHIGN
	*@ret: ERROR STATUS
	*/
	Timers_ErrorSTATUS_t Timer2_enumInit(void)
	{
	Timers_ErrorSTATUS_t Local_enuReturnStatus = Timers_enuOK ;
	
	
	/******************************************************
	 * 	Default intialization(prebuild intialization)     *
	 ******************************************************/
		
		/**
		*@ check timer/counter 2 operation mode
		*@ it may be timer (synchronus) or counter (asynchronus)
		*/
		#if (TIMER_COUNTER_2_OPERATION_MODE == SYNCHRONUS)
			
			/**
			*@ TIMER Mode
			*/
			SET_BIT(ASSR,BIT_3);
			
			#if (TIMER2_OPERATION_MODE == TIMER2_MODE_NORMAL)	
					/**
					*@ NON PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE
					*/
					SET_BIT(TCCR2,BIT_7);
					/**
					*@ NORMAL MODE
					*@ P3,P6
					*@  0 0 --> NORMAL MODE
					*@  0 1 --> PWM PHASE CORRECT MODE
					*@  1 0 --> CTC MODE
					*@  1 1 --> FAST PWM MODE
					*/
					CLR_BIT(TCCR2,BIT_6);
					CLR_BIT(TCCR2,BIT_3);
					/**
					*@ ENABLE OVERFLOW INTERRUPT
					*/
					#if ( TIMER2_OVF_INT == ENABLE )
						
						SET_BIT(TIMSK,BIT_6);
					#elif ( TIMER0_OVF_INT == DISABLE )
						CLR_BIT(TIMSK,BIT_6);
					#else
						Local_enuReturnStatus = Timers_enuNOK ;
					#endif	
			#elif (TIMER2_OPERATION_MODE == TIMER2_MODE_PWM_PC)
					/**
					*@  PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE			
					*/
					CLR_BIT(TCCR2,BIT_7);
					/**
					*@ TIMER2_MODE_PWM_PC
					*@
					*@ P3,P6			
					*@ 0 0 --> NORMAL MODE
					*@ 0 1 --> PWM PHASE CORRECT MODE
					*@ 1 0 --> CTC MODE
					*@ 1 1 --> FAST PWM MODE
					*/
					SET_BIT(TCCR2,BIT_6);
					CLR_BIT(TCCR2,BIT_3);	
					/**
					*@ Hardware behavior OC2 pin
					*@  FAST PWM MODE 
					*@ 00 --> Normal port operation, OC2 disconnected.
					*@ 01 --> reserved
					*@ 10 --> TIMER0_OC2_PWM_PC_NON_INVERTING
					*@ 11 --> TIMER0_OC2_PWM_PC_INVERTING
					*/
					#if (TIMER2_OUTPUT_MODE == TIMER0_OC2_DISCONNECTED)
							/**
							*@  PWM Mode , OC2 DISCONNECTED NORMAL PORT OPERATION
							*/
							CLR_BIT(TCCR2,BIT_5);
							CLR_BIT(TCCR2,BIT_4);
							
					#elif (TIMER2_OUTPUT_MODE == TIMER0_OC2_PWM_PC_NON_INVERTING)
							/**
							*@ FAST PWM Mode 
							*/
							CLR_BIT(TCCR2,BIT_4);
							SET_BIT(TCCR2,BIT_5);
							/**
							*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					#elif (TIMER2_OUTPUT_MODE == TIMER0_OC2_PWM_PC_INVERTING)
							/**
							*@  FAST PWM Mode 
							*/
							SET_BIT(TCCR2,BIT_5);
							SET_BIT(TCCR2,BIT_4);
							/**
							*@ SET PIN3 AT PORTB (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					
					#else 
						Local_enuReturnStatus = Timers_enuNOK ;	
					#endif   
			
			#elif (TIMER2_OPERATION_MODE == TIMER2_MODE_CTC) 
					/**
					*@ NON PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE			
					*/
					SET_BIT(TCCR2,BIT_7);
					/**
					*@ TIMER0_MODE_CTC
					*@
					*@ P3,P6			
					*@ 0 0 --> NORMAL MODE
					*@ 0 1 --> PWM PHASE CORRECT MODE
					*@ 1 0 --> CTC MODE
					*@ 1 1 --> FAST PWM MODE
					*/
					SET_BIT(TCCR2,BIT_3);
					CLR_BIT(TCCR2,BIT_6);	
					
					
					/**
					*@ Hardware behavior OC2 pin
					*@ NON PWM MODE
					*@ 00 --> Normal port operation, OC2 disconnected.
					*@ 01 --> Toggle OC2 on compare match
					*@ 10 --> Clear OC2 on compare match
					*@ 11 --> Set OC2 on compare match
					*/
					#if (TIMER2_OUTPUT_MODE == TIMER2_OC2_DISCONNECTED)
							/**
							*@ NON PWM Mode , OC2 DISCONNECTED NORMAL PORT OPERATION
							*/
							CLR_BIT(TCCR2,BIT_5);
							CLR_BIT(TCCR2,BIT_4);
							
					#elif (TIMER2_OUTPUT_MODE == TIMER2_OC2_TOGGLE)
							/**
							*@ NON PWM Mode , OC2 TIMER0_OC2_TOGGLE
							*/
							CLR_BIT(TCCR2,BIT_5);
							SET_BIT(TCCR2,BIT_4);
							/**
							*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					#elif (TIMER2_OUTPUT_MODE == TIMER2_OC2_CLEAR)
							/**
							*@ NON PWM Mode , OC2 TIMER2_OC2_CLEAR
							*/
							SET_BIT(TCCR2,BIT_5);
							CLR_BIT(TCCR2,BIT_4);
							/**
							*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					#elif (TIMER2_OUTPUT_MODE == TIMER2_OC2_SET)
							/**
							*@ NON PWM Mode , OC2 TIMER2_OC2_SET
							*/
							SET_BIT(TCCR2,BIT_5);
							SET_BIT(TCCR2,BIT_4);
							/**
							*@ SET PIN3 AT PORTB (OC2) AS OUTPUT
							*/
							SET_BIT(DDR2,BIT_7);
		
					#else 
						Local_enuReturnStatus = Timers_enuNOK ;
					#endif   
					
					/**
					*@ ENABLE CTC INTERRUPT
					*/
					#if ( TIMER2_OVF_INT == ENABLE )
						
						SET_BIT(TIMSK,BIT_7);
					#elif ( TIMER2_OVF_INT == DISABLE )
						CLR_BIT(TIMSK,BIT_7);
					#else
						Local_enuReturnStatus = Timers_enuNOK ;
					#endif	
				
			#elif (TIMER2_OPERATION_MODE == TIMER2_MODE_PWM_F) 
					/**
					*@ NON PWM Mode
					*@ 0 --> PWM MODE
					*@ 1 --> NON PWM MODE			
					*/
					CLR_BIT(TCCR2,BIT_7);
					/**
					*@ TIMER2_MODE_CTC
					*@
					*@ P3,P6			
					*@ 0 0 --> NORMAL MODE
					*@ 0 1 --> PWM PHASE CORRECT MODE
					*@ 1 0 --> CTC MODE
					*@ 1 1 --> FAST PWM MODE
					*/
					SET_BIT(TCCR2,BIT_3);
					SET_BIT(TCCR2,BIT_6);
					/**
					*@ Hardware behavior OC2 pin
					*@  FAST PWM MODE 
					*@ 00 --> Normal port operation, OC2 disconnected.
					*@ 01 --> reserved
					*@ 10 --> TIMER2_OC2_PWM_F_CLR_NON_INVERTING
					*@ 11 --> TIMER2_OC2_PWM_F_INVERTING
					*/
					#if (TIMER2_OUTPUT_MODE == TIMER2_OC2_DISCONNECTED)
							/**
							*@  PWM Mode , OC2 DISCONNECTED NORMAL PORT OPERATION
							*/
							CLR_BIT(TCCR2,BIT_5);
							CLR_BIT(TCCR2,BIT_4);
							
					#elif (TIMER2_OUTPUT_MODE == TIMER2_OC2_PWM_F_CLR_NON_INVERTING)
							/**
							*@ FAST PWM Mode 
							*/
							CLR_BIT(TCCR2,BIT_4);
							SET_BIT(TCCR2,BIT_5);
							/**
							*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					#elif (TIMER2_OUTPUT_MODE == TIMER2_OC2_PWM_F_INVERTING)
							/**
							*@  FAST PWM Mode 
							*/
							SET_BIT(TCCR2,BIT_5);
							SET_BIT(TCCR2,BIT_4);
							/**
							*@ SET PIN7 AT PORTD (OC2) AS OUTPUT
							*/
							SET_BIT(DDRD,BIT_7);
		
					
					#else 
						Local_enuReturnStatus = Timers_enuNOK ;	
					#endif		
				
			#else
					Local_enuReturnStatus = Timers_enuNOK ;
			#endif	
		#elif (TIMER_COUNTER_2_OPERATION_MODE == ASYNCHRONUS)
			/**
			*@ counter mode
			*/
			CLR_BIT(ASSR,BIT_3);
		#else
			Local_enuReturnStatus = Timers_enuNOK ;
		#endif		
	
	/**
	*@	Clock Selection (prescaler)      		
	*@ OPTIONS :
	*@
	*@ 0 0 0 -->  TIMER2_NO_CLK	(Timer/Counter stopped).
	*@ 0 0 1 -->  TIMER2_PRESCALER_DIV_1
	*@ 0 1 0 -->  TIMER2_PRESCALER_DIV_8
	*@ 0 1 1 -->  TIMER2_PRESCALER_DIV_32	
	*@ 1 0 0 -->  TIMER2_PRESCALER_DIV_64
	*@ 1 0 1 -->  TIMER2_PRESCALER_DIV_128
	*@ 1 1 0 -->  TIMER2_PRESCALER_DIV_256
	*@ 1 1 1 -->  TIMER2_PRESCALER_DIV_1024
	*/
			
	#if (TIMER2_CLK_SEL == TIMER2_NO_CLK)
		/**
		*@ 0 0 0 --> No clock source (Timer/Counter stopped).
		*/
		CLR_BIT(TCCR2,BIT_2);
		CLR_BIT(TCCR2,BIT_1);
		CLR_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_1)
		/**
		*@ 0 0 1 --> clkI/O/(No prescaling)
		*/
		CLR_BIT(TCCR2,BIT_2);
		CLR_BIT(TCCR2,BIT_1);
		SET_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_8)
		/**
		*@ 0 1 0 --> clkI/O/8 (From prescaler)
		*/
		CLR_BIT(TCCR2,BIT_2);
		SET_BIT(TCCR2,BIT_1);
		CLR_BIT(TCCR2,BIT_0);

	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_32)
		/**
		*@ 0 1 1 --> clkI/O/32 (From prescaler)
		*/
		CLR_BIT(TCCR2,BIT_2);
		CLR_BIT(TCCR2,BIT_1);
		CLR_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_64)
		/**
		*@ 1 0 0 --> clkI/O/64 (From prescaler)
		*/
		SET_BIT(TCCR2,BIT_2);
		CLR_BIT(TCCR2,BIT_1);
		CLR_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_128)
		/**
		*@ 1 0 1 --> clkI/O/128 (From prescaler)
		*/
		SET_BIT(TCCR2,BIT_2);
		CLR_BIT(TCCR2,BIT_1);
		SET_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_256)
		/**
		*@ 1 1 0 --> TIMER2_PRESCALER_DIV_256
		*/
		SET_BIT(TCCR2,BIT_2);
		SET_BIT(TCCR2,BIT_1);
		CLR_BIT(TCCR2,BIT_0);
	#elif (TIMER2_CLK_SEL == TIMER2_PRESCALER_DIV_1024)
		/**
		*@ 1 1 1 --> TIMER2_PRESCALER_DIV_1024
		*/
		SET_BIT(TCCR2,BIT_2);
		SET_BIT(TCCR2,BIT_1);
		SET_BIT(TCCR2,BIT_0);
	#else
			Local_enuReturnStatus = Timers_enuNOK ;
	#endif	
	
	
	/**
	*@ RESET TCNT2 REGISTER,COUNTING VALUE TO BE SET USING Timer_enumSetTimer() FUNCTION
	*/
	TCNT2 = 0X00;
	/**
	*@ ENABLE GLOBAL INTERRUPT
	*/
	SET_BIT(SREG,BIT_7);


	
	
  return Local_enuReturnStatus ;
}  /* Timer2_enumInit Function*/
