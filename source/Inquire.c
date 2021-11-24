/**
 * @file Inquire.c
 * @brief 查询相关源文件
 * @details 包含查询信息相关函数的实现
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#include "../head/FileIO.h"


/**
 * @brief 查询全部学生信息
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
int InquireAll(){
    if(FileOut())
        return 1;
    else
        return 0;
}

/**
 * @brief 按照id查询学生信息
 * @param id
 * @param name
 * @param grade
 * @return 是否成功找到
 * @retval 0 失败
 * @retval 1 成功
 */
int Inquire(char id[], char name[], char grade[]){
    if(FileFind(id, name, grade) != -1)
        return 1;
    else
        return 0;
}
