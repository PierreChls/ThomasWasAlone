#include "niveau.h"

void initializeFromFile(int number_level, Personnagelist* personnagelist, Blocklist* blocklist){

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

  if(fscanf(file, "nbPerso = %d nbBlock = %d", &nbPerso, &nbBlock)==2){
		printf("%d %d\n", nbPerso, nbBlock);
	}
	else{
    printf("Failed to assign the right inputs.\n");
    exit(1);
  }

  for (i = 0; i < nbPerso; ++i)
  {
  	if(fscanf(file, "%f %f %f %f %f %f %f %d %d %d %d %d", &hauteur, &largeur, &x_start, &y_start, &x_end, &y_end, &puissance_saut, &TouchDown, &TouchTop, &colorR, &colorG, &colorB)==12){
		    printf("%f %f %f %f %f %f %f %d %d %d %d %d\n", hauteur, largeur, x_start, y_start, x_end, y_end, puissance_saut, TouchDown, TouchTop, colorR, colorG, colorB);
        //(*platforms)[i] = createPlatform(w, h, x, y, shadow, type);
	  }
	  else printf("Failed to assign the right inputs.\n");
  }

  for (i = nbPerso; i < (nbPerso + nbBlock); ++i)
  {
  	if(fscanf(file, "%f %f %f %f %d", &hauteur_block, &largeur_block, &x, &y, &move)==5){
		    printf("%f %f %f %f %d\n", hauteur_block, largeur_block, x, y, move);
        //(*platforms)[i] = createPlatform(w, h, x, y, shadow, type);
	  }
	  else printf("Failed to assign the right inputs.\n");
  }

  fclose(file);

}

void load_niveau(Personnagelist* personnagelist, Blocklist* blocklist, int number_level){

  if(number_level == 1){
    AddPersonnagelist(personnagelist, 6, 1.3, -150, -9.5, -140, -9.5, 1.1, 1, 0, 173, 155, 55); //hauteur, largeur, x_start, y_start, x_end, y_end, puissance_saut, Touchdown, TouchTop, R, G, B
    AddPersonnagelist(personnagelist, 1.8, 1.8, -145, -11.6, -135, -11.6, 0.8, 1, 0, 208, 108, 53);
    AddPersonnagelist(personnagelist, 3, 1.7, -140, 0, -150, -11, 1, 1, 0, 166, 55, 59);

    AddBlocklist(blocklist, 20, 300, -40, -22.5, 0); //hauteur, largeur, x, y
    AddBlocklist(blocklist, 10, 7, -115, -11, 0);
    AddBlocklist(blocklist, 20, 10, -80, -11, 0);
    AddBlocklist(blocklist, 70, 50, 20, 20, 0);
    AddBlocklist(blocklist, 90, 20, -30, 50, 0);
    AddBlocklist(blocklist, 3, 8, -8, -5, 1); //Block vertical1
    AddBlocklist(blocklist, 3, 8, -5, 53.5, 0);
    AddBlocklist(blocklist, 3, 8, -17, 53.5, 2);//Block vertical2
    AddBlocklist(blocklist, 50, 80, 0, 110, 0);
    AddBlocklist(blocklist, 90, 80, 150, 10, 0);
    AddBlocklist(blocklist, 40, 80, 80, 0, 0);
    AddBlocklist(blocklist, 2, 6, 50, 54, 3); //Block horizontal1
    AddBlocklist(blocklist, 2, 6, 105, 54, 4); //Block horizontal2
    AddBlocklist(blocklist, 9, 10, 120, 62, 0);
    AddBlocklist(blocklist, 10, 6, 122, 71, 0);
    AddBlocklist(blocklist, 30, 10, 50, 30, 0);
    AddBlocklist(blocklist, 30, 10, 60, 20, 0);
    AddBlocklist(blocklist, 30, 10, 70, 10, 0);
  }


  if(number_level == 2){
    AddPersonnagelist(personnagelist, 6, 1.3, -150, -9.5, -140, -9.5, 1.1, 1, 0, 173, 155, 55);

    AddBlocklist(blocklist, 20, 300, -40, -22.5, 0); //hauteur, largeur, x, y
    AddBlocklist(blocklist, 10, 7, -115, -11, 0);
  }
}

int evolution_niveau(Blocklist* blocklist, Personnagelist* personnagelist, Personnage** perso, int windowWidth, int windowHeight, int* booleanPressed, int* booleanChangePersonnage, int* reset, int* jump, int* verif, int* verif2, int* verif3, float* pesanteur, float* acceleration, float* positionparallax, float* movetop, int* verifTop, int* parallax_move, int* son_bottom, int* verifsound3, float* distance_x, float* distance_y, float* camera_center_x, float* camera_center_y, Mix_Chunk* son_win, Mix_Chunk* son_ground, Mix_Chunk* son_jump,  GLuint texture_front, GLuint texture_back, float* positionparallaxfixed, int* cpt_finish_level, int* son_top){

  moveCameraSuivrePerso(*perso, distance_x, distance_y, camera_center_x, camera_center_y);
  //mouvementCamera(*perso, windowWidth, windowHeight, camera_center_x,camera_center_y);

  glClear(GL_COLOR_BUFFER_BIT);

  glClearColor(0.15, 0.18, 0.18, 1.0);
  //Changement de matrice
  glMatrixMode(GL_MODELVIEW);

  move_texture(&texture_front, &positionparallax);
  move_texture(&texture_back, &positionparallaxfixed);


  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);

  /* Affichage */
  dessinBlock(1, blocklist);
  dessinPersonnage(personnagelist);
  dessinPersonnageBarre(personnagelist, *perso, windowWidth, windowHeight, camera_center_x, camera_center_y);


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
          (*perso)->largeur_color -= 0.04;
          if((*perso)->largeur_color <= 1.05) {
            (*verif2) = 1;
            (*verif3) = 1;
          }
        }
      }
      if((*verif2) == 1) {
        (*perso)->largeur_color += 0.04;
          if((*perso)->largeur_color >= (*perso)->largeur) {
            (*verif2) = 0;
          }
      }
    }
  }

  if( (*jump) == 0){
    (*son_top) = 0;
  }

  /*Fin Saut*/


  if( (*jump)==0 && (*pesanteur)!=0 && collisionBottomWithoutJump(*perso, blocklist)!=NULL ){
    (*pesanteur) = 0;
    (*jump) = 0;
  }

  if( (*acceleration) != 0 && collisionPersonnageTop(*perso, personnagelist) == NULL  && (*parallax_move) == 0) {
    parallax(*booleanPressed, positionparallax);
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
