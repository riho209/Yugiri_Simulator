#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Keyboard.h"

const static int PLAY_Y = 240;    //�u�e�{�v������y�ʒu
const static int EXPLANATION_Y = 300;    //�u�ݒ�v������y�ʒu

typedef enum {

    eMenu_PLAY,        //�v���C
    
    eMenu_EXPLANATION,    //�������

    eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_PLAY;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
void Menu_Update() {
    if (Keyboard_Get(KEY_INPUT_DOWN) == 1) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (Keyboard_Get(KEY_INPUT_UP) == 1) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_PLAY://�v���C�I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
            break;
        case eMenu_EXPLANATION://��������I�𒆂Ȃ�
            SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
            break;
        }
    }
}

//�`��
void Menu_Draw() {
    DrawString(200, 150, "���j���[��ʂł��B", GetColor(255, 255, 255));
    DrawString(200, 170, "�㉺�L�[�������A�G���^�[�������ĉ������B", GetColor(255, 255, 255));
    DrawString(280, PLAY_Y, "�v���C", GetColor(255, 255, 255));
    DrawString(280, EXPLANATION_Y, "�������", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMenu_PLAY://�Q�[���I�𒆂Ȃ�
        y = PLAY_Y;    //�Q�[���̍��W���i�[
        break;
    case eMenu_EXPLANATION://�ݒ�I�𒆂Ȃ�
        y = EXPLANATION_Y;    //�ݒ�̍��W���i�[
        break;
    }
    DrawString(250, y, "��", GetColor(255, 255, 255));
}
