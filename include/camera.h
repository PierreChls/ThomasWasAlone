#ifndef CAMERA_H_
#define CAMERA_H_

#include <SDL/SDL.h>
#ifdef __APPLE__
  //MACOS
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#elif __unix__
  //UNIX
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif __linux__
  //LINUX
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif __MINGW32__
  //WINDOWS
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include "personnage.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void moveCameraSuivrePerso(Personnage* perso, float* distance_x, float* distance_y, float* camera_center_x, float* camera_center_y);
void parallax(int booleanPressed, float* positionparallax);
void deffilement(float* positionparallax);

#endif
