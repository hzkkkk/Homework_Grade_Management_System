#pragma once	
/* menu.h -- constants and declarations for menu.c  */
#pragma once
//避免重复定义
#include <stdbool.h> 
//bool是C++的关键字 C不支持

#ifndef LIST_H_
#define LIST_H_
//避免多重编译

#pragma once
#include <string.h>
#define ERROR 0
#define OK 1
#define Status int
#define MAXSIZE 100


/* 结构体定义 */
#define MqSIZE      45    /* size of array to hold title  */

typedef struct
{
	int snumber;
	char sname[20];
	int score;
}Stu;


typedef struct node* pointer;

struct node
{
	Stu elem;
	pointer next;
	int n;//编号  
};

typedef pointer sqlist;

sqlist InitSqList();

void DestorySqLIst(sqlist head);

pointer Get(sqlist head, int i);

unsigned int SqListCount(const sqlist head);


int Add(sqlist head, Stu e, int i);

int Delete(sqlist head, int i);

int Traverse(const sqlist head);

pointer Search(const sqlist head, int temp, char* temp_3);

int Destory(sqlist head);

int Delete_Lowest_Highest(sqlist head, int lowest, int highest);//根据特定查找
#endif
																//避免多重编译





