/**
 * @file Input.c
 * @brief 录入信息源文件
 * @details 包含和录入相关操作的有关函数的实现
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#include "../head/Input.h"
#include "../head/FileIO.h"

/**
 * @brief 只用姓名录入
 * @param[in] id
 * @param[in] name
 * @return 是否成功写入
 * @retval 0 失败
 * @retval 1 成功
 */
int NameIn(char id[], char name[]) {
    if (FileIn(id, name, "NULL"))
        return 1;
    else
        return 0;
}

/**
 * @brief 只用成绩录入
 * @param[in] id
 * @param[in] name
 * @return 是否录入成功
 * @retval 0 失败
 * @retval 1 成功
 */
int GradeIn(char id[], char grade[]) {
    if (FileIn(id, "NULL", grade))
        return 1;
    else
        return 0;
}

/**
 * @brief 录入学生信息
 * @param[in] id
 * @param[in] name
 * @param[in] grade
 * @return 是否录入成功
 * @retval 0 失败
 * @retval 1 成功
 */
int In(char id[], char name[], char grade[]){
    if(FileIn(id, name, grade))
        return 1;
    else
        return 0;
}
