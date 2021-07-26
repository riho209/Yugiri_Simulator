#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void End_Update() {
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //エンターキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}

//描画
void End_Draw() {
    DrawString(0, 0, "End画面です。", GetColor(255, 255, 255));
    DrawString(0, 20, "エンターキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}