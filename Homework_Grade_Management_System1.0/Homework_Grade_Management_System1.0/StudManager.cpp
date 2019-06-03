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

		switch (menu_flag)
		{
		case 2:
			for (int i = 1; i <= 1; i++)
			{
				printf("请输入要插入的学生的信息,每个数据 之间空格隔开\n");
				Stud stud = { 0 };
#ifdef DEBUG_INPUT_0
				cin >> stud;

#endif
#ifdef DEBUG_INPUT_1
				stud.setSid(i);
				stud.setSname("233");
				stud.setSnumber(2017100);
#endif			
				Stus.Append(stud);

				printf("插入成功\n");
			}
			break;
		case 3:
		{
			//生成供用户输入的对象
			if (Stus.Delete_by_find(Stud::getMatchPattern_by_user()))  printf("删除成功\n");
			else printf("删除失败\n");
			break;
		}
		case 4:
		{
			Stus.Find(Stud::getMatchPattern_by_user());
			break;
		}

		case 6:
		{
			cout << "输出学生信息" << endl;
			cout << "有" << Stus.Size() << "个学生" << endl;
			Stus.Print();
			break;
		}

		case 7:
		{
			Stud stud_temp;
			vector<TPList<Stud>::iterator> students_iter;
			printf("请输入要修改的序号:");


			
#ifdef DEBUG_INPUT_0
			//存到students里面去
			students_iter = Stus.Edit_by_find(Stud::getMatchPattern_by_user());

#endif
#ifdef DEBUG_INPUT_1
			stud_temp.setSid(1);
			stud_temp.setSname("322");
			stud_temp.setSnumber(2000000);
			stud_temp.setMode_fitter(0b0001);

			//存到students里面去
			students_iter = Stus.Edit_by_find(stud_temp);
#endif


			for (int i = 0;i < students_iter.size();i++)
			{
				printf("students: %d \n",i);
				cout << *students_iter[i] << endl;
			}

			printf("实际上还没修改.\n");
			printf("修改成功\n");
			break;
		}
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

