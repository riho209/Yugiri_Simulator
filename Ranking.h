#ifndef _RANKING_H_
#define _RANKING_H_

struct string_rank {

    char rank[20] = "�����L���O";
    char explan[40] = "Enter�L�[�������Ă�������";
    char time[20] = "�o�ߎ���(�~���b):�@";
    char score[15] = "�X�R�A:�@";
};
//������
void Ranking_Initialize();

//�X�V
void Ranking_Update();

//�`��
void Ranking_Draw();

//�I������
void Ranking_Finalize();
#endif // _RANKING_H_