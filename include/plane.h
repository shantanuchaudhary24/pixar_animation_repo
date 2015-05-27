/*
 * floor.h
 *
 *  Created on: 01-Nov-2014
 *      Author: shantanu
 */

#ifndef FLOOR_H_
#define FLOOR_H_
#include "../include/headers.h"
#include "../include/matrix.h"
#include "../include/ctexture.h"


class plane
{

public:
	//plane();
	GLuint texture;
	void drawplane();
	GLuint LoadTexture(const char *filename);
};

#endif /* FLOOR_H_ */
