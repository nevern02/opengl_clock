#include <iostream>

#include "Clock.h"

// Window display size
GLsizei winWidth = 800, winHeight = 600;   

// Initialize method
void init()
{
  // Get and display your OpenGL version
  std::cout << "Your OpenGL version is " << glGetString(GL_VERSION) << std::endl;

  // Black background
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // Projection on World Coordinates 
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,(GLdouble) winWidth , 0.0,(GLdouble) winHeight);
}


// Draw method
void displayFcn()
{
  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  

  // Draw clock
  Clock clock(winWidth / 2, winHeight / 2, winWidth / 3.0);

  glFlush( );
}

// Window redraw method
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0.0,(GLdouble) newWidth, 0.0,(GLdouble) newHeight);
    glClear(GL_COLOR_BUFFER_BIT);  
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);

    glutCreateWindow("Rice Homework 2");
    init();
    glutDisplayFunc(displayFcn);

    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();

    return 0;
}
