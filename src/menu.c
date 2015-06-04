#include "menu.h"

void dessinCarre(){
  glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
  glEnd();
}
