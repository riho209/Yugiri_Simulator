#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "WaterMeter.h"
#include <math.h>

#define PI 3.141592654f
//�Ăڂ̍��W
static int x;
static int y;

static int water = 100;
unsigned int cr = GetColor(255, 255, 255);

static int mImageHandle;//�摜�̃��[�h
unsigned int background_cr = GetColor(254, 247, 240);
static char c;
static int tebo_image;
static int hirazaru_image;
static int logo_image;
static data_bank d;

static int count_down_st;
static int count_down_length;
static eGameMode current_game_mode;

//������
void Game_Initialize() {
    mImageHandle = LoadGraph("images/game_frame2.png");//�摜�̃��[�h
    tebo_image = LoadGraph("images/���炷�Ƃ�_�Ă�.png");
    hirazaru_image = LoadGraph("images/�Ђ炴��_����.png");
    logo_image = LoadGraph("images/fcac755457d6a1c96093e16707ad773c_t.jpeg");
    
    send_current_equipment();

    count_down_st = GetNowCount();
    count_down_length = 3000;
    current_game_mode = count_down;
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��
}
//�X�V
void Game_Update() {
    switch (current_game_mode) {
    case count_down:
        if ((GetNowCount() - count_down_st) >= count_down_length) {
            CurrentPlayData_Initialize();
            current_game_mode = play;
        }
        break;
    case play:
        Time_Update();
        //�{�Ԃ͉�3�s����Ȃ�
        if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
            water = water - 1;
        }

        if (water <= 0) {
            water = 100;
            SceneMgr_ChangeScene(eScene_Score);
        }

        switch (get_buf_shogeki()) {
        case 'l':
            UseEquipment_MoveDraw(100, 100, 0, 50, 100);
            water -= 1;
            break;
        case 'm':
            UseEquipment_MoveDraw(100, 100, 0, 50, 50);
            water -= 5;
            break;
        case 'h':
            UseEquipment_MoveDraw(100, 100, 0, 50, 10);
            water -= 10;
            break;
        default:
            UseEquipment_MoveDraw(100, 100, 0, 50, 500);
            break;
        }
        break;
    }
}

//�`��
void Game_Draw() {
    //timer(100);
    switch (current_game_mode) {
    case count_down:
        DrawFormatString(0, 50, cr, "%d", GetNowCount() - count_down_st);
        DrawFormatString(0, 100, cr, "%d", (count_down_length / 1000) - (((GetNowCount() -count_down_st) / 1000) % 60));
        break;
    case play:
        DrawGraph(0, 0, mImageHandle, TRUE); // �摜��`�悷��
        DrawString(0, 0, "�v���C���", cr);
        DrawString(0, 20, "esc�L�[�������Đ����ʂ�0�ɂ��Ă�������", cr);
        DrawFormatString(0, 40, cr,"������: %d", water);
        Time_Draw(0, 60, cr);
        UseEquipment_Draw(0, 80, cr);
        //�`��
        SetBackgroundColor(254, 247, 240);
        //DrawRotaGraph(310, 225, 1.4, 0.0, imageHandle, TRUE); //�摜�̕`��
        SetFontSize(64);
        DrawString(0, 0, "�v���C���", cr);
        SetFontSize(20);
        //DrawString(0, 80, "�������[�^", cr);
        WaterMeter_Calc(water, 500, 100, 5, 100, 50, 2);
        DrawFormatString(500, 400, cr, "������: %d", water);
        //WaterMeter_Sound(water);

        //UseEquipment_MoveDraw(100, 100, 0, 50, 10);
        Time_Draw(0, 60, cr);
        d.count++;
        break;
    }
}
//�Ăڂ̃o�C�u���[�V�����@�\
void UseEquipment_MoveDraw(int x0, int y0, int dx, int dy, int t) {
    x = x0 + dx * cos(2 * PI / t * d.count);
    y = y0 + dy * sin(2 * PI / t * d.count);
    switch (UseEquipment_Get()) {
    case tebo:
        DrawGraph(x, y, tebo_image, TRUE);
        break;
    case hirazaru:
        DrawGraph(x, y, hirazaru_image, TRUE);
        break;
    }
    d.count++;
}