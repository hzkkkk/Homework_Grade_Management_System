#include "input.h"


int input_num_unit()
{
	int stutas;
	int input_number;
	//检查输入，并吃掉循环
	//当输入为非整型数据时，scanf返回0，menu_Status=0，故menu_Status！=1，执行循环。
	//②当输入为整型数据时，例如flag = X，scanf返回1，stutas = 1, 
	//于是要继续判断(flag < 1 || flag >x)，满足，执行循环。
	//③当输入为整型数据时，例如stutas = 1，scanf返回1
	//于是要继续判断(flag < 1 || flag > X)，不满足，跳出循环。
	while ((stutas = scanf("%d", &input_number)) != 1)
	{
		// 处理掉stdin里的非整型 
		if (stutas != 1)
			scanf("%*s");
		//输入为'qq'时退出
		if (input_number == 122) {
			if (scanf("%d", &input_number) == 122) {
				input_number = QUIT;
				break;
			}
		}
		// 重新输入提示
		printf("错误.不要输入其他字符.\n");
		printf("请再输一次.\n");
		printf("请输入一个整数");
	}
	return input_number;
}

int input_num_unit(int number_limitmin,int number_limitmax)
{
	int stutas;
	int input_number;
	//检查输入，并吃掉循环
	//当输入为非整型数据时，scanf返回0，stutas=0，故stutas！=1，执行循环。
	//②当输入为整型数据时，例如flag = X，scanf返回1，stutas = 1, 
	//于是要继续判断(flag < 1 || flag >x)，满足，执行循环。
	//③当输入为整型数据时，例如stutas = 1，scanf返回1
	//于是要继续判断(flag < 1 || flag > X)，不满足，跳出循环。
	while ((stutas = scanf("%d", &input_number)) != 1 ||
		(input_number == -3 || input_number < number_limitmin || input_number > number_limitmax))
	{
		// 处理掉stdin里的非整型 
		if (input_number != 1)
			scanf("%*s");
		//输入为'qq'时退出
		if (input_number == 122) {
			if (scanf("%d", &input_number) == 122) {
				input_number = QUIT;
				break;
			}
		}
		// 重新输入提示
		printf("错误.不要输入其他字符.\n");
		printf("请再输一次.\n");
		printf("请输入一个整数 %d~%d ", number_limitmin, number_limitmax);
	}
	getchar();

	return input_number;
}

int input_String() {
	return 0;
}

bool input_character_string() {
	char array[20];
	scanf("%s", &array);
	int len = strlen(array);
	int j = 0;
	for (int i = 0; i < len; i++)  //遍历整个字符串
	{
		if (array[i] <= 90 && array[i] >= 65 || array[i] <= 122 && array[i] >= 97)
		{
			j++;
		} 
	}

#ifdef DEBUGMODE_1
	if (j == len) { printf("全为字母"); return true; }
	else if (j == 0) { printf("全不为字母"); return false; }
	else {  printf("不全为字母"); return false;}
#endif

#ifdef DEBUGMODE_0
	if (j == len) {  return true; }
	else if (j == 0) { return false; }
	else { return false; }
#endif


}

bool input_num_string()
{
	char array[20];
	scanf("%s", &array);
	int len = strlen(array);
	int j = 0;
	for (int i = 0; i < len; i++)  //遍历整个字符串
	{
		if (array[i] <= 57 && array[i] >= 48)  //0~9的ASCII码是48~57
		{
			j++;
		}  //找到数字了就数量++
	}
	//数字总数和字符串长度一样，则全是数字，总数为0，则都不是数字，在0~len之间则有部分是数字
#ifdef DEBUGMODE_1
	if (j == len) { printf("全为数字"); return true; }
	else if (j == 0) { printf("全不为数字"); return false; }
	else { printf("不全为数字");  return false;  }
#endif

#ifdef DEBUGMODE_0
	if (j == len) {  return true; }
	else if (j == 0) {  return false; }
	else { return false;  }
#endif


}

bool input_Rex(std::string regex) {
	std::string str;
	std::cin >> str;
	std::regex rx(regex);
	bool bl = std::regex_match(str.begin(), str.end(), rx);
	getchar();

#ifdef DEBUGMODE_1
	if (bl) { std::cout << "正则表达式:" << regex << "匹配成功" << std::endl;  return true; }
	else { std::cout << "正则表达式:" << regex << "匹配失败" << std::endl;  return false; }
#endif

#ifdef DEBUGMODE_0
	if (bl) {  return true; }
	else {   return false; }
#endif

}