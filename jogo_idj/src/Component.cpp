/**
 * @file Component.cpp
 *
 * Parts of the game objects in the game.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Component.h"


Component::Component(GameObject& associated) : associated(associated) {}

Component::~Component() {}
