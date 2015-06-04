#include "block.h"
//Initialisation

Blocklist* InitialiserBlocklist () {
	Blocklist* bl = calloc(1, sizeof(Blocklist));
	Block* block = calloc(1, sizeof(Block));
	if (bl == NULL || block == NULL) {
		exit(1);
	}
	block=NULL;
	bl->first = block;
	return bl;
}

void supprimerBlocklist(Blocklist* blocklist){
		if(blocklist==NULL){
	    return;
	  }
	  Block* actu = blocklist->first;
		Block* temp;
	  while(actu!=NULL){
	    temp=actu->next;
	    free(actu);
	    actu=temp;
	  }
}

void AddBlocklist (Blocklist liste[], float hauteur, float largeur, float x, float y, int move) {
	Block* b = calloc(1, sizeof(Block));
	if (b == NULL || liste == NULL) {
		exit(1);
	}
	b->hauteur = hauteur;
	b->largeur = largeur;
	b->x = x;
	b->y = y;
	b->move = move;
	b->next = liste->first;
	liste->first = b;
}

//Dessin du bloc
void dessinBlock (int Filled, Blocklist* Blocklist){
	glLoadIdentity();
	if (Blocklist == NULL) {
		exit(1);
	}
	Block* ActualBlock = Blocklist->first;
	while (ActualBlock != NULL) {
		glColor4f(0, 0, 0, 0.25);
	  	glBegin(GL_QUADS);
	    	glVertex2f(((ActualBlock->x) - (ActualBlock->largeur)/2)-1, ((ActualBlock->y) + (ActualBlock->hauteur)/2)+1);
	    	glVertex2f(((ActualBlock->x) + (ActualBlock->largeur)/2)-1, ((ActualBlock->y) + (ActualBlock->hauteur)/2)+1);
	    	glVertex2f(((ActualBlock->x) + (ActualBlock->largeur)/2)-1, ((ActualBlock->y) - (ActualBlock->hauteur)/2)+1);
	    	glVertex2f(((ActualBlock->x) - (ActualBlock->largeur)/2)-1, ((ActualBlock->y) - (ActualBlock->hauteur)/2)+1);
	  	glEnd();
		glColor3ub(0, 0, 0);
	  	glBegin(GL_QUADS);
	    	glVertex2f((ActualBlock->x) - (ActualBlock->largeur)/2, (ActualBlock->y) + (ActualBlock->hauteur)/2);
	    	glVertex2f((ActualBlock->x) + (ActualBlock->largeur)/2, (ActualBlock->y) + (ActualBlock->hauteur)/2);
	    	glVertex2f((ActualBlock->x) + (ActualBlock->largeur)/2, (ActualBlock->y) - (ActualBlock->hauteur)/2);
	    	glVertex2f((ActualBlock->x) - (ActualBlock->largeur)/2, (ActualBlock->y) - (ActualBlock->hauteur)/2);
	  	glEnd();
	  	ActualBlock = ActualBlock->next;
	}
}

void moveBlock (Blocklist* Blocklist, float* movetop, int* verifTop){
	if (Blocklist == NULL) {
		exit(1);
	}
	Block* ActualBlock = Blocklist->first;
	while (ActualBlock != NULL) {
		if(ActualBlock->move == 1 && (*verifTop) == 0) {
			ActualBlock->y += 0.1;
			(*movetop) += 0.1;
			if ((*movetop) >= 27) {
				*verifTop = 1;
			}
		}
		if(ActualBlock->move == 1 && (*verifTop) == 1) {
			ActualBlock->y -= 0.1;
			(*movetop) -= 0.1;
			if ((*movetop) <= 0) {
				*verifTop = 0;
			}

		}

		if(ActualBlock->move == 2 && (*verifTop) == 0) {
			ActualBlock->y -= 0.1;
		}
		if(ActualBlock->move == 2 && (*verifTop) == 1) {
			ActualBlock->y += 0.1;
		}

		if(ActualBlock->move == 3 && (*verifTop) == 0) {
			ActualBlock->x += 0.085;
		}
		if(ActualBlock->move == 3 && (*verifTop) == 1) {
			ActualBlock->x -= 0.085;
		}

		if(ActualBlock->move == 4 && (*verifTop) == 0) {
			ActualBlock->x -= 0.085;
		}
		if(ActualBlock->move == 4 && (*verifTop) == 1) {
			ActualBlock->x += 0.085;
		}
	  	ActualBlock = ActualBlock->next;
	}
}
