#include "camera.h"

void moveCameraSuivrePerso(Personnage* perso, float* distance_x, float* distance_y, float* camera_center_x, float* camera_center_y){
  if(perso != NULL){
    glMatrixMode(GL_PROJECTION);
    (*distance_x) = perso->x_start - (*camera_center_x);
    (*distance_y) = perso->y_start - (*camera_center_y);

    glTranslatef(-(*distance_x), -(*distance_y), 0);

    (*camera_center_x) = perso->x_start;
    (*camera_center_y) = perso->y_start;
  }
}

void parallax(int booleanPressed, float* positionparallax) {
  if(booleanPressed==1) {
    (*positionparallax) -= 0.03;
  }
  if(booleanPressed==2) {
    (*positionparallax) += 0.03;
  }
}

void deffilement(float* positionparallax) {
  (*positionparallax) -= 0.01;
}