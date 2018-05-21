#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"

#include <string>


class TileSet {

 public:

  TileSet(GameObject& associated, std::string file, int tileWidth, int tileHeight);
  ~TileSet();

  void RenderTile(int index, int x, int y);
  int GetTileWidth();
  int GetTileHeight();

 private:

  Sprite tileSet;
  int tileWidth;
  int tileHeight;
  int rows;
  int columns;

};
#endif /* TILESET_H */
