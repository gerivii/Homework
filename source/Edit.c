/**
 * @file Edit.c
 * @brief 信息编辑源程序
 * @details 包含信息编辑相关函数的实现
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#include "../head/FileIO.h"
#include <stdio.h>


/**
 * @brief 添加新的学生信息
 * @param[in] id
 * @param[in] name
 * @param[in] grade
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
int Add(char id[], char name[], char grade[]) {
    if (FileIn(id, name, grade))
        return 1;
    else
        return 0;
}

/**
 * @brief 删除学生信息
 * @param id
 * @return 是否成功
 * @retval 0 失败
 * @retval 1 成功
 */
int Del(char id[]) {
    if (FileDel(id))
        return 1;
    else
        return 0;

}

/**
 * @brief 修改指定id的学生的姓名
 * @param id
 * @param name
 * @return 是否成功
 * @retval 0 失败
 * @retval 1 成功
 */
int EditName(char id[], char name[]) {
    int position = FileFindById(id);
    if (position == -1) {
        printf("未找到该学生\n");
        return 0;
    } else {
        if (FileReplace(position, name, 1))
            return 1;
        else
            return 0;
    }
}

/**
 * @brief 修改指定id的学生的成绩
 * @param id
 * @param grade
 * @return 是否成功
 * @retval 0 失败
 * @retval 1 成功
 */
int EditGrade(char id[], char grade[]) {
    int position = FileFindById(id);
    if (position == -1) {
        printf("未找到该学生\n");
        return 0;
    } else {
        if (FileReplace(position, grade, 2))
            return 1;
        else
            return 0;
    }
}

/**
 * 修改指定id的学生的信息
 * @param id
 * @param name
 * @param grade
 * @return 是否成功
 * @retval 0 失败
 * @retval 1 成功
 */
int Edit(char id[], char name[], char grade[]) {
    int position = FileFindById(id);
    if (position == -1) {
        printf("未找到该学生\n");
        return 0;
    } else {
        if (FileReplace(position, name, 1) && FileReplace(position, grade, 2))
            return 1;
        else
            return 0;
    }
}