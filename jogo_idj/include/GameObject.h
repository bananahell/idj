/**
 * @file GameObject.h
 *
 * GameObject's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rect.h"

#include <memory>
#include <string>
#include <vector>

/* Forward declaration to use Component. Way of dodging circular dependency. */
class Component;

/**
 * GameObject class. The class that represents an object in the game, holding
 * each of its characteristics, which are called components.
 */
class GameObject {
 public:
  /**
   * GameObject's constructor. Makes sure the object is alive.
   */
  GameObject();
  /**
   * GameObject's destructor. Clears the whole vector of components.
   */
  ~GameObject();

  /**
   * Function called in State's Update to Update the components in the object.
   *
   * @param dt - Unused yet.
   */
  void Update();
  /**
   * Function called in State's Render to Render the components in the object.
   */
  void Render();
  /**
   * Public function used to check if the game object is dead, which means that
   * its Face's hitpoints have reached zero or less.
   *
   * @return True if the game object is dead (Face::hitpoints <= 0).
   */
  bool IsDead();
  /**
   * Function that sets the object's death to true.
   */
  void RequestDelete();
  /**
   * Function used to add components to the object.
   *
   * @param cpt - Component to be added itself.
   */
  void AddComponent(Component* cpt);
  /**
   * Function used to remove components from the object.
   *
   * @param cpt - Component to be removed itself.
   */
  void RemoveComponent(Component* cpt);
  /**
   * Function used to look for an object's component by type.
   *
   * @param type - The type being looked for.
   *
   * @return Component The component with the matching type passed as parameter,
   * <code>nullptr</code> if not found.
   */
  Component* GetComponent(std::string type);

  /**
   * Box in which the object is inserted in the game, with information like x
   * and y positions and width and height.
   */
  Rect box;

 private:
  /**
   * Vector of unique pointers used to hold the object's components.
   */
  std::vector<std::unique_ptr<Component>> components;
  /**
   * Variable that determines if the object is alive or not.
   */
  bool isDead;
};
#endif /* GAMEOBJECT_H */
