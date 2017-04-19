//  Trabalho da Disciplina de Computação Gráfica:
//  "Moinho"
//
//  Created by Gabriel Scalici 9292970 on 11/04/17.
//
//  Copyright © 2017 Gabriel Scalici. All rights reserved.
//

//Para conseguir ler tanto no wind quanto no mac
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


//Metodo de evento do mouse
GLfloat R=0.0f, G=0.0f, B=0.0f, angle = 0.0f;


void on_mouseClick(int botao_clicado, int estado_do_click, int x_mouse_position, int y_mouse_position) {
    
    if (estado_do_click == GLUT_DOWN) {
        if (botao_clicado == GLUT_RIGHT_BUTTON) {

        } else if (botao_clicado == GLUT_LEFT_BUTTON) {

        }
    }
    
    glutPostRedisplay(); // For�a a glut redesenhar a cena ap�s a atualiza��o.
}


//Funcoes auxiliares
void desenha(){

    // Colorir o fundo de branco
    glClearColor(0.28f, 0.82f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    // Iniciar as transforma��es 2D
    glMatrixMode(GL_MODELVIEW); // Inicia-se a matriz de transforma��es da openGL
    glLoadIdentity();
    ///////////////////////////////
    
    
    // Especifica a cor
    glColor3f(0.18f, 0.31f, 0.31f);
    
    // Desenha o triangulo
    glBegin(GL_TRIANGLES);
    glVertex2f(90.0f, 30.0f);
    glVertex2f(100.0f, 120.0f);
    glVertex2f(110.0f, 30.0f);
    glEnd();

    // Especifica a cor
    glColor3f(0.44f, 0.5f, 0.56f);
    
    // Desenha um retângulo preenchido com a cor corrente
    glBegin(GL_POLYGON);
    glVertex2f(95.0f, 70.0f);
    glVertex2f(103.0f, 70.0f);
    glVertex2f(103.0f, 160.0f);
    glVertex2f(95.0f, 160.0f);
    glEnd();
    
    // Especifica a cor
    glColor3f(0.44f, 0.5f, 0.56f);
    
    // Desenha um retângulo preenchido com a cor corrente
    glBegin(GL_POLYGON);
    glVertex2f(60.0f, 110.0f);
    glVertex2f(140.0f, 110.0f);
    glVertex2f(140.0f, 120.0f);
    glVertex2f(60.0f, 120.0f);
    glEnd();
    
    
    glFlush();
    
}


int main(int argc, const char * argv[]) {
    
    glutInit(&argc, argv); // Inicia uma inst�ncia da glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de display do buffer
    glutInitWindowSize(800, 600); // Define o tamanho em pixels da janela
    glutCreateWindow("Ventilador"); // Define o t�tulo da janela
     // Estabelece que a fun��o de rendering � a fun��o "desenha(.)"
    
    
    glutMouseFunc(on_mouseClick); // Evento de click do mouse
    
    
    glMatrixMode(GL_PROJECTION); // Especifica��es de observa��o de cena
    gluOrtho2D(0, 200, 0, 200);	// Observa-se a se��o de plano [0,200]x[0,200]
    
    glutDisplayFunc(desenha);
    
    
    glutMainLoop();
    
    
    
}
