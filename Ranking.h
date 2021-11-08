#ifndef _RANKING_H_
#define _RANKING_H_

struct string_rank {

    char rank[20] = "ランキング";
    char explan[40] = "Enterキーを押してください";
    char time[20] = "経過時間(ミリ秒):　";
    char score[15] = "スコア:　";
};
//初期化
void Ranking_Initialize();

//更新
void Ranking_Update();

//描画
void Ranking_Draw();

//終了処理
void Ranking_Finalize();
#endif // _RANKING_H_