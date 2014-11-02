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

static float lampMovement[6]={0,0,0,0,0,0};    //{ }
//static bool rotateball=false;

void animation();
class lamp
{
private:
	float translateX;
	float translateY;
	float translateZ;
	float rotationX;
	float rotationY;
	float rotationZ;
	float rotationX_head;
	float rotationY_head;
	float rotationZ_head;

public:
	lamp();
	void drawlamp();
	float returnX();
	float returnY();
	float returnZ();
	void translate_lamp(float x, float y, float z);
};

#endif /* LAMP_H_ */
