#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Game_Update() {
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //�G���^�[�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Score);//�V�[�����X�R�A�ɕύX
    }
}

//�`��
void Game_Draw() {
    DrawString(0, 0, "�v���C��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Enter�L�[�������ƃX�R�A��ʂɈڂ�܂��B", GetColor(255, 255, 255));
}