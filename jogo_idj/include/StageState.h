#ifndef STAGESTATE_H
#define STAGESTATE_H

#include "GameObject.h"
#include "Music.h"
#include "State.h"
#include "TileSet.h"


class StageState : public State {

 public:

  StageState();
  ~StageState();

  void LoadAssets();
  void Start();
  void Pause();
  void Resume();
  void CollisionCheck();
  void DeletionCheck();
  void Update(float dt);
  void Render();

 private:

  GameObject* bg;
  GameObject* map;
  TileSet* set;
  Music backgroundMusic;

};
#endif /* STAGESTATE_H */
