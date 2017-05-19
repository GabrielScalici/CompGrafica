#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

#define DIREITA 1
#define ESQUERDA 0
#define SPACEBAR 32
#define TRUE 1
#define FALSE 0

//INIMIGOS
GLint posX = 0,moveInimigox = 0, larguraInimigo = 50, alturaInimigo = 15, distanciaX = 100;
GLint fileira1y = 550, fileira2y = 520, fileira3y = 490, fileira4y = 460, fileira5y = 430;
int direcaoX = DIREITA;

//NAVE
GLint naveX = 370, naveY = 20, larguraNave = 60, alturaNave = 50;

//TELA
GLdouble ortholeft = 0, orthoright = 800, orthobot = 0, orthotop = 600;
GLsizei largura = 800, altura = 600;

//MISSEL
GLint misselX = naveX, moveMisselY = 0, misselMoving = FALSE, aux = naveX;

void iniciaParametrosVisualizacao(void) {
    glClearColor(0.18f, 0.31f, 0.31f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(ortholeft, orthoright, orthobot, orthotop);
}

void desenhaMissel(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(1.0f,0.0f,0.0f);
    glPointSize(5.0);
    glBegin(GL_POINTS);
   	 	glVertex2i(misselX + (larguraNave/2-1) , 70 + moveMisselY);
   		glEnd();
   	glBegin(GL_POINTS);
   		glVertex2i(misselX + (larguraNave/2-1) , 72 + moveMisselY);
   	glEnd();
   		glBegin(GL_POINTS);
   		glVertex2i(misselX + (larguraNave/2-1) , 74 + moveMisselY);
   	glEnd();
   		glBegin(GL_POINTS);
   		glVertex2i(misselX + (larguraNave/2-1) , 76 + moveMisselY);
   	glEnd();
   		glBegin(GL_POINTS);
   		glVertex2i(misselX + (larguraNave/2-1) , 78 + moveMisselY);
   	glEnd();
}

void desenhaAviao(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(1.0f,1.0f,1.0f);

	glColor3f(1.0f,1.0f,1.0f);
    glLineWidth(2);

    glBegin(GL_TRIANGLES);
        glVertex2f(naveX,naveY);
        glVertex2f(naveX + larguraNave,naveY);
        glVertex2f(naveX + (larguraNave/2),naveY+alturaNave);
    glEnd();
}

void desenhaInimigo(GLint x0, GLint y0,GLint x1, GLint y1,GLint x2, GLint y2,GLint x3, GLint y3){
	glBegin(GL_POLYGON);
      glVertex2f(x0,y0);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
      glVertex2f(x3, y3);
  	glEnd();
}

void desenhaInimigos(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

 	//primeira fileira
    glColor3f(1.0f, 1.0f, 0.88f);

    desenhaInimigo(moveInimigox,fileira1y + alturaInimigo,moveInimigox,fileira1y,moveInimigox + larguraInimigo,
	fileira1y,moveInimigox + larguraInimigo,fileira1y + alturaInimigo);
  	//glBegin(GL_POLYGON);
     // glVertex2f(moveInimigox,fileira1y + alturaInimigo);
     // glVertex2f(moveInimigox, fileira1y);
     // glVertex2f(moveInimigox + larguraInimigo, fileira1y);
     // glVertex2f(moveInimigox + larguraInimigo, fileira1y + alturaInimigo);
  	//glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira1y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira1y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira1y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira1y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();

  	//segunda fileira
  	glColor3f(0.94f, 1.0f, 0.94f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox, fileira2y);
      glVertex2f(moveInimigox + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira2y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira2y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira2y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira2y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();

  	//terceira fileira
  	glColor3f(1.0f, 1.0f, 0.88f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox, fileira3y);
      glVertex2f(moveInimigox + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira3y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira3y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira3y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira3y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();

  	//quarta fileira
  	glColor3f(0.94f, 1.0f, 0.94f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox, fileira4y);
      glVertex2f(moveInimigox + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira4y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira4y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira4y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira4y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();

  	//quinta fileira
  	glColor3f(1.0f, 1.0f, 0.88f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox, fileira5y);
      glVertex2f(moveInimigox + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira5y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira5y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira5y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira5y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
}

void display(void) {
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    desenhaInimigos();
    desenhaAviao();
    desenhaMissel();
	glutSwapBuffers();
    glFlush();
}

void moveInimigos(int passo){
	if(direcaoX == DIREITA){
		moveInimigox += passo;
		if(moveInimigox + distanciaX*4+larguraInimigo >= 799){
			fileira1y -= 30;
			fileira2y -= 30;
			fileira3y -= 30;
			fileira4y -= 30;
			fileira5y -= 30;
			direcaoX = ESQUERDA;
		}
	}
	else{
		moveInimigox -= passo;
		if(moveInimigox == 0){
			direcaoX = DIREITA;
			fileira1y -= 30;
			fileira2y -= 30;
			fileira3y -= 30;
			fileira4y -= 30;
			fileira5y -= 30;
		}
	}
	glutPostRedisplay();
    glutTimerFunc(20, moveInimigos, passo);
}

void moveMissel(int passo){
	if(moveMisselY + 71 >= orthotop){
		misselMoving = FALSE;
		moveMisselY = 0;
		misselX = naveX;
	}
	if(misselMoving)
    	moveMisselY += passo;
    glutPostRedisplay();
    glutTimerFunc(5, moveMissel, passo);
}

void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT)
    {
        naveX -= 10;
        if (naveX <= ortholeft)
            naveX = 0;
        if(!misselMoving)
        	misselX = naveX;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        naveX += 10;
        if (naveX+larguraNave >= orthoright )
            naveX = orthoright-1;
        if(!misselMoving)
        	misselX = naveX;
    }
    if(key == GLUT_KEY_UP){
    	if(!misselMoving){
        	misselX = naveX;
        	misselMoving = TRUE;
			glutTimerFunc(5, moveMissel, 1);
    	}
	}

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("space Invaders!");

    iniciaParametrosVisualizacao();
    glutDisplayFunc(display);
    glutSpecialFunc(TeclasEspeciais);
	glutTimerFunc(10, moveInimigos, 3);
    glutMainLoop();
    return 0;
}
