/**
 * @file State.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef STATE_H
#define STATE_H

#include "GameObject.h"

#include <memory>
#include <vector>


/**
 * State class. The class in which the game manifests its current behavior, like
 * which music it's playing or if it wants to quit.
 */
class State {

 public:

  State();
  virtual ~State();

  virtual std::weak_ptr<GameObject> AddObject(GameObject* go);
  virtual std::weak_ptr<GameObject> GetObjectPtr(GameObject* go);
  virtual void LoadAssets() = 0;
  virtual void Start() = 0;
  virtual void Pause() = 0;
  virtual void Resume() = 0;
  virtual void Update(float dt) = 0;
  virtual void Render() = 0;
  bool PopRequested();
  bool QuitRequested();

 protected:

  void StartArray();
  virtual void UpdateArray(float dt);
  virtual void RenderArray();

  std::vector<std::shared_ptr<GameObject>> objectArray;
  bool popRequested;
  bool quitRequested;
  bool started;

};
#endif /* STATE_H */
