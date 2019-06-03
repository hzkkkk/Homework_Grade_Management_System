#include "StudManager.h"
#include "Config.h"
#include "DataBase.h"
#include "menu.h"
#include "input.h"
extern TPList<Stud> Stus;

StudManager::StudManager(){}

StudManager::~StudManager(){}

int StudManager::mode_select(){
	//menu_Status:�˵�״̬ 1:���� 0:ֹͣ,Ĭ������
	unsigned int menu_Status = 1;
	//menu_flag:�˵�ѡ�� 
	unsigned int menu_flag = 1;

	for (;;){
		SHOW_MENU_STU();
		menu_flag = input_num_unit(MENU_STU_NUMBER_LIMIT_MIN, MENU_STU_NUMBER_LIMIT_MAX);

		switch (menu_flag)
		{
		case 2:
			for (int i = 1; i <= 1; i++)
			{
				printf("������Ҫ�����ѧ������Ϣ,ÿ������ ֮��ո����\n");
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

				printf("����ɹ�\n");
			}
			break;
		case 3:
		{
			//���ɹ��û�����Ķ���
			if (Stus.Delete_by_find(Stud::getMatchPattern_by_user()))  printf("ɾ���ɹ�\n");
			else printf("ɾ��ʧ��\n");
			break;
		}
		case 4:
		{
			Stus.Find(Stud::getMatchPattern_by_user());
			break;
		}

		case 6:
		{
			cout << "���ѧ����Ϣ" << endl;
			cout << "��" << Stus.Size() << "��ѧ��" << endl;
			Stus.Print();
			break;
		}

		case 7:
		{
			Stud stud_temp;
			vector<TPList<Stud>::iterator> students_iter;
			printf("������Ҫ�޸ĵ����:");


			
#ifdef DEBUG_INPUT_0
			//�浽students����ȥ
			students_iter = Stus.Edit_by_find(Stud::getMatchPattern_by_user());

#endif
#ifdef DEBUG_INPUT_1
			stud_temp.setSid(1);
			stud_temp.setSname("322");
			stud_temp.setSnumber(2000000);
			stud_temp.setMode_fitter(0b0001);

			//�浽students����ȥ
			students_iter = Stus.Edit_by_find(stud_temp);
#endif


			for (int i = 0;i < students_iter.size();i++)
			{
				printf("students: %d \n",i);
				cout << *students_iter[i] << endl;
			}

			printf("ʵ���ϻ�û�޸�.\n");
			printf("�޸ĳɹ�\n");
			break;
		}
			//case 8:
			//	if (Destory(head))  printf("���ٳɹ�\n");
			//	else printf("����ʧ��\n");
			//	break;
			//case 9:
			//	menu_flag = 0;
			//	number = 0;
			//	break;

			//case 10:
			//	int lowest, highest;
			//	printf("������������������:");
			//	cin >> lowest >> highest;
			//	if (Delete_Lowest_Highest(head, lowest, highest))
			//		printf("ɾ�ɹ�\n");
			//	else printf("ɾʧ��\n");
			//	break;

		default:
			menu_flag = 1;
			break;
		}
		//system("cls");
	}

	return 0;
}

