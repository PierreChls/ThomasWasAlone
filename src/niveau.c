#include "niveau.h"

void loadNiveau(int number_level, Personnagelist* personnagelist, Blocklist* blocklist){

	FILE *file = NULL;

  char path[14];

  sprintf(path, "niveau//%d.txt", number_level);

  file = fopen(path, "r");

  if (file == NULL)
  {
  	printf("Le fichier de niveau n'a pas pu être ouvert\n");
  	exit(1);
  }

  int i = 0;
  int nbPerso, nbBlock;
  float hauteur, largeur, x_start, y_start, x_end, y_end, puissance_saut;
  int TouchDown, TouchTop, colorR, colorG, colorB;
  float hauteur_block, largeur_block, x, y;
  int move;

  if(fscanf(file, "nbPerso = %d nbBlock = %d", &nbPerso, &nbBlock)!=2) {
    printf("Failed to assign the right inputs.\n");
    exit(1);
  }

  for (i = 0; i < nbPerso; ++i)
  {
  	if(fscanf(file, "%f, %f, %f, %f, %f, %f, %f, %d, %d, %d, %d, %d", &hauteur, &largeur, &x_start, &y_start, &x_end, &y_end, &puissance_saut, &TouchDown, &TouchTop, &colorR, &colorG, &colorB)==12){
		    AddPersonnagelist(personnagelist, hauteur, largeur, x_start, y_start, x_end, y_end, puissance_saut, TouchDown, TouchTop, colorR, colorG, colorB);
	  }
	  else printf("Failed to assign the right inputs.\n");
  }

  for (i = nbPerso; i < (nbPerso + nbBlock); ++i)
  {
  	if(fscanf(file, "%f, %f, %f, %f, %d", &hauteur_block, &largeur_block, &x, &y, &move)==5){
		    AddBlocklist(blocklist, hauteur_block, largeur_block, x, y, move);
	  }
	  else printf("Failed to assign the right inputs.\n");
  }

  fclose(file);

}

int evolution_niveau(Blocklist* blocklist, Personnagelist* personnagelist, Personnage** perso, int windowWidth, int windowHeight, int* booleanPressed, int* booleanChangePersonnage, int* reset, int* jump, int* verif, int* verif2, int* verif3, float* pesanteur, float* acceleration, float* positionparallax, float* movetop, int* verifTop, int* parallax_move, int* son_bottom, int* verifsound3, float* distance_x, float* distance_y, float* camera_center_x, float* camera_center_y, Mix_Chunk* son_win, Mix_Chunk* son_ground, Mix_Chunk* son_jump,  GLuint texture_front, GLuint texture_back, float* positionparallaxfixed, int* cpt_finish_level, int* son_top, GLuint texture_brume,  GLuint texture_gradient, float* rotateCarre) {
  int t;
  moveCameraSuivrePerso(*perso, distance_x, distance_y, camera_center_x, camera_center_y);
  //mouvementCamera(*perso, windowWidth, windowHeight, camera_center_x,camera_center_y);

  glClear(GL_COLOR_BUFFER_BIT);

  glClearColor(0.098, 0.25, 0.30, 1.0);
  //Changement de matrice
  glMatrixMode(GL_MODELVIEW);
  move_texture(&texture_front, &positionparallax, 0);
  move_texture(&texture_brume, &positionparallax, 1);
  //move_texture(&texture_back, &positionparallaxfixed);


  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);

  for(t=0; t<1000; t+=100) {
    glLoadIdentity();
    glTranslatef(t-150, 5, 1);
    glRotatef(*rotateCarre, 0, 0, 1);
    dessinCarre(10);
  }

  for(t=0; t<1000; t+=120) {
    glLoadIdentity();
    glTranslatef(t-110, -10, 1);
    glRotatef(*rotateCarre, 0, 0, 1);
    dessinCarre(20);
  }

  for(t=0; t<1000; t+=150) {
    glLoadIdentity();
    glTranslatef(t-130, 15, 1);
    glRotatef(-(*rotateCarre), 0, 0, 1);
    dessinCarre(15);
  }

  /* Affichage */
  dessinBlock(1, blocklist);
  dessinPersonnage(personnagelist);
  dessinPersonnageBarre(personnagelist, *perso, windowWidth, windowHeight, camera_center_x, camera_center_y);

  *rotateCarre += 0.01;

  if (TargetAll(personnagelist) == 0) {
    dessinPersonnageSelect(*perso);
  }

  moveBlock(blocklist, movetop, verifTop);

  if ( (*booleanChangePersonnage) == 1 && (*jump) !=1) {
    (*perso) = changePersonnage (personnagelist, *perso);
    (*booleanChangePersonnage) = 0;
  }

  if( (*reset) == 1 && (*jump) !=1) {
    (*perso) = resetAllPersonnage(personnagelist);
    (*reset) = 0;
  }

  if (Target(*perso) == 1) {
    (*perso)->colorR = 255;
    (*perso)->colorG = 255;
    (*perso)->colorB = 255;
  }
  if (Target(*perso) == 0) {
    (*perso)->colorR = (*perso)->colorRtrue;
    (*perso)->colorG = (*perso)->colorGtrue;
    (*perso)->colorB = (*perso)->colorBtrue;
  }

  if (TargetAll(personnagelist) == 1) {
    (*booleanPressed) = 0;
    (*jump) = 0;
    if ( (*verifsound3) == 0) {
      Mix_PlayChannel(0, son_win, 0);
      compressPersos(personnagelist);
      (*verifsound3) = 1;
    }
    (*cpt_finish_level)++;
    if( (*cpt_finish_level) >= 100 ){
      (*cpt_finish_level) = 0;
      (*verifsound3) = 0;
      return 1;
    }
  }

  /*Gestion du saut*/

  if ( (*jump) == 1) {
    if(collisionPersonnageTop(*perso, personnagelist) == NULL){

      (*verif) = 0;
      (*son_bottom) = 0;
      (*perso)->y_start += (*perso)->puissance_saut;
      (*perso)->y_start += (*pesanteur);
      (*pesanteur) += -0.04;

      if( (*son_top) == 0){
        Mix_PlayChannel(0, son_jump, 0);
        (*son_top) = 1;
      }

      if((*perso)->largeur_color > 0.11 && (*verif2) == 0) {
        if((*verif3) == 0) {
          (*perso)->largeur_color -= 0.05;
          if((*perso)->largeur_color <= 1.05) {
            (*verif2) = 1;
            (*verif3) = 1;
          }
        }
      }
      if((*verif2) == 1) {
        (*perso)->largeur_color += 0.05;
          if((*perso)->largeur_color >= (*perso)->largeur) {
            (*verif2) = 0;
          }
      }
    }
  }

  if( (*jump) == 0){
    (*son_top) = 0;
  }

  deffilement(positionparallax);

  if( (*jump)==0 && (*pesanteur)!=0 && collisionBottomWithoutJump(*perso, blocklist)!=NULL ){
    (*pesanteur) = 0;
    (*jump) = 0;
  }

  if( (*acceleration) != 0 && collisionPersonnageTop(*perso, personnagelist) == NULL  && (*parallax_move) == 0) {
    //parallax(*booleanPressed, positionparallax);
  }


  Block* BlockCollisionTop;
  BlockCollisionTop = collisionTop(*perso, blocklist);

  Block* BlockCollisionBottom;
  BlockCollisionBottom = collisionBottom(*perso, blocklist);

  if(BlockCollisionTop != NULL){
    controlCollisionTop(*perso, BlockCollisionTop);
    (*pesanteur) = 0;
    (*jump) = 0;
    (*verif) = 1;
  }

  //Si collisionBottom != NULL on applique le controlCollision
  if (BlockCollisionBottom != NULL && BlockCollisionTop == NULL) {
    controlCollisionBottom(*perso, BlockCollisionBottom, &verifTop );
    (*perso)->largeur_color = (*perso)->largeur;
    if( (*son_bottom) == 0){
      Mix_PlayChannel(0, son_ground, 0);
      (*son_bottom) = 1;
    }
    (*pesanteur) = 0;
    (*jump) = 0;
    (*verif) = 1;
    (*verif3) = 0;
  }

  if(BlockCollisionBottom == NULL && collisionPersonnageTop(*perso, personnagelist) != NULL){
    (*pesanteur) = 0;
    (*jump) = 0;
    (*verif) = 1;
  }

  if(collisionPersonnageBottom(*perso, personnagelist) != NULL){
    (*pesanteur) = 0;
    (*jump) = 0;
    (*verif) = 1;
    if( (*son_bottom) == 0){
      Mix_PlayChannel(0, son_ground, 0);
      (*son_bottom) = 1;
    }
    (*verif3) = 0;
    (*perso)->largeur_color = (*perso)->largeur;
  }

  //Si collisionBottom == NULL et qu'il ne saute pas, on applique la pesanteur
  if (BlockCollisionBottom == NULL && (*jump) == 0 && collisionPersonnageBottom(*perso, personnagelist) == NULL) {
    (*pesanteur) += -0.07;
    (*perso)->y_start += (*pesanteur);
  }

  /*Gestion de l'accélération gauche et droite + gestion des collisions*/
  if ( (*booleanPressed) == 1) {

    //GESTION DES BLOCKS

    if ( (*acceleration) <= 0.3 && collisionRight(*perso, blocklist) == NULL) {
      if(controlVitesseRight(*perso, blocklist) == 0){
        (*acceleration) += 0.02;
      }
    }
    if(controlVitesseRight(*perso, blocklist) == 1){
      (*acceleration) = 0.01;
    }
    if (collisionRight(*perso, blocklist) != NULL) {
      (*acceleration) = 0;
    }
    (*perso)->x_start += (*acceleration);

    //GESTION DES PERSONNAGES

    if(collisionPersoRight(*perso, personnagelist) != NULL){
      (*perso)->x_start -= (*acceleration);
      (*parallax_move) = 1;
    }
    else{
      (*parallax_move) = 0;
    }
  }

  if ( (*booleanPressed) == 2) {

    //GESTION DES BLOCKS


    if ( (*acceleration) >= -0.3 && collisionLeft(*perso, blocklist) == NULL) {
      if(controlVitesseLeft(*perso, blocklist) == 0){
        (*acceleration) -= 0.02;
      }
    }

    if(controlVitesseLeft(*perso, blocklist) == 1){
      (*acceleration) = -0.01;
    }
    if (collisionLeft(*perso, blocklist) != NULL) {
      (*acceleration) = 0;
    }
    (*perso)->x_start += (*acceleration);

    //GESTION DES PERSONNAGES

    if(collisionPersoLeft(*perso, personnagelist) != NULL){
      (*perso)->x_start -= (*acceleration);
      (*parallax_move) = 1;
    }
    else{
      (*parallax_move) = 0;
    }
  }
  /*Fin de gestion de l'accélération gauche et droite + fin gestion des collisions*/

  collisionEveryPerso (*perso, blocklist, personnagelist, verifTop);

  return 0;

}
