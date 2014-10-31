/*
 * ball.cpp
 *
 *  Created on: 31-Oct-2014
 *      Author: shantanu
 */

#include "../include/headers.h"
#include "../include/ball.h"
#include "../include/macros.h"



ball::ball()
{
	rotateBall = rotation_flag;
}

void ball::drawball()
{
	glPushMatrix();
	myTranslatef(80-moveball,-13.0,0.0);
	if(rotateBall)
		myRotatef(1,0,0,1);
	glutSolidSphere(7.0,30.0,30.0);
	glPopMatrix();
}

void ball::set_rotate(bool x)
{
	rotateBall = x;
}


void animate_ball()
{
	if(moveball<60){
		moveball+=(moveball/50+0.2);
	}
	if(moveball>=60){
		rotation_flag=false;
	}
	glutPostRedisplay();
}
