/*
 * DIO_interface.h
 *
 * Created: 9/24/2023 10:08:56 PM
 *  Author: nadia
 */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA            0
#define DIO_PORTB            1
#define DIO_PORTC            2
#define DIO_PORTD            3

#define DIO_PIN_INPUT        0
#define DIO_PIN_OUTPUT       1

#define DIO_PIN_LOW          0
#define DIO_PIN_HIGH         1

#define DIO_PIN0             0
#define DIO_PIN1             1
#define DIO_PIN2             2
#define DIO_PIN3             3
#define DIO_PIN4             4
#define DIO_PIN5             5
#define DIO_PIN6             6
#define DIO_PIN7             7


void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection);
void DIO_setPinValue    (u8 PortId, u8 PinId, u8 PinValue);
void DIO_getPinValue    (u8 PortId, u8 PinId, u8* PinValue);
void DIO_togglePinValue (u8 PortId, u8 PinId);
void DIO_activePinInPullUpResistance(u8 PortId, u8 PinId);


void DIO_setPortDirection(u8 PortId, u8 PinDirection);
void DIO_setPortValue    (u8 PortId, u8 PinValue);
void DIO_getPortValue    (u8 PortId, u8* PinValue);
void DIO_togglePortValue (u8 PortId);
void DIO_activePortInPullUpResistance(u8 PortId);

#endif /* DIO_INTERFACE_H_ */
