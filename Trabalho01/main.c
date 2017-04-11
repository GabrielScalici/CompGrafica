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


void desenha(){

    // Colorir o fundo de branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    // Iniciar as transforma��es 2D
    glMatrixMode(GL_MODELVIEW); // Inicia-se a matriz de transforma��es da openGL
    glLoadIdentity();
    ///////////////////////////////
    
    
    // Especifica a cor preta
    glColor3f(0.0f, 0.0f, 0.0f);
    
    // Desenha o triangulo
    glBegin(GL_TRIANGLES);
    glVertex2f(60.0f, 30.0f);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(120.0f, 30.0f);
    glEnd();
    
    glLoadIdentity();
    

    
    glFlush();
    
}


int main(int argc, const char * argv[]) {
    
    glutInit(&argc, argv); // Inicia uma inst�ncia da glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de display do buffer
    glutInitWindowSize(800, 600); // Define o tamanho em pixels da janela
    glutCreateWindow("Ventilador"); // Define o t�tulo da janela
    glutDisplayFunc(desenha); // Estabelece que a fun��o de rendering � a fun��o "desenha(.)"
    
    
    //glutMouseFunc(on_mouseClick); // Evento de click do mouse
    
    
    glMatrixMode(GL_PROJECTION); // Especifica��es de observa��o de cena
    gluOrtho2D(0, 200, 0, 200);	// Observa-se a se��o de plano [0,200]x[0,200]
    
    
    glutMainLoop();
    
}
