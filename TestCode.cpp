//Tactical_Hacker

#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);  // Initialize GLUT
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);   // Set up some memory buffers for our display
	
	glutInitWindowSize(900, 700);  // Set the window size
	
	glutCreateWindow("Tactical_Hacker, GL");   // Create the window with the title "Tactical_Hacker,GL"
	
	glutReshapeFunc(changeViewPort);  // Bind the two functions (above) to respond when necessary

	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can call all the functions in the API.

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	glutMainLoop();
	return 0;
}