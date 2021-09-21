#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
/*
#include <iostream>
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
*/

static int water = 100;
unsigned int cr = GetColor(255, 255, 255);

//�X�V
void Game_Update() {
    Time_Update();
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
        water = water - 1;
    }
    if (water <= 0) {
        water = 100;
        Enter_Sound();
        SceneMgr_ChangeScene(eScene_Score);
    }
}

//�`��
void Game_Draw() {
    //timer(100);
    DrawString(0, 0, "�v���C��ʂł��B", cr);
    DrawString(0, 20, "esc�L�[�������Đ����ʂ�0�ɂ��Ă�������", cr);
    DrawFormatString(0, 40, cr,"������: %d", water);
    Time_Draw(0, 60, cr);
    UseEquipment_Draw(0, 80, cr);
}