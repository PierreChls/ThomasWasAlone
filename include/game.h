#ifndef GAME_H_
#define GAME_H_

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

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned int windowWidth  = 1440;
unsigned int windowHeight = 900;
int booleanPressed = 0;
int booleanChangePersonnage = 0;
int reset = 0;
int jump = 0;
int verif = 1;
int verif2 = 0;
int verif3 = 0;
float pesanteur = 0;
float acceleration = 0;
float positionparallax = 0;
float positionparallaxfixed = 0;
float movetop = 0;
int verifTop = 0;
int parallax_move = 0;
int son_bottom = 0;
int verifsound3 = 0;
float distance_x = 0, distance_y = 0;
float camera_center_x = 0, camera_center_y = 0;

#endif
