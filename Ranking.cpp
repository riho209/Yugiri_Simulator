#include "Ranking.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"
#include<vector>
#include <algorithm>
using namespace std;
//更新

static string_rank str_rank;
const static int font_size = 30;
static vector <vector<int>> allplay_data;
static int efsHandle;//効果音Enter
static int mImageHandle;
//初期化
void Ranking_Initialize() {
    efsHandle = LoadSoundMem("sounds/決定、ボタン押下1.mp3");
    allplay_data = csv2vector("Save_Data/Score.csv", 0);
    sort(allplay_data.rbegin(), allplay_data.rend(), [](const vector<int>& alpha, const vector<int>& beta) {return alpha[1] < beta[1]; });
    mImageHandle= LoadGraph("images/rank.jpg");
}
void Ranking_Update() {
    //sleep(100);
    if (CheckHitKey(KEY_INPUT_RETURN) == 0 && SceneChangeFlag_Get() == 0) {
        SceneChangeFlag_Allow();
    }
    if (CheckHitKey(KEY_INPUT_RETURN) != 0 && SceneChangeFlag_Get() == 1) {
        SceneChangeFlag_Forbid();
        PlaySoundMem(efsHandle, DX_PLAYTYPE_BACK);
        SceneMgr_ChangeScene(eScene_Menu);//シーンをメニュー画面に変更
    }
    //H8
    /*
    if (get_buf_h8maikon() == 'a') {
        SceneMgr_ChangeScene(eScene_Menu);
    }
    */
}

//描画
void Ranking_Draw() {
    DrawGraph(0, 0, mImageHandle, TRUE);
    DrawString(600-5*font_size, 0,str_rank.rank, GetColor(255, 255, 255));
    DrawString(600-5*font_size,font_size, str_rank.explan, GetColor(255, 255, 255));
    AllPlayData_Draw(400, 150, allplay_data);
}

//終了処理
void Ranking_Finalize() {
    //vectorの解法
    DeleteSoundMem(efsHandle);//サウンド開放
    DeleteGraph(mImageHandle);//画像の解放
}