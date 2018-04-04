/**
 * @file Component.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

/* Com isso, tá dando erro de compilação, sem isso, o problema saiu
mas tirar isso de GameObject.h e Component.h dá ruinzão
Dependência circular? como faz isso?
não esquecer de descomentar o endif no final vvvvv
*/
#ifndef COMPONENT_H
#define COMPONENT_H

#include <GameObject.h>

#include <string>


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class Component {

 public:

  /**
   * State's constructor. Sets its content, like background image and music.
   */
  Component(GameObject& associated);
  /**
   * State's constructor. Sets its content, like background image and music.
   */
  virtual ~Component();

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  virtual void Update(float dt) = 0;
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  virtual void Render() = 0;
  /**
   * Function that determines the behavior of the game when something happens,
   like when the player inserts an input.
   */
  virtual bool Is(std::string type) = 0;

 protected:

  /**
   * Function that gathers Sprite's renderings and takes them to Game.
   */
  GameObject& associated;

};
#endif /* STATE_H */
