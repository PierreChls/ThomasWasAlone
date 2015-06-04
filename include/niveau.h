#ifndef NIVEAU_H_
#define NIVEAU_H_

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
#include "block.h"
#include "collision.h"
#include "camera.h"
#include "texture.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
void initializeFromFile(int number_level, Personnagelist* personnagelist, Blocklist* blocklist);
void load_niveau(Personnagelist* personnagelist, Blocklist* blocklist, int number_level);
int evolution_niveau(Blocklist* blocklist, Personnagelist* personnagelist, Personnage** perso, int windowWidth, int windowHeight, int* booleanPressed, int* booleanChangePersonnage, int* reset, int* jump, int* verif, int* verif2, int* verif3, float* pesanteur, float* acceleration, float* positionparallax, float* movetop, int* verifTop, int* parallax_move, int* son_bottom, int* verifsound3, float* distance_x, float* distance_y, float* camera_center_x, float* camera_center_y, Mix_Chunk* son_win, Mix_Chunk* son_ground, Mix_Chunk* son_jump, GLuint texture_front, GLuint texture_back, float* positionparallaxfixed, int* cpt_finish_level, int* son_top);

#endif
