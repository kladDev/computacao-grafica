#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

// Variáveis globais
GLuint idTextura;
GLdouble rotX, rotY;

void loadBMP(char *filename)
{

	unsigned int width, height;
	unsigned char header[54];

	unsigned char *data;

	FILE *file;
	file = fopen(filename, "rb");

	if (file == NULL)
	{
		printf("Arquivo não encontrado!\n");
		return;
	}
	// Leitura do cabeçalho
	if (fread(header, 1, 54, file) != 54)
	{
		printf("Problema ao ler cabeçalho do arquivo!\n");
		return;
	}
	width = *(int *)&(header[0x12]);
	height = *(int *)&(header[0x16]);

	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;
	}

	glGenTextures(1, &idTextura);
	glBindTexture(GL_TEXTURE_2D, idTextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
				 GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_TEXTURE_2D);
}

void drawTriangle()
{
	// GL_CLAMP_TO_BORDER,GL_CLAMP_TO_EDGE,GL_MIRRORED_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBegin(GL_TRIANGLES);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0f, 1.0f, -1.0f);
	glEnd();
}

void drawCube()
{
	// Desenha um cubo no qual a textura é aplicada
	glBegin(GL_QUADS);
	{

		// Face frente
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.33f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.33f);
		glVertex3f(-1.0f, 1.0f, 1.0f);

		// Face fundo
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.33f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.5f, 0.33f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		// Face superior
		glTexCoord2f(0.0f, 0.66f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.66f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		// Face inferior
		glTexCoord2f(0.0f, 0.33f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.33f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.66f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.66f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Face lateral direita
		glTexCoord2f(0.5f, 0.33f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.33f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.66f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.5f, 0.66f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		// Face lateral esquerda
		glTexCoord2f(0.5f, 0.66f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.66f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
	}
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);

	// drawTriangle();
	drawCube();

	glPopMatrix();

	glutSwapBuffers();
}

void init(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	loadBMP("hunter.bmp");
}

void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(45, fAspect, 0.4, 100);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		rotX += 5;
		break;
	case GLUT_KEY_DOWN:
		rotX -= 5;
		break;
	case GLUT_KEY_LEFT:
		rotY -= 5;
		break;
	case GLUT_KEY_RIGHT:
		rotY += 5;
		break;
	case 32: // "camera reset"
		rotX = 0;
		rotY = 0;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mapeamento de Textura");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
