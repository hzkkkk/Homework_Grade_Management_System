#include "StudManager.h"
#include "Config.h"
#include "DataBase.h"
#include "menu.h"
#include "input.h"
extern TPList<Stud> Stus;

StudManager::StudManager(){}

StudManager::~StudManager(){}

int StudManager::mode_select(){
	//menu_Status:菜单状态 1:运行 0:停止,默认运行
	unsigned int menu_Status = 1;
	//menu_flag:菜单选择 
	unsigned int menu_flag = 1;

	for (;;){
		SHOW_MENU_STU();
		menu_flag = input_num_unit(MENU_STU_NUMBER_LIMIT_MIN, MENU_STU_NUMBER_LIMIT_MAX);

		switch (menu_flag){
		
		case 2:
			for (int i = 1; i <= 5; i++)
			{
				printf("请输入要插入的学生的信息,每个数据之间空格隔开\n");
				Stud stud;
#ifdef DEBUG_INPUT_0
				//cin >> stud;
#endif
#ifdef DEBUG_INPUT_1
				stud._sid = i;
				stud._sname = "233";
				stud._snumber = 2017100;
#endif
				Stus.Append(stud);
				Stus.Delete();
				printf("插入成功\n");
				
			}
			break;

		case 3:
		{
			int count_3 = 0;
			int i3 = 0;
			printf("请输入要删除的学生的序号\n");
			cin >> i3;
			/*if (Stus.Erase(head, i3))
			printf("删除成功\n");*/
			break;
		}
			

		case 6:
			cout << "输出学生信息" << endl;
			cout << "有" << Stus.Size() << "个学生" << endl;
			Stus.Print();
			break;

			
			//case 4:
			//	printf("请输入要查找的字段所在属性");
			//	printf("如:number name score\n");
			//	//目前只支持number score
			//	//temp_3全局变量
			//	cin >> temp_3;

			//	//判断输入是否在属性里面
			//	if ((strcmp(temp_3, "number")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
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

			//case 5:
			//	printf("请输入要获取的序号:");
			//	int temp;
			//	cin >> temp;
			//	pointer p;
			//	if ((p = Get(head, temp)) != NULL)
			//	{
			//		printf("获取成功\n");
			//		cout << "score:" << p->elem.score << endl;
			//		cout << "sname:" << p->elem.sname << endl;
			//		cout << "sumber:" << p->elem.snumber << endl;
			//	}
			//	else printf("获取失败\n");
			//	break;

			//case 6:
			//	Traverse(head);
			//	break;

			//	//case 7:
			//	//	printf("请输入要修改的序号:");
			//	//	cin >> count_4;
			//	//	Stu x;
			//	//	cin >> x.snumber >> x.sname >> x.score;

			//	//	//if (Change(head, x, count_4))
			//	//		printf("修改成功\n");
			//	//break;
			//case 8:
			//	if (Destory(head))  printf("销毁成功\n");
			//	else printf("销毁失败\n");
			//	break;
			//case 9:
			//	menu_flag = 0;
			//	number = 0;
			//	break;

			//case 10:
			//	int lowest, highest;
			//	printf("请输入结点条件上下限:");
			//	cin >> lowest >> highest;
			//	if (Delete_Lowest_Highest(head, lowest, highest))
			//		printf("删成功\n");
			//	else printf("删失败\n");
			//	break;

		default:
			menu_flag = 1;
			break;
		}
		//system("cls");
	}

	return 0;
}

