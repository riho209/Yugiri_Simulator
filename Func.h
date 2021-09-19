#pragma once


typedef enum {
	init,
    tebo,
    hirazaru
} eKind;

typedef struct
{
	int startTime;
	int time;
	int score;
	int equipment;
} SaveData;

void sleep(int ms);

void timer(int second);

int Time_Get();
void Time_Update();
void Time_Draw();
void Time_Finalize();

void ScoreV_Update();
int ScoreV_Get();
void ScoreV_Finalize();

int UseEquipment_Get();
void UseEquipment_Update(eKind kind);

int SceneChangeFlag_Get();
void SceneChangeFlag_Allow();
void SceneChangeFlag_Forbid();

SaveData CurrentPlayData_Get();

void AllPlayData_Update();
void AllPlayData_Draw(int x, int y);