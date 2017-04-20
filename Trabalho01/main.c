//  Trabalho da Disciplina de Computação Gráfica:
//  "CATA-VENTO"
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
GLfloat R=0.0f, G=0.0f, B=0.0f, angulo = 0.0f;

GLfloat vel = 0.0f, vellimit = 6.0f, accel = 3.0f, air = 0.1f;


void on_mouseClick(int botao_clicado, int estado_do_click, int x_mouse_position, int y_mouse_position) {
    
    if (estado_do_click == GLUT_DOWN) {
        if (botao_clicado == GLUT_RIGHT_BUTTON) {
            vel -= accel;
        } else if (botao_clicado == GLUT_LEFT_BUTTON) {
            vel += accel;
        }
    }
    
    glutPostRedisplay(); // For�a a glut redesenhar a cena ap�s a atualiza��o.
}

void redesenha(int height, int width){
    if (height == 0)
        height = 1;
    if (width == 0)
        width = 1;
    float aspect = width * 1.0 / height;
    
    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();
    
    glViewport(0, 0, width, height);
    gluOrtho2D(-100 * aspect, 100 * aspect, -100, 100);
    
    glMatrixMode(GL_MODELVIEW);
}


//Funcoes auxiliares
void desenha(){
    
    
    // Limpar a tela
    glClearColor(0.28f, 0.82f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Adicao de plano de fundo
    //retangulo para chão
    
    glLoadIdentity();
     glColor3f(0.51f, 0.26f, 0.0f);
    
    glBegin(GL_POLYGON);
        glVertex2f(-100.0f, -100.0f);
        glVertex2f(100.0f, -100.0f);
        glVertex2f(100.0f, -100.0f);
        glVertex2f(-100.0f, -60.0f);
    glEnd();
    
    //Sol
    
    
    
    
    
    // Iniciar as transforma��es 2D
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    
    // Especifica a cor
    glColor3f(0.18f, 0.31f, 0.31f);
    
    glTranslatef(-30.0f, -115.0f, 0.0f);
    
    // Desenha o triangulo
    glBegin(GL_TRIANGLES);
    glVertex2f(40.0f, 20.0f);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(60.0f, 20.0f);
    glEnd();
    
    glLoadIdentity();
    // Especifica a cor
    glColor3f(0.44f, 0.5f, 0.56f);
    
    if(vel <= -air)
        vel = vel + air;
    else if (vel >= air)
        vel = vel - air;
    else if (vel > -air && vel < air)
        vel = 0;
    
    if(vel > vellimit)
        vel = vellimit;
    else if(vel < - vellimit)
        vel = -vellimit;
    
    angulo = angulo + vel;
    
    if(angulo > 360){
        angulo = 0;
    }
    else if(angulo < 0){
        angulo = 360;
    }
    
    float midX = (45.0 * 2 + 55.0 *2)/4;
    float midY = (70.0 * 2 + 160.0 * 2)/4;
    
    glTranslatef(-30.0f, -115.0f, 0.0f);
    
    glTranslatef(midX, midY, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);
    glTranslatef(-midX, -midY, 0.0f);
    
    // Desenha um retângulo preenchido com a cor corrente
    glBegin(GL_POLYGON);
        glVertex2f(45.0f, 70.0f);
        glVertex2f(55.0f, 70.0f);
        glVertex2f(55.0f, 160.0f);
        glVertex2f(45.0f, 160.0f);
    glEnd();
    
    glLoadIdentity();
    // Especifica a cor
    glColor3f(0.44f, 0.5f, 0.56f);
    
    glTranslatef(-30.0f, -115.0f, 0.0f);
    
    glTranslatef(midX, midY, 0.0f);
    glRotatef(angulo + 90, 0.0f, 0.0f, 1.0f);
    glTranslatef(-midX, -midY, 0.0f);
    
    // Desenha um retângulo preenchido com a cor corrente
    glBegin(GL_POLYGON);
        glVertex2f(45.0f, 70.0f);
        glVertex2f(55.0f, 70.0f);
        glVertex2f(55.0f, 160.0f);
        glVertex2f(45.0f, 160.0f);
    glEnd();
    
    glFlush();
    
}

void atualizar(){
    // Background color
    glClearColor(0.28f, 0.82f, 0.8f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Repaint screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Draw scene
    desenha();
    
    glutSwapBuffers();
}


int main(int argc, const char * argv[]) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //glEnable(GL_MULTISAMPLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Hélices");
    
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, 800, 450);
    gluOrtho2D(-300, 300, -300, 300);
    
    
    //Funcoes para desenhar na tela
    glutDisplayFunc(atualizar);
    glutIdleFunc(atualizar);
    glutReshapeFunc(redesenha);
    
    //Funcoes para identificar o clique do mouse
    glutMouseFunc(on_mouseClick);
    
    
    glutMainLoop();
    
}
