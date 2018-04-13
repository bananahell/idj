/**
 * @file TileMap.h
 *
 * TileMap's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Component.h"
#include "GameObject.h"
#include "TileSet.h"

#include <string>
#include <vector>


/**
 * TileMap class. Class that holds the sound a game's object makes.
 */
class TileMap : public Component {

 public:

  /**
   * TileMap's constructor with file's name. Calls the first constructor and Open.
   */
  TileMap(GameObject& associated, std::string file, TileSet* tileSet);

  /**
   * Function that plays opened song.
   *
   * @param times - Times wanted for the sound to play.
   */
  void Load(std::string file);
  /**
   * Function that stops opened song.
   */
  void SetTileSet(TileSet* tileSet);
  /**
   * Function that opens a song by its file's name.
   *
   * @param file - File's directory and name.
   */
  int& At(int x, int y, int z = 0);
  /**
   * Function that checks if the sound is open.
   *
   * @return True if sound is open.
   */
  void Render();
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
  /**
   * Function called in State's Render to Render the component.
   */
  int GetWidth();
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is TileMap.
   */
  int GetHeight();
  /**
   * Function that checks if the sound is currently playing.
   *
   * @return True if sound is playing.
   */
  int GetDepth();
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  void Update(float dt);
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is TileMap.
   */
  bool Is(std::string type);

 private:

  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  std::vector<int> tileMatrix;
  /**
   * Channel used for this sound.
   */
  TileSet* tileSet;
  /**
   * Channel used for this sound.
   */
  int mapWidth;
  /**
   * Channel used for this sound.
   */
  int mapHeight;
  /**
   * Channel used for this sound.
   */
  int mapDepth;

};
#endif /* TILEMAP_H */
