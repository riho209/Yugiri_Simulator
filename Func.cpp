#include "Func.h"
#include "DxLib.h"
#include <iostream>
#include <chrono>
#include <thread>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
#define RANKINGRANGE 10
using namespace std;
//using std::this_thread::sleep_for;

static int sceneChangeFlag = 0; //0:画面遷移を禁止 1:画面遷移を許可

static SaveData currentPlayData;

static int imageHandle = LoadGraph("images/1.png");

/*
void sleep(int ms) {
	sleep_for(std::chrono::milliseconds(ms));
}
*/

void timer(int second) {
    int timediff = 1;
    LONGLONG timelimit = GetNowHiPerformanceCount() + second * 1000000;
    while (timediff > 0) {
        timediff = int(timelimit - GetNowHiPerformanceCount());
        ClearDrawScreen();
        DrawFormatString(5, 5, GetColor(255, 255, 255), "%02d'%02d'%d%d", timediff / 60000000, (timediff % 60000000) / 1000000, ((timediff % 60000000) % 1000000) / 100000, (((timediff % 60000000) % 1000000) % 100000) / 10000);
        ScreenFlip();
    }
}

int Time_Get() {
    return(currentPlayData.time);
}

void Time_Draw(int x, int y, int cr) {
    DrawFormatString(x, y, cr, "経過時間(ミリ秒): %d", currentPlayData.time);
    DrawFormatString(x, y+100, cr, "経過時間(h:m:s): %02d:%02d:%02d", (currentPlayData.time / 1000) /3600, ((currentPlayData.time / 1000) % 3600) / 60, (currentPlayData.time/1000) % 60);
}

void Time_Update() {
    currentPlayData.time = GetNowCount() - currentPlayData.startTime;
}

void ScoreV_Update() {
    switch (currentPlayData.equipment) {
    case tebo:
        currentPlayData.score = 10000 - currentPlayData.time + 10;
        break;
    case hirazaru:
        currentPlayData.score = 10000 - currentPlayData.time + 100;
        break;
    }
    if (currentPlayData.score < 1) {
        currentPlayData.score = 1;
    }
}

int ScoreV_Get() {
    return(currentPlayData.score);
}

void ScoreV_Finalize() {
    currentPlayData.score = 0;
}

int UseEquipment_Get() {
    return(currentPlayData.equipment);
}

void UseEquipment_Update(eKind kind) {
    currentPlayData.equipment = kind;
}

void UseEquipment_Draw(int x, int y, int cr) {
    switch (currentPlayData.equipment) {
    case tebo:
        DrawString(x, y, "てぼモード", cr);
        break;
    case hirazaru:
        DrawString(x, y, "ひらざるモード", cr);
        break;
    }
}

int SceneChangeFlag_Get() {
    return(sceneChangeFlag);
}

void SceneChangeFlag_Allow() {
    sceneChangeFlag = 1;
}

void SceneChangeFlag_Forbid() {
    sceneChangeFlag = 0;
}

SaveData CurrentPlayData_Get() {
    return(currentPlayData);
}

//csvで書き込み time,score,equipment
int WritePlayData(const char* fileName) {
    std::ofstream ofs(fileName, std::ios::app);
    if (!ofs) {
        std::cout << "ファイルが開けませんでした" << endl;
        return 0;
    }
    ofs << currentPlayData.time << "," << currentPlayData.score << "," << currentPlayData.equipment << endl;
    cout << "書き込み完了" << endl;

    return 1;
}

vector<int> split(string str, char del) {
    int first = 0;
    int last = int(str.find_first_of(del));

    vector<int> result;
    int size = int(str.size());
    while (first < size) {
        string subStr(str, first, last - first);
        int num = stoi(subStr.c_str());
        result.push_back(num);
        first = last + 1;
        last = int(str.find_first_of(del, first));
        if (last == string::npos) {
            last = int(str.size());
        }
    }
    return result;
}
vector <vector<int>> csv2vector(string filename, int ignore_line_num) {
    //csvファイルの読み込み
    ifstream reading_file;
    reading_file.open(filename, ios::in);
    if (!reading_file) {
        vector<vector<int> > data;
        return data;
    }
    std::string reading_line_buffer;
    for (int line = 0; line < ignore_line_num; line++) {
        getline(reading_file, reading_line_buffer);
        if (reading_file.eof()) break;
    }
    //二次元のvectorを作成
    vector<vector<int> > data;
    while (getline(reading_file, reading_line_buffer)) {
        if (reading_line_buffer.size() == 0) break;
        vector<int> temp_data;
        temp_data = split(reading_line_buffer, ',');
        data.push_back(temp_data);
    }
    return data;
}

void CurrentPlayData_Initialize() {
    currentPlayData = {
        GetNowCount(),
        0,
        0,
        init
    };
}

void AllPlayData_Update() {
    int f = WritePlayData("Save_Data/Score.csv");
    if (f == 0) return; //書き込み失敗
    
}

void AllPlayData_Draw(int x, int y) {
    static int cr;
    vector <vector<int>> allplay_data=csv2vector("Save_Data/Score.csv", 0);
    sort(allplay_data.rbegin(), allplay_data.rend(),[](const vector<int>& alpha, const vector<int>& beta) {return alpha[1] < beta[1]; });
    DrawString(x, y-20, "順位　時間　スコア　器具", GetColor(255, 255, 255));
    int range = RANKINGRANGE;
    if (int(allplay_data.size()) < RANKINGRANGE) range = int(allplay_data.size());
    for (int i = 0; i <range; i++) {
        if (currentPlayData.time == allplay_data[i][0]) { //ここの比較方法あまり良くないかも
            cr = GetColor(255, 255, 0);
        }
        else {
            cr = GetColor(255, 255, 255);
        }
        switch (allplay_data[i][2]) {
        case tebo:
            DrawFormatString(x, y + i * 20, cr, "%d位 %d %d てぼ", i + 1, allplay_data[i][0], allplay_data[i][1]);
            break;
        case hirazaru:
            DrawFormatString(x, y + i * 20, cr, "%d位 %d %d ひらざる", i + 1, allplay_data[i][0], allplay_data[i][1]);
            break;   
        }
    }
}

void Enter_Sound() {
    static int Handle = LoadSoundMem("sounds/決定、ボタン押下1.mp3");
    PlaySoundMem(Handle, DX_PLAYTYPE_BACK);
}
