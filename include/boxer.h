//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <assert.h>
//#include <GL/glut.h>
//#include <GL/glu.h>

#include "../include/headers.h"
#include "../include/matrix.h"

static float moveHand[6]={0.0,0.0,0.0,0.0,0.0,0.0};    //{angle_upperarm, angle_forearm, forearm_x,forearm_y, fist_x,fist_y }
static float moveHand2[6]={0.0,0.0,0.0,0.0,0.0,0.0};
static int selectLeft=0;

void punch();
void punch2();

class boxer{
	public:
	boxer();
	boxer(bool x);
	bool isRight ;
    void drawboxer();
    void drawLeftboxer();	
	void set( bool x );
	void setSelLeft(int x);	
	};
    
