#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə���Ɨ���ʐݒ�

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ��

        Keyboard_Update();    //�L�[�{�[�h�̍X�V

        SceneMgr_Update();  //�X�V
        SceneMgr_Draw();    //�`��

    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}