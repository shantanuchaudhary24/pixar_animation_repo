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
private:
	ctexture planeTex;
	GLuint texCode ;

public:
	plane();
	void drawplane(const char *filename);
	void load_texture();
};

#endif /* FLOOR_H_ */
