/**********************************************************************
	
  Camera with OpenGL

  March, 13th, 2003

  This tutorial was written by Philipp Crocoll
  Contact: 
	philipp.crocoll@web.de
	www.codecolony.de

  Every comment would be appreciated.

  If you want to use parts of any code of mine:
	let me know and
	use it!

**********************************************************************
ESC: exit

CAMERA movement:
w : forwards
s : backwards
a : turn left
d : turn right
x : turn up
y : turn down
v : strafe right
c : strafe left
r : move up
f : move down
m/n : roll

***********************************************************************/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int b_up = 0;
int b_down = 0;
int b_left = 0;
int b_right = 0;


#include "camera.h"


CCamera Camera;


void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0
	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);  //Use the whole window for rendering
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
		
	glTranslatef(0.0,-0.5,-6.0);


	glColor3f(0.3,0.0,0.0);

	glTranslatef(Camera.Position.x, Camera.Position.y, Camera.Position.z);

	

	glBegin (GL_LINES);

		glColor3f(0.2,0.2,0.2);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.UpVector.x,0.0,0.0);

	  glVertex3f(Camera.UpVector.x,0.0,0.0);
	  glVertex3f(Camera.UpVector.x,0.0,Camera.UpVector.z);

	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.UpVector.x,0.0,Camera.UpVector.z);
	  
	  glVertex3f(Camera.UpVector.x,0.0,Camera.UpVector.z);
	  glVertex3f(Camera.UpVector.x,Camera.UpVector.y,Camera.UpVector.z);

	glColor3f(0.2,0.0,0.0);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.RightVector.x,0.0,0.0);
	  
	  glVertex3f(Camera.RightVector.x,0.0,0.0);
	  glVertex3f(Camera.RightVector.x,0.0,Camera.RightVector.z);

	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.RightVector.x,0.0,Camera.RightVector.z);

	  glVertex3f(Camera.RightVector.x,0.0,Camera.RightVector.z);
	  glVertex3f(Camera.RightVector.x,Camera.RightVector.y,Camera.RightVector.z);

	glColor3f(0.3,0.3,0.0);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.ViewDir.x,0.0,0.0);
	  
	  glVertex3f(Camera.ViewDir.x,0.0,0.0);
	  glVertex3f(Camera.ViewDir.x,0.0,Camera.ViewDir.z);

	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.ViewDir.x,0.0,Camera.ViewDir.z);

	  glVertex3f(Camera.ViewDir.x,0.0,Camera.ViewDir.z);
	  glVertex3f(Camera.ViewDir.x,Camera.ViewDir.y,Camera.ViewDir.z);

	glEnd();
	
	glBegin (GL_LINES);
glColor3f(1.0,1.0,1.0);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.UpVector.x,Camera.UpVector.y,Camera.UpVector.z);

	  glColor3f(1.0,0.0,0.0);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.RightVector.x,Camera.RightVector.y,Camera.RightVector.z);

	  glColor3f(1.0,1.0,0.0);
	  glVertex3f(0.0f,0.0f,0.0f);
	  glVertex3f(Camera.ViewDir.x,Camera.ViewDir.y,Camera.ViewDir.z);

	glEnd();



	glFlush();  
	glutSwapBuffers();

}
void KeyDown(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 'c':
		Camera.RotateY(5.0);
		Display();
		break;
	case 'v':
		Camera.RotateY(-5.0);
		Display();
		break;
	case 's':
		Camera.MoveForward( -0.1 ) ;
		Display();
		break;
	case 'w':
		Camera.MoveForward( 0.1 ) ;
		Display();
		break;
	case 'x':		
		Camera.RotateX(5.0);
		Display();
		break;
	case 'y':		
		Camera.RotateX(-5.0);
		Display();
		break;
	case 'a':
		Camera.StrafeRight(-0.1);
		Display();
		break;
	case 'd':
		Camera.StrafeRight(0.1);
		Display();
		break;
	case 'f':
		Camera.MoveUpward(-0.3);
		Display();
		break;
	case 'r':
		Camera.MoveUpward(0.3);
		Display();
		break;
	case 'm':
		Camera.RotateZ(-5.0);
		Display();
		break;
	case 'n':
		Camera.RotateZ(5.0);
		Display();
		break;

	}
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Camera");
	Camera.Move( F3dVector(0.0, 0.0, 3.0 ));
	Camera.MoveForward( 1.0 );
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutMainLoop();
	return 0;             
}
