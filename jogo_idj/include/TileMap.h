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
 * TileMap class. Class that holds the map in which the tiles must be rendered.
 */
class TileMap : public Component {

 public:

  /**
   * TileMap's constructor.
   *
   * @param associated - Game object to which this tile map is associated.
   * @param file - Directory and name of the text map file.
   * @param tileSet - Set of tiles to be used in this map.
   */
  TileMap(GameObject& associated, std::string file, TileSet* tileSet);

  /**
   * Function that gets the map's coordinates' values.
   *
   * @param file - Directory and name of the text map file.
   */
  void Load(std::string file);
  /**
   * Sets the tile set.
   *
   * @param tileSet - Tile set to be set.
   */
  void SetTileSet(TileSet* tileSet);
  /**
   * Function that finds the value of the tile in the map in these coordinates.
   * Since the tiles' matrix is actually a vector, this function is needed to
   * calculate the position in the vector.
   *
   * @param x - Horizontal coordinate.
   * @param y - Vertical coordinate.
   * @param z - Depth coordinate.
   *
   * @return Value in given coordinate.
   */
  int& At(int x, int y, int z = 0);
  /**
   * Function called by the state's Render to render the map tile.
   */
  void Render();
  /**
   * Function that renders one of the map's depth layers.
   *
   * @param layer - Depth layer to be rendered.
   * @param cameraX - Horizontal position of camera.
   * @param cameraY - Vertical position of camera.
   */
  void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
  /**
   * Gets the private width.
   *
   * @return Width of the map.
   */
  int GetWidth();
  /**
   * Gets the private height.
   *
   * @return Height of the map.
   */
  int GetHeight();
  /**
   * Gets the private depth.
   *
   * @return Depth of the map.
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
   * Vector of tile values.
   */
  std::vector<int> tileMatrix;
  /**
   * Channel used for this sound.
   */
  TileSet* tileSet;
  /**
   * Map's width.
   */
  int mapWidth;
  /**
   * Map's height.
   */
  int mapHeight;
  /**
   * Map's depth
   */
  int mapDepth;

};
#endif /* TILEMAP_H */
