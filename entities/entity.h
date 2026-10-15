#ifndef ENTITY_H
#define ENTITY_H

#include "../sfw/sfw.h"

class Entity: public Resource{
    SFW_OBJECT(Entity, Resource)
public:
    Vector2 position;
    Vector2 size;

    Entity() {position = {0, 0}, size = {0, 0};}
    virtual ~Entity() = default;

    virtual void Update(float dt) = 0;
};

#endif