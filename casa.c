#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

void display(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
	glClear(GL_COLOR_BUFFER_BIT);		  // Inicializa o buffer de cores antes de ele ser alterado

	glMatrixMode(GL_MODELVIEW); // Informa que as operações seguintes serão executadas na matrix modelview
	glLoadIdentity();			// Carrega a matriz identidade

	glPointSize(50); // Define quantos pixels representarão um vértice na tela
	glLineWidth(5);

	// Frente da casa
	glBegin(GL_POLYGON); // Indica que serão desenhados somente pontos
	{
		glColor3f(0.984f, 0.843f, 0.129f); // Define a cor do desenho em formato RGB
		glVertex2f(-0.4f, -0.4f);		   // Especifica pontos no espaço bidimensional (pixels)
		glVertex2f(0, -0.4f);
		glVertex2f(0, 0);
		glVertex2f(-0.4f, 0.2f);
		glVertex2f(-0.2f, 0.5f);
		glVertex2f(0.1f, 0.1f);
	}
	glEnd(); // Encerra a criação de pontos

	// Teto do lado esquerdo
	glBegin(GL_QUADS);
	{
		glColor3f(0.878f, 0.435f, 0.137f);

		glVertex2f(-0.4f, 0.2f);
		glVertex2f(-0.10f, 0.5f);
		glVertex2f(-0.25f, 0.5f);
		glVertex2f(-0.55f, 0.2f);
	}
	glEnd();

	// Teto do lado direito
	glBegin(GL_QUADS);
	{
		glColor3f(0.945f, 0.502f, 0.141f);

		glVertex2f(-0.25f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.7f, 0.1f);
		glVertex2f(0, 0.1f);
	}
	glEnd();

	// Base da casa, local onde colocam os imóveis
	glBegin(GL_QUADS);
	{
		glColor3f(0.894f, 0.714f, 0.133f);
		glVertex2f(0, 0.1f);
		glVertex2f(0.6f, 0.1f);
		glVertex2f(0.6f, -0.4f);
		glVertex2f(0, -0.4f);
	}
	glEnd();

	// Porta
	glBegin(GL_QUADS);
	{
		glColor3f(0.945f, 0.502f, 0.141f);
		glVertex2f(-0.3f, -0.4f);
		glVertex2f(-0.1f, -0.4f);
		glVertex2f(-0.1f, -0.1f);
		glVertex2f(-0.3f, -0.1f);
	}
	glEnd();

	//Sombra do porta
	glBegin(GL_QUADS);
	{
		glVertex2f(-0.3f, -0.4f);
		glVertex2f(-0.1f, -0.4f);
		glVertex2f(-0.2f, -0.7f);
		glVertex2f(-0.4f, -0.7f);
	}
	glEnd();

	// Janela da Frente
	glBegin(GL_QUADS);
	{
		glColor3f(0.396f, 0.78f, 0.816f);
		glVertex2f(-0.1, 0);
		glVertex2f(-0.3f, 0);
		glVertex2f(-0.3f, 0.2f);
		glVertex2f(-0.1f, 0.2f);
	}
	glEnd();

	// Janela do meio
	glBegin(GL_QUADS);
	{
		glVertex2f(0.15f, 0.03f);
		glVertex2f(0.5f, 0.03f);
		glVertex2f(0.5f, -0.15f);
		glVertex2f(0.15f, -0.15);
	}
	glEnd();

	// Contorno
	glBegin(GL_LINES);
	{
		glColor3f(0, 0, 0);

		glVertex2f(-0.4f, -0.4f); // Especifica pontos no espaço bidimensional (pixels)
		glVertex2f(0, -0.4f);

		glVertex2f(0, -0.4f);
		glVertex2f(0, 0.1f);

		glVertex2f(-0.25f, 0.5f);
		glVertex2f(0, 0.1f);

		glVertex2f(-0.25f, 0.5f);
		glVertex2f(-0.55f, 0.2f);

		glVertex2f(-0.55f, 0.2f);
		glVertex2f(-0.4f, 0.2f);

		glVertex2f(-0.4f, 0.2f);
		glVertex2f(-0.2f, 0.4f);

		glVertex2f(-0.4f, -0.4f);
		glVertex2f(-0.4f, 0.2f);

		// Janela
		glVertex2f(-0.1, 0);
		glVertex2f(-0.3f, 0);

		glVertex2f(-0.3f, 0);
		glVertex2f(-0.3f, 0.2f);

		glVertex2f(-0.3f, 0.2f);
		glVertex2f(-0.1f, 0.2f);

		glVertex2f(-0.1f, 0.2f);
		glVertex2f(-0.1f, 0);

		// Janela Frente  (Grade dos meios)
		glVertex2f(-0.2, 0);
		glVertex2f(-0.2f, 0.2f);

		glVertex2f(-0.3f, 0.1f);
		glVertex2f(-0.1f, 0.1f);

		// Janela do meio

		glVertex2f(0.15f, 0.03f);
		glVertex2f(0.5f, 0.03f);

		glVertex2f(0.5f, 0.03f);
		glVertex2f(0.5f, -0.15f);

		glVertex2f(0.5f, -0.15f);
		glVertex2f(0.15f, -0.15);

		glVertex2f(0.15f, -0.15);
		glVertex2f(0.15f, 0.03f);

		// Janela do meio (Grades)
		glVertex2f(0.325f, 0.03f);
		glVertex2f(0.325f, -0.15f);

		glVertex2f(0.15f, -0.06f);
		glVertex2f(0.5f, -0.06f);

		// Base
		glVertex2f(0, 0.1f);
		glVertex2f(0.6f, 0.1f);

		glVertex2f(0.6f, 0.1f);
		glVertex2f(0.6f, -0.4f);

		glVertex2f(0.6f, -0.4f);
		glVertex2f(0, -0.4f);

		// Teto Principal

		glVertex2f(-0.25f, 0.5f);
		glVertex2f(0.5f, 0.5f);

		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.7f, 0.1f);

		glVertex2f(0.7f, 0.1f);
		glVertex2f(0, 0.1f);

		glVertex2f(0, 0.1f);
		glVertex2f(-0.25f, 0.5f);

		// Porta
		glVertex2f(-0.3f, -0.4f);
		glVertex2f(-0.1f, -0.4f);

		glVertex2f(-0.1f, -0.4f);
		glVertex2f(-0.1f, -0.1f);

		glVertex2f(-0.1f, -0.1f);
		glVertex2f(-0.3f, -0.1f);

		glVertex2f(-0.3f, -0.1f);
		glVertex2f(-0.3f, -0.4f);
	}
	glEnd();

	glFlush(); // Informa que as operações devem ser processadas imediatamente e exibidas na tela
}

/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 32:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
		break;
	default:
		printf("Código tecla: %i. Mouse em (%i,%i)\n", key, x, y);
		break;
	}
	glutPostRedisplay(); // Informa que a janela atual deve ser redesenhada
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);						 // Inicializa a OpenGL
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura os modos de exibição (mais detalhes no futuro)
	glutInitWindowSize(500, 500);				 // Define o tamanho da janela em pixels
	glutInitWindowPosition(0, 0);				 // Define a posição inicial da janela
	glutCreateWindow("Primeiro Exemplo");		 // Cria a janela especificando seu título
	glutDisplayFunc(display);					 // Especifica a função de rendering (exibe a cena no loop)
	glutReshapeFunc(resize);					 // Especifica função a ser executada quando a janela é redimensionada
	glutKeyboardFunc(keyboard);					 // Especifica função a ser executada quando uma tecla é pressionada

	glutMainLoop(); // Executa o loop de renderização
	return 0;
}
