#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "Sound.h"
#include "WaterMeter.h"
#include <math.h>

#define PI 3.141592654f
//�Ăڂ̍��W
static int x;
static int y;

static int water = 100;
unsigned int cr = GetColor(255, 255, 255);

static int mImageHandles;//�摜�̃��[�h
unsigned int background_cr = GetColor(254, 247, 240);
static char c;
static int tebo_image;
static int hirazaru_image;
static int logo_image;
static data_bank d;

static int count_down_st;
static int count_down_length;
static eGameMode current_game_mode;

static int s321_images[4];
static int nokori_jikan;


//������
void Game_Initialize() {
    mImageHandles = LoadGraph("images/game_frame2.png");//�摜�̃��[�h
    tebo_image = LoadGraph("images/���炷�Ƃ�_�Ă�.png");
    hirazaru_image = LoadGraph("images/�Ђ炴��_����.png");
    logo_image = LoadGraph("images/fcac755457d6a1c96093e16707ad773c_t.jpeg");
    s321_images[0]= LoadGraph("s321_images_v1/start.png");
    s321_images[1] = LoadGraph("s321_images_v1/1.png");
    s321_images[2] = LoadGraph("s321_images_v1/2.png");
    s321_images[3] = LoadGraph("s321_images_v1/3.png");
    send_current_equipment();
    count_down_st = GetNowCount();
    count_down_length = 3000;
    current_game_mode = count_down;
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandles);//�摜�̉��
}
//�X�V
void start123_Draw(double nokori_jikan);
void Game_Update() {
        switch (current_game_mode) {
        case count_down:
            nokori_jikan = (count_down_length / 1000) - (((GetNowCount() - count_down_st) / 1000) % 60);
            start123_Draw(nokori_jikan);
            if ((GetNowCount() - count_down_st) >= count_down_length) {
                Time_Reset();
                current_game_mode = play;
            }
            break;
        case play:
            ScoreV_Update();
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
                //DrawString(0, 0, "Low", cr);
                water -= 1;
                break;
            case 'm':
                UseEquipment_MoveDraw(100, 100, 0, 50, 50);
                //DrawString(0, 0, "Mid", cr);
                water -= 5;
                break;
            case 'h':
                UseEquipment_MoveDraw(100, 100, 0, 50, 10);
                //DrawString(600, 350, "High!!", cr);
                HighCount_Increment(); // 11/12�ǉ�
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
    switch (current_game_mode) {
    case count_down:
        DrawFormatString(0, 50, cr, "%d", GetNowCount() - count_down_st);
        DrawFormatString(0, 100, cr, "%d", (count_down_length / 1000) - (((GetNowCount() - count_down_st) / 1000) % 60));
        break;
    case play:
        DrawGraph(0, 0, mImageHandles, TRUE); // �摜��`�悷��
        DrawBox(680, 90,1100,250, GetColor(255,0,0), TRUE);
        UseEquipment_Draw(700,100, cr);
        DrawFormatString(700, 130, cr, "������: %d", water);
        Time_Draw(700,160, cr);
        //DrawRotaGraph(310, 225, 1.4, 0.0, imageHandle, TRUE); //�摜�̕`��
        //DrawString(0, 80, "�������[�^", cr);
        WaterMeter_Calc(water, 500, 100, 5, 100, 50, 2);
        DrawFormatString(500, 400, cr, "������: %d", water);
        WaterMeter_Sound(water);
        DrawFormatString(500, 420, cr, "�X�R�A: %d", ScoreV_Get()); // 11/12�ǉ�
        DrawFormatString(500, 440, cr, "High���o������: %d", HighCount_Get()); // 11/12�ǉ�
        /// <summary>
        /// ///////////////////////////////////////////////////////////////////

        //UseEquipment_MoveDraw(100, 100, 0, 50, 10);
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
void start123_Draw(double nokori_jikan) {
    DrawString(300, 100, "�Q�[���J�n�܂Ŏc��", GetColor(255, 255, 255));
    nokori_jikan = (count_down_length / 1000) - (((GetNowCount() - count_down_st) / 1000) % 60);
    if (4.0 >= nokori_jikan && nokori_jikan > 3.0) {
        DrawRotaGraph(400, 300, 1.5, 0.0, s321_images[3], TRUE); // 3
    }
    else if (3.0 >= nokori_jikan && nokori_jikan > 2.0) {
        DrawRotaGraph(400, 300, 1.5, 0.0, s321_images[2], TRUE); // 2
    }
    else if (2.0 >= nokori_jikan && nokori_jikan > 1.0) {
        DrawRotaGraph(400, 300, 1.5, 0.0, s321_images[1], TRUE); // 1
    }
    else if (1.0 >= nokori_jikan && nokori_jikan > 0.1) {
        DrawRotaGraph(400, 300, 1.5, 0.0, s321_images[0], TRUE); // �Q�[���J�n
        ShakuHachi_Sound();
    }
}