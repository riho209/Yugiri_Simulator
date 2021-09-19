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
unsigned int cr;

//更新
void Game_Update() {
    Time_Update();
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
        water = water - 1;
    }
    if (water == 0) {
        water = 100;
        SceneMgr_ChangeScene(eScene_Score);
    }
}

//描画
void Game_Draw() {
    //timer(100);
    cr = GetColor(255, 255, 255);
    DrawString(0, 0, "プレイ画面です。", cr);
    DrawString(0, 20, "escキーを押して水分量を0にしてください", cr);
    DrawFormatString(0, 40, cr,"水分量: %d", water);
    DrawFormatString(0, 60, cr, "経過時間(ミリ秒): %d", Time_Get());
    switch (UseEquipment_Get()) {
    case tebo:
        DrawString(0, 80, "てぼモード", cr);
        break;
    case hirazaru:
        DrawString(0, 80, "ひらざるモード", cr);
        break;
    }
}