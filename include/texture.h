#ifndef TEXTURE_H_
#define TEXTURE_H_

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
#include <SDL/SDL_image.h>
#include "menu.h"

GLuint load_Texture(char* path);
void move_texture(GLuint* texture, float** positionparallax, int brume);
void move_texture_menu(GLuint* texture_menu, float* rotation1);
void dessinCarre(int cote);
void move_texture_menuLvl(GLuint* texture, float x1, float x2, float y1, float y2);
void selector(float x1, float x2, float y1, float y2, int cpt_select_menu);
void move_texture_win(GLuint* texture);

#endif
