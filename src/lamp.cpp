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

			//floor
			glPushMatrix();
			glColor3f(1,1,1);
			myTranslatef(0,-20,0);
			myRotatef(90,1,0,0);
			glRectf(-100,100, 100, -100);
			glPopMatrix();

			glColor3f(0.6,0,0);
			//base plate
			glPushMatrix();
			myTranslatef(0.0,-20.0,0.0);
			myRotatef(-90,1,0,0);
			glutSolidCone(10,5,100,100);
			//gluDisk(quad, 2.0, 7.0, 100, 100 );
			glPopMatrix();

			//base support
			glPushMatrix();
			myTranslatef(0.0,-2.0,0.0);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 1, 1, 15.0,100,100);
			glPopMatrix();

			//base support
			glPushMatrix();
			myTranslatef(10.0,8.0,0.0);
			myRotatef(-45.0f,0.0f,0.0f,1.0f);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 1, 1, 15.0,100,100);
			glPopMatrix();

			//face
			glPushMatrix();
			myTranslatef(16.3,1.0,0.0);
			myRotatef(-135.0f,0.0f,0.0f,1.0f);
			myRotatef(90.0f,1.0f,0.0f,0.0f);
			gluCylinder(quad, 8, 1, 10.0,100,100);
			glPopMatrix();

			// Support sphere
//			glPushMatrix();
//			myTranslatef(80-moveball,-13.0,0.0);
//			if(rotateball)
//				myRotatef(1,0,0,1);
//			glutSolidSphere(7.0,30.0,30.0);
//			glPopMatrix();

		glPopMatrix();
}

void animation(){
//	if(moveball<60){
//		moveball+=(moveball/50+0.2);
//	}
//	if(moveball>=60){
//		rotateball=false;
//
//	}
//	glutPostRedisplay();
}
