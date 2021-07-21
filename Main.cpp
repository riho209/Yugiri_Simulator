#include "DxLib.h"
#include "Mwindow.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //

    DxLib_End(); //
    return 0;
}