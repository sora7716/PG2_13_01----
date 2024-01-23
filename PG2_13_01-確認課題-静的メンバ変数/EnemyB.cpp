#include "EnemyB.h"

EnemyB::EnemyB(GameObject enemy) {
	enemy_ = enemy;
}

void EnemyB::Draw() {
	Novice::DrawEllipse((int)enemy_.position.x, (int)enemy_.position.y, (int)enemy_.radius, (int)enemy_.radius, 0.0f, RED, kFillModeSolid);
}

void EnemyB::Update() {
	if (Enemy::isAlive) {
	    Move();
		Draw();
	}
}