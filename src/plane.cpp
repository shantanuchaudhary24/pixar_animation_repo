/*
 * floor.cpp
 *
 *  Created on: 01-Nov-2014
 *      Author: shantanu
 */

#include "../include/headers.h"
#include "../include/plane.h"
#include "../include/macros.h"

plane::plane()
{

}

void plane::drawplane()
{
	//plane
	glPushMatrix();
	glColor3f(1,1,1);
	myTranslatef(0,-20,0);
	myRotatef(90,1,0,0);
	glRectf(-100,100, 100, -100);
	glPopMatrix();

}
