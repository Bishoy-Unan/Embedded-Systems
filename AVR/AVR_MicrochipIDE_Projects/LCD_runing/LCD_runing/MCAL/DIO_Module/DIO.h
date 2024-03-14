/*
 * DIO.h
 *
 *  Created on: Sep 16, 2019
 *      Author: BISHOY
 */

#ifndef MCAL_DIO_MODULE_DIO_H_
#define MCAL_DIO_MODULE_DIO_H_

/*Define port number */
#define PORTA ((u8)1)    //casting operator
#define PORTB ((u8)2)
#define PORTC ((u8)3)
#define PORTD ((u8)4)

#define HIGH   ((u8)1)
#define LOW    ((u8)0)

/*Define port Direction */

#define OUTPUT  ((u8)0)
#define INPUT   ((u8)1)

/*Define Pins NO*/

#define PIN0   ((u8)0x00)
#define PIN1   ((u8)0x01)
#define PIN2   ((u8)0x02)
#define PIN3   ((u8)0x03)
#define PIN4   ((u8)0x04)
#define PIN5   ((u8)0x05)
#define PIN6   ((u8)0x06)
#define PIN7   ((u8)0x07)
#define PIN8   ((u8)0x08)

void DIO_VidSetPortDir(u8 PortName, u8 PortDir);
void DIO_VidSetPinDir(u8 PortName, u8 PinNo , u8 PinDir);
void DIO_VidSetPortValue(u8 PortName , u8 PortValue);
void DIO_VidSetPinValue(u8 PortName , u8 PinNo , u8 PinValue);
u8 DIO_U8GetPortValue(u8 PortName);
u8 DIO_U8GetPinaValue(u8 PortName , u8 PinNo );



#endif /* MCAL_DIO_MODULE_DIO_H_ */
