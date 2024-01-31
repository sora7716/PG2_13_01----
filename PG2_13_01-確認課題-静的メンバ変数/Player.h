#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{
private:
	GameObject player_;
	Bullet* bullet_;
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="gameObject"></param>
	Player(GameObject gameObject);

	/// <summary>
	/// デストラクター
	/// </summary>
	~Player();

	/// <summary>
	/// playerにspeedを加算
	/// </summary>
	void Translate();

	/// <summary>
	/// キー入力で動かす
	/// </summary>
	/// <param name="keys"></param>
	void Move(char *keys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 上記の処理をまとめた
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="object"></param>
	/// <param name="isHit"></param>
	void Update(char *keys,char *preKeys, GameObject object);
};

