#pragma once
#include<string>
#include<vector>
using namespace std;

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
	int high_count; // 11/12í«â¡
} SaveData;


int Time_Get();
void Time_Update();
void Time_Draw(int x, int y, int cr);
void Time_Reset();
void ScoreV_Update();
int ScoreV_Get();
void ScoreV_Finalize();

void HighCount_Increment(); // 11/12í«â¡
int HighCount_Get(); // 11/12í«â¡

int UseEquipment_Get();
void UseEquipment_Update(eKind kind);
void UseEquipment_Draw(int x, int y, int cr);

int SceneChangeFlag_Get();
void SceneChangeFlag_Allow();
void SceneChangeFlag_Forbid();

SaveData CurrentPlayData_Get();
int WritePlayData(const char* fileName); //csvÇ≈èëÇ´çûÇ›
void CurrentPlayData_Initialize();

void AllPlayData_Update();
void AllPlayData_Draw(int x, int y, vector <vector<int>> allplay_data);
//serialí êMä÷òA
void serial_initialize();
char get_buf_h8maikon();
char get_buf_shogeki();
void send_current_equipment();

vector <vector<int>> csv2vector(string filename, int ignore_line_num);
