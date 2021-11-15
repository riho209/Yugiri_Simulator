#include "Score.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "Sound.h"
#include <iostream>
#include <string>

static string_score str_score;

static int cr1 = GetColor(255, 255, 255);
static int font_size;
static int mImageHandles;
static int FontHandle;
//1200, 700
//初期化
void Score_Initialize() {
    FontHandle = CreateFontToHandle("HG行書体", 40, 9);
    font_size = 40;
    mImageHandles = LoadGraph("images/Score.png");
    ScoreV_Update();
}
//更新
void Score_Update() {
    //sleep(100);
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //エンターキーが押されていたら
        SceneChangeFlag_Forbid();
        AllPlayData_Update();
        Enter_Sound();
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
    DrawGraph(0, 0, mImageHandles,TRUE);
    //DrawString(0, 0, str_score.explanation, cr1);
    //DrawString(0, font_size, str_score.ranking, cr1);
    DrawStringToHandle(font_size * 2, font_size * 2, str_score.score, cr1, FontHandle);
    DrawFormatStringToHandle(font_size *6, font_size * 2, cr1, FontHandle,"%d", ScoreV_Get());
    DrawStringToHandle(font_size * 13, font_size * 2, str_score.time, cr1,FontHandle);
    DrawFormatStringToHandle(font_size * 23, font_size * 2, cr1, FontHandle, "%d", Time_Get());
    //DrawFormatString(font_size*30, font_size*2, cr1, "%d", Time_Get());
}
//終了処理
void Score_Finalize() {
    DeleteGraph(mImageHandles);//画像の解放
}