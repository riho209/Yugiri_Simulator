#ifndef _SCORE_H_
#define _SCORE_H_

struct string_score {

    char explanation[20] = "�X�R�A";
    char ranking[40] = "Enter�L�[�������Ă�������";
    char time[20] = "�o�ߎ���(�~���b):�@";
    char score[15] = "�X�R�A:�@";
};
//������
void Score_Initialize();
//�X�V
void Score_Update();
//�`��
void Score_Draw();
//�I������
void Score_Finalize();
#endif // _SCORE_H_