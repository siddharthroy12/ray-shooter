#include "../Globals.hpp"
#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include "Player.hpp"

Enemy::Enemy(Node* parent) : Node(parent) {
    if (GetRandomValue(0, 1)) {
        position.x = 0.0f;
    } else {
        position.x = SCREEN_WIDTH;
    }
    if (GetRandomValue(0, 1)) {
        position.y = 0.0f;
    } else {
        position.y = SCREEN_HEIGHT;
    }
    this->texture = LoadTexture("assets/enemy.png");
    this->sourceRec = { 0.0f, 0.0f, texture.width, texture.height };
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5};
    this->origin = { (texture.width*5) /2, (texture.height*5)/2 };
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3};
}

void Enemy::render() {
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, WHITE);
}

void Enemy::update() {
    Player* tmpp = (Player*) parent->getChildren("Player");
    if (tmpp == NULL) {
        std::cout << "ca" << std::endl;
    }
    Vector2 playerPosition = tmpp->getPosition();
    float tmp = atan2(playerPosition.y -position.y, playerPosition.x - position.x);
    rotation = (tmp * 180 / PI) + 90;
    this->head.x = cos(tmp);
    this->head.y = sin(tmp);
    this->setPosition({ this->getPosition().x + (head.x * speed), this->getPosition().y + (head.y * speed) });
}

Vector2 Enemy::getPosition() { return this-> position; }

void Enemy::setPosition(Vector2 position) {
    this->position = position;
    this->destRec = { this->position.x, this->position.y, texture.width*5, texture.height*5 };
    this->hitbox = { this->position.x - ((texture.width*3) / 2), this->position.y - ((texture.height*3) /2), texture.width*3, texture.height*3 };
}

Enemy::~Enemy() {
    UnloadTexture(this->texture);
}