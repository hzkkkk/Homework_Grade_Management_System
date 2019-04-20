#include "Config.h"
#include "input.h"
#include "menu.h"

int show_menu(int log_number) {
	SHOW_MENU();
	//��ʾ�˵�
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

	//menu_Status:�˵�״̬ 1:���� 0:ֹͣ
	unsigned int menu_Status = 0;
	//menu_flag:�˵�ѡ�� 
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
//	cout << "��" << SqListCount(head) << "��ѧ��" << endl;
//	break;
//case 2:
//	printf("������Ҫ�����ѧ������Ϣ,ÿ������֮��ո����\n");
//	for (int i = 1; i <= 5; i++)
//	{
//		Stu x;
//		//x.score = i;
//		strcpy(x.sname, "����");
//		x.snumber = i + 4;
//		if (Add(head, x, i))
//			printf("����ɹ�\n");
//	}
//	//cin >> x.snumber >> x.sname >> x.score >> i;
//
//case 3:
//	count_3 = 0;
//	printf("������Ҫɾ����ѧ�������\n");
//	int i;
//	cin >> i;
//	if (Delete(head, i))
//		printf("ɾ���ɹ�\n");
//	break;
//
//case 4:
//	printf("������Ҫ���ҵ��ֶ���������");
//	printf("��:menu_Status name score\n");
//	//Ŀǰֻ֧��menu_Status score
//	//temp_3ȫ�ֱ���
//	cin >> temp_3;
//
//	//�ж������Ƿ�����������
//	if ((strcmp(temp_3, "menu_Status")) || (strcmp(temp_3, "name")) || (strcmp(temp_3, "score")))
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
//
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
//
//case 5:
//	printf("������Ҫ��ȡ�����:");
//	int temp;
//	cin >> temp;
//	pointer p;
//	if ((p = Get(head, temp)) != NULL)
//	{
//		printf("��ȡ�ɹ�\n");
//		//cout << "score:" << p->elem.score << endl;
//		cout << "sname:" << p->elem.sname << endl;
//		cout << "sumber:" << p->elem.snumber << endl;
//	}
//	else printf("��ȡʧ��\n");
//	break;
//
//case 6:
//	Traverse(head);
//	break;
//
//	//case 7:
//	//	printf("������Ҫ�޸ĵ����:");
//	//	cin >> count_4;
//	//	Stu x;
//	//	cin >> x.snumber >> x.sname >> x.score;
//
//	//	//if (Change(head, x, count_4))
//	//		printf("�޸ĳɹ�\n");
//	//break;
//case 8:
//	if (Destory(head))  printf("���ٳɹ�\n");
//	else printf("����ʧ��\n");
//	break;
//case 9:
//	//˫�ر���
//	menu_flag = 0;
//	menu_Status = 0;
//	break;
//
//case 10:
//	int lowest, highest;
//	printf("������������������:");
//	cin >> lowest >> highest;
//	if (Delete_Lowest_Highest(head, lowest, highest))
//		printf("ɾ�ɹ�\n");
//	else printf("ɾʧ��\n");
//	break;
//
//default:
//	menu_Status = 1;
//	break;
//}


