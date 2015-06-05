#include "collision.h"

Block* collisionRight (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - ((ActualBlock->largeur)/2)-0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
        //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
          return ActualBlock;
        }
        else {
          ActualBlock = ActualBlock->next;
        }
      }
      else {
        ActualBlock = ActualBlock->next;
      }
  }
  return NULL;
}

Block* collisionBlockRight (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
    if (((perso->x_start) + (perso->largeur)/2 + 0.25 >= (ActualBlock->x) - ((ActualBlock->largeur)/2)) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
      //Si le point y le plus bas du perso est < au point y le plus haut du block
      if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2 - 0.25) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
        return ActualBlock;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}

Block* collisionLeft (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
    if (((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + ((ActualBlock->largeur)/2)+0.05) && ((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2)) {
      //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
        return ActualBlock;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}

Block* collisionBlockLeft (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
    if (((perso->x_start) - (perso->largeur)/2 - 0.5 <= (ActualBlock->x) + ((ActualBlock->largeur)/2)) && ((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2)) {
      //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2 - 0.25) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
          return ActualBlock;
        }
        else {
          ActualBlock = ActualBlock->next;
        }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}

Block* collisionBottomWithoutJump (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    if (((perso->y_start) - (perso->hauteur)/2 - 0.5 <= (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualBlock->y) - (ActualBlock->hauteur)/2)) {
       //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
       if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2 - 0.05)) {
             if(ActualBlock->move==2 || ActualBlock->move==1){
               perso->y_start -= 0.5;
             }
        return ActualBlock;
       }
       else {
         ActualBlock = ActualBlock->next;
       }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}

Block* collisionBottom (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
    if (((perso->y_start) - (perso->hauteur)/2 <= (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
        return ActualBlock;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}

Block* collisionTop (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si le point le plus haut du perso est < ou = au point le plus haut du block
    if (((perso->y_start) + (perso->hauteur)/2 >= (ActualBlock->y) - (ActualBlock->hauteur)/2) && ((perso->y_start - perso->hauteur/2) < (ActualBlock->y - ActualBlock->hauteur/2))) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
        return ActualBlock;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return NULL;
}


int controlVitesseRight (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - ((ActualBlock->largeur)/2)-0.25) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
        //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
          return 1;
        }
        else {
          ActualBlock = ActualBlock->next;
        }
      }
      else {
        ActualBlock = ActualBlock->next;
      }
  }
  return 0;
}

int controlVitesseLeft (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
    if (((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + ((ActualBlock->largeur)/2)+0.2) && ((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2)) {
      //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualBlock->y) + (ActualBlock->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)){
        return 1;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return 0;
}

int controlVitesseTop (Personnage* perso, Blocklist* Blocklist) {
  Block* ActualBlock = Blocklist->first;
  while (ActualBlock != NULL) {
    //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
    if (((perso->y_start) - (perso->hauteur)/2 <= (ActualBlock->y) + ((ActualBlock->hauteur)/2)+2.1) && ((perso->y_start) + (perso->hauteur)/2 > (ActualBlock->y) - (ActualBlock->hauteur)/2)) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualBlock->x) - (ActualBlock->largeur)/2) && ((perso->x_start) - (perso->largeur)/2 <= (ActualBlock->x) + (ActualBlock->largeur)/2)) {
        return 1;
      }
      else {
        ActualBlock = ActualBlock->next;
      }
    }
    else {
      ActualBlock = ActualBlock->next;
    }
  }
  return 0;
}

void controlCollisionBottom (Personnage* perso, Block* block, int** verifTop) {
  if(block == NULL){
    printf("ERREUR\n");
    exit(1);
  }
  else{
    if (((perso->y_start) - (perso->hauteur)/2 <= (block->y) + (block->hauteur/2))  && ((perso->y_start) + (perso->hauteur)/2 >= (block->y) - (block->hauteur/2))) {
      if ((perso->x_start + perso->largeur/2 > block->x - block->largeur/2) && (perso->x_start - perso->largeur/2 < block->x + block->largeur/2)) {
        perso->y_start = block->y + (block->hauteur)/2 + (perso->hauteur)/2;
        if(block->move == 3){
          if( (**verifTop) == 0 ){
            perso->x_start += 0.085;
          }
          if( (**verifTop) == 1 ){
            perso->x_start -= 0.085;
          }
        }
        if(block->move == 4){
          if( (**verifTop) == 0 ){
            perso->x_start -= 0.085;
          }
          if( (**verifTop) == 1 ){
            perso->x_start += 0.085;
          }
        }
      }
    }
  }
}

void controlCollisionTop (Personnage* perso, Block* block) {
  if(block == NULL){
    printf("ERREUR\n");
    exit(1);
  }
  else{
    if (((perso->y_start) - (perso->hauteur)/2 <= (block->y) + (block->hauteur/2))  && ((perso->y_start) + (perso->hauteur)/2 >= (block->y) - (block->hauteur/2))) {
      if ((perso->x_start + perso->largeur/2 > block->x - block->largeur/2) && (perso->x_start - perso->largeur/2 < block->x + block->largeur/2)) {
        perso->y_start = block->y - (block->hauteur)/2 - (perso->hauteur)/2;
      }
    }
  }
}


Personnage* collisionPersoRight (Personnage* perso, Personnagelist* personnagelist) {
  Personnage* ActualPerso = personnagelist->first;
  while (ActualPerso != NULL) {
    if(ActualPerso == perso){
      ActualPerso = ActualPerso->next;
    }
    else{
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - ((ActualPerso->largeur)/2)) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2)) {
        //Si le point y le plus bas du perso est < au point y le plus haut du block
        if (((perso->y_start) - (perso->hauteur)/2 < (ActualPerso->y_start) + (ActualPerso->hauteur)/2 - 0.25) && ((perso->y_start) + (perso->hauteur)/2 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)){
          return ActualPerso;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  return NULL;
}

Personnage* collisionPersoLeft (Personnage* perso, Personnagelist* personnagelist) {
  Personnage* ActualPerso = personnagelist->first;
  while (ActualPerso != NULL) {
    if(ActualPerso == perso){
      ActualPerso = ActualPerso->next;
    }
    else{
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + ((ActualPerso->largeur)/2)) && ((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2)) {
        //Si le point y le plus bas du perso est < au point y le plus haut du block
          if (((perso->y_start) - (perso->hauteur)/2 < (ActualPerso->y_start) + (ActualPerso->hauteur)/2 - 0.25) && ((perso->y_start) + (perso->hauteur)/2 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)){
            return ActualPerso;
          }
          else {
            ActualPerso = ActualPerso->next;
          }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  return NULL;
}

Personnage* collisionPersonnageBottom (Personnage* perso, Personnagelist* personnagelist) {
  Personnage* ActualPerso = personnagelist->first;

  if(perso->next != NULL){
    while (ActualPerso != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          //perso->y_start = ActualPerso->y_start + (ActualPerso->hauteur/2) + (perso->hauteur/2);
          if(((perso->y_start - (perso->hauteur)/2) - 0.05 <= (ActualPerso->y_start + (ActualPerso->hauteur)/2 + 0.05)) && (perso->y_start > ActualPerso->y_start)){
            perso->y_start = ActualPerso->y_start + (ActualPerso->hauteur)/2 + (perso->hauteur/2) + 0.04;
          }
          return ActualPerso;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  else{
    while (ActualPerso->next != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          if(((perso->y_start - (perso->hauteur)/2) - 0.05 <= (ActualPerso->y_start + (ActualPerso->hauteur)/2 + 0.05)) && (perso->y_start > ActualPerso->y_start)){
            perso->y_start = ActualPerso->y_start + (ActualPerso->hauteur)/2 + (perso->hauteur/2) + 0.04;
          }
          return ActualPerso;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  return NULL;
}

Personnage* controlCollisionPersonnageBottom (Personnage* perso, Personnage* ActualPerso) {

  if(perso->next != NULL){
    while (ActualPerso != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          return ActualPerso;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  else{
    while (ActualPerso->next != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          return ActualPerso;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  return NULL;
}

Personnage* collisionPersonnageTop (Personnage* perso, Personnagelist* personnagelist) {
  Personnage* ActualPerso = personnagelist->first;
  while (ActualPerso != NULL) {
    //Si le point le plus haut du perso est < ou = au point le plus haut du block
    if (((perso->y_start) + (perso->hauteur)/2 >= (ActualPerso->y_start) - (ActualPerso->hauteur)/2 - 0.5) && ((perso->y_start - perso->hauteur/2) < (ActualPerso->y_start - ActualPerso->hauteur/2))) {
      //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
      if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 - 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2)) {
        if((controlCollisionPersonnageBottom(perso, ActualPerso) != NULL) && ((perso->y_start) + (perso->hauteur)/2 + 2 >= (ActualPerso->y_start) - (ActualPerso->hauteur)/2)){
          perso->y_start = ActualPerso->y_start - (ActualPerso->hauteur)/2 - (perso->hauteur)/2 - 0.15;
        }
        return ActualPerso;
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
    else {
      ActualPerso = ActualPerso->next;
    }
  }
  return NULL;
}

int collisionPersonnageBottomEvery(Personnage* perso, Personnagelist* personnagelist){

  Personnage* ActualPerso = personnagelist->first;

  if(perso->next != NULL){
    while (ActualPerso != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          //perso->y_start = ActualPerso->y_start + (ActualPerso->hauteur/2) + (perso->hauteur/2);
          return 1;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  else{
    while (ActualPerso->next != NULL) {
      if(ActualPerso == perso){
        ActualPerso = ActualPerso->next;
      }
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (((perso->y_start) - (perso->hauteur)/2 <= (ActualPerso->y_start) + (ActualPerso->hauteur)/2) && ((perso->y_start) + (perso->hauteur)/2 - 0.25 > (ActualPerso->y_start) - (ActualPerso->hauteur)/2)) {
        //Si la largeur (axe x) du personnage est touche ou est compris dans la largeur du block
        if (((perso->x_start) + (perso->largeur)/2 >= (ActualPerso->x_start) - (ActualPerso->largeur)/2 + 0.05) && ((perso->x_start) - (perso->largeur)/2 <= (ActualPerso->x_start) + (ActualPerso->largeur)/2 - 0.05)) {
          return 1;
        }
        else {
          ActualPerso = ActualPerso->next;
        }
      }
      else {
        ActualPerso = ActualPerso->next;
      }
    }
  }
  return 0;
}

void collisionEveryPerso (Personnage* perso, Blocklist* Blocklist, Personnagelist* personnagelist, int* verifTop) {
  Block* ActualBlock = NULL;
  Personnage* ActualPerso = personnagelist->first;
  while (ActualPerso != NULL) {
    if (ActualPerso == perso)
    {
      ActualPerso = ActualPerso->next;
    }
    else{
      ActualBlock = collisionBottom(ActualPerso, Blocklist);
      //Si le point le plus bas du perso est < ou = au point le plus haut du block et que le pt le plus haut du perso est > ou = au pt le plus bas du block
      if (ActualBlock != NULL) {
        if(ActualBlock->move == 1 || ActualBlock->move == 2){
          ActualPerso->y_start =  ActualBlock->y + ActualBlock->hauteur/2 + ActualPerso->hauteur/2;
        }
        if(ActualBlock->move == 3 || ActualBlock->move == 4){
          ActualPerso->y_start = ActualBlock->y + ActualBlock->hauteur/2 + ActualPerso->hauteur/2;
          if(ActualBlock->move == 3){
            if( (*verifTop) == 0 ){
              ActualPerso->x_start += 0.085;
            }
            if( (*verifTop) == 1 ){
              ActualPerso->x_start -= 0.085;
            }
          }
          if(ActualBlock->move == 4){
            if( (*verifTop) == 0 ){
              ActualPerso->x_start -= 0.085;
            }
            if( (*verifTop) == 1 ){
              ActualPerso->x_start += 0.085;
            }
          }
        }
      }
      else {
        if(collisionPersonnageBottomEvery(ActualPerso, personnagelist) == 0){
          ActualPerso->y_start -= 0.1;
        }
      }
      ActualBlock = collisionTop(ActualPerso, Blocklist);
      if (ActualBlock != NULL) {
        ActualPerso->y_start = ActualBlock->y - ActualBlock->hauteur/2 - ActualPerso->hauteur/2;
      }
      ActualPerso = ActualPerso->next;
    }
  }
}
