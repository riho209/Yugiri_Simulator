#include "Ranking.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include "Sound.h"
#include<vector>
#include <algorithm>
using namespace std;
//�X�V

static string_rank str_rank;
const static int font_size = 40;
static vector <vector<int>> allplay_data;
static int mImageHandles;
//������
void Ranking_Initialize() {
    SetFontSize(font_size);
    allplay_data = csv2vector("Save_Data/Score.csv", 0);
    sort(allplay_data.rbegin(), allplay_data.rend(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[1] < beta[1]; });
    mImageHandles= LoadGraph("images/rank.jpg");
}
void Ranking_Update() {
    //sleep(100);
    if (CheckHitKey(KEY_INPUT_RETURN) == 0 && SceneChangeFlag_Get() == 0) {
        SceneChangeFlag_Allow();
    }
    if (CheckHitKey(KEY_INPUT_RETURN) != 0 && SceneChangeFlag_Get() == 1) {
        SceneChangeFlag_Forbid();
        Enter_Sound();
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[��ʂɕύX
    }
    //H8
    /*
    if (get_buf_h8maikon() == 'a') {
        SceneMgr_ChangeScene(eScene_Menu);
    }
    */
}

//�`��
void Ranking_Draw() {
    DrawGraph(0, 0, mImageHandles, TRUE);
    //DrawString(600-5*font_size, 0,str_rank.rank, GetColor(255, 255, 255));
    //DrawString(600-5*font_size,font_size, str_rank.explan, GetColor(255, 255, 255));
    AllPlayData_Draw(400, 110, allplay_data);
}

//�I������
void Ranking_Finalize() {
    //vector�̉�@

    DeleteGraph(mImageHandles);//�摜�̉��
}