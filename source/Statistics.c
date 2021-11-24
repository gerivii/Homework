/**
 * @file Statistics.c
 * @brief 查询相关源文件
 * @details 包含查询信息相关函数的实现
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#include "../head/FileIO.h"

/**
 * @return 返回学生总分
 * @retval -1 未能查询总分
 */
float total() {
    return FileTotal();
}

/**
 * @return 返回学生平均分
 * @retval -1 查询失败
 */
float ave() {
    float total = FileTotal();
    int num = FileCount();
    if (total != -1 && num != -1) {
        return total / (float)num;
    } else
        return -1;
}

/**
 * @brief 返回信息中成绩最大的学生的id、姓名、成绩
 * @param[out] id
 * @param[out] name
 * @param[out] grade
 * @return 是否成功找到
 * @retval 0 失败
 * @retval 1 成功
 */
int max(char id[], char name[], char grade[]) {
    return FileMax(id, name, grade);
}

/**
 * @brief 返回信息中成绩最小的学生的id、姓名、成绩
 * @param[out] id
 * @param[out] name
 * @param[out] grade
 * @return 是否成功找到
 * @retval 0 失败
 * @retval 1 成功
 */
int min(char id[], char name[], char grade[]) {
    return FileMin(id, name, grade);
}