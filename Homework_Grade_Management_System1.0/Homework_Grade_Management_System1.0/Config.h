#pragma once

#include <windows.h> //Sleep()
#include <cstdio>

#include <string>
#include <Regex>
#include <iostream>
#include <string>
#include <stdbool.h> //bool��C++�Ĺؼ��� C��֧��
#pragma warning (disable:4996)  
using namespace std;
////////////////////////////////////////
///login.h

enum Authority{
	STU, TE, ADMIN, VISITOR
};


#define LOG_NUMBER_LIMIT_MIN 1
#define LOG_NUMBER_LIMIT_MAX 3


////////////////////////////////////////
///input.h

#define REGEX_NUMSTRING "[0-9]+"
////////////////////////////////////////


/* �ṹ�嶨�� */
#define MqSIZE 45 


#define ERROR 0
#define QUIT -3 //'qq'
#define OK 1

//����궨��
#define NODE_ELEM elem
#define NODE_N n 	//���ݱ��  
#define NODE_DATA data 	
#define NODE_NEXT next	
#define SQLIST_DATA sqlist_data
#define SQLIST_STU sqlist_stu



#define HOMEW_HNUMBER hnumber
#define HOMEW_SNAME hname
#define HOMEW_SCORE hscore

////////////////////////////////////////
///Homework
typedef struct
{
	int HOMEW_HNUMBER;
	char HOMEW_SNAME[20];
	int HOMEW_SCORE;
}Homework;
typedef struct node_data* pointer_data;
typedef pointer_data SQLIST_DATA;
struct node_data
{
	Homework NODE_ELEM;
	pointer_data NODE_NEXT;
	int NODE_N;
};

#define STU_SNUMBER snumber
#define STU_SNAME sname


////////////////////////////////////////
///Student.h
typedef struct
{
	int STU_SNUMBER;
	char STU_SNAME[20];
	
}Stu;
typedef struct node_stu* pointer;
typedef pointer SQLIST_STU;
struct node_stu
{
	Stu NODE_ELEM;
	pointer NODE_NEXT;
	int NODE_N;	//���ݱ�� 
	pointer_data NODE_DATA;
};


#define Status int
#define MAXSIZE 100

#define DEBUGMODE_1 //�Ƿ�������ģʽ



////////////////////////////////////////
///menu.h
#define SHOW_MENU() \
	printf("         *********************************************************************************\n");\
	printf("         ********************************��ҵ�ɼ�����ϵͳ*********************************\n");\
	printf("         *********************************************************************************\n");

#define SHORTLINEHOLDER "         ---------------------------------------------------------------------------------"
#define PLACEHOLDER "                                     "

///menu.cpp
#define MENU_STU_NUMBER_LIMIT_MIN 1
#define MENU_STU_NUMBER_LIMIT_MAX 9
#define MENU_TE_NUMBER_LIMIT_MIN 1
#define MENU_TE_NUMBER_LIMIT_MAX 9
#define MENU_ADMIN_NUMBER_LIMIT_MIN 1
#define MENU_ADMIN_NUMBER_LIMIT_MAX 9