/**
 * @file State.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef STATE_H
#define STATE_H

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"

#include <memory>
#include <vector>


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class State {

 private:

  void Input();
  void AddObject(int mouseX, int mouseY);

  /**
   * State's background music.
   */
  Music music;
  /**
   * State's need to quit the game.
   */
  bool quitRequested;
  std::vector<std::unique_ptr<GameObject>> objectArray;

 public:

  /**
   * State's constructor. Sets its content, like background image and music.
   */
  State();
  ~State();

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  bool QuitRequested();
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  void LoadAssets();
  /**
   * Function that determines the behavior of the game when something happens,
   like when the player inserts an input.
   */
  void Update(float dt);
  /**
   * Function that gathers Sprite's renderings and takes them to Game.
   */
  void Render();

};
#endif /* STATE_H */
