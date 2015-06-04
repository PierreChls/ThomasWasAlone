#include "texture.h"

GLuint load_Texture(char* path){

  glEnable(GL_BLEND); //Permet l'utilsation de l'alpha dans glColor4f
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  SDL_Surface* image = IMG_Load(path);
  if(image == NULL) {
      fprintf(stderr, "Impossible de charger l'image\n");
      return EXIT_FAILURE;
  }

  GLuint textureId;

  glGenTextures(1, &textureId);
  glBindTexture(GL_TEXTURE_2D, textureId);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  GLenum format;
  switch(image->format->BytesPerPixel) {
      case 1:
          format = GL_RED;
          break;
      case 3:
          format = GL_RGB;
          break;
      case 4:
          format = GL_RGBA;
          break;
      default:
          fprintf(stderr, "Format des pixels de l'image non pris en charge\n");
          return EXIT_FAILURE;
  }
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);

  glBindTexture(GL_TEXTURE_2D, 0);

  SDL_FreeSurface(image);

  return textureId;
}

void dessinCarre(int cote) {
  glColor4f(1, 1, 1, 0.03);
  glBegin(GL_QUADS);
    glVertex2f(-cote, cote);
    glVertex2f(-cote, -cote);
    glVertex2f(cote, -cote);
    glVertex2f(cote, cote);
  glEnd();
}

void move_texture(GLuint* texture, float** positionparallax, int brume){
  if(brume == 0) {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, (*texture) );
  glLoadIdentity();
  glTranslatef(( (**positionparallax) * 2)-120, 0, 1);
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1);

    glTexCoord2f(0, 1);
    glVertex2f(-60, -100);

    glTexCoord2f(1, 1);
    glVertex2f(400, -100);

    glTexCoord2f(1, 0);
    glVertex2f(400, 160);

    glTexCoord2f(0, 0);
    glVertex2f(-60, 160);
  glEnd(); 
  }
  if(brume == 1) {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, (*texture) );
  glLoadIdentity();
  glTranslatef(( (**positionparallax) * 2)-120, 0, 1);
  glBegin(GL_QUADS);
    glColor3f(1, 1, 1);

    glTexCoord2f(0, 1);
    glVertex2f(-60, -20);

    glTexCoord2f(1, 1);
    glVertex2f(400, -20);

    glTexCoord2f(1, 0);
    glVertex2f(400, -5);

    glTexCoord2f(0, 0);
    glVertex2f(-60, -5);
  glEnd(); 
  }


}

void move_texture_menuLvl(GLuint* texture, float x1, float x2, float y1, float y2){

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, *texture);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glBegin(GL_QUADS);

  glColor3f(1, 1, 1);
  glTexCoord2f(0, 1);
  glVertex2f(x1, y1);

  glTexCoord2f(1, 1);
  glVertex2f(x2, y1);

  glTexCoord2f(1, 0);
  glVertex2f(x2, y2);

  glTexCoord2f(0, 0);
  glVertex2f(x1, y2);

  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);
}

void selector() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void move_texture_menu(GLuint* texture_menu, float* rotation1){

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, *texture_menu);
  glBegin(GL_QUADS);

  glColor3f(1, 1, 1);

  glTexCoord2f(0, 1);
  glVertex2f(-1, -1);

  glTexCoord2f(1, 1);
  glVertex2f(1, -1);

  glTexCoord2f(1, 0);
  glVertex2f(1, 1);

  glTexCoord2f(0, 0);
  glVertex2f(-1, 1);

  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_TEXTURE_2D);

  glEnable(GL_BLEND); //Permet l'utilsation de l'alpha dans glColor4f
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glLoadIdentity();
  glScalef(0.1,0.16,0.0);
  glTranslatef(-10, -5, 1);
  glColor4f(1, 0, 0, 0.7);
  glRotatef((*rotation1)/2, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.1,0.16,0.0);
  glTranslatef(-7, -4.5, 1);
  glColor4f(1, 0, 0, 0.7);
  glRotatef(-(*rotation1), 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.1,0.16,0.0);
  glTranslatef(-8, -5.5, 1);
  glColor4f(0.1, 0.5, 0, 0.7);
  glRotatef((*rotation1), 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.1,0.16,0.0);
  glTranslatef(-8.5, -3.5, 1);
  glColor4f(1, 1, 0, 0.7);
  glRotatef(-(*rotation1)/2, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.1,0.16,0.0);
  glTranslatef(-8, -4, 1);
  glColor4f(0, 0.3, 0.6, 0.7);
  glRotatef(-(*rotation1)/3, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.08,0.14,0.0);
  glTranslatef(-7, -4, 1);
  glColor4f(0, 0.3, 0.6, 0.7);
  glRotatef(-(*rotation1)/3, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.07,0.13,0.0);
  glTranslatef(-9.5, -3.5, 1);
  glColor4f(0.1, 0.5, 0, 0.7);
  glRotatef((*rotation1)/4, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.06,0.12,0.0);
  glTranslatef(-9.5, -2.5, 1);
  glColor4f(1, 1, 0, 0.7);
  glRotatef(-(*rotation1)/4, 0, 0, 1);
  dessinCarre2();

  glLoadIdentity();
  glScalef(0.05,0.08,0.0);
  glTranslatef(-10, -2.5, 1);
  glColor4f(1, 0, 0, 0.7);
  glRotatef((*rotation1)/5, 0, 0, 1);
  dessinCarre2();
}
