#ifndef _GAME_H_
#define _GAME_H_
struct data_bank {
	int count = 0;
};

typedef enum {
	count_down,
	play,
} eGameMode;

//�X�V
void Game_Update();

//������
void Game_Initialize();

//�`��
void Game_Draw();

//�I������
void Game_Finalize();
void UseEquipment_MoveDraw(int x0, int y0, int dx, int dy, int t);
#endif // _GAME_H_