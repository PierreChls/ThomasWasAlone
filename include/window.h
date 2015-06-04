#ifndef WINDOW_H_
#define WINDOW_H_

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

static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void reshape(int winWidth, int winHeight);
void reshapeResize(Personnage* perso, int winWidth, int winHeight);
void setVideoMode(int winWidth, int winHeight);
void setVideoModeResize(Personnage* perso, int winWidth, int winHeight);

#endif
