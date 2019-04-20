#include "Config.h"
#include "input.h"
#include "menu.h"

int show_menu(int log_number) {
	SHOW_MENU();
	//显示菜单
	switch (log_number)
	{
	case 1:
		SHOW_MENU_STU();
		break;
	case 2:
		SHOW_MENU_TE();
		break;
	case 3:
		SHOW_MENU_ADMIN();
		break;
	}

	//menu_Status:菜单状态 1:运行 0:停止
	unsigned int menu_Status = 0;
	//menu_flag:菜单选择 
	unsigned int menu_flag = 1;

	menu_flag = input_num_unit(MENU_STU_NUMBER_LIMIT_MIN, MENU_STU_NUMBER_LIMIT_MAX);
	while (menu_Status)
	{
		switch(menu_flag)
		{
		case 1:
			SHOW_MENU_STU();
			break;
		case 2:
			SHOW_MENU_TE();
			break;
		case 3:
			SHOW_MENU_ADMIN();
			break;
		}
	}
	return 0;
}

//
//switch (menu_flag)
//{
//case 1:
//	cout << "有" << SqListCount(head) << "个学生" << endl;
//	break;
//case 2:
//	printf("请输入要插入的学生的信息,每个数据之间空格隔开\n");
//	for (int i = 1; i <= 5; i++)
//	{
//		Stu x;
//		//x.score = i;
//		strcpy(x.sname, "辣鸡");
//		x.snumber = i + 4;
//		if (Add(head, x, i))
//			printf("插入成功\n");
//	}
//	//cin >> x.snumber >> x.sname >> x.score >> i;
//
//case 3:
//	count_3 = 0;
//	printf("请输入要删除的学生的序号\n");
//	int i;
//	cin >> i;
//	if (Delete(head, i))
//		printf("删除成功\n");
//	break;
//
//case 4:
//	printf("请输入要查找的字段所在属性");
//	printf("如:menu_Status name score\n");
//	//目前只支持menu_Status score
//	//temp_3全局变量
//	cin >> temp_3;
//
//	//判断输入是否在属性里面
//	if ((strcmp(temp_3, "menu_Status")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
//	{
//		printf("请输入要查找的数据:");
//		int temp;
//		cin >> temp;
//		pointer temp_p = Search(head, temp, temp_3);
//		if (temp_p != NULL)
//		{
//			printf("查找成功\n");
//			cout << "地址为：" << &temp_p << endl;
//		}
//		else printf("查找失败\n");
//
//		//目前只支持float
//		/*cin >> temp_3_2;
//		SearchElem(head, float(temp_3_2) );*/
//	}
//	else
//	{
//		printf("输入的 %s 有误\n", temp_3);
//		break;
//	}
//	break;
//
//case 5:
//	printf("请输入要获取的序号:");
//	int temp;
//	cin >> temp;
//	pointer p;
//	if ((p = Get(head, temp)) != NULL)
//	{
//		printf("获取成功\n");
//		//cout << "score:" << p->elem.score << endl;
//		cout << "sname:" << p->elem.sname << endl;
//		cout << "sumber:" << p->elem.snumber << endl;
//	}
//	else printf("获取失败\n");
//	break;
//
//case 6:
//	Traverse(head);
//	break;
//
//	//case 7:
//	//	printf("请输入要修改的序号:");
//	//	cin >> count_4;
//	//	Stu x;
//	//	cin >> x.snumber >> x.sname >> x.score;
//
//	//	//if (Change(head, x, count_4))
//	//		printf("修改成功\n");
//	//break;
//case 8:
//	if (Destory(head))  printf("销毁成功\n");
//	else printf("销毁失败\n");
//	break;
//case 9:
//	//双重保险
//	menu_flag = 0;
//	menu_Status = 0;
//	break;
//
//case 10:
//	int lowest, highest;
//	printf("请输入结点条件上下限:");
//	cin >> lowest >> highest;
//	if (Delete_Lowest_Highest(head, lowest, highest))
//		printf("删成功\n");
//	else printf("删失败\n");
//	break;
//
//default:
//	menu_Status = 1;
//	break;
//}


