/*
author:							hzk
Vertion:						1.0
Attention��						Just for Study.
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

	//menu_Status:�˵�״̬
	//menu_flag:�˵�ѡ��
	int  menu_Status = 0, menu_flag = 0;

	number = 1;

	while (number)
	{
		cout << endl;
		printf("************************************************************\n");
		printf("****************ѧ����¼����ϵͳ****************************\n");
		printf("------------------------------------------------------------\n");
		printf("****  ��1�� ͳ��ѧ������                                  **\n");//��һ�λᴴ������֮������½ڵ�
		printf("****  ��2�� ����ѧ����Ϣ								  **\n");//�����ڵ�
		printf("****  ��3�� ɾ��ѧ����Ϣ								  **\n");//Ҳ�Ǳ���
		printf("****  ��4�� ��ѧ��Ϊx�Ľ��ĵ�ַ�����                         **\n");
		printf("****  ��5�� ��ȡ��i��ѧ����Ϣ                             **\n");
		printf("****  ��6�� ��ʾѧ�����е�����Ԫ��,�ͱ�                        **\n");
		printf("****  ��7�� �޸�ĳ��ѧ���ķ�����ûʵ��	��						  **\n");
		printf("****  ��8�� ��������						                **\n");
		printf("****  ��9�� �˳�										  **\n");
		printf("****  ��10��	ɾ������ѧ����a��b֮������н��										  **\n");
		printf("������һ������ 1~8: ");

		//������룬���Ե�ѭ��
		//������Ϊ����������ʱ��scanf����0��menu_Status=0����menu_Status��=1��ִ��ѭ����
		//�ڵ�����Ϊ��������ʱ������menu_flag = 6��scanf����1��stutas = 1, 
		//����Ҫ�����ж�(menu_flag < 1 || menu_flag >8)�����㣬ִ��ѭ����
		//�۵�����Ϊ��������ʱ������menu_flag = 1��scanf����1��stutas = 1,
		//����Ҫ�����ж�(menu_flag < 1 || menu_flag > 8)�������㣬����ѭ����
		while ((menu_Status = scanf("%d", &menu_flag)) != 1 ||
			(menu_flag < 1 || menu_flag > 10))
		{
			// �����stdin��ķ�����
			if (menu_Status != 1)
				scanf("%*s");
			// ����������ʾ
			printf("����.��Ҫ���������ַ�.\n");
			printf("������һ��.\n");
			printf("������һ������ 1~8: ");
		}
		//�������
		cout << endl;
		switch (menu_flag)
		{
		case 1:
			cout << "��" << SqListCount(head) << "��ѧ��" << endl;
			break;
		case 2:
			printf("������Ҫ�����ѧ������Ϣ,ÿ������֮��ո����\n");
			for (int i = 1; i <= 5; i++)
			{
				Stu x;
				x.score = i;
				strcpy(x.sname, "����");
				x.snumber = i + 4;
				if (Add(head, x, i))
					printf("����ɹ�\n");
			}
			//cin >> x.snumber >> x.sname >> x.score >> i;

		case 3:
			count_3 = 0;
			printf("������Ҫɾ����ѧ�������\n");
			int i;
			cin >> i;
			if (Delete(head, i))
				printf("ɾ���ɹ�\n");
			break;

		case 4:
			printf("������Ҫ���ҵ��ֶ���������");
			printf("��:number name score\n");
			//Ŀǰֻ֧��number score
			//temp_3ȫ�ֱ���
			cin >> temp_3;

			//�ж������Ƿ�����������
			if ((strcmp(temp_3, "number")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
			{
				printf("������Ҫ���ҵ�����:");
				int temp;
				cin >> temp;
				pointer temp_p = Search(head, temp, temp_3);
				if (temp_p != NULL)
				{
					printf("���ҳɹ�\n");
					cout << "��ַΪ��" << &temp_p << endl;

				}
				else printf("����ʧ��\n");

				//Ŀǰֻ֧��float
				/*cin >> temp_3_2;
				SearchElem(head, float(temp_3_2) );*/
			}
			else
			{
				printf("����� %s ����\n", temp_3);
				break;
			}
			break;

		case 5:
			printf("������Ҫ��ȡ�����:");
			int temp;
			cin >> temp;
			pointer p;
			if ((p = Get(head, temp)) != NULL)
			{
				printf("��ȡ�ɹ�\n");
				cout << "score:" << p->elem.score << endl;
				cout << "sname:" << p->elem.sname << endl;
				cout << "sumber:" << p->elem.snumber << endl;
			}
			else printf("��ȡʧ��\n");
			break;

		case 6:
			Traverse(head);
			break;

			//case 7:
			//	printf("������Ҫ�޸ĵ����:");
			//	cin >> count_4;
			//	Stu x;
			//	cin >> x.snumber >> x.sname >> x.score;

			//	//if (Change(head, x, count_4))
			//		printf("�޸ĳɹ�\n");
			//break;
		case 8:
			if (Destory(head))  printf("���ٳɹ�\n");
			else printf("����ʧ��\n");
			break;
		case 9:
			menu_flag = 0;
			number = 0;
			break;

		case 10:
			int lowest, highest;
			printf("������������������:");
			cin >> lowest >> highest;
			if (Delete_Lowest_Highest(head, lowest, highest))
				printf("ɾ�ɹ�\n");
			else printf("ɾʧ��\n");
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






