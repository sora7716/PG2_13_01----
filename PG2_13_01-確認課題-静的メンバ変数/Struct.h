#pragma once

const int ENEMY_NUM = 2;
const int BULLET_NUM = 10;

typedef struct Vector2 {
	float x;
	float y;
}Vector2;

typedef struct GameObject {
	Vector2 position;
	Vector2 velocity;
	float radius;
	bool isAlive;
}GameObject;
