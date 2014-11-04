/*
 * floor.cpp
 *
 *  Created on: 01-Nov-2014
 *      Author: shantanu
 */

#include "../include/headers.h"
#include "../include/plane.h"
#include "../include/macros.h"

int load_image(const char *filename, Image *image)
{
	FILE *file;
	unsigned long size; // size of the image in bytes.
	unsigned long i; // standard counter.
	unsigned short int planes; // number of planes in image (must be 1)
	unsigned short int bpp; // number of bits per pixel (must be 24)
	char temp; // temporary color storage for bgr-rgb conversion.

	// make sure the file is there.
	if ((file = fopen(filename, "rb")) == NULL)
	{
		printf("File Not Found : %s\n", filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

	// read the width
	if ((i = fread(&image->width, 4, 1, file)) != 1)
	{
		printf("Error reading width from %s.\n", filename);
		return 0;
	}


	// read the height
	if ((i = fread(&image->height, 4, 1, file)) != 1)
	{
		printf("Error reading height from %s.\n", filename);
		return 0;
	}

	// calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->width * image->height * 3;

	printf("Size of Image:%d x %d\n",image->width,image->height);
	// read the planes
	if ((fread(&planes, 2, 1, file)) != 1)
	{
		printf("Error reading planes from %s.\n", filename);
		return 0;
	}

	if (planes != 1)
	{
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bitsperpixel
	if ((i = fread(&bpp, 2, 1, file)) != 1)
	{
		printf("Error reading bpp from %s.\n", filename);
		return 0;
	}

	if (bpp != 24)
	{
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}
	// seek past the rest of the bitmap header.

	fseek(file, 24, SEEK_CUR);
	// read the data.

	image->data = (char *) malloc(size);
	if (image->data == NULL)
	{
		printf("%d x %d", image->width, image->height);
		printf("Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->data, size, 1, file)) != 1)
	{
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	fclose(file);
	for (i = 0; i < size; i += 3)
	{ // reverse all of the colors. (bgr -> rgb)
		temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}
	return 1;
}

Image* load_texture1(const char *filename)
{
	Image *image1;

	// allocate space for texture
	image1 = (Image *) malloc(sizeof(Image));
	if (image1 == NULL)
	{
		printf("Error allocating space for image");
		exit(0);
	}

	if (!load_image(filename, image1))
		exit(1);

//	glGenTextures(1, &texcode);
//	glBindTexture(GL_TEXTURE_2D, texcode);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->width, image1->height, 0,
//	GL_RGB, GL_UNSIGNED_BYTE, image1->data);

	return image1;
}

unsigned char* readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    for(i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }

    return data;
}

plane::plane()
{
	texCode = -1;
}

void plane::drawplane(const char *filename)
{

	//plane
	glPushMatrix();
	Image* image1;
	glColor3f(1,1,1);
	myTranslatef(0,-20,0);
	myRotatef(90,1,0,0);
	glRectf(-256,-256, 256, 256);
	glPopMatrix();

}

void plane::load_texture()
{
	return;
}
