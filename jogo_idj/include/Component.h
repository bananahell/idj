/**
 * @file Component.h
 *
 * Component's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef COMPONENT_H
#define COMPONENT_H

#include "GameObject.h"
#include "Vec2.h"

#include <string>


/**
 * Component class. Abstract class that represents the concept of a concept of
 * a game object, like a an image or a sound of a character.
 */
class Component {

 public:

  /**
   * Component's constructor. This is what keeps the components connected.
   *
   * @param associated - Game object that has this component.
   */
  explicit Component(GameObject& associated);
  /**
   * Component's destructor. Just forces each component to implement a
   * destructor.
   */
  virtual ~Component();

  /**
   * Pure virtual function that is called in State's Update to Update the
   * component.
   *
   * @param dt - Unused yet.
   */
  virtual void Update(float dt) = 0;
  /**
   * Pure virtual function that is called in State's Render to Render the
   * component.
   */
  virtual void Render(Vec2 cameraPos) = 0;
  /**
   * Pure virtual function that forces each component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type.
   */
  virtual bool Is(std::string type) = 0;
  virtual void Start();

 protected:

  /**
   * Game object to which this component is associated.
   */
  GameObject& associated;

};
#endif /* COMPONENT_H */
