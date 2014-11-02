/*
 * lamp.cpp
 *
 *  Created on: 29-Oct-2014
 *      Author: shantanu
 */

#include "../include/headers.h"
#include "../include/lamp.h"
#include "../include/macros.h"
lamp::lamp()
{
	translateX = 0;
	translateY = 0;
	translateZ = 0;
	rotationX = 0;
	rotationY = 0;
	rotationZ = 0;
	rotationX_head = 0;
	rotationY_head = 0;
	rotationZ_head = 0;
}

void lamp::translate_lamp(float x, float y, float z)
{
	translateX = x;
	translateY = 0;	// move in X-Z plane only
	translateZ = z;
}

void lamp::drawlamp()
{

	GLUquadric *quad=gluNewQuadric();

		glPushMatrix();

			glColor3f(0.6,0,0);
			//base plate
			glPushMatrix();
			myTranslatef(0.0 + translateX,-20.0 + translateY,0.0 + translateZ);
			myRotatef(-90,1,0,0);
			glutSolidCone(10,5,100,100);
			//gluDisk(quad, 2.0, 7.0, 100, 100 );
			glPopMatrix();

			//base support
			glPushMatrix();
			myTranslatef(0.0 + translateX ,-2.0 + translateY ,0.0 + translateZ);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 1, 1, 15.0,100,100);
			glPopMatrix();

			//upper support
			glPushMatrix();
			myTranslatef(10.0 + translateX ,8.0 + translateY ,0.0 + translateZ);
			myRotatef(-45.0f,0.0f,0.0f,1.0f);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 1, 1, 15.0,100,100);
			glPopMatrix();

			//face
			glPushMatrix();
			myTranslatef(16.3 + translateX ,1.0 + translateY ,0.0 + translateZ);
			myRotatef(-135.0f,0.0f,0.0f,1.0f);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 8, 1, 10.0,100,100);
			glPopMatrix();

		glPopMatrix();
}

float lamp::returnX()
{
	return translateX;
}

float lamp::returnY()
{
	return translateY;
}

float lamp::returnZ()
{
	return translateZ;
}

/* Code for lamp animation*/
void animation(){

}
