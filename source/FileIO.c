/**
 * @file FileIO.c
 * @brief 实现文件读写源程序
 * @details 包含文件读写相关函数
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
 * @brief 在文件尾部追加数据
 * @param[in] id
 * @param[in] name
 * @param[in] grade
 * @return 是否成功打开文件
 * @retval 1 成功
 * @retval 0 失败
 */
int FileIn(char id[], char name[], char grade[]) {
    FILE *fp;
    fp = fopen(data, "ab");
    if (fp == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
        return 0;
    } else {
        char temp[100];
        strcat(temp, id);
        strcat(temp, " ");

        //确保姓名长度一致
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
 * @brief 查找符合id的学生全部信息
 * @param[in] id
 * @param[out] name
 * @param[out] grade
 * @return 该学生信息所在文件中的位置
 * @retval -1 未能找到学生信息
 * @retval 其他数值 则为该信息距离文件头的偏移量
 */
int FileFind(char id[], char name[], char grade[]) {
    int position = -1;
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
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
 * @brief 根据id找到特定学生信息并且返回位置
 * @param id
 * @return 该信息位置
 * @retval -1 未找到该信息
 * @retval 其他数值 该id所在位置
 */
int FileFindById(char id[]) {
    int position = -1;
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
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
 * @brief 输出全部文件信息
 * @return 是否成功打开文件
 * @retval 0 失败
 * @retval 1 成功
 */
int FileOut() {
    FILE *fp;
    fp = fopen(data, "rb");
    if (fp == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
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
 * @brief 根据id删除学生信息
 * @param id
 * @return 是否成功删除
 * @retval 0 失败
 * @retval 1 成功
 */
int FileDel(char id[]) {
    FILE *fp, *t;
    fp = fopen(data, "rb");
    t = fopen("../temp", "wb");
    if (fp == NULL || t == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
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
 * @brief 替换指定位置字符串
 * @param position
 * @param str
 * @param flag 修改的字符串类型，0表示id，1表示姓名，2表示成绩
 * @return 是否成功
 * @retval 0 失败
 * @retval 1 成功
 *
 */
int FileReplace(int position, char str[], int flag) {
    FILE *fp;
    fp = fopen(data, "rb+");
    if (fp == NULL) {
        fprintf(stderr, "错误号：%d\n", errno);
        perror("错误");
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