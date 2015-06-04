#include "personnage.h"

//Initialisation de Personnagelist

Personnagelist* InitialiserPersonnagelist () {
	Personnagelist* plist = calloc(1, sizeof(Personnagelist));
	Personnage* p = calloc(1, sizeof(Personnage));
	if (plist == NULL || p == NULL) {
		exit(1);
	}
	p = NULL;
	plist->first = p;
	return plist;
}

//Ajouter un personnage à Personnagelist

void AddPersonnagelist (Personnagelist liste[], float hauteur, float largeur, float x_start, float y_start, float x_end, float y_end, float puissance_saut, int TouchDown, int TouchTop, int colorR, int colorG, int colorB) {
	Personnage* p = calloc(1, sizeof(Personnage));
	if (p == NULL || liste == NULL) {
		exit(1);
	}
	p->hauteur = hauteur;
	p->largeur = largeur;
	p->x_start = x_start;
	p->y_start = y_start;
	p->x_end = x_end;
	p->y_end = y_end;
	p->puissance_saut = puissance_saut;
	p->TouchDown = TouchDown;
	p->TouchTop = TouchTop;
	p->x_reset = x_start;
	p->y_reset = y_start;
	p->colorRtrue = colorR;
	p->colorGtrue = colorG;
	p->colorBtrue = colorB;
	p->colorR = colorR;
	p->colorG = colorG;
	p->colorB = colorB;
	p->largeur_color = largeur;
	p->next = liste->first;
	liste->first = p;
}


void supprimerPersonnagelist(Personnagelist* personnagelist){
		if(personnagelist==NULL){
	    return;
	  }
	  Personnage* actu = personnagelist->first;
		Personnage* temp;
	  while(actu!=NULL){
	    temp=actu->next;
	    free(actu);
	    actu=temp;
	  }
}


//Dessin du personnage

void dessinPersonnage (Personnagelist* Personnagelist){
	if (Personnagelist == NULL) {
		exit(1);
	}
	glLoadIdentity();
	dessinPersonnageOmbre(Personnagelist);
	Personnage* ActualPerso = Personnagelist->first;
	while (ActualPerso != NULL) {
	  	glBegin(GL_QUADS);
				glColor3ub(ActualPerso->colorR, ActualPerso->colorG, ActualPerso->colorB);
				glVertex2f((ActualPerso->x_start) - (ActualPerso->largeur_color)/2, (ActualPerso->y_start) + (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_start) + (ActualPerso->largeur_color)/2, (ActualPerso->y_start) + (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_start) + (ActualPerso->largeur_color)/2, (ActualPerso->y_start) - (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_start) - (ActualPerso->largeur_color)/2, (ActualPerso->y_start) - (ActualPerso->hauteur)/2);
	  	glEnd();
	  	glBegin(GL_LINE_LOOP);
	  	  glColor3ub(255, 255, 255);
				glVertex2f((ActualPerso->x_end) - (ActualPerso->largeur)/2, (ActualPerso->y_end) + (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_end) + (ActualPerso->largeur)/2, (ActualPerso->y_end) + (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_end) + (ActualPerso->largeur)/2, (ActualPerso->y_end) - (ActualPerso->hauteur)/2);
				glVertex2f((ActualPerso->x_end) - (ActualPerso->largeur)/2, (ActualPerso->y_end) - (ActualPerso->hauteur)/2);
	  	glEnd();
	  	ActualPerso = ActualPerso->next;
	}
}

void dessinPersonnageOmbre(Personnagelist* Personnagelist){
	if (Personnagelist == NULL) {
		exit(1);
	}
	glLoadIdentity(); 
	Personnage* ActualPerso = Personnagelist->first;
	while (ActualPerso != NULL) {
		glBegin(GL_QUADS);
	  	  glColor4f(0, 0, 0, 0.25);
				glVertex2f(((ActualPerso->x_start) - (ActualPerso->largeur_color)/2)-1, ((ActualPerso->y_start) + (ActualPerso->hauteur)/2)+1);
				glVertex2f(((ActualPerso->x_start) + (ActualPerso->largeur_color)/2)-1, ((ActualPerso->y_start) + (ActualPerso->hauteur)/2)+1);
				glVertex2f(((ActualPerso->x_start) + (ActualPerso->largeur_color)/2)-1, ((ActualPerso->y_start) - (ActualPerso->hauteur)/2)+1);
				glVertex2f(((ActualPerso->x_start) - (ActualPerso->largeur_color)/2)-1, ((ActualPerso->y_start) - (ActualPerso->hauteur)/2)+1);
	  	glEnd();
	  	ActualPerso = ActualPerso->next;
	}
}

void dessinPersonnageSelect(Personnage* ActualPerso){
	if (ActualPerso == NULL) {
		exit(1);
	}
	glLoadIdentity();
	glBegin(GL_TRIANGLES);
		glColor3ub(255, 255, 255);
		glVertex2f((ActualPerso->x_start) - 0.25, (ActualPerso->y_start) + (ActualPerso->hauteur)/2 + 1);
		glVertex2f((ActualPerso->x_start) + 0.25, (ActualPerso->y_start) + (ActualPerso->hauteur)/2 + 1);
		glVertex2f((ActualPerso->x_start), (ActualPerso->y_start) + (ActualPerso->hauteur)/2 + 0.5);
	glEnd();
}

void dessinPersonnageBarre(Personnagelist* Personnagelist, Personnage* PersoRepere, int windowWidth, int windowHeight, float* centreX, float* centreY){
	if (Personnagelist == NULL) {
		exit(1);
	}
	int decallage = 0;
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(-(windowWidth/2 +20 ), -(windowHeight/2 +20), 0);
	Personnage* ActualPerso = Personnagelist->first;
	while (ActualPerso != NULL) {
	  	glBegin(GL_QUADS);
			//glTranslatef(windowWidth/2 - 100, windowHeight/2 - 100, 1);
				glColor3ub(ActualPerso->colorR, ActualPerso->colorG, ActualPerso->colorB);
				glVertex2f(*centreX + 25 - decallage - 0.5, *centreY - 12 + 0.5);
				glVertex2f(*centreX + 25 - decallage + 0.5, *centreY - 12 + 0.5);
				glVertex2f(*centreX + 25 - decallage + 0.5, *centreY - 12 - 0.5);
				glVertex2f(*centreX + 25 - decallage - 0.5, *centreY - 12 - 0.5);
	  	glEnd();
			if(ActualPerso == PersoRepere){
				glBegin(GL_TRIANGLES);
					glColor3ub(255, 255, 255);
					glVertex2f(PersoRepere->x_start + (windowWidth/47) - decallage - 0.3, PersoRepere->y_start - (windowHeight/64) + 0.5 + 1);
					glVertex2f(PersoRepere->x_start + (windowWidth/47) - decallage + 0.3, PersoRepere->y_start - (windowHeight/64) + 0.5 + 1);
					glVertex2f(PersoRepere->x_start + (windowWidth/47) - decallage, PersoRepere->y_start - (windowHeight/64) + 0.5 + 0.5);
				glEnd();
			}
			decallage += 1;
	  	ActualPerso = ActualPerso->next;
	}
	//glTranslatef((windowWidth/2 +20), (windowHeight/2+20), 0);
}

Personnage* changePersonnage (Personnagelist* personnagelist, Personnage* ActualPerso){
	if (personnagelist == NULL) {
		exit(1);
	}

	if(ActualPerso->next == NULL){
		ActualPerso = personnagelist->first;
	}
	else{
		ActualPerso = ActualPerso->next;
	}

	return ActualPerso;
}

Personnage* resetAllPersonnage (Personnagelist* personnagelist){
	if (personnagelist == NULL) {
		exit(1);
	}
	Personnage* ActualPerso = personnagelist->first;

	while(ActualPerso != NULL){
		//ActualPerso->colorR = ActualPerso->colorRtrue;
		//ActualPerso->colorG = ActualPerso->colorGtrue;
		//ActualPerso->colorG = ActualPerso->colorBtrue;
		ActualPerso->x_start = ActualPerso->x_reset;
		ActualPerso->y_start = ActualPerso->y_reset;
		ActualPerso = ActualPerso->next;
	}

	return personnagelist->first;
}

int Target (Personnage* perso) {
  if ((perso->x_start - perso->x_end <=0.5) && (perso->x_start - perso->x_end >=0)) {
    if ((perso->y_start - perso->y_end <=0.5) && (perso->y_start - perso->y_end >=0)) {
      return 1;
    }
    else {
      return 0;
    }
  }
  if ((perso->x_end - perso->x_start <=0.5) && (perso->x_end - perso->x_start >=0)) {
    if ((perso->y_end - perso->y_start <=0.5) && (perso->y_end - perso->y_start >=0)) {
      return 1;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

int TargetAll (Personnagelist* Personnagelist) {
	if (Personnagelist == NULL) {
		exit(1);
	}
	Personnage* ActualPerso = Personnagelist->first;
	while(ActualPerso != NULL) {
		if (Target(ActualPerso) == 1) {
			ActualPerso = ActualPerso->next;
		}
		else {
			return 0;
		}
	}
	return 1;
}

void compressPersos (Personnagelist* Personnagelist) {
	if (Personnagelist == NULL) {
		exit(1);
	}
	Personnage* ActualPerso = Personnagelist->first;
	while(ActualPerso != NULL) {
		if (ActualPerso->largeur_color >= 0) {
			ActualPerso->largeur_color -= 0.01;
		}
		ActualPerso = ActualPerso->next;
	}
}
