/**
 * @file Music.h
 *
 * Music's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <string>


/**
 * Music class. The class responsible for the game's music.
 */
class Music {

 private:

  /**
   * SDL's music type played by this class.
   */
  Mix_Music* music;

 public:

  /**
   * Music's empty constructor. Starts the member music as a
   * <code>nullptr</code>.
   */
  Music();
  /**
   * Music's constructor with a song. Opens the song already.
   *
   * @param file - Song's directory and name to be played.
   */
  explicit Music(std::string file);
  /**
   * Music's destructor.
   */
  ~Music();

  /**
   * Function that plays opened song.
   *
   * @param times Amount of times the song is supposed to be played. -1 for
   * infinite loop.
   */
  void Play(int times = -1);
  /**
   * Function that stops playing song.
   *
   * @param msToStop Time, in milliseconds, requested for the song to stop
   * through fading out. 0 for immediate stop.
   */
  void Stop(int msToStop = 1500);
  /**
   * Function that opens the song to be played. Does not play, only opens.
   *
   * @param file Song's directory and name to be played.
   */
  void Open(std::string file);
  /**
   * Checks if Music's member music is null.
   *
   * @return False if null.
   */
  bool IsOpen();

};
#endif /* MUSIC_H */
