#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rect.h"

#include <memory>
#include <string>
#include <vector>


class Component;

class GameObject {

 public:

  Rect box;
  float rotation;

  GameObject();
  ~GameObject();

  void Start();
  void AddComponent(Component* cpt);
  void AddComponentAsFirst(Component* cpt);
  void RemoveComponent(Component* cpt);
  Component* GetComponent(std::string type);
  void RequestDelete();
  void Update(float dt) ;
  void Render();
  void NotifyCollision(GameObject& other);
  void Activate();
  void Deactivate();
  bool IsActive();
  bool IsDead();

 private:

  std::vector<std::unique_ptr<Component>> components;
  bool started;
  bool active;
  bool isDead;

};
#endif /* GAMEOBJECT_H */
