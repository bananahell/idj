/**
 * @file TileSet.h
 *
 * TileSet's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"

#include <string>


/**
 * TileSet class. Class that holds the tile set clipped from an image to be
 * shown in a tile map.
 */
class TileSet {

 public:

  /**
   * TileSet's constructor.
   *
   * @param associated - Game object to which it is associated.
   * @param tileWidth - Width of the desired tile.
   * @param tileHeight - Height of the desired tile.
   * @param file - Directory and name of the image that holds the tiles.
   */
  TileSet(GameObject& associated, std::string file, int tileWidth, int tileHeight);
  ~TileSet();

  /**
   * Function that renders one tile.
   *
   * @param index - Value of tile.
   * @param x - Horizontal position of tile.
   * @param y - Vertical position of tile.
   */
  void RenderTile(int index, int x, int y);
  /**
   * Function that returns the private tile's width.
   *
   * @return Width of the tile.
   */
  int GetTileWidth();
  /**
   * Function that returns the private tile's height.
   *
   * @return Height of the tile.
   */
  int GetTileHeight();

 private:

  /**
   * Texture that renders the tile.
   */
  Sprite tileSet;
  /**
   * How many of this tile fit horizontally.
   */
  int rows;
  /**
   * How many of this tile fit vetically.
   */
  int columns;
  /**
   * Tile's width.
   */
  int tileWidth;
  /**
   * Tile's height.
   */
  int tileHeight;

};
#endif /* TILESET_H */
