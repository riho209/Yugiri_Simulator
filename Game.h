#ifndef _GAME_H_
#define _GAME_H_
struct data_bank {
	int count = 0;
};
typedef enum {
	count_down,
	play,
} eGameMode;
//更新
void Game_Update();

//初期化
void Game_Initialize();

//描画
void Game_Draw();

//終了処理
void Game_Finalize();
void UseEquipment_MoveDraw(int x0, int y0, int dx, int dy, int t);
#endif // _GAME_H_