/**
 * @file Main.cpp
 * 
 * Game's main function.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Game.h"


int main(int argc, char** argv) {

  Game game = Game::GetInstance();
  game.Run();
  return 0;

}
