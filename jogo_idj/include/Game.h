/**
 * @file Game.h
 *
 * Game's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.h"

#include <memory>
#include <stack>
#include <string>


/**
 * Game class. The class in which the game has its basic functionalities, like
 * running in a loop and making a single instance of itself.
 */
class Game {

 private:


  /**
   * Game's unique singleton constructor. It initializes every basic SDL
   * functionality of the game, like SDL_Init.
   *
   * @param title Title/name of the game.
   * @param width Width of game's window.
   * @param height Height of game's window.
   */
  Game(std::string title, int width, int height);

  void CalculateDeltaTime();

  /**
   * Game's unique instance.
   */
  static Game* instance;
  /**
   * Window in which the game is displayed.
   */
  SDL_Window* window;
  /**
   * Renderer responsible for filling the window.
   */
  SDL_Renderer* renderer;
  static std::stack<std::unique_ptr<State>> stateStack;
  static State* storedState;
  int frameStart;
  float dt;

 public:

  /**
   * Game's destructor.
   */
  ~Game();

  /**
   * Game's running loop. Here the game's state is update, screen rendered, and
   so on.
   */
  void Run();
  /**
   * Access to the Game's private member renderer.
   *
   * @see renderer
   *
   * @return Game's renderer.
   */
  SDL_Renderer* GetRenderer();
  /**
   * Game's way of having a singleton instance.
   *
   * @return Game's instance.
   */
  static Game& GetInstance();
  float GetDeltaTime();
  State& GetCurrentState();
  void Push(State* state);

};
#endif /* GAME_H */
