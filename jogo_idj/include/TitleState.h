#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "GameObject.h"
#include "State.h"
#include "Timer.h"


class TitleState : public State {

 public:

  TitleState();
  ~TitleState();

  void LoadAssets();
  void Start();
  void Pause();
  void Resume();
  void Update(float dt);
  void Render();

 private:

  GameObject* bg;
  GameObject* txt;
  Timer toggleText;

};
#endif /* TITLESTATE_H */
