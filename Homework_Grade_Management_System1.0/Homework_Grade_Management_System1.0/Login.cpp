#include "Config.h"
#include "input.h"
#include "Login.h"

Authority showLogin() {
	SHOW_MENU();
	printf("         ************************************��¼����*************************************\n");
	printf("         ---------------------------------------------------------------------------------\n");
	printf("                                        ��1�� ѧ����¼                                      \n");
	printf("                                        ��2�� ��ʦ��¼							      	   \n");
	printf("                                        ��3�� ��������Ա��¼						           \n");
	printf("������һ������ %d~%d: " , LOG_NUMBER_LIMIT_MIN, LOG_NUMBER_LIMIT_MAX);
	
	//
	int log_status = 0;
	char log_user[20] = { '0' };
	char log_password[20] = { '0' };
	//

	log_status = input_num_unit(LOG_NUMBER_LIMIT_MIN, LOG_NUMBER_LIMIT_MAX);
	system("CLS");
	//[1]��ʾ��¼����
	switch (log_status)
	{
	case 1:
		printf("                                               ѧ����¼                                    \n");
		break;

	case 2:
		printf("                                               ��ʦ��¼                                    \n");
		break;

	case 3:
		printf("                                             ��������Ա��¼                                 \n");
		break;
	default :
		printf("����һ��ERROR :\n ");
		break;
	}

	printf("                                              �û��� :");
	scanf("%s", &log_user);
	getchar();

	printf("                                                ���� :");
	scanf("%s", &log_password);
	getchar();


#ifdef DEBUGMODE_1
	printf("log_user:%s\n", log_user);
	printf("log_PASSWORD:%s\n", log_password);
#endif // DEBUGMODE_1




	switch (log_status)
	{
	case 1:
		printf("                                               ѧ����¼                                  **\n");
		if (!(strcmp(log_user, "1")) && !(strcmp(log_password, "1"))) {
			printf("ѧ����¼�ɹ�\n");
			CLS();
			return STU;
		}
		else { printf("�û������������\n"); }
		break;

	case 2:
		printf("                                               ��ʦ��¼                                  **\n");
		if (!(strcmp(log_user, "2")) && !(strcmp(log_password, "2"))) {
			printf("��ʦ��¼�ɹ�\n");
			CLS();
			return TE;
		}
		else { printf("�û������������\n"); }
		break;

	case 3:
		printf("****          ��������Ա��¼                                  **\n");
		if (!(strcmp(log_user, "3")) && !(strcmp(log_password, "3"))) {
			printf("����Ա��¼�ɹ�\n");
			CLS();
			return ADMIN;
		}
		else { printf("�û������������\n"); }
		break;
	default:
		printf("����һ��ERROR :\n ");
		CLS();
		break;
	}
	return VISITOR;
}

void CLS() {
	Sleep(1000);
	system("CLS");
}

///*               �û���������֤����               */
////�Ƿ����û�����ѯ 1:�ر�(����) 0:����
////bool ifFindUser_locked;
//
////�Ƿ��Զ�����û����Ƿ����
////bool ifFindUserName = true;

//////���������
////if (ifFindUser_locked)
////{
////	//DEBUG:�ѿ����û����Զ���ѯ
////	printf("�ѿ����û����Զ���ѯ\n");
////	//TODO:FindUser��ѯ�㷨

////	
////	if (ifFindUserName) 
////	{
////		printf("****           ���룺								  **\n");
////		cin >> log_password;
////	}
////	else
////	{
////		printf("û�ҵ��û���\n");
////	}
////}
////�رյ����
////else
////{
////	printf("****           ���룺								  **\n");
////	cin >> log_password;
////	//TODO:FindUser��ѯ�㷨
////	//TODO:FindPassword��ѯ�㷨
////}
//
///*               �û���������֤����               */