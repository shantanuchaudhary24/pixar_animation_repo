
#include "../include/headers.h"
#include "../include/matrix.h"
#include "../include/lamp.h"
#include "../include/plane.h"
#include "../include/ball.h"
#include "../include/macros.h"

using namespace std;


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 20.0f, 50.0f, 50.0f, 0.0f };
const GLfloat light_position2[] = { -20.0f, -50.0f, -50.0f, 0.0f };


//This header file contains the variables used in the main file//
float angle_x = 0.0f;
float angle_y = 0.0f;
float factor = 1.0f;

//declare the components
plane floor1;
lamp lamp1;
ball ball1;

void initRendering(){
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
   
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);

	glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}

void handleResize(int w, int h){
    screen_width = w ;
    screen_height = h ;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)w / (double)h, 1.0, 2000.0);

}


void handleMouseMotion(int x, int y)
{
	GLdouble model_view[16];
	glGetDoublev(GL_MODELVIEW_MATRIX, model_view);
	GLdouble projection[16];
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	GLint viewport[4]; 
	glGetIntegerv(GL_VIEWPORT, viewport);
	double dx; double dy; double dz;
	GLfloat depth[2];	 
	glReadPixels (x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, depth); 
	gluUnProject(x, y, depth[0], model_view, projection, viewport, &dx, &dy, &dz);
	
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y ) {
			
	//x and y are the current mouse coordinates
	switch (key) {
		float x,y,z;
		case 27: //escape key
			exit(0); //exit the program
			break;

		case 'a':
//			rotateball=true;
			x = lamp1.returnX()+0.5; y = lamp1.returnY()+0.5; z = lamp1.returnZ()+0.5;
			lamp1.translate_lamp(x,y,z);
			ball1.set_rotate(true);
			glutIdleFunc(animate_ball);
			break;
		}
	return  ;
}


void handleKeypressSpecial(int key, int x, int y ) {
//x and y are the current mouse coordinates
	switch (key) {
		case GLUT_KEY_UP:{
			angle_x += 2.0f;
			glutPostRedisplay();
			break;
		}
		case GLUT_KEY_DOWN:{
			angle_x -= 2.0f;
			glutPostRedisplay();
			break;
		}
		case GLUT_KEY_LEFT:{
			angle_y += 2.0f;
			glutPostRedisplay();
			break;
		}
		case GLUT_KEY_RIGHT:{
			angle_y -= 2.0f;
			glutPostRedisplay();
			break;
		}

	}
}

void drawScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glPushMatrix();

	//myScalef(0.1,0.1,0.1);
 
	myTranslatef(0,0,-100);

	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);

	glRotatef(angle_y, 0.0f, 1.0f, 0.0f);

	glColor3f(0.4,0.4,0.4);
	floor1.drawplane();
	lamp1.drawlamp();
	ball1.drawball();

	glPopMatrix();
	glutSwapBuffers();
}


int main(int argc, char** argv){

	/* Call to default constructors*/
	floor1 = new plane();
	lamp1 = new lamp();
	ball1 = new ball();

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(WINDOW_WIDTH,WINDOWS_HEIGHT);
	glutInitWindowPosition(WINDOW_WIDTH/4,WINDOWS_HEIGHT/4);
	glutCreateWindow("Pixar Animation");

	initRendering();

	glutDisplayFunc(drawScene);

	glutSpecialFunc(handleKeypressSpecial);

	glutKeyboardFunc(handleKeypress);
    
	glutReshapeFunc(handleResize);

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutMainLoop();

	return 0;
}
