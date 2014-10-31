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

static float moveball=0;
static bool rotation_flag = false;
void animate_ball();
class ball
{

	private:
	bool rotateBall;

	public:
	ball();
	void drawball();
	void set_rotate(bool x);

};



#endif /* BALL_H_ */
