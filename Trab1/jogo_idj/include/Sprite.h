/**
 * @file Sprite.h
 * 
 * Sprite's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include <string>


/**
 * Sprite class. The class responsible for the game's textures and images.
 */
class Sprite {

 private:

  /**
   * Image/texture to be displayed.
   */
  SDL_Texture* texture;
  /**
   * Texture's width.
   */
  int width;
  /**
   * Texture's height.
   */
  int height;
  /**
   * Texture clipped rectangle supposed to be rendered.
   */
  SDL_Rect clipRect;

 public:

  /**
   * Sprite's empty constructor. Sets texture to <code>nullptr</code>.
   */
  Sprite();
  /**
   * Sprite's constructor with a texture. Opens the texture already.
   *
   * @param file Texture's directory and name to be rendered.
   */
  explicit Sprite(std::string file);
  /**
   * Sprite's destructor.
   */
  ~Sprite();

  /**
   * Function that opens the texture to be rendered. Does not renders, only
   opens.
   *
   * @param file Texture's directory and name to be rendered.
   */
  void Open(std::string file);
  /**
   * Sets the clipped portion of the texture supposed to be displayed.
   *
   * @param x Top left horizontal coordinate of the clipping.
   * @param y Top left vertical coordinate of the clipping.
   * @param w Width of the clipping.
   * @param h Height of the clipping.
   */
  void SetClip(int x, int y, int w, int h);
  /**
   * Takes the texture to be rendered to State's Render function.
   *
   * @param x Top left horizontal position in the Game's renderer.
   * @param y Top left vertical position in the Game's renderer.
   */
  void Render(int x, int y);
  /**
   * Access to the private member width.
   *
   * @return Sprite's width.
   */
  int GetWidth();
  /**
   * Access to the private member height.
   *
   * @return Sprite's height.
   */
  int GetHeight();
  /**
   * Checks if Sprite's member texture is null.
   *
   * @return False if null.
   */
  bool IsOpen();

};
#endif /* SPRITE_H */
