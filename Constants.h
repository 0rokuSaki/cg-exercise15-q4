/*****************************************************************//**
 * \file   Constants.h
 * \brief  Various constants for the program.
 *
 * \author aaron
 * \date   May 2023
 *********************************************************************/

#pragma once

 /* Window constants */
#define WINDOW_INIT_POS  100, 100
#define WINDOW_INIT_SIZE 720, 480  // width height
#define WINDOW_TITLE     "CG Maman 15 Q4 - Rotating Polyhedron"

/* Display constants */
#define ORTHOGRAPHIC_COORD -5.0, 5.0, -5.0, 5.0, 1.0, 100.0
#define PERSPECTIVE_COORD  60.0, aspectRatio, 1, 100.0
#define TRANSLATION_PARAMS 0.0, 0.0, -10.0         // Initial translation
#define SCALING_PARAMS     1.0, 1.0, 1.0           // Initial scaling
#define ROTATION_PARAMS    15, 1.0, 1.0, 1.0       // Initial rotation
#define LINE_WIDTH         3.0f
#define CUBE_SIZE          2.0
#define REFRESH_RATE_FPS   60.0
#define MAX_ROTATION_ANGLE 360.0

/* Color constants */
#define GREEN 0.3, 8.0, 0.3
#define BLUE  0.0, 0.0, 0.8

enum EPolyhedronType : unsigned char
{
    FIRST_OF_POLYHEDRON_TYPE = '0',
    TETRAHEDRON,
    CUBE,
    OCTAHEDRON,
    DODECAHEDRON,
    ICOSAHEDRON,
    LAST_OF_POLYHEDRON_TYPE
};

enum EProjectionType : unsigned char
{
    ORTHOGRAPHIC = 'o',
    PERSPECTIVE = 'p'
};
