/*
 * texture.h
 *
 *  Created on: 04-Nov-2014
 *      Author: shantanu
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../include/headers.h"

typedef struct Image
{

	unsigned int width;
	unsigned int height;
	char *data;

}Image;

class ctexture
{

private:
	GLuint textureID;
	int load_image(const char *filename, Image *image);

public:
	ctexture();
	bool load_texture(const char *filename);
	GLuint return_texID();
};

#endif /* TEXTURE_H_ */
