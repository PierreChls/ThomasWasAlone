#ifndef BLOCK_H_
#define BLOCK_H_

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

typedef struct Block Block;
struct Block {
  float hauteur;
  float largeur;
  float x;
  float y;
  int move;
  Block* next;
};

//Liste de block

typedef struct Blocklist Blocklist;
struct Blocklist {
  Block *first;
};


//Initialisation

Blocklist* InitialiserBlocklist ();

void AddBlocklist (Blocklist liste[], float hauteur, float largeur, float x, float y, int move);
void supprimerBlocklist(Blocklist* blocklist);
void dessinBlock (int Filled, Blocklist* Blocklist);
void moveBlock (Blocklist* Blocklist, float* movetop, int* verifTop);

#endif
