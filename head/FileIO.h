/**
 * @file FileIO.h
 * @brief 文件读写头文件
 * @details 包含文件读写相关函数
 * @author gerivii
 * @date 2021-11-18
 * @version 1.0
 */

#ifndef DOUBLECREAT_FILEIO_H
#define DOUBLECREAT_FILEIO_H

int FileIn(char id[], char name[], char grade[]);

int FileOut();

int FileFind(char id[], char name[], char grade[]);

int FileFindById(char id[]);

int FileDel(char id[]);

int FileReplace(int position, char str[], int flag);

int FileCount();

float FileTotal();

int FileMax(char id[], char name[], char grade[]);

int FileMin(char id[], char name[], char grade[]);


#endif //DOUBLECREAT_FILEIO_H
