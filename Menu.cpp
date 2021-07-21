#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int PLAY_Y = 240;    //「テボ」文字のy位置
const static int EXPLANATION_Y = 300;    //「設定」文字のy位置

typedef enum {

    eMenu_PLAY,        //プレイ
    
    eMenu_EXPLANATION,    //操作説明

    eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_PLAY;    //現在の選択状態(初期はゲーム選択中)

//更新
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_PLAY://プレイ選択中なら
            SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
            break;
        case eMenu_EXPLANATION://操作説明選択中なら
            SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
            break;
        }
    }
}

//描画
void Menu_Draw() {
    DrawString(200, 150, "メニュー画面です。", GetColor(255, 255, 255));
    DrawString(200, 170, "上下キーを押し、エンターを押して下さい。", GetColor(255, 255, 255));
    DrawString(280, PLAY_Y, "プレイ", GetColor(255, 255, 255));
    DrawString(280, EXPLANATION_Y, "操作説明", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_PLAY://ゲーム選択中なら
        y = PLAY_Y;    //ゲームの座標を格納
        break;
    case eMenu_EXPLANATION://設定選択中なら
        y = EXPLANATION_Y;    //設定の座標を格納
        break;
    }
    DrawString(250, y, "■", GetColor(255, 255, 255));
}
