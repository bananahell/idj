/**
 * @file Sound.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef SOUND_H
#define SOUND_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.h"


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class Sound : public Component {

 public:

  /**
   * State's constructor. Sets its content, like background image and music.
   */
  Sound(GameObject& associated);
  Sound(GameObject& associated, std::string file);
  ~Sound();

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  void Play(int times = 1);
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  void Stop();
  /**
   * Function that determines the behavior of the game when something happens,
   like when the player inserts an input.
   */
  void Open(std::string file);
  /**
   * Function that gathers Sprite's renderings and takes them to Game.
   */
  bool IsOpen();
  void Update(float dt);
  void Render();
  bool Is(std::string type);

 private:

  /**
   * State's background image/texture.
   */
  Mix_Chunk* chunk;
  /**
   * State's background music.
   */
  int channel;

};
#endif /* STATE_H */
