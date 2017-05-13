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

// Declaraусo de variрveis globais
GLfloat tx = 0;
GLfloat ang1 = 0, ang2 = -90;
GLfloat win = 25;

// Funусo para desenhar um "braуo" do objeto
void DesenhaBraco()
{
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.0,4.6);
        glVertex2f(1.0,-0.8);
        glVertex2f(-1.0,-0.8);
        glVertex2f(-1.0,4.6);
    glEnd();
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2i(0,0);
    glEnd();
}

// Funусo para desenhar a base do objeto
void DesenhaBase()
{
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.8,1);
        glVertex2f(1.8,-1.5);
        glVertex2f(1.0,-1.5);
        glVertex2f(1.0,-1);
        glVertex2f(-1.0,-1);
        glVertex2f(-1.0,-1.5);
        glVertex2f(-1.8,-1.5);
        glVertex2f(-1.8,1);
    glEnd();
}

// Funусo callback de redesenho da janela de visualizaусo
void Desenha(void)
{
    // Muda para o sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa a matriz de transformaусo corrente
    glLoadIdentity();

    // Limpa a janela de visualizaусo com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o "chсo"
    glColor3f(0.0f,0.0f,0.0f);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-win,-3.9);
        glVertex2f(win,-3.9);
    glEnd();

    // Desenha um objeto modelado com transformaушes hierрrquicas
    // Salva a matriz M1 do modelo, sem nenhuma transformacao
    glPushMatrix();    // Salva a identidade

    glTranslatef(tx,0.0f,0.0f);

    // Salva a matriz M2, transladada em tx
    glPushMatrix();

    glScalef(8.5f,2.5f,1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    DesenhaBase();

    // Recupera a matriz M2
    glPopMatrix();

    glTranslatef(0.0f,1.5f,0.0f);
    glRotatef(ang1,0.0f,0.0f,1.0f);
    glScalef(1.4f,1.4f,1.0f);
    glColor3f(0.0f,1.0f,0.0f);
    DesenhaBraco();

    glTranslatef(0.4f,2.6f,0.0f);
    glRotatef(ang2,0.0f,0.0f,1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    DesenhaBraco();

    // Recupera a matriz M1
    glPopMatrix();

    // Executa os comandos OpenGL
    glFlush();
}

// Funусo callback chamada quando o tamanho da janela ж alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    GLsizei largura, altura;

    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Atualiza as variрveis
    largura = w;
    altura = h;

    // Especifica as dimensшes da Viewport
    glViewport(0, 0, largura, altura);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleусo (esquerda, direita, inferior,
    // superior) mantendo a proporусo com a janela de visualizaусo
    if (largura <= altura)
    {
        gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
        win = 25.0f;
    }
    else
    {
        gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
        win = 25.0f*largura/altura;
    }
}

// Funусo callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais(int key, int x, int y)
{
    // Move a base
    if(key == GLUT_KEY_LEFT)
    {
        tx-=2;
        if ( tx < -win )
            tx = -win;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        tx+=2;
        if ( tx > win )
            tx = win;
    }

    // Rotaciona braco1
    if(key == GLUT_KEY_HOME)
        ang1-=5;
    if(key == GLUT_KEY_END)
        ang1+=5;

    // Rotaciona braco2
    if(key == GLUT_KEY_PAGE_UP)
        ang2-=5;
    if(key == GLUT_KEY_PAGE_DOWN)
        ang2+=5;

    glutPostRedisplay();
}

// Funусo callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
    //if (key == 27)
      //  exit(0);
}

// Funусo responsрvel por inicializar parРmetros e variрveis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualizaусo como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Exibe mensagem que avisa como interagir
    //printf(" Setas para esquerda e para direita movimentam a base (vermelha)");
    //printf("\n Home e End rotacionam o braco 1 (verde)");
    //printf("\n PageUP e PageDn rotacionam o braco 2 (azul)");
}


// Programa Principal
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Inicia uma instРncia da glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(450,300);
    glutCreateWindow("Desenho de objeto modelado com transformaушes hierрrquicas");

    // Registra a funусo callback de redesenho da janela de visualizaусo
    glutDisplayFunc(Desenha);

    // Registra a funусo callback de redimensionamento da janela de visualizaусo
    glutReshapeFunc(AlteraTamanhoJanela);

    // Registra a funусo callback para tratamento das teclas especiais
    glutSpecialFunc(TeclasEspeciais);

    // Registra a funусo callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);

    // Chama a funусo responsрvel por fazer as inicializaушes
    Inicializa();

    // Inicia o processamento e aguarda interaушes do usuрrio
    glutMainLoop();

    return 0;
}
