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


struct Inimigo{
      GLint x;
      GLint y;
   };

typedef struct Inimigo inimigo;

//INIMIGOS
inimigo inimigos[25]; //cria um vetor de inimigos
GLint posX = 0,moveInimigox = 0, larguraInimigo = 50, alturaInimigo = 15, distanciaX = 100;
GLint fileira1y = 550, fileira2y = 520, fileira3y = 490, fileira4y = 460, fileira5y = 430;
GLint inimigosX[25]; //variaveis que guardam a posicao x das naves
GLint inimigosY[25];
int direcaoX = DIREITA;
int vivos[25];

//NAVE
GLint naveX = 370, naveY = 20, larguraNave = 60, alturaNave = 50;

//TELA
GLdouble ortholeft = 0, orthoright = 800, orthobot = 0, orthotop = 600;
GLsizei largura = 800, altura = 600;

//MISSEL
GLint misselX = naveX+(larguraNave/2)-1, moveMisselY = 0, misselMoving = FALSE, aux = naveX;

void preencheVivos(){
	int i;
	for(i=0;i<25;i++){
		vivos[i] = 1;
	}
}

void iniciaParametrosVisualizacao(void) {
    glClearColor(0.18f, 0.31f, 0.31f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(ortholeft, orthoright, orthobot, orthotop);
}

//funcao para desenhar o missel
void desenhaMissel(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(1.0f,0.0f,0.0f);

   	glLineWidth(4.0);
   	glBegin(GL_LINES); //desenha o missel em cima da nave
   		glVertex2f(misselX, 70 + moveMisselY);
    	glVertex2f(misselX, 82 + moveMisselY);
    glEnd();
}

//funcao para desenhar o aviao
void desenhaAviao(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(1.0f,1.0f,1.0f);
    glLineWidth(2);

    glBegin(GL_TRIANGLES);
        glVertex2f(naveX,naveY);
        glVertex2f(naveX + larguraNave,naveY);
        glVertex2f(naveX + (larguraNave/2),naveY+alturaNave);
    glEnd();
}

//funcao que verifica se algum inimigo vivo chegou ao final da tela
int chegouNoFinal(){
	int i;
	for(i=0;i<25;i++){
		if((inimigos[i].y == 70) && (vivos[i])) //chegou no fim da tela, acabou jogo
			return 1;
	}
	return 0;
}

//funcao que verifica se todos os inimigos foram mortos
int ganhouJogo(){
	int i;
	for(i=0;i<25;i++){
		if(vivos[i]) //se ha algum vivo
			return 0;
	}
	return 1;
}

//funcao que desenha os inimigos
void desenhaInimigos(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

 	//primeira fileira

	if(vivos[0])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox, fileira1y);
      glVertex2f(moveInimigox + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	inimigos[0].x = moveInimigox;
  	inimigos[0].y = fileira1y;
  	if(vivos[1])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira1y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	inimigos[1].x = moveInimigox + distanciaX;
  	inimigos[1].y = fileira1y;
  	if(vivos[2])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira1y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	inimigos[2].x = moveInimigox + distanciaX*2;
  	inimigos[2].y = fileira1y;
  	if(vivos[3])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira1y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	inimigos[3].x = moveInimigox + distanciaX*3;
  	inimigos[3].y = fileira1y;
  	if(vivos[4])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira1y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira1y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira1y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira1y + alturaInimigo);
  	glEnd();
  	inimigos[4].x = moveInimigox + distanciaX*4;
  	inimigos[4].y = fileira1y;

  	//segunda fileira
  	if(vivos[5])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox, fileira2y);
      glVertex2f(moveInimigox + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	inimigos[5].x = moveInimigox;
  	inimigos[5].y = fileira2y;
  	if(vivos[6])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira2y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	inimigos[6].x = moveInimigox + distanciaX;
  	inimigos[6].y = fileira2y;
  	if(vivos[7])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira2y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	inimigos[7].x = moveInimigox + distanciaX*2;
  	inimigos[7].y = fileira2y;
  	if(vivos[8])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira2y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	inimigos[8].x = moveInimigox + distanciaX*3;
  	inimigos[8].y = fileira2y;
  	if(vivos[9])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira2y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira2y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira2y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira2y + alturaInimigo);
  	glEnd();
  	inimigos[9].x = moveInimigox + distanciaX*4;
  	inimigos[9].y = fileira2y;

  	//terceira fileira
  	if(vivos[10])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox, fileira3y);
      glVertex2f(moveInimigox + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	inimigos[10].x = moveInimigox;
  	inimigos[10].y = fileira3y;
  	if(vivos[11])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira3y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	inimigos[11].x = moveInimigox + distanciaX;
  	inimigos[11].y = fileira3y;
  	if(vivos[12])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira3y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	inimigos[12].x = moveInimigox + distanciaX*2;
  	inimigos[12].y = fileira3y;
  	if(vivos[13])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira3y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	inimigos[13].x = moveInimigox + distanciaX*3;
  	inimigos[13].y = fileira3y;
  	if(vivos[14])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira3y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira3y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira3y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira3y + alturaInimigo);
  	glEnd();
  	inimigos[14].x = moveInimigox + distanciaX*4;
  	inimigos[14].y = fileira3y;

  	//quarta fileira
  	if(vivos[15])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox, fileira4y);
      glVertex2f(moveInimigox + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	inimigos[15].x = moveInimigox;
  	inimigos[15].y = fileira4y;
  	if(vivos[16])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira4y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	inimigos[16].x = moveInimigox + distanciaX;
  	inimigos[16].y = fileira4y;
  	if(vivos[17])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira4y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	inimigos[17].x = moveInimigox + distanciaX*2;
  	inimigos[17].y = fileira4y;
  	if(vivos[18])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira4y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	inimigos[18].x = moveInimigox + distanciaX*3;
  	inimigos[18].y = fileira4y;
  	if(vivos[19])
  		glColor3f(0.94f, 1.0f, 0.94f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira4y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira4y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira4y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira4y + alturaInimigo);
  	glEnd();
  	inimigos[19].x = moveInimigox + distanciaX*4;
  	inimigos[19].y = fileira4y;

  	//quinta fileira
  	if(vivos[20])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox, fileira5y);
      glVertex2f(moveInimigox + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	inimigos[20].x = moveInimigox;
  	inimigos[20].y = fileira5y;
  	if(vivos[21])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX, fileira5y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	inimigos[21].x = moveInimigox+distanciaX;
  	inimigos[21].y = fileira5y;
  	if(vivos[22])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*2,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*2, fileira5y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*2 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	inimigos[22].x = moveInimigox+distanciaX*2;
  	inimigos[22].y = fileira5y;
  	if(vivos[23])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
  	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*3,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*3, fileira5y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*3 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	inimigos[23].x = moveInimigox + distanciaX*3;
  	inimigos[23].y = fileira5y;
  	if(vivos[24])
  		glColor3f(1.0f, 1.0f, 0.88f);
  	else
  		glColor3f(0.18f, 0.31f, 0.31f);
	glBegin(GL_POLYGON);
      glVertex2f(moveInimigox + distanciaX*4,fileira5y + alturaInimigo);
      glVertex2f(moveInimigox + distanciaX*4, fileira5y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira5y);
      glVertex2f(moveInimigox + distanciaX*4 + larguraInimigo, fileira5y + alturaInimigo);
  	glEnd();
  	inimigos[24].x = moveInimigox + distanciaX*4;
  	inimigos[24].y = fileira5y;
}

//funcao para mover os inimigos alterando as coordenadas X e Y de cada nave
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
	if(chegouNoFinal()){
		glClearColor(1.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
		passo = 0;
		glutSpecialFunc(NULL);
	}

	glutPostRedisplay();
    glutTimerFunc(20, moveInimigos, passo);
}

//funcao de desenho
void display(void) {
	if(ganhouJogo()){
		glClear(GL_COLOR_BUFFER_BIT);
		glutTimerFunc(10, moveInimigos, 0);
		glutSpecialFunc(NULL);
	}
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    desenhaInimigos();
    desenhaAviao();
    desenhaMissel();
	glutSwapBuffers();
    glFlush();
}

//funcao que verifica colisao do tiro com algum inimigo
int colisao(GLint tiroX, GLint tiroY){
	int i;

	for(i=24;i>=0;i--){
		if(vivos[i])
			if(((inimigos[i].x <= tiroX) && (tiroX <= inimigos[i].x + larguraNave)) && tiroY == inimigos[i].y){
				vivos[i] = 0;
				return 1;
			}
	}
	return 0;
}

//funcao que move o missel
void moveMissel(int passo){
	if(colisao(misselX,moveMisselY)){
		misselMoving = FALSE;
		moveMisselY = 0;
		misselX = naveX + (larguraNave/2)-1;
	}
	if(moveMisselY + 71 >= orthotop){
		misselMoving = FALSE;
		moveMisselY = 0;
		misselX = naveX + (larguraNave/2)-1;
	}
	if(misselMoving)
		moveMisselY += passo;
    glutPostRedisplay();
    glutTimerFunc(1, moveMissel, passo);
}

//funcao que identifica quando uma tecla do teclado foi clicada
void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT)
    {
        naveX -= 10;
        if (naveX <= ortholeft)
            naveX = 0;
        if(!misselMoving)
        	misselX = naveX + (larguraNave/2)-1;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        naveX += 10;
        if (naveX+larguraNave >= orthoright )
            naveX = orthoright-1;
        if(!misselMoving)
        	misselX = naveX + (larguraNave/2)-1;
    }
    if(key == GLUT_KEY_UP){
    	if(!misselMoving){
        	misselX = naveX + (larguraNave/2)-1;
        	misselMoving = TRUE;
			glutTimerFunc(10, moveMissel,1);
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
 	preencheVivos();

    iniciaParametrosVisualizacao();
    glutDisplayFunc(display);
    glutSpecialFunc(TeclasEspeciais);
	glutTimerFunc(10, moveInimigos, 3);
    glutMainLoop();
    return 0;
}
