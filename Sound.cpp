#include "DxLib.h"
#include "Sound.h"

static int opening_handle;
static int enter_handle;
static int applause;
static int menu_bgm;
static int shaku_hachi_handle;
//ロード
void Sound_Initialize() {
    opening_handle = LoadSoundMem("sounds/ラーメン屋台登場.mp3");
    enter_handle = LoadSoundMem("sounds/和太鼓でドドン.mp3");
    applause = LoadSoundMem("sounds/歓声と拍手.mp3");
    menu_bgm = LoadSoundMem("sounds/メニューBGM.wav");
    shaku_hachi_handle = LoadSoundMem("sounds/尺八.mp3");
}
//メモリ開放
void Sound_Finalize() {
     InitSoundMem();
}
void Menu_BGM() {
    PlaySoundMem(menu_bgm, DX_PLAYTYPE_LOOP);
}
void Stop_Menu_BGM() {
    StopSoundMem(menu_bgm);
}
void Opening_Sound() {
    PlaySoundMem(opening_handle, DX_PLAYTYPE_LOOP);
}

void Enter_Sound() {
    PlaySoundMem(enter_handle, DX_PLAYTYPE_BACK);
}
void Applause_Sound() {
    PlaySoundMem(applause, DX_PLAYTYPE_BACK);
}
void ShakuHachi_Sound() {
    PlaySoundMem(shaku_hachi_handle, DX_PLAYTYPE_BACK);
}