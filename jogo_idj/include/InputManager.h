/**
 * @file InputManager.h
 *
 * InputManager's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT

#define INCLUDE_SDL
#include "SDL_include.h"

#include "Vec2.h"

#include <unordered_map>


/**
 * InputManager class. Class that holds the tile set clipped from an image to be
 * shown in a tile map.
 */
class InputManager {

 public:

  static void Update();
  static bool KeyPress(int key);
  static bool KeyRelease(int key);
  static bool IsKeyDown(int key);
  static bool MousePress(int button);
  static bool MouseRelease(int button);
  static bool IsMouseDown(int button);
  static int GetMouseX();
  static int GetMouseY();
  static bool QuitRequested();
  static InputManager& GetInstance();
	static Vec2 GetMousePos();

 private:

  InputManager();
  ~InputManager();

  static bool mouseState[6];
  static int mouseUpdate[6];
  static std::unordered_map<int, bool> keyState;
  static std::unordered_map<int, int> keyUpdate;
  static bool quitRequested;
  static int updateCounter;
  static int mouseX;
  static int mouseY;

};
#endif /* INPUTMANAGER_H */
