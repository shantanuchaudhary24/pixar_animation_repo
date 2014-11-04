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
	moveball=0;
	gettimeofday(&startTime, NULL);
}

void ball::drawball()
{
	glPushMatrix();
	myTranslatef(30+moveball,-13.0,0.0);
	glutSolidSphere(7.0,30.0,30.0);
	glPopMatrix();
}

void ball::animation(){
	gettimeofday(&currentTime, NULL);
	float total_time_spent = ((float)(currentTime.tv_usec-startTime.tv_usec)) / 1000000 +  (float)(currentTime.tv_sec-startTime.tv_sec);

	if(total_time_spent>8.0f && total_time_spent<12.0f)
		moveball+=0.5;

}
