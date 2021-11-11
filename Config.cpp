#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "Sound.h"
#include "Keyboard.h"

static int mImageHandles[6];    //画像ハンドル格納用変数
//初期化
void Config_Initialize() {
    mImageHandles[0] = LoadGraph("images/config/back_alpha.png");//背景
    mImageHandles[1] = LoadGraph("images/config/menu.png");//メニュー
    mImageHandles[2] = LoadGraph("images/config/menu_ex.png");//メニュー拡大
    mImageHandles[3] = LoadGraph("images/config/play.png");//プレイ
    //mImageHandles[4] = LoadGraph("images/config/play.png");//プレイ説明
    mImageHandles[4] = LoadGraph("images/config/score.png");//スコア
    mImageHandles[5] = LoadGraph("images/config/rank.png");//ランク
}

//終了処理
void Config_Finalize() {
    DeleteGraph(mImageHandles[0]);//画像の解放
}

enum {
    pMenu,
    pGame,
    pScore_Rank,
};
#define PAGE_NUMBER 3 //ページ数
static int Page = pMenu;
//更新
void Config_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
        Enter_Sound();
        Config_Finalize();
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
        Page++;
        Page %= PAGE_NUMBER;
    }
}
void Con_Menu();
void Con_Game();
void Con_GameEX();
void Con_ScoreRank();

//描画
void Config_Draw() {
    DrawBox(0, 0,1200, 700, GetColor(255, 255, 255),TRUE);
    DrawGraph(0, 0, mImageHandles[0], TRUE); // 画像を描画する
    DrawBoxAA(100,50,1100,650,GetColor(255,0,0), FALSE);
    DrawString(0, 0, "操作説明～", GetColor(0,0,0));
    DrawString(800, 640, "Escキーでメニューに戻る", GetColor(0, 0, 0));
    DrawString(800,670, "Enterキーで次のページ", GetColor(0, 0, 0));
    switch (Page)
    {
    case pMenu:
        Con_Menu();
        break;
    case pGame:
        Con_Game();
        break;
    case pScore_Rank:
        Con_ScoreRank();
        break;
    default:
        break;
    }
    //DrawString(0, 20, "Escキーでメニューに戻る", GetColor(255, 255, 255));

}
//説明
void Con_Menu() {
    DrawString(30*5, 0, "メニュー～", GetColor(0, 0, 0));
    DrawGraph(150, 60, mImageHandles[1], TRUE);//メニュー
    DrawGraph(150, 400, mImageHandles[2], TRUE);//メニュー拡大
    
}
void Con_Game() {
    DrawString(30 * 5, 0, "プレイ～", GetColor(0, 0, 0));
    DrawGraph(150, 100, mImageHandles[3], TRUE);//ゲーム
}
void Con_GameEX() {

}
void Con_ScoreRank() {
    DrawString(30 * 5, 0, "スコア＆ランキング～", GetColor(0, 0, 0));
    DrawGraph(150, 100, mImageHandles[4], TRUE);//スコア
    DrawGraph(550, 100, mImageHandles[5], TRUE);//ランキング
}