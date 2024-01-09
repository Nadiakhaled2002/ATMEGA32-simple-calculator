/*
 * KPD_interface.h
 *
 *  Created on: Nov 23, 2023
 *      Author: nadia
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_NOT_PRESSED      0xFF
void KPD_init(void);
void kpd_getValue(u8 *k);


#endif /* KPD_INTERFACE_H_ */
