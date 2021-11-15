#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "Sound.h"
#include "Keyboard.h"

static int mImageHandles[6];    //�摜�n���h���i�[�p�ϐ�
//������
void Config_Initialize() {
    mImageHandles[0] = LoadGraph("images/config/back_alpha.png");//�w�i
    mImageHandles[1] = LoadGraph("images/config/�X���C�h1.png");
    mImageHandles[2] = LoadGraph("images/config/�X���C�h2.png");
    mImageHandles[3] = LoadGraph("images/config/�X���C�h3.png");
}

//�I������
void Config_Finalize() {
    DeleteGraph(mImageHandles[0]);//�摜�̉��
    DeleteGraph(mImageHandles[1]);//�摜�̉��
    DeleteGraph(mImageHandles[2]);//�摜�̉��
    DeleteGraph(mImageHandles[3]);//�摜�̉��
}

enum {
    pMenu,
    pGame,
    pScore_Rank,
};
#define PAGE_NUMBER 3 //�y�[�W��
static int Page = pMenu;
//�X�V
void Config_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
        Enter_Sound();
        Config_Finalize();
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
    if (Keyboard_Get(KEY_INPUT_RETURN) == 1) {
        Page++;
        Page %= PAGE_NUMBER;
    }
}
void Con_Menu();
void Con_Game();
void Con_GameEX();
void Con_ScoreRank();

//�`��
void Config_Draw() {
    DrawBox(0, 0,1200, 700, GetColor(255, 255, 255),TRUE);
    DrawGraph(0, 0, mImageHandles[0], TRUE); // �摜��`�悷��
    DrawBoxAA(100,50,1100,640,GetColor(255,0,0), FALSE);
    DrawString(0, 0, "��������`", GetColor(0,0,0));
    DrawString(800, 640, "Esc�L�[�Ń��j���[�ɖ߂�", GetColor(0, 0, 0));
    DrawString(800,670, "Enter�L�[�Ŏ��̃y�[�W", GetColor(0, 0, 0));
    switch (Page)
    {
    case pMenu:
        Con_Menu();
        break;
    case pGame:
        Con_Game();
        break;
    case pScore_Rank:
        Con_ScoreRank();
        break;
    default:
        break;
    }
    //DrawString(0, 20, "Esc�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}
//����
void Con_Menu() {
    DrawString(30*5, 0, "���j���[�`", GetColor(0, 0, 0));
    DrawGraph(100, 50, mImageHandles[1], TRUE);//���j���[
}
void Con_Game() {
    DrawString(30 * 5, 0, "�v���C�`", GetColor(0, 0, 0));
    DrawGraph(100, 50, mImageHandles[2], TRUE);//�Q�[��
}
void Con_GameEX() {

}
void Con_ScoreRank() {
    DrawString(30 * 5, 0, "�X�R�A�������L���O�`", GetColor(0, 0, 0));
    DrawGraph(100, 50, mImageHandles[3], TRUE);//���j���[
}