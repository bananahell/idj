/**
 * @file GameObject.h
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
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rect.h"

#include <string>
#include <vector>


class Component;

/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class GameObject {

 public:

  /**
   * State's constructor. Sets its content, like background image and music.
   */
  GameObject();
  ~GameObject();

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  void Update(float dt);
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  void Render();
  /**
   * Function that determines the behavior of the game when something happens,
   like when the player inserts an input.
   */
  bool IsDead();
  /**
   * Function that gathers Sprite's renderings and takes them to Game.
   */
  void RequestDelete();
  void AddComponent(Component* cpt);
  void RemoveComponent(Component* cpt);
  Component* GetComponent(std::string type);

  Rect box;

 private:

  /**
   * State's background image/texture.
   */
  std::vector<Component*> components;
  /**
   * State's background music.
   */
  bool isDead;

};
#endif /* STATE_H */
