/*
 * floor.cpp
 *
 *  Created on: 01-Nov-2014
 *      Author: shantanu
 */

#include "../include/headers.h"
#include "../include/plane.h"
#include "../include/macros.h"

GLuint plane::LoadTexture(const char *filename)
{
	  GLuint texture;

	  int width, height;

	  unsigned char * data;

	  FILE * file;

	  file = fopen( filename, "rb" );

	  if ( file == NULL ) return 0;
	  width = 256;
	  height = 256;
	  data = (unsigned char *)malloc( width * height * 3 );
	  //int size = fseek(file,);
	  fread( data, width * height * 3, 1, file );
	  fclose( file );

	 for(int i = 0; i < width * height ; ++i)
	{
	   int index = i*3;
	   unsigned char B,R;
	   B = data[index];
	   R = data[index+2];

	   data[index] = R;
	   data[index+2] = B;

	}


	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	free( data );

	return texture;
}

void plane::drawplane()
{

	//plane
	glPushMatrix();
	glColor3f(1,1,1);
	myTranslatef(0,-20,0);
	//myRotatef(90,1,0,0);
	//glRectf(-150, -150, 150, 150);
	glBegin(GL_QUADS);
		glTexCoord2f(1,0); glVertex3f(150,0,150);
		glTexCoord2f(0,0); glVertex3f(150,0,-150);
		glTexCoord2f(0,1); glVertex3f(-150,0,-150);
		glTexCoord2f(1,1); glVertex3f(-150,0,150);
	glEnd();
	glPopMatrix();

}
