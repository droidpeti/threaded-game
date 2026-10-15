#include "player.h"

Player::Player(){

}

Player::~Player(){

}

void Player::Init(Vector2 position, Vector2 size, float speed){
    this->position = position;
    this->size = size;
    this->speed = speed;
    this->velocity = {0.0f, 0.0f};
}

void Player::SetMoveDirection(Vector2 dir){
    velocity = dir;
}

void Player::Update(float dt){
    position += speed * velocity.normalized() * dt;
}
