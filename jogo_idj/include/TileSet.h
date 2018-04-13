/**
 * @file TileSet.h
 *
 * TileSet's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef TILESET_H
#define TILESET_H

#include "GameObject.h"
#include "Sprite.h"

#include <string>


/**
 * TileSet class. Class that holds the sound a game's object makes.
 */
class TileSet {

 public:

  /**
   * TileSet's constructor with file's name. Calls the first constructor and Open.
   */
  TileSet(GameObject& associated,
          int tileWidth,
          int tileHeight,
          std::string file);

  /**
   * Function that plays opened song.
   *
   * @param times - Times wanted for the sound to play.
   */
  void RenderTile(unsigned int index, float x, float y); // TODO unsigned INT, né?
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is TileSet.
   */
  int GetTileWidth();
  /**
   * Function that checks if the sound is currently playing.
   *
   * @return True if sound is playing.
   */
  int GetTileHeight();

 private:

  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  Sprite tileSet;
  /**
   * Channel used for this sound.
   */
  int rows;
  /**
   * Channel used for this sound.
   */
  int columns;
  /**
   * Channel used for this sound.
   */
  int tileWidth;
  /**
   * Channel used for this sound.
   */
  int tileHeight;

};
#endif /* TILESET_H */
