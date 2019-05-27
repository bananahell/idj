/**
 * @file Main.cpp
 *
 * Game's main function.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Game.h"

int main() {
  Game game = Game::GetInstance();
  game.Run();
  return 0;
}
