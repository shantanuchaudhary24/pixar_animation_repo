
#include "../include/headers.h"
#include "../include/boxer.h"
boxer::boxer(){
isRight = true ;
}

boxer::boxer(bool x){
isRight = x ;
}

void boxer::set( bool x ){
isRight = x ;
}

void boxer::setSelLeft(int x){
	selectLeft = x;
}

void boxer::drawboxer(){

	GLUquadricObj *quad=gluNewQuadric();
		
if(isRight)
	{
		glPushMatrix();
		
		myTranslatef(-60.0,20.0,0.0);	
		
		//head
		glPushMatrix();
		myTranslatef(0.0,20.0,0.0);
		glutSolidSphere(15.0,30.0,30.0);
		glPopMatrix();
		
		//eye
		glPushMatrix();
		myTranslatef(14.0,25.0,8.0);
		glutSolidSphere(2.0,30.0,30.0);
		glPopMatrix();
		
		//eye
		glPushMatrix();
		myTranslatef(14.0,25.0,-8.0);
		glutSolidSphere(2.0,30.0,30.0);
		glPopMatrix();
		
		//body
		glPushMatrix();
		myTranslatef(0.0,5.0,0.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,20.0f,20.0f,50.0f,100,100);
		glPopMatrix();
		
		//upper arm
		glPushMatrix();
		myTranslatef(0.0,0.0,20.0);
		myRotatef(30.0f+moveHand[0],0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//upper arm
		glPushMatrix();
		myTranslatef(0.0,0.0,-20.0);
		myRotatef(30.0f,0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//forearm
		glPushMatrix();
		myTranslatef(40.0,-10.0,20.0);
		myTranslatef(moveHand[2],moveHand[3],0.0);
		myRotatef(-60.0f+moveHand[1],0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,30.0f,100,100);
		glPopMatrix();
		
		//forearm
		glPushMatrix();
		myTranslatef(40.0,-10.0,-20.0);
		myRotatef(-60.0f,0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,30.0f,100,100);
		glPopMatrix();
		
		//palm
		glPushMatrix();
		myTranslatef(40.0,-10.0,20.0);
		myTranslatef(moveHand[4],moveHand[5],0.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		//palm
		glPushMatrix();
		myTranslatef(40.0,-10.0,-20.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
	
		/////////////////////////////////////
		
		//thigh
		glPushMatrix();
		myTranslatef(0.0,-50.0,-5.0);
		myRotatef(110.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//thigh
		glPushMatrix();
		myTranslatef(0.0,-50.0,5.0);
		myRotatef(70.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foreleg
		glPushMatrix();
		myTranslatef(0.0,-75.0,-15.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foreleg
		glPushMatrix();
		myTranslatef(0.0,-75.0,15.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foot
		glPushMatrix();
		myTranslatef(0.0,-100.0,-15.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		//foot
		glPushMatrix();
		myTranslatef(0.0,-100.0,15.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		glPopMatrix();
	}
else
	{
		glPushMatrix();
		
		myTranslatef(60.0,20.0,0.0);
		myRotatef(180.0f,0.0f,1.0f,0.0f);	
		
		//head
		glPushMatrix();
		myTranslatef(0.0,20.0,0.0);
		glutSolidSphere(15.0,30.0,30.0);
		glPopMatrix();
		
		//eye
		glPushMatrix();
		myTranslatef(14.0,25.0,8.0);
		glutSolidSphere(2.0,30.0,30.0);
		glPopMatrix();
		
		//eye
		glPushMatrix();
		myTranslatef(14.0,25.0,-8.0);
		glutSolidSphere(2.0,30.0,30.0);
		glPopMatrix();
		
		//body
		glPushMatrix();
		myTranslatef(0.0,5.0,0.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,20.0f,20.0f,50.0f,100,100);
		glPopMatrix();
		
		//upper arm
		glPushMatrix();
		myTranslatef(0.0,0.0,20.0);
		myRotatef(30.0f+moveHand2[0],0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//upper arm
		glPushMatrix();
		myTranslatef(0.0,0.0,-20.0);
		myRotatef(30.0f,0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//forearm
		glPushMatrix();
		myTranslatef(40.0,-10.0,20.0);
		myTranslatef(moveHand2[2],moveHand2[3],0.0);
		myRotatef(-60.0f+moveHand2[1],0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,30.0f,100,100);
		glPopMatrix();
		
		//forearm
		glPushMatrix();
		myTranslatef(40.0,-10.0,-20.0);
		myRotatef(-60.0f,0.0f,0.0f,1.0f);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,30.0f,100,100);
		glPopMatrix();
		
		//palm
		glPushMatrix();
		myTranslatef(40.0,-10.0,20.0);
		myTranslatef(moveHand2[4],moveHand2[5],0.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		//palm
		glPushMatrix();
		myTranslatef(40.0,-10.0,-20.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
	
		/////////////////////////////////////
		
		//thigh
		glPushMatrix();
		myTranslatef(0.0,-50.0,-5.0);
		myRotatef(110.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//thigh
		glPushMatrix();
		myTranslatef(0.0,-50.0,5.0);
		myRotatef(70.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foreleg
		glPushMatrix();
		myTranslatef(0.0,-75.0,-15.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foreleg
		glPushMatrix();
		myTranslatef(0.0,-75.0,15.0);
		myRotatef(90.0f,1.0f,0.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,25.0f,100,100);
		glPopMatrix();
		
		//foot
		glPushMatrix();
		myTranslatef(0.0,-100.0,-15.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		//foot
		glPushMatrix();
		myTranslatef(0.0,-100.0,15.0);
		myRotatef(90.0f,0.0f,1.0f,0.0f);
		gluCylinder(quad,5.0f,5.0f,10.0f,100,100);
		glPopMatrix();
		
		glPopMatrix();
	}
	
}
void punch()
{
	if(selectLeft)
	{
		if(moveHand[2]<=15)
		{
			moveHand[0]+=2.5;
			moveHand[1]-=0.5;
			moveHand[2]+=0.65;
			moveHand[3]+=0.75;
			moveHand[4]+=0.65;
			moveHand[5]+=0.75;
		}
	}
	else
	{
		if(moveHand2[2]<=15)
		{
			moveHand2[0]+=2.5;
			moveHand2[1]-=0.5;
			moveHand2[2]+=0.65;
			moveHand2[3]+=0.75;
			moveHand2[4]+=0.65;
			moveHand2[5]+=0.75;
		}
	}
	
	
	glutPostRedisplay();
}

void punch2()
{
	//printf("ss %d \n",selectLeft);
	if(selectLeft)
	{
		if(moveHand[2]>=0)
		{
			moveHand[0]-=2.5;
			moveHand[1]+=0.5;
			moveHand[2]-=0.65;
			moveHand[3]-=0.75;
			moveHand[4]-=0.65;
			moveHand[5]-=0.75;
		}
	}
	else
	{
		if(moveHand2[2]>=0)
		{
			moveHand2[0]-=2.5;
			moveHand2[1]+=0.5;
			moveHand2[2]-=0.65;
			moveHand2[3]-=0.75;
			moveHand2[4]-=0.65;
			moveHand2[5]-=0.75;
		}
	}
	
	glutPostRedisplay();
}
/*
void punch()
{
	if(moveHand[2]<=50)
	{
		moveHand[0]+=1.5;
		moveHand[1]-=0.5;
		moveHand[2]+=1;
		moveHand[3]+=0.5;
		moveHand[4]+=1;
		moveHand[5]+=0.5;
	}
	
	glutPostRedisplay();
}

void punch2()
{
	if(moveHand[2]>=0)
	{
		moveHand[0]-=1.5;
		moveHand[1]+=0.5;
		moveHand[2]-=1;
		moveHand[3]-=0.5;
		moveHand[4]-=1;
		moveHand[5]-=0.5;
	}
	
	glutPostRedisplay();
}
*/
