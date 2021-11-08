#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
static int efsHandle;//���ʉ�Enter
//������
void Config_Initialize() {
    mImageHandle = LoadGraph("images/back.jpg");//�摜�̃��[�h
    efsHandle = LoadSoundMem("sounds/����A�{�^������1.mp3");
}

//�I������
void Config_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��
    DeleteSoundMem(efsHandle);//�T�E���h�J��
}
//�X�V
void Config_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        PlaySoundMem(efsHandle, DX_PLAYTYPE_BACK);
        Config_Finalize();
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Config_Draw() {
    DrawGraph(0, 0, mImageHandle, TRUE); // �摜��`�悷��
    DrawString(0, 0, "�������", GetColor(255, 255, 255));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}