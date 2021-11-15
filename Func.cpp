#include "Func.h"
#include "DxLib.h"
#include <iostream>
#include <chrono>
#include <thread>
#include<fstream>
#include "erslib19.h" //�V���A���ʐM���ȒP�ɂ��Ă����w�b�_�t�@�C��
#define RANKINGRANGE 10
//using std::this_thread::sleep_for;

static int sceneChangeFlag = 0; //0:��ʑJ�ڂ��֎~ 1:��ʑJ�ڂ�����

static SaveData currentPlayData;
//��������V���A���ʐM�p�ϐ�
#define BUFSIZE 5000

static int com_h8maikon = 1;
static char buf_h8maikon[1000];
static int r_h8maikon;

static int com_shogeki_tebo = 3;
static char buf_shogeki_tebo[1000];
static int r_shogeki_tebo;

static int com_shogeki_hira = 4;
static char buf_shogeki_hira[1000];
static int r_shogeki_hira;

static char buf_current_equipment[1000];
//�����܂ŃV���A���ʐM�p�ϐ�
static int yello = GetColor(255, 241, 0);
//�^�C�}���Z�b�g
void Time_Reset() {
    currentPlayData.startTime = GetNowCount();
}
int Time_Get() {
    return(currentPlayData.time);
}

void Time_Draw(int x, int y, int cr) {
    DrawFormatString(x, y, cr, "�o�ߎ���(�~���b): %d", currentPlayData.time);
    DrawFormatString(x, y+30, cr, "�o�ߎ���(h:m:s): %02d:%02d:%02d", (currentPlayData.time / 1000) /3600, ((currentPlayData.time / 1000) % 3600) / 60, (currentPlayData.time/1000) % 60);
}

void Time_Update() {
    currentPlayData.time = GetNowCount() - currentPlayData.startTime;
}

void ScoreV_Update() {
    switch (currentPlayData.equipment) {
    case tebo:
        currentPlayData.score = 10000 - currentPlayData.time + 10 + currentPlayData.high_count * 100;
        break;
    case hirazaru:
        currentPlayData.score = 10000 - currentPlayData.time + 100 + currentPlayData.high_count * 100;
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

void HighCount_Increment() {
    currentPlayData.high_count += 1;
}
int HighCount_Get() {
    return(currentPlayData.high_count);
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
        DrawString(x, y, "�Ăڃ��[�h", cr);
        break;
    case hirazaru:
        DrawString(x, y, "�Ђ炴�郂�[�h", cr);
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

//csv�ŏ������� time,score,equipment
int WritePlayData(const char* fileName) {
    std::ofstream ofs(fileName, std::ios::app);
    if (!ofs) {
        std::cout << "�t�@�C�����J���܂���ł���" << endl;
        return 0;
    }
    ofs << currentPlayData.time << "," << currentPlayData.score << "," << currentPlayData.equipment << currentPlayData.high_count<< endl;
    cout << "�������݊���" << endl;

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
    //csv�t�@�C���̓ǂݍ���
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
    //�񎟌���vector���쐬
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
        init,
        0 // 11/12�ǉ�
    };
}

void AllPlayData_Update() {
    int f = WritePlayData("Save_Data/Score.csv");
    if (f == 0) return; //�������ݎ��s
    
}
static int cr;
#define FONT 40

void AllPlayData_Draw(int x, int y, vector <vector<int>> allplay_data) {
    DrawString(x,y- FONT, "���� ���� �X�R�A ���@HIGH�̉�", GetColor(255, 255, 255));
    int range = RANKINGRANGE;
    if (int(allplay_data.size()) < RANKINGRANGE) range = int(allplay_data.size());
    for (int i = 0; i <range; i++) {
        if (currentPlayData.time == allplay_data[i][0]) { //�����̔�r���@���܂�ǂ��Ȃ�����
            cr = GetColor(255, 255, 0);
        }
        else {
            cr = GetColor(255, 255, 255);
        }
        switch (allplay_data[i][2]) {
        case tebo:
            DrawFormatString(x, y + (i+1) * FONT, cr, "%2d�� %4d %5d  �Ăځ@�@ %2d", i + 1, allplay_data[i][0], allplay_data[i][1], allplay_data[i][3]);
            break;
        case hirazaru:
            DrawFormatString(x, y + (i + 1) * FONT, cr, "%2d�� %4d %5d  �Ђ炴�� %2d", i + 1, allplay_data[i][0], allplay_data[i][1], allplay_data[i][3]);
            break;   
        }
    }
}

//��������V���A���ʐM�֐�
void serial_initialize() {
    r_h8maikon = ERS_Open(com_h8maikon, BUFSIZE, BUFSIZE);    // rs232c�̃|�[�g���I�[�v������
    ERS_Config(com_h8maikon, ERS_9600);		// �ʐM���x��9600bps�ɂ���(�f�t�H���g)

    r_shogeki_tebo = ERS_Open(com_shogeki_tebo, BUFSIZE, BUFSIZE);
    ERS_Config(com_shogeki_tebo, ERS_9600);

    r_shogeki_hira = ERS_Open(com_shogeki_hira, BUFSIZE, BUFSIZE);
    ERS_Config(com_shogeki_hira, ERS_9600);
}


char get_buf_h8maikon() {
    //DrawString(200, 100, "get_buf_h8maikon�֐����s��", yello);
    if (ERS_CheckRecv(com_h8maikon) > 0) {  // �V���A���ʐM�̎�M�f�[�^����
        r_h8maikon = ERS_Recv(com_h8maikon, buf_h8maikon, 1);
        //DrawString(200, 100, "��M�f�[�^����", yello);
        return(buf_h8maikon[0]);
    }
    else {
        return('z');
    }
}

char get_buf_shogeki() {
    //DrawString(200, 100, "get_buf_shogeki�֐����s��", yello);
    switch (currentPlayData.equipment) {
    case tebo:
        if (ERS_CheckRecv(com_shogeki_tebo) > 0) {  // �V���A���ʐM�̎�M�f�[�^����
            r_shogeki_tebo = ERS_Recv(com_shogeki_tebo, buf_shogeki_tebo, 1);
            //DrawString(200, 100, "��M�f�[�^����", yello);
            return(buf_shogeki_tebo[0]);
        }
        break;
    case hirazaru:
        if (ERS_CheckRecv(com_shogeki_hira) > 0) {  // �V���A���ʐM�̎�M�f�[�^����
            r_shogeki_hira = ERS_Recv(com_shogeki_hira, buf_shogeki_hira, 1);
            //DrawString(200, 100, "��M�f�[�^����", yello);
            return(buf_shogeki_hira[0]);
        }
        break;
    default:
        return('z');
    }
    return NULL;
}

void send_current_equipment() {
    buf_current_equipment[0] = 't';
    r_shogeki_tebo = ERS_Send(com_shogeki_tebo, buf_current_equipment, 1);
    buf_current_equipment[0] = 't';

}
//�����܂ŃV���A���ʐM�֐�