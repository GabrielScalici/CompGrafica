#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "obj.h"


// ----------------------------------------------------------
// Declaracoes de Funcoes
// ----------------------------------------------------------
void display();
void specialKeys();


// Variaveis Globais

double rotate_y = 0;
double rotate_x = 0;

double mov_x = 0;
double mov_y = 0;
double mov_z = 0;

//Obj

Obj *apple;

// ----------------------------------------------------------
// fun��o display()
// ----------------------------------------------------------
void display(){

  //  Limpa a tela e o Z-Buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Reinicia transforma��es
  glLoadIdentity();

  //Transladando para andar com o personagem
  glTranslatef(mov_x, 0.0, 0.0);
  glTranslatef(0.0, mov_y, 0.0);
  glTranslatef(0.0, 0.0, mov_z);


  // Rotaciona quando o usu�rio muda rotate_x e rotate_y
  glRotatef(rotate_x, 1.0, 0.0, 0.0 );
  glRotatef(rotate_y, 0.0, 1.0, 0.0 );

  // Outras Transforma��es
  glScalef( 0.2, 0.2, 0.2);          // N�o est� inclu�do

  //Lado multicolorido - FRENTE
  glBegin(GL_POLYGON);

  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 � vermelho
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 � verde
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 � azul
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 � roxo

  glEnd();

  // Lado branco - TRASEIRA
 glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  // Lado roxo - DIREITA
 glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();

  // Lado verde - ESQUERDA
 glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  // Lado azul - TOPO
 glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();

  // Lado vermelho - BASE
 glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();



  glLoadIdentity();
  //tamanho do obj carregado 3D
  glTranslatef(-1, 1, -1);
  glScalef(-0.12, 0.12, 0.12);
  drawObjWireframe(apple);


  glFlush();
  glutSwapBuffers();

}

// ----------------------------------------------------------
// Fun��o specialKeys()
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Seta direita - aumenta rota��o em 5 graus
  if (key == GLUT_KEY_RIGHT)
    mov_x += 0.05;

  //  Seta para esquerda - diminui a rota��o por 5 graus
  else if (key == GLUT_KEY_LEFT)
    mov_x -= 0.05;

  else if (key == GLUT_KEY_UP)
    mov_z += 0.1;

  else if (key == GLUT_KEY_DOWN)
    mov_z -= 0.1;

  //  Requisitar atualiza��o do display
  glutPostRedisplay();

}

int Model(){
  apple = loadObj("./obj/source/apple.obj");

  return 1;
}


// ----------------------------------------------------------
// Fun��o main()
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Inicializa o GLUT e processa os par�metros do usu�rio GLUT
  glutInit(&argc,argv);

  //  Requisita uma janela com buffer duplo e true color com um Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize(800, 600);

  // Cria a janela do programa
  glutCreateWindow("Super Cube");

  Model();

  //  Habilita o teste de profundidade do Z-buffer
  glEnable(GL_DEPTH_TEST);

  // Fun��es
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

  //  Passa o controle dos eventos para o GLUT
  glutMainLoop();

  //  Retorna para o SO
  return 0;

}
