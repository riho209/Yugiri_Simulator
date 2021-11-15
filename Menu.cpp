#include "Menu.h"
#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"
#include "Func.h"
#include "Sound.h"

const static int PADX = 250;
const static int LOCATE = 450;
static string_bank str_data;
//static menu_sounds effect;
typedef enum {
    eMenu_TEBO,
    eMenu_HIRAZARU,
    eMenu_EXPLANATION,    //操作説明
    eMenu_RANKING,
    eMenu_Num,        //本項目の数
} eMenu;
const static int font_size = 30;
static int mImageHandles;    //画像ハンドル格納用変数
static int width, height;
static int OpMaxStrNum = 5 * font_size;
static int y = 0;
bool IsFirstPlay = TRUE;
//初期化
void Menu_Initialize() {

    mImageHandles = LoadGraph("images/2.png");
    GetGraphSize(mImageHandles, &width, &height);
    SetFontSize(font_size);                             //サイズを20に変更
    SetFontThickness(9);                         //太さを9に変更
    ChangeFont("HG行書体");              //HGS行書体に変更
    //アンチエイリアス＆エッジ付きフォントに変更
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

static int NowSelect = eMenu_TEBO;    //現在の選択状態(初期はゲーム選択中)
//static i
//更新
void Menu_Update() {
    if (IsFirstPlay) {
        IsFirstPlay = FALSE;
        Menu_BGM();
    }
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//エンターキーが押されたら
        Enter_Sound();
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_TEBO:
            //BGM STOP
            Stop_Menu_BGM();
            IsFirstPlay = TRUE;
            CurrentPlayData_Initialize();
            UseEquipment_Update(tebo);
            SceneMgr_ChangeScene(eScene_Game);
            break;
        case eMenu_HIRAZARU:
            Stop_Menu_BGM();
            IsFirstPlay = TRUE;
            CurrentPlayData_Initialize();
            UseEquipment_Update(hirazaru);
            SceneMgr_ChangeScene(eScene_Game);
            break;
        case eMenu_EXPLANATION:
            SceneMgr_ChangeScene(eScene_Config);
            break;
        case eMenu_RANKING:
            SceneMgr_ChangeScene(eScene_Ranking);
        }
    }
}

//描画
void Menu_Draw() {

    DrawGraph(600-width/2,350-height/2, mImageHandles,TRUE); // データハンドルを使って画像を描画

    DrawString(OpMaxStrNum + 600 - PADX, LOCATE, str_data.menu, GetColor(200, 0, 255));
    DrawString(600 - PADX+ font_size*3 , LOCATE+font_size, str_data.coment, GetColor(200, 0, 255));
    DrawString(OpMaxStrNum + 600 - PADX, LOCATE+font_size*2,str_data.play, GetColor(255, 0, 0));
    DrawString(OpMaxStrNum + 600 - PADX, LOCATE + font_size*3,str_data.tebo, GetColor(255, 0, 0));
    DrawString(OpMaxStrNum + 600 - PADX, LOCATE + font_size*4,str_data.hira, GetColor(255, 0, 0));
    DrawString(OpMaxStrNum + 600 - PADX, LOCATE + font_size*5,str_data.explanation, GetColor(255, 0, 0));
    DrawString(OpMaxStrNum + 600 - PADX, LOCATE + font_size*6,str_data.ranking, GetColor(255, 0, 0));
    
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_TEBO:
        y = LOCATE + font_size * 3;
        break;
    case eMenu_HIRAZARU:
        y = LOCATE + font_size * 4;
        break;
    case eMenu_EXPLANATION:
        y = LOCATE + font_size * 5;
        break;
    case eMenu_RANKING:
        y = LOCATE + font_size * 6;
        break;
    }
    DrawString(OpMaxStrNum + 600-font_size - PADX, y,str_data.mark, GetColor(255, 255, 255));
}
//終了処理
void Menu_Finalize() {
    DeleteGraph(mImageHandles);//画像の解放
}
