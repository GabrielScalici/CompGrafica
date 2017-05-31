//*****************************************************
//
// Exemplo3D.cpp 
// Um programa OpenGL simples que abre uma janela GLUT 
// e desenha um cubo para exemplificar a visualização
// de objetos 3D utilizando a projeção perspectiva.
//
// Marcelo Cohen e Isabel H. Manssour
// Este código acompanha o livro 
// "OpenGL - Uma Abordagem Prática e Objetiva"
// 
//*****************************************************

#include <stdlib.h>
#include <GL/glut.h>

GLfloat fAspect;

GLfloat cameraX = 101.0f;
GLfloat cameraY = 101.0f;
GLfloat cameraZ = 101.0f;

GLfloat angulo_de_visao_vertical = 70.0f;

void DesenhaCuboRGB(void)
{
	
    //glTranslatef(0.0f, 0.0f, -30.0f);
    
    // Desenhas as linhas das "bordas" do cubo
	glColor3f(0.0f, 0.0f, 0.0f); 
	glLineWidth(1.6f);
	glBegin(GL_LINE_LOOP);	// frontal
		glVertex3f(40.0, -40.0, 40.0);
        glVertex3f(-40.0, -40.0, 40.0);
        glVertex3f(-40.0, 40.0, 40.0);
        glVertex3f(40.0, 40.0, 40.0);					
	glEnd();
	glBegin(GL_LINE_LOOP);	//  posterior
		glVertex3f(40.0, 40.0, -40.0);
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, -40.0); 
		glVertex3f(-40.0, 40.0, -40.0);
	glEnd();
	glBegin(GL_LINES);	//  laterais
		glVertex3f(-40.0, 40.0, -40.0);
		glVertex3f(-40.0, 40.0, 40.0); 
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, 40.0);     
		glVertex3f(40.0, 40.0, -40.0);
		glVertex3f(40.0, 40.0, 40.0); 
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(40.0, -40.0, 40.0);  
	glEnd();
 
 
 
	// Desenha as faces do cubo preenchidas
	
	glBegin(GL_QUADS);
		// Face frontal
		glColor3f(1.0f, 0.5f, 1.0f); //Pink		
        glVertex3f(40.0, 40.0, 40.0);
        glVertex3f(-40.0, 40.0, 40.0);
        glVertex3f(-40.0, -40.0, 40.0);
        glVertex3f(40.0, -40.0, 40.0);                                         					
	    // Face posterior
		glColor3f(0.0f, 0.0f, 0.0f); //Black
		glVertex3f(40.0, 40.0, -40.0);
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(-40.0, 40.0, -40.0);
	    // Face lateral esquerda
		glColor3f(0.0f, 1.0f, 0.0f); //Verde
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(-40.0, 40.0, -40.0);
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, 40.0);
	    // Face lateral direita
		glColor3f(1.0f, 0.0f, 0.0f); //Vermelho
		glVertex3f(40.0, 40.0, 40.0); 
		glVertex3f(40.0, -40.0, 40.0); 
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(40.0, 40.0, -40.0);
	    // Face superior  
		glColor3f(1.0f, 1.0f, 0.0f); //Amarelo
        glVertex3f(-40.0, 40.0, -40.0);
		glVertex3f(-40.0, 40.0, 40.0); 
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(40.0, 40.0, -40.0);
	    // Face inferior
		glColor3f(0.0f, 0.0f, 1.0f); //Azul
		glVertex3f(-40.0, -40.0, -40.0); 
		glVertex3f(40.0, -40.0, -40.0);  
		glVertex3f(40.0, -40.0, 40.0); 
		glVertex3f(-40.0, -40.0, 40.0);
	glEnd();
}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();	

	// Altera a cor do desenho para preto
	glColor3f(0.0f, 0.0f, 1.0f);
      
        // Função da GLUT para fazer o desenho de um cubo 
	// com a cor corrente
	//glutWireCube(50);
	//GLfloat escala = 1.0/3.0;
	//glScalef(escala,escala,escala);
	DesenhaCuboRGB();
			
        
	glFlush();
	glutSwapBuffers();
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angulo_de_visao_vertical,fAspect,1.0f,1000.0f);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(cameraX, cameraY, cameraZ,    0,0,0,    1.0,1.0,0.0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
    if (key == 'A') {
    	cameraX += 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'a') {
    	cameraX -= 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'S') {
    	cameraY += 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 's') {
    	cameraY -= 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'D') {
    	cameraZ += 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'd') {
    	cameraZ -= 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'W') {
    	angulo_de_visao_vertical += 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'w') {
    	angulo_de_visao_vertical -= 10;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'Q') {
    	fAspect += 0.1;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
    if (key == 'q') {
    	fAspect -= 0.1;
    	EspecificaParametrosVisualizacao();
    	Desenha();
    }
        
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{   
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	glLineWidth(2.0);
}

// Programa Principal 
int main(int argc, char *argv[])
{

        glutInit(&argc, argv);	

        // Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(5,5); 

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450); 
 
	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Desenho de um cubo");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);

	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a função responsável por fazer as inicializações 
	Inicializa();

 	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
