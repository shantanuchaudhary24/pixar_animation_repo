/*
 * ball.h
 *
 *  Created on: 31-Oct-2014
 *      Author: shantanu
 */

#ifndef BALL_H_
#define BALL_H_

#include "../include/headers.h"
#include "../include/matrix.h"

class ball
{
	public:
	float moveball;
	float rotateball;
	struct timeval startTime, currentTime;
	ball();
	void drawball();
	void animation();
};

#endif /* BALL_H_ */
