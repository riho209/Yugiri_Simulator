#ifndef _MENU_H_
#define _MENU_H_

//������
void Menu_Initialize();

//�X�V
void Menu_Update();

//�`��
void Menu_Draw();

void Menu_Finalize();//�I������
struct string_bank{
    char  menu[30] = "���j���[";
    char  coment[60] = "�㉺�L�[�I���AEnter����";
    char play[10] = "�v���C";
    char tebo[10] = "�Ă�";
    char hira[10] = "���U��";
    char explanation[10] = "�������";
    char ranking[12] = "�����L���O";
    char mark[5] = "��";
};

#endif //_MENU_H_