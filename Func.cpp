#include "Func.h"
#include "DxLib.h"
#include <iostream>
#include <chrono>
#include <thread>

using std::this_thread::sleep_for;

static int sceneChangeFlag = 0; //0:‰æ–Ê‘JˆÚ‚ð‹ÖŽ~ 1:‰æ–Ê‘JˆÚ‚ð‹–‰Â

static SaveData currentPlayData = {
    GetNowCount(),
    0,
    0,
    init
};

static SaveData allPlayData[100] = {};

static int playDataNumber = 0; //allPlayData‚Ì—v‘f”‚ðŠÇ—‚·‚é•Ï”

void sleep(int ms) {
	sleep_for(std::chrono::milliseconds(ms));
}

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

void Time_Draw() {
    DrawFormatString(0, 60, GetColor(255, 255, 255), "Œo‰ßŽžŠÔ(ƒ~ƒŠ•b): %d", currentPlayData.time);
}

void Time_Update() {
    currentPlayData.time = GetNowCount() - currentPlayData.startTime;
}

void Time_Finalize() {
    currentPlayData.time = 0;
    currentPlayData.startTime = GetNowCount();
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


void AllPlayData_Update() {
    allPlayData[playDataNumber] = currentPlayData;
    playDataNumber = playDataNumber + 1;
}
int compar(const void* a, const void* b) {
    if (((SaveData*)a)->score < ((SaveData*)b)->score) {
        return 1;
    }
    else {
        return -1;
    }
}

void AllPlayData_Draw(int x, int y) {
    qsort(allPlayData, 10, sizeof(SaveData), compar);
    for (int i = 0; i < 10; i++) {
        switch (allPlayData[i].equipment) {
        case tebo:
            DrawFormatString(x, y + i * 20, GetColor(255, 255, 255), "%d %d ‚Ä‚Ú", allPlayData[i].time, allPlayData[i].score);
            break;
        case hirazaru:
            DrawFormatString(x, y + i * 20, GetColor(255, 255, 255), "%d %d ‚Ð‚ç‚´‚é", allPlayData[i].time, allPlayData[i].score);
            break;
        }
    }
}