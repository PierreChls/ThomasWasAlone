#ifndef MUSIC_H_
#define MUSIC_H_

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

void init_music();
Mix_Music* load_music_MP3(char* path, int volume);
Mix_Chunk* load_music_WAV(char* path, int volume);

#endif
