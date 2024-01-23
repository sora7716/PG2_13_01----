#include "Player.h"
#include "EnemyA.h"
#include "EnemyB.h"

const char kWindowTitle[] = "GC1A_01_イイヅカ_ソラ_title";

bool Enemy::isAlive = true;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//playerのインスタンス↓
	GameObject pos = {{ 640,600 }, { 5,5 }, 32};
	Player* player = new Player(pos);
	//playerのインスタンス↑

	//enemyのインスタンス↓
	Enemy* enemy[ENEMY_NUM];
	GameObject enemyObject[ENEMY_NUM] = { {{0,300},{-5,5},16,true},{ {200,500},{-5,5},16 ,true} };
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (i == 0) {
			enemy[i] = new EnemyA(enemyObject[i]);
		}
		else {
			enemy[i] = new EnemyB(enemyObject[i]);
		}
	}
	//enemyのインスタンス↑


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		for (int i = 0; i < ENEMY_NUM; i++) {
			enemy[i]->Update();//エネミーの処理
		    player->Update(keys,preKeys,enemy[i]->GetGameObject(), &Enemy::isAlive);//プレイヤーと弾の処理
			//リセット
		    if (keys[DIK_R] && !preKeys[DIK_R]) {
		    	Enemy::isAlive = true;
		    }
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
