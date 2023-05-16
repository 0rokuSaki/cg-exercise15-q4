/*****************************************************************//**
 * \file   main.cpp
 * \brief  My solution for Q4 in exersice ('Maman') 15 in Computer Graphics (20562) course.
 * 
 * This program displays a rotating polyhedron.
 * Press on keys 1-5 to switch between the different polyhedrons.
 * Press on keys p and o to switch between orthographic and perspective projections.
 *
 * Repo link: https://github.com/0rokuSaki/cg-exercise15-q4
 *
 * *** BUILD INSTRUCTIONS (VS2019/VS2022 Windows 10/11) ***
 * 1. Setup OpenGL: https://www.geeksforgeeks.org/how-to-setup-opengl-with-visual-studio-2019-on-windows-10/.
 * 2. Select x86 Debug configuration.
 * 3. Build the solution (ctrl + shift + B).
 *
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#include <Windows.h>
#include <GL/glut.h>

#include <iostream>
#include <vector>
#include <cmath>

#include "Constants.h"


EPolyhedronType currentPolyhedron = TETRAHEDRON;
EProjectionType currentProjection = ORTHOGRAPHIC;
GLdouble       currentRotationAngle = 0.0;
GLdouble       aspectRatio;


 /* Creates and initializes GLUT display-window. */
void createWindow(int argc, char** argv)
{
    /* Create the window */
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowPosition(WINDOW_INIT_POS);      // Set top-left window position
    glutInitWindowSize(WINDOW_INIT_SIZE);         // Set window width and height
    glutCreateWindow(WINDOW_TITLE);               // Create window

    /* Initialize the window */
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // Set window color to white
}


void displayPolyhedron(EPolyhedronType polyhedron)
{
    currentPolyhedron = polyhedron;

    glLineWidth(LINE_WIDTH);

    switch (polyhedron)
    {
    case TETRAHEDRON:
        glutWireTetrahedron();
        break;
    case CUBE:
        glutWireCube(CUBE_SIZE);
        break;
    case OCTAHEDRON:
        glutWireOctahedron();
        break;
    case DODECAHEDRON:
        glutWireDodecahedron();
        break;
    case ICOSAHEDRON:
        glutWireIcosahedron();
        break;
    default:
        break;
    }
}


void updateProjection(EProjectionType projection)
{
    currentProjection = projection;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    switch (projection)
    {
    case ORTHOGRAPHIC:
        glOrtho(ORTHOGRAPHIC_COORD);
        glColor3d(GREEN);
        break;
    case PERSPECTIVE:
        gluPerspective(PERSPECTIVE_COORD);
        glColor3d(BLUE);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}


/* Callback for 'glutDisplayFunc' */
void displayCallback(void)
{
    aspectRatio = ((GLdouble)glutGet(GLUT_SCREEN_WIDTH)) / glutGet(GLUT_SCREEN_HEIGHT);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(TRANSLATION_PARAMS);
    glScaled(SCALING_PARAMS);
    glRotated(ROTATION_PARAMS);
    glRotated(currentRotationAngle, 0.0, 1.0, 0.0);

    updateProjection(currentProjection);

    displayPolyhedron(currentPolyhedron);

    glFlush();
    glutSwapBuffers();
}


void keyboardCallback(unsigned char key, int x, int y)
{
    if (FIRST_OF_POLYHEDRON_TYPE < key && key < LAST_OF_POLYHEDRON_TYPE)
    {
        displayPolyhedron((EPolyhedronType) key);
    }
    else if (tolower(key) == ORTHOGRAPHIC || tolower(key) == PERSPECTIVE)
    {
        updateProjection((EProjectionType) tolower(key));
    }
    else
    {
        // A different button was pressed; do nothing
    }
}


void timerCallback(int value)
{
    currentRotationAngle += 1.0;
    if (currentRotationAngle > MAX_ROTATION_ANGLE)
    {
        currentRotationAngle = 0.0;
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / REFRESH_RATE_FPS, timerCallback, value);
}


/* Assigns callback functions for events */
void registerCallbacks(void)
{
    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardCallback);
    glutTimerFunc(100, timerCallback, 0);
}


int main(int argc, char** argv)
{
    /* Initialize OpenGL */
    createWindow(argc, argv);  // Create the display-window
    registerCallbacks();       // Assign callback functions for events
    glutMainLoop();            // Display everything and wait

    return 0;
}
