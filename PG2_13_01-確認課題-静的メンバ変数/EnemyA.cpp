#include "EnemyA.h"

EnemyA::EnemyA(GameObject enemy) {
	enemy_ = enemy;
}

void EnemyA::Draw() {
	Novice::DrawEllipse((int)enemy_.position.x, (int)enemy_.position.y, (int)enemy_.radius, (int)enemy_.radius, 0.0f, RED, kFillModeSolid);
}

void EnemyA::Update() {
	if (Enemy::isAlive) {
	    Move();
		Draw();
	}
}