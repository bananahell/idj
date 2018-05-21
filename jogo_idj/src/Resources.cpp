#include "Resources.h"

#include "Game.h"


std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Resources::imageTable;
std::unordered_map<std::string, std::shared_ptr<Mix_Music>> Resources::musicTable;
std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> Resources::soundTable;
std::unordered_map<std::string, std::shared_ptr<TTF_Font>> Resources::fontTable;

std::shared_ptr<SDL_Texture> Resources::GetImage(std::string file) {

  if (!Resources::imageTable.count(file)) {
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    Resources::imageTable.emplace(file, std::shared_ptr<SDL_Texture>(texture, [](SDL_Texture* p) { SDL_DestroyTexture(p); }));
  }
  if (!Resources::imageTable.at(file)) {
    printf("IMG_LoadTexture failed: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  return Resources::imageTable.at(file);

}

void Resources::ClearImages() {

  Resources::imageTable.clear();

}

std::shared_ptr<Mix_Music> Resources::GetMusic(std::string file) {

  if (!Resources::musicTable.count(file)) {
    Mix_Music* music = Mix_LoadMUS(file.c_str());
    Resources::musicTable.emplace(file, std::shared_ptr<Mix_Music>(music, [](Mix_Music* p) { Mix_FreeMusic(p); }));
  }
  if (Resources::musicTable.at(file) == nullptr) {
    printf("Mix_LoadMUS failed: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  return Resources::musicTable.at(file);

}

void Resources::ClearMusics() {

  Resources::musicTable.clear();

}

std::shared_ptr<Mix_Chunk> Resources::GetSound(std::string file) {

  if (!Resources::soundTable.count(file)) {
    Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());
    Resources::soundTable.emplace(file, std::shared_ptr<Mix_Chunk>(chunk, [](Mix_Chunk* p) { Mix_FreeChunk(p); }));
  }
  if (Resources::soundTable.at(file) == nullptr) {
    printf("Mix_LoadWAV failed: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  return Resources::soundTable.at(file);

}

void Resources::ClearSounds() {

  Resources::soundTable.clear();

}

std::shared_ptr<TTF_Font> Resources::GetFont(std::string fontFile, int fontSize) {

  char size[3];
  sprintf(size, "%d", fontSize);
  std::string key = fontFile+size;
  if (!Resources::fontTable.count(key)) {
    TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
    fontTable.emplace(key, std::shared_ptr<TTF_Font>(font, [](TTF_Font* p) { TTF_CloseFont(p); }));
  }
  if (Resources::fontTable.at(key) == nullptr) {
    printf("TTF_OpenFont failed: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  return Resources::fontTable.at(key);

}

void Resources::ClearFonts() {

  Resources::fontTable.clear();

}
