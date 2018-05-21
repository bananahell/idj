#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "GameObject.h"
#include "Music.h"
#include "State.h"


class EndState : public State {

 public:

  EndState();
  ~EndState();

  void LoadAssets();
  void Start();
  void Pause();
  void Resume();
  void Update(float dt);
  void Render();

 private:

  GameObject* bg;
  GameObject* txt;
  Music backgroundMusic;

};
#endif /* ENDSTATE_H */
