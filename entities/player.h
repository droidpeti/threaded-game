// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
    SFW_OBJECT(Player, Entity)
public:

    Player();
    ~Player();

    void Init(Vector2 position, Vector2 size, float speed);
    void SetMoveDirection(Vector2 dir);
    void Update(float dt) override;

private:
    Vector2 velocity{0.0f, 0.0f};
    float speed = 200.0f;
};

#endif