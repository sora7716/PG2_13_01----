#pragma once
#include <Novice.h>
#include "Struct.h"

class Enemy
{
public:
	/// <summary>
	/// 静的メンバ変数
	/// </summary>
	static bool isAlive;
protected:
	GameObject enemy_;
public:
	/// <summary>
	/// ゲッター
	/// </summary>
	/// <returns></returns>
	GameObject GetGameObject() { return enemy_; };
	
	/// <summary>
	/// エネミーの動き
	/// </summary>
	void Move();

	/// <summary>
	/// 仮想の関数
	/// </summary>
	virtual void Update();
};

