#include "Collision.h"

bool Collision::Box(GameObject standard, GameObject object) {
	if (standard.position.x <= object.position.x + object.radius && object.position.x <= standard.position.x + standard.radius &&
		standard.position.y <= object.position.y + object.radius && object.position.y <= standard.position.y + standard.radius) {
		return true;
    }
	return false;
}