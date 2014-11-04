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
	texCode = -1;
}

void plane::drawplane(const char *filename)
{

	//plane
	glPushMatrix();
//	glColor3f(1,1,1);
	myTranslatef(0,-20,0);
	myRotatef(90,1,0,0);
	planeTex.load_texture(filename);
	texCode = planeTex.return_texID();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texCode);
	glRectf(-100,100, 100, -100);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void plane::load_texture()
{
	return;
}
