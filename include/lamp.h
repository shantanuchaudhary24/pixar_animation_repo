/*
 * lamp.h
 *
 *  Created on: 29-Oct-2014
 *      Author: shantanu
 */

#ifndef LAMP_H_
#define LAMP_H_

#include "../include/headers.h"
#include "../include/matrix.h"


class lamp
{
public:
	struct timeval startTime, currentTime;
	float baseTranslate[3];
	float baseRotate[3];
	float support1Rotate;
	float support2Rotate;
	float faceRotate[3];
	lamp();
	void drawlamp();
	void animation();
};

#endif /* LAMP_H_ */
