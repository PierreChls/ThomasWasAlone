#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

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

typedef struct Personnage Personnage;
struct Personnage {
	float hauteur;
	float largeur;
	float x_start;
	float y_start;
	float x_end;
	float y_end;
	float puissance_saut;
	int TouchDown, TouchTop;
	float x_reset;
	float y_reset;
	int colorRtrue;
	int colorGtrue;
	int colorBtrue;
	int colorR;
	int colorG;
	int colorB;
	float largeur_color;
	Personnage* next;
};

//Liste des personnages

typedef struct Personnagelist Personnagelist;
struct Personnagelist {
	Personnage *first;
};

Personnagelist* InitialiserPersonnagelist ();
void AddPersonnagelist (Personnagelist liste[], float hauteur, float largeur, float x_start, float y_start, float x_end, float y_end, float puissance_saut, int TouchDown, int TouchTop, int colorR, int colorG, int colorB);
void supprimerPersonnagelist(Personnagelist* personnagelist);
void dessinPersonnage (Personnagelist* Personnagelist);
void dessinPersonnageOmbre(Personnagelist* Personnagelist);
void dessinPersonnageSelect(Personnage* ActualPerso);
void dessinPersonnageBarre(Personnagelist* Personnagelist, Personnage* PersoRepere, int windowWidth, int windowHeight, float* centreX, float* centerY);
Personnage* changePersonnage (Personnagelist* personnagelist, Personnage* ActualPerso);
Personnage* resetAllPersonnage (Personnagelist* personnagelist);
int Target (Personnage* perso);
int TargetAll (Personnagelist* Personnagelist);
void compressPersos (Personnagelist* Personnagelist);

#endif
