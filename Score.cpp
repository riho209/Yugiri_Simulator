#include "Score.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Score_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Ranking);//�V�[���������L���O�ɕύX
    }
}

//�`��
void Score_Draw() {
    DrawString(0, 0, "�X�R�A��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Enter�L�[�������ƃ����L���O��ʂɈڂ�", GetColor(255, 255, 255));
}