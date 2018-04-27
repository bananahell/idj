/**
 * @file Sound.h
 *
 * Sound's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef SOUND_H
#define SOUND_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.h"


/**
 * Sound class. Class that holds the sound a game's object makes.
 */
class Sound : public Component {

 public:

  /**
   * Sound's constructor. Sets <code>nullptr</code> to it's music chunk.
   */
  explicit Sound(GameObject& associated);
  /**
   * Sound's constructor with file's name. Calls the first constructor and Open.
   */
  Sound(GameObject& associated, std::string file);
  /**
   * Sound's destructor. Stops the sound and destroys itself.
   */
  ~Sound();

  /**
   * Function that plays opened song.
   *
   * @param times - Times wanted for the sound to play.
   */
  void Play(int times = 1);
  /**
   * Function that stops opened song.
   */
  void Stop();
  /**
   * Function that opens a song by its file's name.
   *
   * @param file - File's directory and name.
   */
  void Open(std::string file);
  /**
   * Function that checks if the sound is open.
   *
   * @return True if sound is open.
   */
  bool IsOpen();
  /**
   * Function called in State's Update to Update the component.
   *
   * @param dt - Unused yet.
   */
  void Update(float dt);
  /**
   * Function called in State's Render to Render the component.
   */
  void Render(Vec2 cameraPos);
  /**
   * Function that forces the component to identify itself.
   *
   * @param type - The type which this component is asked to be.
   *
   * @return True if type asked in the parameter matches the component's type,
   * which in this case is Sound.
   */
  bool Is(std::string type);
  /**
   * Function that checks if the sound is currently playing.
   *
   * @return True if sound is playing.
   */
  bool GetIsPlaying();

 private:

  /**
   * Chunk of sound used in the SDL functions to play the sounds.
   */
  Mix_Chunk* chunk;
  /**
   * Channel used for this sound.
   */
  int channel;

};
#endif /* SOUND_H */
