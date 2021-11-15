#ifndef _MENU_H_
#define _MENU_H_

//初期化
void Menu_Initialize();

//更新
void Menu_Update();

//描画
void Menu_Draw();

void Menu_Finalize();//終了処理
struct string_bank{
    char  menu[30] = "メニュー";
    char  coment[60] = "上下キー選択、Enter決定";
    char play[10] = "プレイ";
    char tebo[10] = "てぼ";
    char hira[10] = "平ザル";
    char explanation[10] = "操作説明";
    char ranking[12] = "ランキング";
    char mark[5] = "■";
};

#endif //_MENU_H_