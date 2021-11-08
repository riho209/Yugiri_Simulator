#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"

static int mImageHandle;    //画像ハンドル格納用変数
static int efsHandle;//効果音Enter
//初期化
void Config_Initialize() {
    mImageHandle = LoadGraph("images/back.jpg");//画像のロード
    efsHandle = LoadSoundMem("sounds/決定、ボタン押下1.mp3");
}

//終了処理
void Config_Finalize() {
    DeleteGraph(mImageHandle);//画像の解放
    DeleteSoundMem(efsHandle);//サウンド開放
}
//更新
void Config_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
        PlaySoundMem(efsHandle, DX_PLAYTYPE_BACK);
        Config_Finalize();
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
}

//描画
void Config_Draw() {
    DrawGraph(0, 0, mImageHandle, TRUE); // 画像を描画する
    DrawString(0, 0, "操作説明", GetColor(255, 255, 255));
    DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}