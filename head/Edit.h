/**
 * @file Edit.h
 * @brief 信息编辑头文件
 * @details 包含信息编辑相关函数
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#ifndef DOUBLECREAT_EDIT_H
#define DOUBLECREAT_EDIT_H

int Add(char id[], char name[], char grade[]);

int Del(char id[]);

int EditName(char id[], char name[]);

int EditGrade(char id[], char grade[]);

int Edit(char id[], char name[], char grade[]);


#endif //DOUBLECREAT_EDIT_H
