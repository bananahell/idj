#include "Game.h"

#include "TitleState.h"


int main(int argv, char** args) {

  Game game = Game::GetInstance();
  State* newState = new TitleState();
  game.Push(newState);
  game.Run();
  return 0;

}
