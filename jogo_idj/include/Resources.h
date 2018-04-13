/**
 * @file Resources.h
 *
 * Resources's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef RESOURCES_H
#define RESOURCES_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <string>
#include <unordered_map>


/**
 * Resources class. Class that holds the sound a game's object makes.
 */
class Resources {

 public:

  /**
   * Function that plays opened song.
   *
   * @param times - Times wanted for the sound to play.
   */
  static SDL_Texture* GetImage(std::string file);
  /**
   * Function that stops opened song.
   */
  static void ClearImages();
  /**
   * Function that opens a song by its file's name.
   *
   * @param file - File's directory and name.
   */
  static Mix_Music* GetMusic(std::string file);
  /**
   * Function that checks if the sound is open.
   *
   * @return True if sound is open.
   */
  static void ClearMusics();
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  static Mix_Chunk* GetSound(std::string file);
  /**
   * Function called in State's Render to Render the component.
   */
  static void ClearSounds();

 private:

  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  static std::unordered_map<std::string, SDL_Texture*> imageTable;
  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  static std::unordered_map<std::string, Mix_Music*> musicTable;
  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  static std::unordered_map<std::string, Mix_Chunk*> soundTable;

};
#endif /* RESOURCES_H */
