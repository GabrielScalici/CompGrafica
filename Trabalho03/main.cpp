/**********************************************************************
	Trabalho 03 da matéria de Computação gráfica
	Tema: Ambiente 3D com movimentos e objeto de modelo 3D (Apple)
	Data: 02-06-2017
	Autor: Gabriel Henrique C. Scalici 9292970
				 Keith T. Sasaki 9293414


Como usar:

Movimento da camera/personagem primeira pessoa
W - para frente
S - para trás
A - para a esquerda
D - para a direita

Movimento do objeto carregado de um modelo 3D (apple)
I - rotaciona para cima
K - rotaciona para baixo
L - rotaciona para a esquerda
J - rotaciona para a direita
P - rotaciona para a direita no proprio eixo
O - rotaciona para a esquerda no proprio eixo


***********************************************************************/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
//Incluindo outros arquivos
#include "camera.h"
#include "obj.h"
#include "./SOIL/SOIL.h"

//Objeto da classe
CCamera Camera;
//Objeto modelo 3D
Obj *apple;

//variaveis para mexer o modelo 3D
int angulo1 = 0;
int angulo2 = 0;
int angulo3 = 0;

void reshape(int x, int y)
{
	if (y == 0 || x == 0){
		return;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);
}

//Funcao para desenhar a maca de objeto 3D
void draw_apple(int ang1, int ang2, int ang3){
	glColor3f(1.0,  1.0,  1.0 );
	glTranslatef(0, 0, 0);
	glScalef(-0.15, 0.15, 0.15);
	//glRotatef(ang, rot_x, rot_y, rot_z);
	glRotatef(ang1, 1.0, 0.0, 0.0);
	glRotatef(ang2, 0.0, 1.0, 0.0);
	glRotatef(ang3, 0.0, 0.0, 1.0);
	drawObjWireframe(apple);
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//carregando a matriz identidade
	glLoadIdentity();

	glTranslatef(0.0,-0.5,-6.0);
	glColor3f(0.3,0.0,0.0);
	glTranslatef(Camera.Position.x, Camera.Position.y, Camera.Position.z);

	//Desenhando o chao da cena
	glBegin(GL_POLYGON);
   glColor3f(   1.0,  0.0,  0.0 );
   glVertex3f(  1.5, -0.5, -1.5 );
   glVertex3f(  1.5, -0.5, 5.0 );
   glVertex3f( -1.5, -0.5, 5.0 );
   glVertex3f( -1.5, -0.5, -1.5 );
   glEnd();

	//Pegando o modelo 3D
	draw_apple(angulo1, angulo2, angulo3);

	glFlush();
	glutSwapBuffers();

}

//Metodo para identificar a tecla apertada
void KeyDown(unsigned char key, int x, int y)
{
	switch (key){
	//Andar com a personagem
	case 'w':
		Camera.MoveForward(0.1) ;
		Display();
		break;
	case 'a':
		Camera.StrafeRight(0.1);
		Display();
		break;
	case 'd':
		Camera.StrafeRight(-0.1);
		Display();
		break;
	case 's':
		Camera.MoveForward( -0.1 ) ;
		Display();
		break;
	case 'r':
		Camera.MoveUpward(-0.3);
		Display();
		break;
	case 'f':
		Camera.MoveUpward(0.3);
		Display();
		break;

	//Rotacionar o modelo 3D
	case 'i':
		angulo1 = angulo1 + 5.0;
		Display();
		break;
	case 'k':
		angulo1 = angulo1 - 5.0;
		Display();
		break;
	case 'l':
		angulo2 = angulo2 + 5.0;
		Display();
		break;
	case 'j':
		angulo2 = angulo2 - 5.0;
		Display();
		break;
	case 'o':
		angulo3 = angulo3 + 5.0;
		Display();
		break;
	case 'p':
		angulo3 = angulo3 - 5.0;
		Display();
		break;


	}
}

//Funcao para colocar o modelo 3D
int Model(){
	//carregando o modelo desse repositorio
  apple = loadObj("./obj/source/apple.obj");
  return 1;
}


//Funcao principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Apple 3D");
	//funcao para modelo 3D
	Model();
	Camera.Move( F3dVector(0.0, 0.0, 3.0 ));
	Camera.MoveForward( 1.0 );
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutMainLoop();
	return 0;
}
