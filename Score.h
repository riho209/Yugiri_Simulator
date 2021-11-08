#ifndef _SCORE_H_
#define _SCORE_H_

struct string_score {

    char explanation[20] = "スコア";
    char ranking[40] = "Enterキーを押してください";
    char time[20] = "経過時間(ミリ秒):　";
    char score[15] = "スコア:　";
};
//初期化
void Score_Initialize();
//更新
void Score_Update();
//描画
void Score_Draw();
//終了処理
void Score_Finalize();
#endif // _SCORE_H_