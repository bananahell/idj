/**
 * @file TileSet.cpp
 *
 * Game's sounds manager. They are the game's objects' sound components.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "TileSet.h"

#include "GameObject.h"


TileSet::TileSet(GameObject& associated,
                 int tileWidth,
                 int tileHeight,
                 std::string file) :
                tileSet(Sprite(associated, file)) {

  TileSet::tileWidth = tileWidth;
  TileSet::tileHeight = tileHeight;

  TileSet::columns = TileSet::tileSet.GetWidth() / TileSet::tileWidth;
  TileSet::rows = TileSet::tileSet.GetHeight() / TileSet::tileHeight;

}

void TileSet::RenderTile(unsigned int index, float x, float y) {

  if (index < TileSet::columns * TileSet::rows) {
    TileSet::tileSet.SetClip(TileSet::tileWidth * (index % TileSet::columns),
                             TileSet::tileHeight * (index / TileSet::columns),
                             TileSet::tileWidth,
                             TileSet::tileHeight);
    TileSet::tileSet.Render(x, y);
  }

}

int TileSet::GetTileWidth() {

  return TileSet::tileWidth;

}

int TileSet::GetTileHeight() {

  return TileSet::tileHeight;

}
