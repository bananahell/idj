#include "Text.h"

#include "Camera.h"
#include "Game.h"
#include "Resources.h"


Text::Text(GameObject& associated) : Component(associated), font(nullptr), fontFile(""), text("") {

  Text::texture = nullptr;
  Text::fontSize = 0;
  Text::color = SDL_Color {};
  Text::style = SOLID;

}

Text::Text(GameObject& associated, std::string fontFile, int fontSize, std::string text, SDL_Color color, TextStyle style) : Text(associated) {

  Text::fontFile = fontFile;
  Text::fontSize = fontSize;
  Text::text = text;
  Text::color = color;
  Text::style = style;
  Open();

}

Text::~Text() {

  if (Text::texture) {
    SDL_DestroyTexture(Text::texture);
  }
  Text::texture = nullptr;
  Text::font = nullptr;

}

void Text::RemakeTexture() {

  if (IsOpen()) {
    SDL_DestroyTexture(Text::texture);
  }

  SDL_Surface* surface = nullptr;
  if (Text::style == SOLID) {
    surface = TTF_RenderText_Solid(font.get(), text.c_str(), color);
  }
  if (Text::style == SHADED) {
    surface = TTF_RenderText_Shaded(font.get(), text.c_str(), color, SDL_Color {});
  }
  if (Text::style == BLENDED) {
    surface = TTF_RenderText_Blended(font.get(), text.c_str(), color);
  }
  Text::texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);
  SDL_FreeSurface(surface);

  if (!IsOpen()) {
    SDL_Log("Unable to load texture: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  int w, h;
  SDL_QueryTexture(Text::texture, nullptr, nullptr, &w, &h);
  Text::associated.box.SetSize(Vec2(w, h));

}

void Text::Open() {

  Text::font = Resources::GetFont(Text::fontFile, Text::fontSize);
  RemakeTexture();

}

void Text::SetFontFile(std::string fontFile) {

  Text::fontFile = fontFile;
  Open();

}

void Text::SetFontSize(int fontSize) {

  Text::fontSize = fontSize;
  Open();

}

void Text::SetText(std::string text) {

  Text::text = text;
  RemakeTexture();

}

void Text::SetColor(SDL_Color color) {

  Text::color = color;
  RemakeTexture();

}

void Text::SetStyle(TextStyle style) {

  Text::style = style;
  RemakeTexture();

}

void Text::Update(float dt) {


}

void Text::Render() {

  SDL_Rect clipRect = SDL_Rect {0, 0, (int)associated.box.w, (int)associated.box.h};
  SDL_Rect dstRect = clipRect;
  dstRect.x = (int)associated.box.x-Camera::pos.x;
  dstRect.y = (int)associated.box.y-Camera::pos.y;
  SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect, associated.rotation, nullptr, SDL_FLIP_NONE);

}

bool Text::Is(std::string type) {

  if (type.compare("Text") == 0) {
    return true;
  }
  return false;

}

bool Text::IsOpen() {

  if (Text::texture == nullptr) {
    return false;
  }
  return true;

}
