/*
 * lamp.h
 *
 *  Created on: 29-Oct-2014
 *      Author: shantanu
 */

#ifndef LAMP_H_
#define LAMP_H_

#include "../include/headers.h"
#include "../include/matrix.h"

static float lampMovement[6]={0.0,0.0,0.0,0.0,0.0,0.0};    //{p1_angle, p1_x, p1_y, }

class lamp
{
	public:
	lamp();
	void drawlamp();
};

#endif /* LAMP_H_ */
