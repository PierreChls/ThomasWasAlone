#include <SDL/SDL.h>
#ifdef __APPLE__
  //MACOS
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#elif __unix__
  //UNIX
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif __linux__
  //LINUX
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif __MINGW32__
  //WINDOWS
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#include "menu.h"
#include "block.h"
#include "personnage.h"
#include "collision.h"
#include "window.h"
#include "camera.h"
#include "texture.h"
#include "music.h"
#include "niveau.h"


int main(int argc, char** argv) {

  if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
    return EXIT_FAILURE;
  }

  unsigned int windowWidth  = 1200;
  unsigned int windowHeight = 700;
  int booleanPressed = 0;
  int booleanChangePersonnage = 0;
  int reset = 0;
  int jump = 0;
  int verif = 1;
  int verif2 = 0;
  int verif3 = 0;
  float pesanteur = 0;
  float acceleration = 0;
  float positionparallax = 0;
  float positionparallaxfixed = 0;
  float movetop = 0;
  int verifTop = 0;
  int parallax_move = 0;
  int son_bottom = 0;
  int son_top = 0;
  int verifsound3 = 0;
  float distance_x = 0, distance_y = 0;
  float camera_center_x = 0, camera_center_y = 0;
  int testwin = 0;
  int cpt_finish_level = 0;
  float rotation_menu = 0;
  float rotateCarre = 0;
  int actif_menu = 1;
  int actif_win = 0;
  int cpt_select_menu = 1;
  int menu_load = 0;
  int cpt = 0;
  int sheet = 0;

  setVideoMode(windowWidth, windowHeight);
  SDL_WM_SetCaption("Thomas Was Not Alone", NULL);

  Personnagelist* personnagelist;
  Blocklist* blocklist;
  Personnage* perso;

  GLuint texture_menu = load_Texture("img/menu2.jpg");
  GLuint texture_front = load_Texture("img/texture1.png");
  GLuint texture_back = load_Texture("img/texture2.png");
  GLuint texture_brume = load_Texture("img/brume.png");
  GLuint texture_lvl1 = load_Texture("img/lvl1.png");
  GLuint texture_lvl2 = load_Texture("img/lvl2.png");
  GLuint texture_lvl3 = load_Texture("img/lvl3.png");
  GLuint texture_gradient = load_Texture("img/texture_ombre.png");
  GLuint texture_win = load_Texture("img/win.png");

  init_music();
  Mix_Music* music_game = load_music_MP3("music/gamse.mp3", 2);
  Mix_Chunk* son_jump = load_music_WAV("music/jump.wav", 2);
  Mix_Chunk* son_ground = load_music_WAV("music/ground.wav", 3);
  Mix_Chunk* son_win = load_music_WAV("music/win.wav", 1);

  int loop = 1;
  while(loop) {
    /* temps au début de la boucle */
    Uint32 startTime = SDL_GetTicks();

    if(actif_win == 1){
      move_texture_win(&texture_win);
    }

    if(actif_menu == 1){
      move_texture_menu(&texture_menu, &rotation_menu);
      selector(-0.05, 0.75, -0.25, 0, cpt_select_menu);
      move_texture_menuLvl(&texture_lvl1, 0, 0.7, -0.2, -0.05);//texture, x1, x2, y1, y2
      move_texture_menuLvl(&texture_lvl2, 0, 0.7, -0.5, -0.35);//texture, x1, x2, y1, y2
      move_texture_menuLvl(&texture_lvl3, 0, 0.7, -0.8, -0.65);//texture, x1, x2, y1, y2
      rotation_menu += 0.1;
    }
    else{

      if(sheet==1) {
        supprimerPersonnagelist(personnagelist);
        supprimerBlocklist(blocklist);
        personnagelist = InitialiserPersonnagelist();
        blocklist = InitialiserBlocklist();
        loadNiveau(cpt_select_menu, personnagelist, blocklist);
        perso = personnagelist->first;
        sheet = 0;
      }

      if(menu_load == 0){
        personnagelist = InitialiserPersonnagelist();
        blocklist = InitialiserBlocklist();
        loadNiveau(cpt_select_menu, personnagelist, blocklist);
        perso = personnagelist->first;
        menu_load = 1;
      }

      if(testwin==0 && actif_win == 0 && evolution_niveau(blocklist, personnagelist, &perso, windowWidth, windowHeight, &booleanPressed, &booleanChangePersonnage, &reset, &jump, &verif, &verif2, &verif3, &pesanteur, &acceleration, &positionparallax, &movetop, &verifTop, &parallax_move, &son_bottom, &verifsound3, &distance_x, &distance_y, &camera_center_x, &camera_center_y, son_win, son_ground, son_jump, texture_front, texture_back, &positionparallaxfixed, &cpt_finish_level, &son_top, texture_brume, texture_gradient, &rotateCarre)){
        testwin=1;
      }

      if(testwin == 1){
        cpt_select_menu++;
        supprimerPersonnagelist(personnagelist);
        supprimerBlocklist(blocklist);
        if(cpt_select_menu != 4) {
          personnagelist = InitialiserPersonnagelist();
          blocklist = InitialiserBlocklist();
          loadNiveau(cpt_select_menu, personnagelist, blocklist);
          perso = personnagelist->first;
        }
        else {
          actif_win = 1;
        }
      testwin=0;
      }
    }

      if(cpt == 0) {
        actif_menu = 0;
        cpt++;
      }
      else if(cpt == 1) {
        actif_menu = 1;
        cpt++;
      }

    SDL_GL_SwapBuffers();

    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_QUIT) {
        loop = 0;
        break;
      }
      switch(e.type) {

        case SDL_VIDEORESIZE:
          windowWidth  = e.resize.w;
          windowHeight = e.resize.h;
          setVideoModeResize(perso, windowWidth, windowHeight);
          break;

        case SDL_KEYUP :
          switch(e.key.keysym.sym){

            case SDLK_RIGHT :
              booleanPressed = 0;
              acceleration = 0;
            break;

            case SDLK_LEFT :
              booleanPressed = 0;
              acceleration = 0;
            break;

            default : break;
          }
          break;

        case SDL_KEYDOWN:
          switch(e.key.keysym.sym){

            case SDLK_RETURN :
              if(actif_menu == 1) {
                actif_menu = 0;
                sheet = 1;
                reshapeResize(perso, windowWidth, windowHeight);
              }
            break;

             case SDLK_ESCAPE :
              if(actif_menu == 0){
                actif_menu = 1;
              }
              else if(actif_menu == 1){
                actif_menu = 0;
                reshapeResize(perso, windowWidth, windowHeight);
              }
            break;

            case SDLK_RIGHT :
              booleanPressed = 1;
            break;

            case SDLK_LEFT :
              booleanPressed = 2;
            break;

            case SDLK_UP :
              if(actif_menu == 1){
                if(cpt_select_menu > 1 ){
                  cpt_select_menu--;
                }
              }
              else{
                if (verif == 1) {
                  pesanteur = -0.08;
                  jump = 1;
                }
              }
            break;

            case SDLK_DOWN :
              if(actif_menu == 1){
                if(cpt_select_menu < 3 ){
                  cpt_select_menu++;
                }
              }
            break;

            case 'r' :
                reset = 1;
            break;
            case 'q' :
              loop = 0;
            break;
            case 'c' :
                booleanChangePersonnage = 1;
            break;

            default : break;
          }
          break;

        default:
          break;
      }
    }

    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    if(elapsedTime < FRAMERATE_MILLISECONDS) {
      SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
    }
  }

  glDeleteTextures(1, &texture_menu);
  glDeleteTextures(1, &texture_front);
  glDeleteTextures(1, &texture_back);

  Mix_FreeMusic(music_game);
  Mix_FreeChunk(son_jump);
  Mix_FreeChunk(son_ground);
  Mix_FreeChunk(son_win);
  Mix_CloseAudio();
  SDL_Quit();

  return EXIT_SUCCESS;
}
