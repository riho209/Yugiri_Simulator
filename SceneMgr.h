#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_

typedef enum {
    eScene_Menu,    //メニュー画面
    eScene_Game,    //ゲーム画面
    eScene_Config,  //設定画面
    eScene_Ranking, //ランキング画面
    eScene_Score, //スコア表示画面

    eScene_None //none
} eScene ;


//更新
void SceneMgr_Update();

//描画
void SceneMgr_Draw();

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene);
void SceneMgr_Initialize();//初期化
void SceneMgr_Finalize();//終了処理
#endif //_SCENEMGR_H_