#include "Ranking.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Ranking_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Ranking);//シーンを終了画面に変更
    }
}

//描画
void Ranking_Draw() {
    DrawString(0, 0, "ランキング画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Enterキーを押すと終了画面に移る", GetColor(255, 255, 255));
}