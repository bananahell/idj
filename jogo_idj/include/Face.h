/**
 * @file Face.h
 *
 * Face's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef FACE_H
#define FACE_H

#include "Component.h"


/**
 * Face class. This class represents the mechanics component of a game object
 * that identifies the game object itself as a character, in this stage of the
 * project.
 */
class Face : public Component {

 public:

  /**
   * Face's constructor. Sets the game's object's starting health.
   */
  explicit Face(GameObject& associated);

  /**
   * Damage mechanic of this Face game object.
   *
   * @param damage - Damage sent into the character's hitpoints.
   */
  void Damage(int damage);
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  void Update(float dt);
  /**
   * Function called in State's Render to Render the component.
   */
  void Render();
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is Face.
   */
  bool Is(std::string type);
  /**
   * Public function used to check if the game object is dead, which means that
   * its hitpoints have reached zero or less.
   *
   * @return True if the game object is dead (hitpoints <= 0).
   */
  bool IsDead();

  /**
   * Game object's remaining health.
   */
  int hitpoints;

};
#endif /* FACE_H */
