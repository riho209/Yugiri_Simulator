#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"
#include "Sound.h"
#include "Func.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    if(DxLib_Init()==-1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    SetGraphMode(1200, 700, 32);
    SceneMgr_Initialize();
    Sound_Initialize();
    serial_initialize();
    
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        Keyboard_Update();
        SceneMgr_Update();
        SceneMgr_Draw();
        if (CheckHitKey(KEY_INPUT_BACK) != 0) {
            break;
        }
    }
    Sound_Finalize();
    SceneMgr_Finalize();

    DxLib_End();
    return 0;
}