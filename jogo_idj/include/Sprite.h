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

#include "Component.h"

#include <string>


/**
 * Sprite class. The class responsible for the game's textures and images.
 */
class Sprite : public Component {

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
  Vec2 scale;
  int frameCount;
  int currentFrame;
  float frameTime;
  float timeElapsed;

 public:

  /**
   * Sprite's empty constructor. Sets texture to <code>nullptr</code>.
   */
  explicit Sprite(GameObject& associated);
  Sprite(GameObject& associated, std::string file, int frameCount = 1, float frameTime = 1);
  /**
   * Sprite's destructor.
   */
  ~Sprite();

  /**
   * Function that opens the texture to be rendered. Does not renders, only
   * opens.
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
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  void Update(float dt);
  /**
   * Function called in State's Render to render the component. This calls the
   * Render with arguments passing the box's variables as arguments.
   */
  void Render(Vec2 cameraPos);
  /**
   * Function that is called to render the sprite in the specified position.
   *
   * @param 
   */
  void Render(float x, float y);
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is Sprite.
   */
  bool Is(std::string type);
  void SetScaleX(float scaleX, float scaleY);
  Vec2 GetScale();
	void SetScale(Vec2 scale);

};
#endif /* SPRITE_H */
