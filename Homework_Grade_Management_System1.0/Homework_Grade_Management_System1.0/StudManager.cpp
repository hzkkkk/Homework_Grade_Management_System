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

		switch (menu_flag){
		
		case 2:
			for (int i = 1; i <= 5; i++)
			{
				printf("������Ҫ�����ѧ������Ϣ,ÿ������֮��ո����\n");
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
				printf("����ɹ�\n");
				
			}
			break;

		case 3:
		{
			int count_3 = 0;
			int i3 = 0;
			printf("������Ҫɾ����ѧ�������\n");
			cin >> i3;
			/*if (Stus.Erase(head, i3))
			printf("ɾ���ɹ�\n");*/
			break;
		}
			

		case 6:
			cout << "���ѧ����Ϣ" << endl;
			cout << "��" << Stus.Size() << "��ѧ��" << endl;
			Stus.Print();
			break;

			
			//case 4:
			//	printf("������Ҫ���ҵ��ֶ���������");
			//	printf("��:number name score\n");
			//	//Ŀǰֻ֧��number score
			//	//temp_3ȫ�ֱ���
			//	cin >> temp_3;

			//	//�ж������Ƿ�����������
			//	if ((strcmp(temp_3, "number")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
			//	{
			//		printf("������Ҫ���ҵ�����:");
			//		int temp;
			//		cin >> temp;
			//		pointer temp_p = Search(head, temp, temp_3);
			//		if (temp_p != NULL)
			//		{
			//			printf("���ҳɹ�\n");
			//			cout << "��ַΪ��" << &temp_p << endl;

			//		}
			//		else printf("����ʧ��\n");

			//		//Ŀǰֻ֧��float
			//		/*cin >> temp_3_2;
			//		SearchElem(head, float(temp_3_2) );*/
			//	}
			//	else
			//	{
			//		printf("����� %s ����\n", temp_3);
			//		break;
			//	}
			//	break;

			//case 5:
			//	printf("������Ҫ��ȡ�����:");
			//	int temp;
			//	cin >> temp;
			//	pointer p;
			//	if ((p = Get(head, temp)) != NULL)
			//	{
			//		printf("��ȡ�ɹ�\n");
			//		cout << "score:" << p->elem.score << endl;
			//		cout << "sname:" << p->elem.sname << endl;
			//		cout << "sumber:" << p->elem.snumber << endl;
			//	}
			//	else printf("��ȡʧ��\n");
			//	break;

			//case 6:
			//	Traverse(head);
			//	break;

			//	//case 7:
			//	//	printf("������Ҫ�޸ĵ����:");
			//	//	cin >> count_4;
			//	//	Stu x;
			//	//	cin >> x.snumber >> x.sname >> x.score;

			//	//	//if (Change(head, x, count_4))
			//	//		printf("�޸ĳɹ�\n");
			//	//break;
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

