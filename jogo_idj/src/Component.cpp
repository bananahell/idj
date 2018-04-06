/**
 * @file Component.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Component.h"


Component::Component(GameObject& associated) : associated(associated) {}

Component::~Component() {}
