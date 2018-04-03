/**
 * @file State.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef FACE_H
#define FACE_H


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class Face {

 public:

  /**
   * State's constructor. Sets its content, like background image and music.
   */
  Face(GameObject& associated);

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  void Damage(int damage);
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  void Update(float dt);
  void Render();
  void Is(std::string type);

 private:

  /**
   * State's background music.
   */
  int hitpoints;

};
#endif /* STATE_H */
