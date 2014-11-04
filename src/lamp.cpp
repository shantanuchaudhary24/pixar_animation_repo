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
	baseTranslate[0] = baseTranslate[1] = baseTranslate[2] = 0;
	baseRotate[0] = baseRotate[1] = baseRotate[2] = 0;
	support1Rotate = 0;
	support2Rotate = 0;
	faceRotate[0] = faceRotate[1] = faceRotate[2] = 0;
	gettimeofday(&startTime, NULL);
}

void lamp::init_lamp_light()
{

	GLfloat light_ambient[] =
	{ 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] =
	{ 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] =
	{ 1.0, 1.0, 1.0, 1.0 };

	GLfloat light_position[] =
	{ 0, 0, 0, 1.0f };

	GLfloat spotlight_direction[] =
	{ 0, 0, -1 };

	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotlight_direction);
	glEnable(GL_LIGHT2);
}

void lamp::drawlamp()
{

	GLUquadric *quad = gluNewQuadric();


	glPushMatrix();

//	glEnable(GL_LIGHT2);
	glColor3f(0.6, 0, 0);
//	init_lamp_light();
	//base plate
	myTranslatef(0.0, -20.0, 0.0);
	myRotatef(-90, 1, 0, 0);
	myTranslatef(baseTranslate[0], baseTranslate[1], baseTranslate[2]);
	myRotatef(baseRotate[0], 1, 0, 0);
	myRotatef(baseRotate[1], 0, 1, 0);
	myRotatef(baseRotate[2], 0, 0, 1);
	glutSolidCone(10, 5, 100, 100);

	//base support
	myTranslatef(0, 0, 4);
	myRotatef(support1Rotate, 0, 1, 0);
	gluCylinder(quad, 1, 1, 15.0, 100, 100);

	//upper support
	myTranslatef(0, 0, 14);
	myRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	myRotatef(support1Rotate, 0, 1, 0);
	gluCylinder(quad, 1, 1, 15.0, 100, 100);

	//face
	myTranslatef(10, 0, 14);
	myRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	myTranslatef(0, 0, 10);
	myRotatef(-faceRotate[0], 1, 0, 0);
	myRotatef(-faceRotate[1], 0, 1, 0);
	myRotatef(-faceRotate[2], 0, 0, 1);
	myTranslatef(0, 0, -10);
	gluCylinder(quad, 8, 1, 10.0, 100, 100);
	init_lamp_light();
	glColor3f(1,1,1);
	myTranslatef(0,0,4);
	glutSolidSphere(2,100,100);

	glPopMatrix();
}

/* Code for lamp animation*/
void lamp::animation()
{

	gettimeofday(&currentTime, NULL);
	float total_time_spent = ((float) (currentTime.tv_usec - startTime.tv_usec))
			/ 1000000 + (float) (currentTime.tv_sec - startTime.tv_sec);

	if (total_time_spent < 2.0f)
		faceRotate[0] += 1.5;
	if (total_time_spent > 2.0f && total_time_spent < 4.0f)
		faceRotate[0] -= 1.5;
	if (total_time_spent > 4.0f && total_time_spent < 6.0f)
		support1Rotate += 0.45;
	if (total_time_spent > 6.0f && total_time_spent < 7.0f)
		faceRotate[1] -= 1.5;
	if (total_time_spent > 7.0f && total_time_spent < 9.0f)
		faceRotate[1] += 1.5;
	if (total_time_spent > 9.0f && total_time_spent < 10.0f)
		faceRotate[1] -= 1.5;
	if (total_time_spent > 10.0f && total_time_spent < 12.0f)
		support1Rotate -= 0.45;

}
