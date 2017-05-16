  /*
  *  Trabalho 02 de Computacao Grafica
  *  "Space Invader"
  *
  *  Gabriel Henrique Campos Scalici 9292970
  *  Keith Tsukada Sasaki
  *
  */

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

GLfloat missel1_y = 0, missel2_y = 0;
GLfloat aviao_x = 0, missel1_tx = 0, missel2_tx = 0;

bool missel1_moving = false, missel2_moving = false;

int msec_missel1 = 0, msec_missel2 = 0;


void move_missel1(int passo){

    missel1_y += (1.0*passo);
    glutPostRedisplay();

    glutTimerFunc(10, move_missel1, passo);
}
void move_missel2(int passo){

    missel2_y += (1.0*passo);
    glutPostRedisplay();

    glutTimerFunc(10, move_missel2, passo);
}

void DesenhaInimigos(){

  glLoadIdentity();
   glColor3f(1.0f, 1.0f, 1.0f);

  glBegin(GL_POLYGON);
      glVertex2f();
      glVertex2f();
      glVertex2f();
      glVertex2f();
  glEnd();


}

// Funусo para desenhar a base do objeto
void DesenhaAviao(){

    glColor3f(0.83f,0.83f,0.83f);
    glLineWidth(2);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.3f,-0.8f);
        glVertex2f(0.3f,-0.8f);
        glVertex2f(0.0f,0.0f);
    glEnd();

}

void DesenhaMisseis(){

    glColor3f(1.0f,0.0f,0.0f);
    glLineWidth(2);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f,-1.0f);
        glVertex2f(-1.0f,-0.7f);
        glVertex2f(-0.9f,-0.6f);
        glVertex2f(-0.8f,-0.7f);
        glVertex2f(-0.8f,-1.0f);
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

    glTranslatef(aviao_x,0.0f,0.0f);
    glTranslatef(0.0f,-0.7f,0.0f);
    glScalef(0.3f,0.3f,0.0f);
    glPushMatrix();

    if(missel2_moving){
        glTranslatef(-aviao_x,0.0f,0.0f);
        glTranslatef(missel2_tx,0.0f,0.0f);
    }

    //Mьssel 2;
    glTranslatef(0.0f,missel2_y,0.0f);
    glTranslatef(1.8f,0.0f,0.0f);
    DesenhaMisseis();

    glPopMatrix(); // Carrega a identidade = Limpa a matrix de transformaушes.
    glPushMatrix();

    if(missel1_moving){
        glTranslatef(-aviao_x,0.0f,0.0f);
        glTranslatef(missel1_tx,0.0f,0.0f);
    }
    //Mьssel 1.
    glTranslatef(0.0f,missel1_y,0.0f);
    DesenhaMisseis();

    glPopMatrix(); //Pro jatinho nao sair junto com o missel 1.
    // Desenha o jatinho.
    DesenhaAviao();
    DesenhaInimigos();

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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Estabelece a janela de seleусo (esquerda, direita, inferior,
    // superior) mantendo a proporусo com a janela de visualizaусo
    if (largura <= altura)
    {
        gluOrtho2D (-1.0f, 1.0f, -1.0f*altura/largura, 1.0f*altura/largura);
    }
    else
    {
        gluOrtho2D (-1.0f*largura/altura, 1.0f*largura/altura, -1.0f, 1.0f);
    }
}

// Funусo callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT)
    {
        aviao_x-=0.05;
        if ( aviao_x < -1.5f )
            aviao_x = -1.5f;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        aviao_x+=0.05;
        if ( aviao_x > 1.5f )
            aviao_x = 1.5f;
    }
    if(key == GLUT_KEY_UP){
        missel1_moving = true;
        missel1_tx = aviao_x;
        glutTimerFunc(10, move_missel1, 1);
        missel2_moving = true;
        missel2_tx = aviao_x;
        glutTimerFunc(10, move_missel2, 1);
    }

    glutPostRedisplay();
}



// Funусo responsрvel por inicializar parРmetros e variрveis
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualizaусo como branca
    glClearColor(0.18f, 0.31f, 0.31f, 0.0f);
    gluOrtho2D (-1.0f, 1.0f, -1.0f, 1.0f);
    glViewport(0, 0, 500, 500);
}



// Programa Principal
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Inicia uma instРncia da glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("Space Invaders!");

    // Registra a funусo callback de redesenho da janela de visualizaусo
    glutDisplayFunc(Desenha);

    // Registra a funусo callback de redimensionamento da janela de visualizaусo
    glutReshapeFunc(AlteraTamanhoJanela);

    // Registra a funусo callback para tratamento das teclas especiais
    glutSpecialFunc(TeclasEspeciais);

    // Chama a funусo responsрvel por fazer as inicializaушes
    Inicializa();

    glutTimerFunc(0, move_missel1, 0); // Timer para mover o missel 1
    glutTimerFunc(0, move_missel2, 0); // ..........................2

    // Inicia o processamento e aguarda interaушes do usuрrio
    glutMainLoop();

    return 0;
}
