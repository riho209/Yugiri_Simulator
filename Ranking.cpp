#include "Ranking.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Ranking_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Ranking);//�V�[�����I����ʂɕύX
    }
}

//�`��
void Ranking_Draw() {
    DrawString(0, 0, "�����L���O��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Enter�L�[�������ƏI����ʂɈڂ�", GetColor(255, 255, 255));
}