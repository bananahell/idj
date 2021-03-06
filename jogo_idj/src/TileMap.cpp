/**
 * @file TileMap.cpp
 *
 * Game's tile map. With the cut tiles, this class determines where the tile
 * should be displayed.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "TileMap.h"

#include <fstream>


TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) : Component(associated) {

  TileMap::Load(file);
  TileMap::tileSet = tileSet;

}

void TileMap::Load(std::string file) {

  std::ifstream fileContent(file, std::ifstream::in);
  if (!fileContent.is_open()) {
    exit(EXIT_FAILURE); // TODO exits, but how does it explain it?
  }

  std::string lineString;

  int indexValue = 0;
  int nextNum = 0;
  /* Getting the first line, which will always be the sizes of the map. */
  getline(fileContent, lineString);
  for (unsigned int i = 0; i < lineString.size(); i++) {
    if (lineString.at(i) == ',') {
      switch (nextNum) {
        case 0:
          TileMap::mapWidth = indexValue;
          break;
        case 1:
          TileMap::mapHeight = indexValue;
          break;
        case 2:
          TileMap::mapDepth = indexValue;
          break;
      }
      indexValue = 0;
      nextNum++;
    } else {
      indexValue *= 10;
      indexValue += lineString.at(i) - '0';
    }
  }

  /* Getting the rest of the file, where the actual map really is. */
  int tileValue = 0;
  while (getline(fileContent, lineString)) {
    for (unsigned int i = 0; i < lineString.size(); i++) {
      if (lineString.at(i) >= '0' && lineString.at(i) <= '9') {
        tileValue *= 10;
        tileValue += lineString.at(i) - '0';
      } else if (lineString.at(i) == ',') {
        /* Storing it in the vector minus one. */
        TileMap::tileMatrix.push_back(tileValue - 1);
        tileValue = 0;
      } else {
        tileValue = 0;
      }
    }
  }

  fileContent.close();

}

void TileMap::SetTileSet(TileSet* tileSet) {

  TileMap::tileSet = tileSet;

}

int TileMap::At(int x, int y, int z) {

  /* Calculating the coordinates into the vector. */
  return TileMap::tileMatrix.at(x +
                                (y * TileMap::mapWidth) +
                                (z * TileMap::mapWidth * TileMap::mapHeight));

}

void TileMap::Render() {


}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {

  /* Rendering each tile of the layer. */
  for (int j = 0; j < TileMap::mapHeight; j++) {
    for (int i = 0; i < TileMap::mapWidth; i++) {
      TileMap::tileSet->RenderTile(TileMap::At(i, j, layer),
                                   i * TileMap::tileSet->GetTileWidth() - cameraX,
                                   j * TileMap::tileSet->GetTileHeight() - cameraY);
    }
  }

}

int TileMap::GetWidth() {

  return TileMap::mapWidth;

}

int TileMap::GetHeight() {

  return TileMap::mapHeight;

}

int TileMap::GetDepth() {

  return TileMap::mapDepth;

}

void TileMap::Update(float dt) {


}

bool TileMap::Is(std::string type) {

  if (type.compare("TileMap") == 0) {
    return true;
  }
  return false;

}

TileMap::~TileMap() {

  tileSet = nullptr;
  tileMatrix.clear();

}
