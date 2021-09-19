#include "End.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Func.h"

//�X�V
static SaveData data = CurrentPlayData_Get();
void End_Update() {
    Time_Finalize();
    if (CheckHitKey(KEY_INPUT_RETURN) == 0 && SceneChangeFlag_Get() == 0) {
        SceneChangeFlag_Allow();
    }
    if (CheckHitKey(KEY_INPUT_RETURN) != 0 && SceneChangeFlag_Get() == 1) { //�G���^�[�L�[��������Ă�����
        FILE* fp = fopen("savedata.dat", "wb");//�o�C�i���t�@�C�����J��
        fwrite(&data, sizeof(SaveData), sizeof(data) / sizeof(data), fp); // SaveData_t�\���̂̒��g���o��
        fclose(fp);
        SceneChangeFlag_Forbid();
        SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
    }
}

//�`��
void End_Draw() {
    DrawString(0, 0, "End��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 20, "�G���^�[�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}