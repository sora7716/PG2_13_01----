#include "Player.h"

Player::Player(GameObject gameObject) {
	player_ = gameObject;
	bullet_ = new Bullet;
}

Player::~Player() {
	delete bullet_;
}

void Player::Translate() {
	player_.position.x += player_.velocity.x;
	player_.position.y += player_.velocity.y;
}

void Player::Move(char* keys) {
	if (keys[DIK_W]) {
		player_.velocity.y =-5;
	}
	else if (keys[DIK_S]) {
		player_.velocity.y = 5;
	}
	else {
		player_.velocity.y = 0;
	}
	if (keys[DIK_D]) {
		player_.velocity.x = 5;
	}
	else if (keys[DIK_A]) {
		player_.velocity.x = -5;
	}
	else {
		player_.velocity.x = 0;
	}
}

void Player::Draw() {
	Novice::DrawEllipse(
		(int)player_.position.x, (int)player_.position.y, 
		(int)player_.radius,     (int)player_.radius, 
		0.0f, GREEN, kFillModeSolid
	);
}

void Player::Update(char* keys,char* preKeys,GameObject object,bool *isHit) {
	Translate();
	Move(keys);
	bullet_->Update(keys,preKeys,player_.position,object,isHit);
	Draw();
}