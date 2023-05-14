/*****************************************************************//**
 * \file   main.cpp
 * \brief  My solution for Q4 in exersice ('Maman') 15 in Computer Graphics (20562) course.
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
#include <string>
#include <vector>

#include "Constants.h"


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


/* Callback for 'glutDisplayFunc' */
void displayCallback(void)
{
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(WORLD_COORD);

    glClear(GL_COLOR_BUFFER_BIT);
}


/* Assigns callback functions for events */
void registerCallbacks(void)
{
    glutDisplayFunc(displayCallback);
}


int main(int argc, char** argv)
{
    /* Initialize OpenGL */
    createWindow(argc, argv);  // Create the display-window
    registerCallbacks();       // Assign callback functions for events
    glutMainLoop();            // Display everything and wait

    return 0;
}
