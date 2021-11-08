#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_

typedef enum {
    eScene_Menu,    //���j���[���
    eScene_Game,    //�Q�[�����
    eScene_Config,  //�ݒ���
    eScene_Ranking, //�����L���O���
    eScene_Score, //�X�R�A�\�����

    eScene_None //none
} eScene ;


//�X�V
void SceneMgr_Update();

//�`��
void SceneMgr_Draw();

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);
void SceneMgr_Initialize();//������
void SceneMgr_Finalize();//�I������
#endif //_SCENEMGR_H_