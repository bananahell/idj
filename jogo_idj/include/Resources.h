/**
 * @file Resources.h
 *
 * Resources's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef RESOURCES_H
#define RESOURCES_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_TTF
#include "SDL_include.h"

#include <memory>
#include <string>
#include <unordered_map>


/**
 * Resources class. Class that holds the game's assets. This class prevents the
 * game from loading a thing multiple times, using too much processing. Instead,
 * it holds the resources already made in a hash map and gives access to it to
 * whoever asks for it.
 */
class Resources {

 public:

  /**
   * Function that loads the image.
   *
   * @param file - Image's directory and name to be loaded.
   */
  static std::shared_ptr<SDL_Texture> GetImage(std::string file);
  /**
   * Function that clears all images.
   */
  static void ClearImages();
  /**
   * Function that loads the music.
   *
   * @param file - Music's directory and name to be loaded.
   */
  static std::shared_ptr<Mix_Music> GetMusic(std::string file);
  /**
   * Function that clears all musics.
   */
  static void ClearMusics();
  /**
   * Function that loads the sound.
   *
   * @param file - Sound's directory and name to be loaded.
   */
  static std::shared_ptr<Mix_Chunk> GetSound(std::string file);
  /**
   * Function that clears all sounds.
   */
  static void ClearSounds();
  static std::shared_ptr<TTF_Font> GetFont(std::string fontFile, int fontSize);
  static void ClearFonts();

 private:

  /**
   * Hash map of textures.
   */
  static std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> imageTable;
  /**
   * Hash map of musics.
   */
  static std::unordered_map<std::string, std::shared_ptr<Mix_Music>> musicTable;
  /**
   * Hash map of sounds.
   */
  static std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> soundTable;
  static std::unordered_map<std::string, std::shared_ptr<TTF_Font>> fontTable;

};
#endif /* RESOURCES_H */
