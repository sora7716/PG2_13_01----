#include "Enemy.h"

void Enemy::Move() {
	enemy_.position.x += enemy_.velocity.x;
	if (enemy_.position.x > 1280) {
		enemy_.velocity.x *= -1;
	}
	else if (enemy_.position.x < 0) {
		enemy_.velocity.x *= -1;
	}
}

void Enemy::Update()
{
}
