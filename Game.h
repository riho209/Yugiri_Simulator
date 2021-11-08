#ifndef _GAME_H_
#define _GAME_H_
struct data_bank {
	int count = 0;
};
//XV
void Game_Update();

//‰Šú‰»
void Game_Initialize();

//•`‰æ
void Game_Draw();

//I—¹ˆ—
void Game_Finalize();
void UseEquipment_MoveDraw(int x0, int y0, int dx, int dy, int t);
#endif // _GAME_H_