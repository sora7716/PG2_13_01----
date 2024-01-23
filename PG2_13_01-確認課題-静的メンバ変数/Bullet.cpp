#include "Bullet.h"

Bullet::Bullet() {
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet_[i].position = {};
		bullet_[i].velocity = {0,-5};
		bullet_[i].radius = 10;
		bullet_[i].isAlive = false;
	}
	shotTime_ = 0;
	collision_ = new Collision;
}

Bullet::~Bullet() {
	delete collision_;
}

Vector2 Bullet::SetPosition(Vector2 position) {
	Vector2 result = position;
	return result;
}

void Bullet::ShotTime() {
	if (shotTime_ > 0) {
		shotTime_--;
	}
}

void Bullet::Spawn(char* keys, char* preKeys, Vector2 position) {
	ShotTime();
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]&&shotTime_<=0) {
		for (int i = 0; i < BULLET_NUM; i++) {
			if (!bullet_[i].isAlive) {
				bullet_[i].isAlive = true;
				bullet_[i].position = SetPosition(position);
				shotTime_ = 10;
				break;
			}
		}
	}
}

void Bullet::Translate() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet_[i].isAlive) {
			bullet_[i].position.y += bullet_[i].velocity.y;
			if (bullet_[i].position.y <= 0) {
				bullet_[i].isAlive = false;
			}
		}
	}
}

void Bullet::IsHit(GameObject enemy,bool *isHit) {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (collision_->Box(bullet_[i], enemy)) {
			*isHit = false;
		}
	}
}

void Bullet::Draw() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet_[i].isAlive) {
			Novice::DrawEllipse((int)bullet_[i].position.x, (int)bullet_[i].position.y, (int)bullet_[i].radius, (int)bullet_[i].radius, 0.0f, WHITE, kFillModeSolid);

		}
	}
}

void Bullet::Update(char* keys, char* preKeys, Vector2 position, GameObject object,bool *isHit) {
	Spawn(keys,preKeys,position);
	Translate();
	IsHit(object, isHit);
	Draw();
}