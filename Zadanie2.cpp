#include "stdafx.h"
#include <GL\freeglut.h>

void Display()
{
	//15 - k�t

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-22.0f, 0.0f);
	glVertex2f(-20.0f, 8.0f);
	glVertex2f(-17.0f, 15.0f);
	glVertex2f(-10.0f, 20.0f);
	glVertex2f(0.0f, 22.0f);
	glVertex2f(10.0f, 20.0f);
	glVertex2f(17.0f, 15.0f);
	glVertex2f(20.0f, 8.0f);
	glVertex2f(22.0f, 0.0f);
	glVertex2f(20.0f, -8.0f);
	glVertex2f(17.0f, -15.0f);
	glVertex2f(10.0f, -20.0f);
	glVertex2f(-10.0f, -20.0f);
	glVertex2f(-17.0f, -15.0f);
	glVertex2f(-20.0f, -8.0f);
	glVertex2f(-22.0f, 0.0f);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-22.0f, 0.0f);
	glVertex2f(-20.0f, 8.0f);
	glVertex2f(-17.0f, 15.0f);
	glVertex2f(-10.0f, 20.0f);
	glVertex2f(0.0f, 22.0f);
	glVertex2f(10.0f, 20.0f);
	glVertex2f(17.0f, 15.0f);
	glVertex2f(20.0f, 8.0f);
	glVertex2f(22.0f, 0.0f);
	glVertex2f(20.0f, -8.0f);
	glVertex2f(17.0f, -15.0f);
	glVertex2f(10.0f, -20.0f);
	glVertex2f(-10.0f, -20.0f);
	glVertex2f(-17.0f, -15.0f);
	glVertex2f(-20.0f, -8.0f);
	glVertex2f(-22.0f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void onResize(int w, int h)
{
	if (h == 0)
		h = 1;

	float aspect = (float)w / (float)h;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-100.0f, 100.0, -100.0f / aspect, 100.0 / aspect, 1.0f, -1.0f);
	else
		glOrtho(-100.0 * aspect, 100.0 * aspect, -100.0f, 100.0, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRenderingContext()
{
	glClearColor(0.5f, 0.35f, 0.05f, 1.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("M�j pierwszy program w GLUT");

	SetupRenderingContext();

	glutReshapeFunc(onResize);
	glutDisplayFunc(Display);

	glutMainLoop();

	return 0;
}

