#include <stdio.h>
#include "stdlib.h"
#include <string.h>

#ifndef com_h
#define com_h

typedef struct _INF
{
	char name[20];//����
	char sex[4];//�Ա�
	char add[20];//����
	char col[20];//ѧԺ
	char spe[20];//רҵ
	int age;//����
	int num;//ѧ��
	int clas;//�༶
	char recol[20];//ԭѧԺ
	char respe[20];//ԭרҵ
	struct _INF *next;
}Inf;

void input();

void choice_show();

void show_cs();

void chge();

void Dele();

#endif
