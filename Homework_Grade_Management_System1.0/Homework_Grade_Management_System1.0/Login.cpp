#include "Config.h"
#include "input.h"
#include "Login.h"

Authority showLogin() {
	SHOW_MENU();
	printf("         ************************************登录界面*************************************\n");
	printf("         ---------------------------------------------------------------------------------\n");
	printf("                                        （1） 学生登录                                      \n");
	printf("                                        （2） 教师登录							      	   \n");
	printf("                                        （3） 超级管理员登录						           \n");
	printf("请输入一个整数 %d~%d: " , LOG_NUMBER_LIMIT_MIN, LOG_NUMBER_LIMIT_MAX);
	
	//
	int log_status = 0;
	char log_user[20] = { '0' };
	char log_password[20] = { '0' };
	//

	log_status = input_num_unit(LOG_NUMBER_LIMIT_MIN, LOG_NUMBER_LIMIT_MAX);
	system("CLS");
	//[1]显示登录界面
	switch (log_status)
	{
	case 1:
		printf("                                               学生登录                                    \n");
		break;

	case 2:
		printf("                                               教师登录                                    \n");
		break;

	case 3:
		printf("                                             超级管理员登录                                 \n");
		break;
	default :
		printf("发生一个ERROR :\n ");
		break;
	}

	printf("                                              用户名 :");
	scanf("%s", &log_user);
	getchar();

	printf("                                                密码 :");
	scanf("%s", &log_password);
	getchar();


#ifdef DEBUGMODE_1
	printf("log_user:%s\n", log_user);
	printf("log_PASSWORD:%s\n", log_password);
#endif // DEBUGMODE_1




	switch (log_status)
	{
	case 1:
		printf("                                               学生登录                                  **\n");
		if (!(strcmp(log_user, "1")) && !(strcmp(log_password, "1"))) {
			printf("学生登录成功\n");
			CLS();
			return STU;
		}
		else { printf("用户名或密码错误\n"); }
		break;

	case 2:
		printf("                                               教师登录                                  **\n");
		if (!(strcmp(log_user, "2")) && !(strcmp(log_password, "2"))) {
			printf("老师登录成功\n");
			CLS();
			return TE;
		}
		else { printf("用户名或密码错误\n"); }
		break;

	case 3:
		printf("****          超级管理员登录                                  **\n");
		if (!(strcmp(log_user, "3")) && !(strcmp(log_password, "3"))) {
			printf("管理员登录成功\n");
			CLS();
			return ADMIN;
		}
		else { printf("用户名或密码错误\n"); }
		break;
	default:
		printf("发生一个ERROR :\n ");
		CLS();
		break;
	}
	return VISITOR;
}

void CLS() {
	Sleep(1000);
	system("CLS");
}

///*               用户名密码验证过程               */
////是否开启用户名查询 1:关闭(锁定) 0:开启
////bool ifFindUser_locked;
//
////是否自动检查用户名是否存在
////bool ifFindUserName = true;

//////开启的情况
////if (ifFindUser_locked)
////{
////	//DEBUG:已开启用户名自动查询
////	printf("已开启用户名自动查询\n");
////	//TODO:FindUser查询算法

////	
////	if (ifFindUserName) 
////	{
////		printf("****           密码：								  **\n");
////		cin >> log_password;
////	}
////	else
////	{
////		printf("没找到用户名\n");
////	}
////}
////关闭的情况
////else
////{
////	printf("****           密码：								  **\n");
////	cin >> log_password;
////	//TODO:FindUser查询算法
////	//TODO:FindPassword查询算法
////}
//
///*               用户名密码验证过程               */