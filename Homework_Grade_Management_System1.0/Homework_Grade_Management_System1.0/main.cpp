/*
	author:							hzk
	Vertion:						1.0
	Attention：						Just for Study.
	Log:							Create
	Date:							2019/3/21
*/

#include "Config.h"
#include "Login.h"
#include "menu.h"
#include "input.h"
#include "Stud_Plus.h"
#include "Homw_Plus.h"

//int count_list;
//int max;
//char temp_3[20];
//char temp_3_2[20];
//int count_3;
//int count_4;
//int count_5;

int main()
{
	//[0]进入系统
	for (;;) {
		int log_mode; //1:学生 2：老师 3：超级管理员 0:访客
		 //STU:学生 TE：老师 ADMIN：超级管理员  VISITOR:访客

#ifdef DEBUGMODE_1
		Authority autho = STU;
#endif // DEBUGMODE_1

#ifdef DEBUGMODE_0
		Authority autho = showLogin();
#endif // DEBUGMODE_0

		//[1]登录成功
		switch (autho)
		{
		case STU:  log_mode = 1; break;
		case TE:  log_mode = 2; break;
		case ADMIN: log_mode = 3; break;
		default:log_mode = 0; break;
		}

		for (;;) {
			switch (autho)
			{
			case STU:  log_mode = 1; break;
			case TE:  log_mode = 2; break;
			case ADMIN: log_mode = 3; break;
			default:log_mode = 0; break;
			}
			//[2]登录后界面
			if (!show_menu(log_mode)) break;
		}
		system("pause");
	}
	
	return 0;
}

//void outwriteTheList(Item item)
//{
//	FILE *file_list;
//	file_list = fopen("output.txt", "wb+");
//	if (file_list == NULL)
//	{
//		printf("没有打开文件\n");
//		printf("新建一个文件\n");
//		return;
//	}
//	//输出链表节点数据到屏幕 
//	printf("正在读入\n");
//	//输出链表节点数据到文件output.txt 
//
//	printf("  编号Item:%s \n ", item.Item);
//	printf(" 名称Name:%s \n ", item.Name);
//	printf(" 日期Date:%s \n ", item.Date);
//	printf(" 地点Place:%s \n ", item.Place);
//	printf(" 部门Department:%s\n ", item.Department);
//	printf(" 主持人Host:%s  \n ", item.Host);
//	printf(" 记录人Recorder:%s \n ", item.Recorder);
//	printf(" 摘要Abstract:%s  \n ", item.Abstract);
//	printf(" \n ");
//
//	fprintf(file_list, "%s", item.Item);
//	fprintf(file_list, "%s", item.Name);
//	fprintf(file_list, "%s", item.Date);
//	fprintf(file_list, "%s", item.Place);
//	fprintf(file_list, "%s", item.Department);
//	fprintf(file_list, "%s", item.Host);
//	fprintf(file_list, "%s", item.Recorder);
//	fprintf(file_list, "%s", item.Abstract);
//
//	fclose(file_list);
//}

//void saveToFile(char* filename,struct MqList head) {
//	struct MqList *Head = head->next;
//	FILE *fp;
//	
//
//	if ((fp = fopen(filename, "wb")) == NULL) {
//		printf("打开文件失败!");
//		return;
//	}
//	else {
//		while (Head != NULL) {
//			fwrite(Head->elem.Item, sizeof(10), 1, fp);
//			fwrite(Head->elem.Name, sizeof(20), 1, fp);
//			fwrite(Head->elem.Date, sizeof(20), 1, fp);
//			fwrite(Head->elem.Place, sizeof(20), 1, fp);
//			fwrite(Head->elem.Department, sizeof(20), 1, fp);
//			fwrite(Head->elem.Host, sizeof(10), 1, fp);
//			fwrite(Head->elem.Recorder, sizeof(10), 1, fp);
//			fwrite(Head->elem.Abstract, sizeof(10), 1, fp);
//			Head = Head->next;
//		}
//	}
//	fclose(fp);
//}
//
//void readFromFile(int n) {
//	int i = 1;
//	FILE *fp;
//	char filename[30];
//	strcpy(filename, "C:/Users/lenovo/Desktop/testt.txt");
//
//	if ((fp = fopen(filename, "rb")) == NULL) {
//		printf("打开文件失败!");
//		return;
//	}
//	else {
//		while (i < n) {
//			struct MqList*newe = (struct MqList*)malloc(sizeof(struct MqList));
//			fread(newe, sizeof(struct MqList), 1, fp);
//			//PrintList(head);
//		}
//	}
//}




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


