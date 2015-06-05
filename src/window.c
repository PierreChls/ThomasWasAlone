#include "window.h"

void reshape(int winWidth, int winHeight) {
  glViewport(0, 0, winWidth, winHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D( - 40. , 40. , - 40 * (winHeight/(float)winWidth), 40. * (winHeight/(float)winWidth));
}

void reshapeResize(Personnage* perso, int winWidth, int winHeight) {
  glViewport(0, 0, winWidth, winHeight);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D( perso->x_start - 40 , perso->x_start+ 40 , (perso->y_start - 40) * (winHeight/(float)winWidth), (perso->y_start + 40) * (winHeight/(float)winWidth));
  //gluOrtho2D( perso->x_start - 150 , perso->x_start+ 150 , (perso->y_start - 150) * (winHeight/(float)winWidth), (perso->y_start + 150) * (winHeight/(float)winWidth));
}

void setVideoMode(int winWidth, int winHeight) {
  if(NULL == SDL_SetVideoMode(winWidth, winHeight, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE)) {
    fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
    exit(EXIT_FAILURE);
  }
  reshape(winWidth,winHeight);
}

void setVideoModeResize(Personnage* perso, int winWidth, int winHeight) {
  if(NULL == SDL_SetVideoMode(winWidth, winHeight, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE)) {
    fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
    exit(EXIT_FAILURE);
  }
  reshapeResize(perso, winWidth,winHeight);
}
