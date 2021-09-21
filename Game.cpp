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

//更新
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

//描画
void Game_Draw() {
    //timer(100);
    DrawString(0, 0, "プレイ画面です。", cr);
    DrawString(0, 20, "escキーを押して水分量を0にしてください", cr);
    DrawFormatString(0, 40, cr,"水分量: %d", water);
    Time_Draw(0, 60, cr);
    UseEquipment_Draw(0, 80, cr);
}