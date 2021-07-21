#include "DxLib.h"
#include "Mwindow.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}