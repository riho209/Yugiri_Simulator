#include "Score.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include <iostream>
#include <string>

static string_score str_score;

static int cr1 = GetColor(255, 255, 255);
static int font_size;
static int efsHandle;
static int mImageHandle;
//1200, 700
//初期化
void Score_Initialize() {
    font_size = 30;
    efsHandle = LoadSoundMem("sounds/決定、ボタン押下1.mp3");
    mImageHandle = LoadGraph("images/Score.png");
}
//更新
void Score_Update() {
    ScoreV_Update();
    //sleep(100);
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //エンターキーが押されていたら
        SceneChangeFlag_Forbid();
        AllPlayData_Update();
        PlaySoundMem(efsHandle, DX_PLAYTYPE_BACK);
        SceneMgr_ChangeScene(eScene_Ranking);//シーンをランキングに変更
    }
    //H8
    /*
    if (get_buf_h8maikon() == 'a') {
        SceneMgr_ChangeScene(eScene_Ranking);
    }
    */
}

//描画
void Score_Draw() {
    DrawGraph(0, 0, mImageHandle,TRUE);
    DrawString(0, 0, str_score.explanation, cr1);
    DrawString(0, font_size, str_score.ranking, cr1);
    DrawString(0, font_size*2,str_score.score, cr1);
    DrawFormatString(font_size *6, 60, cr1, "%d", Time_Get());
    DrawString(font_size * 20, font_size * 2, str_score.time, cr1);
    DrawFormatString(font_size*30, font_size*2, cr1, "%d", ScoreV_Get());
}
//終了処理
void Score_Finalize() {
    DeleteSoundMem(efsHandle);//サウンド開放
    DeleteGraph(mImageHandle);//画像の解放
}