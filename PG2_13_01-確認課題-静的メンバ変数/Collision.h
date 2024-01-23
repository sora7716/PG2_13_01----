#pragma once
#include "Struct.h"
class Collision
{
public:
	/// <summary>
	/// 矩形の当たり判定
	/// </summary>
	/// <param name="standard"></param>
	/// <param name="object"></param>
	/// <returns></returns>
	bool Box(GameObject standard, GameObject object);
};

