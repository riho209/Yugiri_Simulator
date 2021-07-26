#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Game_Update() {
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //エンターキーが押されていたら
        SceneMgr_ChangeScene(eScene_Score);//シーンをスコアに変更
    }
}

//描画
void Game_Draw() {
    DrawString(0, 0, "プレイ画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Enterキーを押すとスコア画面に移ります。", GetColor(255, 255, 255));
}