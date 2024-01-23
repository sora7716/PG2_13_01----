#pragma once
#include <Novice.h>
#include "Struct.h"
#include "Collision.h"
class Bullet
{
private:
	GameObject bullet_[BULLET_NUM];
	int shotTime_;
	Collision* collision_;

public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Bullet();

	/// <summary>
	/// デストラクター
	/// </summary>
	~Bullet();

	/// <summary>
	/// セッター
	/// </summary>
	/// <param name="position"></param>
	/// <returns></returns>
	Vector2 SetPosition(Vector2 position);

	/// <summary>
	/// 弾の間隔
	/// </summary>
	void ShotTime();

	/// <summary>
	/// 弾のスポーン
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="position"></param>
	void Spawn(char* keys, char* preKeys, Vector2 position);
	
	/// <summary>
	/// 弾の動き
	/// </summary>
	void Translate();

	/// <summary>
	/// 弾とenemyの当たり判定
	/// </summary>
	/// <param name="object"></param>
	/// <param name="isHit"></param>
	void IsHit(GameObject enemy, bool *isHit);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 弾の処理をまとめた
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="position"></param>
	/// <param name="object"></param>
	/// <param name="isHit"></param>
	void Update(char* keys, char* preKeys, Vector2 position, GameObject object, bool* isHit);
};

