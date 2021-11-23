/**
 * @file Struct.h
 * @brief 用于储存结构体头文件
 * @details 包含程序所需的结构体
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */


#ifndef DOUBLECREAT_STRUCT_H
#define DOUBLECREAT_STRUCT_H

/**
 * @brief 储存学生信息的结构体
 */
typedef struct Student{
    char id[100];      ///<    学生id
    char name[100];    ///<    学生姓名
    float grade;    ///<    学生成绩
};


#endif //DOUBLECREAT_STRUCT_H
