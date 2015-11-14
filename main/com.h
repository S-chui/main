#include <stdio.h>
#include "stdlib.h"
#include <string.h>

#ifndef com_h
#define com_h

typedef struct _INF
{
	char name[20];//名字
	char sex[4];//性别
	char add[20];//籍贯
	char col[20];//学院
	char spe[20];//专业
	int age;//年龄
	int num;//学号
	int clas;//班级
	char recol[20];//原学院
	char respe[20];//原专业
	struct _INF *next;
}Inf;

void input();

void choice_show();

void show_cs();

void chge();

void Dele();

#endif
