#include "Score.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Score_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Ranking);//シーンをランキングに変更
    }
}

//描画
void Score_Draw() {
    DrawString(0, 0, "スコア画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "Enterキーを押すとランキング画面に移る", GetColor(255, 255, 255));
}