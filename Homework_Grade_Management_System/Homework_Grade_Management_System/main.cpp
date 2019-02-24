/*
author:							hzk
Vertion:						1.0
Attention：						Just for Study.
Log:							Create
Date:							2019/1/1
*/
#pragma warning (disable:4996)  
//'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
#pragma once
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "main.h"

using namespace std;

int count_list;
int max;
char temp_3[20];
char temp_3_2[20];
int count_3;
int count_4;
int count_5;

int main()
{
	int number;

	sqlist head;
	head = InitSqList();

	//menu_Status:菜单状态
	//menu_flag:菜单选择
	int  menu_Status = 0, menu_flag = 0;

	number = 1;

	while (number)
	{
		cout << endl;
		printf("************************************************************\n");
		printf("****************学生记录管理系统****************************\n");
		printf("------------------------------------------------------------\n");
		printf("****  （1） 统计学生人数                                  **\n");//第一次会创建链表，之后插入新节点
		printf("****  （2） 输入学生信息								  **\n");//遍历节点
		printf("****  （3） 删除学生信息								  **\n");//也是遍历
		printf("****  （4） 找学号为x的结点的地址和序号                         **\n");
		printf("****  （5） 获取第i个学生信息                             **\n");
		printf("****  （6） 显示学生表中的所有元素,和表长                        **\n");
		printf("****  （7） 修改某个学生的分数（没实现	）						  **\n");
		printf("****  （8） 销毁链表						                **\n");
		printf("****  （9） 退出										  **\n");
		printf("****  （10）	删除结点的学号在a和b之间的所有结点										  **\n");
		printf("请输入一个整数 1~8: ");

		//检查输入，并吃掉循环
		//当输入为非整型数据时，scanf返回0，menu_Status=0，故menu_Status！=1，执行循环。
		//②当输入为整型数据时，例如menu_flag = 6，scanf返回1，stutas = 1, 
		//于是要继续判断(menu_flag < 1 || menu_flag >8)，满足，执行循环。
		//③当输入为整型数据时，例如menu_flag = 1，scanf返回1，stutas = 1,
		//于是要继续判断(menu_flag < 1 || menu_flag > 8)，不满足，跳出循环。
		while ((menu_Status = scanf("%d", &menu_flag)) != 1 ||
			(menu_flag < 1 || menu_flag > 10))
		{
			// 处理掉stdin里的非整型
			if (menu_Status != 1)
				scanf("%*s");
			// 重新输入提示
			printf("错误.不要输入其他字符.\n");
			printf("请再输一次.\n");
			printf("请输入一个整数 1~8: ");
		}
		//检查输入
		cout << endl;
		switch (menu_flag)
		{
		case 1:
			cout << "有" << SqListCount(head) << "个学生" << endl;
			break;
		case 2:
			printf("请输入要插入的学生的信息,每个数据之间空格隔开\n");
			for (int i = 1; i <= 5; i++)
			{
				Stu x;
				x.score = i;
				strcpy(x.sname, "辣鸡");
				x.snumber = i + 4;
				if (Add(head, x, i))
					printf("插入成功\n");
			}
			//cin >> x.snumber >> x.sname >> x.score >> i;

		case 3:
			count_3 = 0;
			printf("请输入要删除的学生的序号\n");
			int i;
			cin >> i;
			if (Delete(head, i))
				printf("删除成功\n");
			break;

		case 4:
			printf("请输入要查找的字段所在属性");
			printf("如:number name score\n");
			//目前只支持number score
			//temp_3全局变量
			cin >> temp_3;

			//判断输入是否在属性里面
			if ((strcmp(temp_3, "number")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
			{
				printf("请输入要查找的数据:");
				int temp;
				cin >> temp;
				pointer temp_p = Search(head, temp, temp_3);
				if (temp_p != NULL)
				{
					printf("查找成功\n");
					cout << "地址为：" << &temp_p << endl;

				}
				else printf("查找失败\n");

				//目前只支持float
				/*cin >> temp_3_2;
				SearchElem(head, float(temp_3_2) );*/
			}
			else
			{
				printf("输入的 %s 有误\n", temp_3);
				break;
			}
			break;

		case 5:
			printf("请输入要获取的序号:");
			int temp;
			cin >> temp;
			pointer p;
			if ((p = Get(head, temp)) != NULL)
			{
				printf("获取成功\n");
				cout << "score:" << p->elem.score << endl;
				cout << "sname:" << p->elem.sname << endl;
				cout << "sumber:" << p->elem.snumber << endl;
			}
			else printf("获取失败\n");
			break;

		case 6:
			Traverse(head);
			break;

			//case 7:
			//	printf("请输入要修改的序号:");
			//	cin >> count_4;
			//	Stu x;
			//	cin >> x.snumber >> x.sname >> x.score;

			//	//if (Change(head, x, count_4))
			//		printf("修改成功\n");
			//break;
		case 8:
			if (Destory(head))  printf("销毁成功\n");
			else printf("销毁失败\n");
			break;
		case 9:
			menu_flag = 0;
			number = 0;
			break;

		case 10:
			int lowest, highest;
			printf("请输入结点条件上下限:");
			cin >> lowest >> highest;
			if (Delete_Lowest_Highest(head, lowest, highest))
				printf("删成功\n");
			else printf("删失败\n");
			break;

		default:
			number = 1;
			break;
		}
	}
	return 0;
}


/*********************************************************************


*


* Software License Agreement (BSD License)


*


*  Copyright (c) 2014, Robert Bosch LLC.


*  All rights reserved.


*


*  Redistribution and use in source and binary forms, with or without


*  modification, are permitted provided that the following conditions


*  are met:


*


*   * Redistributions of source code must retain the above copyright


*     notice, this list of conditions and the following disclaimer.


*   * Redistributions in binary form must reproduce the above


*     copyright notice, this list of conditions and the following


*     disclaimer in the documentation and/or other materials provided


*     with the distribution.


*   * Neither the name of the Robert Bosch nor the names of its


*     contributors may be used to endorse or promote products derived


*     from this software without specific prior written permission.


*


*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS


*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT


*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS


*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE


*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,


*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,


*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;


*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER


*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT


*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN


*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE


*  POSSIBILITY OF SUCH DAMAGE.


*


*********************************************************************/






