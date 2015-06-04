#include "music.h"

void init_music(){
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
  {
   printf("%s", Mix_GetError());
  }
}

Mix_Music* load_music_MP3(char* path, int volume){

  Mix_Music *musique; //Création du pointeur de type Mix_Music
  musique = Mix_LoadMUS(path); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

  //on alloue un nombre de canaux
  Mix_AllocateChannels(1);
  //On gère le son du cannal 1
  Mix_Volume(1, MIX_MAX_VOLUME/volume);

  return musique;
}

Mix_Chunk* load_music_WAV(char* path, int volume){
  Mix_Chunk *son;
  son = Mix_LoadWAV(path);
  Mix_VolumeChunk(son, MIX_MAX_VOLUME/volume);
  return son;
}
