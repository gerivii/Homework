/**
 * @file FileIO.c
 * @brief ʵ���ļ���дԴ����
 * @details �����ļ���д��غ���
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#define _CRT_SECURE_NO_WARNINGS

#include "../head/FileIO.h"
#include "../head/Struct.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>


#define data "../data"

/**
 * @brief ���ļ�β��׷������
 * @param[in] id
 * @param[in] name
 * @param[in] grade
 * @return �Ƿ�ɹ����ļ�
 * @retval 1 �ɹ�
 * @retval 0 ʧ��
 */
int FileIn(char id[], char name[], char grade[]) {
    FILE *fp;
    fp = fopen(data, "ab");
    if (fp == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return 0;
    } else {
        char temp[100];
        strcat(temp, id);
        strcat(temp, " ");

        //ȷ����������һ��
        switch ((int) strlen(name)) {
            case 4:
                strcat(name, "****");
                break;
            case 6:
                strcat(name, "**");
                break;
            case 8:
                break;
        }
        strcat(temp, name);
        strcat(temp, " ");
        strcat(temp, grade);
        strcat(temp, "\n");
        fprintf(fp, "%s", temp);
        fclose(fp);
        return 1;
    }
}


/**
 * @brief ���ҷ���id��ѧ��ȫ����Ϣ
 * @param[in] id
 * @param[out] name
 * @param[out] grade
 * @return ��ѧ����Ϣ�����ļ��е�λ��
 * @retval -1 δ���ҵ�ѧ����Ϣ
 * @retval ������ֵ ��Ϊ����Ϣ�����ļ�ͷ��ƫ����
 */
int FileFind(char id[], char name[], char grade[]) {
    int position = -1;
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return -1;
    } else {
        char temp[100];
        while (fgets(temp, 100, fp) != NULL) {
            position += (int) strlen(temp);
            char *id_t, *name_t, *grade_t;
            id_t = strtok(temp, " ");
            name_t = strtok(NULL, " ");
            grade_t = strtok(NULL, "\n");
            if (strcmp(id_t, id) == 0) {
                for (int i = 0; i < strlen(name_t); i++) {
                    if (name_t[i] == '*')
                        name[i] = '\0';
                }
                strcpy(grade, grade_t);
                break;
            }
        }
        if (fgets(temp, 100, fp) == NULL) {
            fclose(fp);
            return -1;
        }
        fclose(fp);
        return position - (int) strlen(id) - (int) strlen(name) - (int) strlen(grade) - 2;
    }
}

/**
 * @brief ����id�ҵ��ض�ѧ����Ϣ���ҷ���λ��
 * @param id
 * @return ����Ϣλ��
 * @retval -1 δ�ҵ�����Ϣ
 * @retval ������ֵ ��id����λ��
 */
int FileFindById(char id[]) {
    int position = -1;
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return -1;
    } else {
        char temp[100];
        char *id_t, *name_t, *grade_t;
        while (fgets(temp, 100, fp) != NULL) {
            position += (int) strlen(temp);
            id_t = strtok(temp, " ");
            name_t = strtok(NULL, " ");
            grade_t = strtok(NULL, "\n");
            if (strcmp(id_t, id) == 0) {
                break;
            }
        }
        if (fgets(temp, 100, fp) == NULL) {
            fclose(fp);
            return -1;
        }
        fclose(fp);
        return position - (int) strlen(id) - (int) strlen(name_t) - (int) strlen(grade_t) - 2;
    }
}


/**
 * @brief ���ȫ���ļ���Ϣ
 * @return �Ƿ�ɹ����ļ�
 * @retval 0 ʧ��
 * @retval 1 �ɹ�
 */
int FileOut() {
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return 0;
    } else {
        char id[100], name[100], grade[100];
        while (fscanf(fp, "%s %s %s", id, name, grade) != EOF) {
            for (int i = 0; i < strlen(name); i++) {
                if (name[i] == '*')
                    name[i] = '\0';
            }
            printf("%s %s %s\n", id, name, grade);
        }
    }
    fclose(fp);
    return 1;
}

/**
 * @brief ����idɾ��ѧ����Ϣ
 * @param id
 * @return �Ƿ�ɹ�ɾ��
 * @retval 0 ʧ��
 * @retval 1 �ɹ�
 */
int FileDel(char id[]) {
    FILE *fp, *t;
    fp = fopen(data, "rb");
    t = fopen("../temp", "wb");
    if (fp == NULL || t == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return 0;
    } else {
        char temp1[100], temp2[100];
        char *id_t;
        while (fgets(temp1, 100, fp) != NULL) {
            strcpy(temp2, temp1);
            id_t = strtok(temp1, " ");
            if (strcmp(id_t, id) != 0) {
                fprintf(t, "%s", temp2);
            } else
                continue;
        }
        fclose(fp);
        fclose(t);
        remove(data);
        rename("../temp", data);
        return 1;
    }

}

/**
 * @brief �滻ָ��λ���ַ���
 * @param position
 * @param str
 * @param flag �޸ĵ��ַ������ͣ�0��ʾid��1��ʾ������2��ʾ�ɼ�
 * @return �Ƿ�ɹ�
 * @retval 0 ʧ��
 * @retval 1 �ɹ�
 *
 */
int FileReplace(int position, char str[], int flag) {
    FILE *fp;
    fp = fopen(data, "rb+");
    if (fp == NULL) {
        fprintf(stderr, "����ţ�%d\n", errno);
        perror("����");
        return 0;
    } else {
        switch (flag) {
            case 0:
                break;
            case 1:
                position += 11;
                break;
            case 2:
                position += 16;

        }
        fseek(fp, position, SEEK_SET);
        fputs(str, fp);
        fclose(fp);
        return 1;
    }
}