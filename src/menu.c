#include "menu.h"

void dessinCarre2(){
  glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
  glEnd();
}
