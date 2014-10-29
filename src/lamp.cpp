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

}


void lamp::drawlamp()
{

	GLUquadric *quad=gluNewQuadric();

		glPushMatrix();

//		myTranslatef(0.0,0.0,-100.0);
//		myRotatef(180.0f,0.0f,1.0f,0.0f);

		//base plate
		glPushMatrix();
		myTranslatef(0.0,-10.0,-10.0);
		myRotatef(90,1,0,0);
		gluDisk(quad, 2.0, 7.0, 100, 100 );
		glPopMatrix();

		//base support
		glPushMatrix();
		myTranslatef(0.0,+5.0,-10.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad, 2, 2, 25.0,100,100);
		glPopMatrix();

		// Support sphere
		glPushMatrix();
		myTranslatef(0.0,0.0,-10.0);
		glutSolidSphere(2.0,30.0,30.0);
		glPopMatrix();

		//base support
		glPushMatrix();
		myTranslatef(0.0,+53.0,-10.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad, 2, 2, 25.0,100,100);
		glPopMatrix();

		//head (frustum)
//		glPushMatrix();
//
//
//		glPopMatrix();


		glPopMatrix();
}
