/*
 * PIT.h
 *
 *  Created on: Jan 22, 2018
 *      Author: User
 */

#ifndef PIT_H_
#define PIT_H_

#include "derivative.h"


	void vfnPITInit(void);
	void vfnPitSetValue(unsigned long dwTime);
	unsigned char bPIT_Valid(void);


#endif /* PIT_H_ */
