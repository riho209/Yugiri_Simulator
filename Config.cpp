#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Config_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Config.png");//�摜�̃��[�h
}

//�I������
void Config_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��
}
//�X�V
void Config_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Config_Draw() {
    DrawString(0, 0, "���������ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}