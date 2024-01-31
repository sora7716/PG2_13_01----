#include "Collision.h"

bool Collision::Box(GameObject standard, GameObject object) {
	if (standard.position.x- standard.radius <= object.position.x + object.radius && object.position.x-object.radius <= standard.position.x + standard.radius &&
		standard.position.y-standard.radius <= object.position.y + object.radius && object.position.y-object.radius <= standard.position.y + standard.radius) {
		return true;
    }
	return false;
}