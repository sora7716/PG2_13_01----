#pragma once
#include "Enemy.h"
class EnemyB :public Enemy
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="enemy"></param>
	EnemyB(GameObject enemy);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// enemyの処理をまとめた
	/// </summary>
	void Update()override;
};

