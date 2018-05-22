/**
 * @file TileSet.cpp
 *
 * Game's tile sets. These will be put into the map of tiles in TileMap.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "TileSet.h"


TileSet::TileSet(GameObject& associated, std::string file, int tileWidth, int tileHeight) : tileSet(associated, file) {

  TileSet::tileWidth = tileWidth;
  TileSet::tileHeight = tileHeight;

  TileSet::columns = TileSet::tileSet.GetWidth()/TileSet::tileWidth;
  TileSet::rows = TileSet::tileSet.GetHeight()/TileSet::tileHeight;

}

TileSet::~TileSet() {


}

void TileSet::RenderTile(int index, int x, int y) {

  if (index > -1 && index < rows*columns) {
    /* Setting the clip. */
    TileSet::tileSet.SetClip(TileSet::tileWidth * (index % TileSet::columns),
                             TileSet::tileHeight * (index / TileSet::columns),
                             TileSet::tileWidth,
                             TileSet::tileHeight);
    /* Rendering the clip. */
    TileSet::tileSet.Render(x, y);
  }

}

int TileSet::GetTileWidth() {

  return TileSet::tileWidth;

}

int TileSet::GetTileHeight() {

  return TileSet::tileHeight;

}
