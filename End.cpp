#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void End_Update() {
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) { //�G���^�[�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void End_Draw() {
    DrawString(0, 0, "End��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "�G���^�[�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}