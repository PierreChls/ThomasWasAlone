#ifndef COLLISION_H_
#define COLLISION_H_

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

#include "personnage.h"
#include "block.h"

Block* collisionRight (Personnage* perso, Blocklist* Blocklist);
Block* collisionLeft (Personnage* perso, Blocklist* Blocklist);
Block* collisionBottomWithoutJump (Personnage* perso, Blocklist* Blocklist);
Block* collisionBottom (Personnage* perso, Blocklist* Blocklist);
Block* collisionTop (Personnage* perso, Blocklist* Blocklist);
int controlVitesseRight (Personnage* perso, Blocklist* Blocklist);
int controlVitesseLeft (Personnage* perso, Blocklist* Blocklist);
int controlVitesseTop (Personnage* perso, Blocklist* Blocklist);
void controlCollisionBottom (Personnage* perso, Block* block, int** verifTop);
void controlCollisionTop (Personnage* perso, Block* block);

Personnage* collisionPersoRight (Personnage* perso, Personnagelist* personnagelist);
Personnage* collisionPersoLeft (Personnage* perso, Personnagelist* personnagelist);
Personnage* collisionPersonnageBottom (Personnage* perso, Personnagelist* personnagelist);
Personnage* controlCollisionPersonnageBottom (Personnage* perso, Personnage* ActualPerso);
Personnage* collisionPersonnageTop (Personnage* perso, Personnagelist* personnagelist);
int collisionPersonnageBottomEvery(Personnage* perso, Personnagelist* personnagelist);
void collisionEveryPerso (Personnage* perso, Blocklist* Blocklist, Personnagelist* personnagelist, int* verifTop);

#endif
