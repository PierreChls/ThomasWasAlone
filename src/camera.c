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

void mouvementCamera(Personnage* perso, int windowWidth, int windowHeight, float* centreX, float* centreY){
  float xRapport, yRapport;
  float distanceCentreX, distanceCentreY, diffX, diffY;

  if(perso){
    diffX = (*centreX);
    diffY = (*centreY);

    distanceCentreX = perso->x_start - (*centreX);
    distanceCentreY = perso->y_start - (*centreY);

    xRapport = 0.01*windowWidth;
    yRapport = 0.01*windowHeight;



    if(distanceCentreX > xRapport){
      (*centreX) += +1 * (distanceCentreX - xRapport) / 10;
    }
    else if (distanceCentreX < (-xRapport)){
      (*centreX) -= -1 * (distanceCentreX + xRapport) / 10;
    }

    if(distanceCentreY > yRapport){
      (*centreY) += +1 * (distanceCentreY - yRapport) / 10;
    }
    else if (distanceCentreY < (-yRapport)){
      (*centreY) -= -1 * (distanceCentreY + yRapport) / 1;
    }

    printf("%f %f\n", perso->x_start, -(*centreX));
    glTranslatef(-(*centreX), -(*centreY), 0.0);

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
