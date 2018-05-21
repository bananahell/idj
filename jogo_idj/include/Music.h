#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <memory>
#include <string>


class Music {

 public:

  Music();
  Music(std::string file);
  ~Music();

  void Open(std::string file);
  void Play(int times = -1);
  void Stop(int msToStop = 1500);
  bool IsOpen();
  bool IsPlaying();

 private:

  std::shared_ptr<Mix_Music> music;

};
#endif /* MUSIC_H */
