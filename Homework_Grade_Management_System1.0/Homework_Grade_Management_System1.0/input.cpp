#include "input.h"


int input_num_unit()
{
	int stutas;
	int input_number;
	//������룬���Ե�ѭ��
	//������Ϊ����������ʱ��scanf����0��menu_Status=0����menu_Status��=1��ִ��ѭ����
	//�ڵ�����Ϊ��������ʱ������flag = X��scanf����1��stutas = 1, 
	//����Ҫ�����ж�(flag < 1 || flag >x)�����㣬ִ��ѭ����
	//�۵�����Ϊ��������ʱ������stutas = 1��scanf����1
	//����Ҫ�����ж�(flag < 1 || flag > X)�������㣬����ѭ����
	while ((stutas = scanf("%d", &input_number)) != 1)
	{
		// �����stdin��ķ����� 
		if (stutas != 1)
			scanf("%*s");
		//����Ϊ'qq'ʱ�˳�
		if (input_number == 122) {
			if (scanf("%d", &input_number) == 122) {
				input_number = QUIT;
				break;
			}
		}
		// ����������ʾ
		printf("����.��Ҫ���������ַ�.\n");
		printf("������һ��.\n");
		printf("������һ������");
	}
	return input_number;
}

int input_num_unit(int number_limitmin,int number_limitmax)
{
	int stutas;
	int input_number;
	//������룬���Ե�ѭ��
	//������Ϊ����������ʱ��scanf����0��stutas=0����stutas��=1��ִ��ѭ����
	//�ڵ�����Ϊ��������ʱ������flag = X��scanf����1��stutas = 1, 
	//����Ҫ�����ж�(flag < 1 || flag >x)�����㣬ִ��ѭ����
	//�۵�����Ϊ��������ʱ������stutas = 1��scanf����1
	//����Ҫ�����ж�(flag < 1 || flag > X)�������㣬����ѭ����
	while ((stutas = scanf("%d", &input_number)) != 1 ||
		(input_number == -3 || input_number < number_limitmin || input_number > number_limitmax))
	{
		// �����stdin��ķ����� 
		if (input_number != 1)
			scanf("%*s");
		//����Ϊ'qq'ʱ�˳�
		if (input_number == 122) {
			if (scanf("%d", &input_number) == 122) {
				input_number = QUIT;
				break;
			}
		}
		// ����������ʾ
		printf("����.��Ҫ���������ַ�.\n");
		printf("������һ��.\n");
		printf("������һ������ %d~%d ", number_limitmin, number_limitmax);
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
	for (int i = 0; i < len; i++)  //���������ַ���
	{
		if (array[i] <= 90 && array[i] >= 65 || array[i] <= 122 && array[i] >= 97)
		{
			j++;
		} 
	}

#ifdef DEBUGMODE_1
	if (j == len) { printf("ȫΪ��ĸ"); return true; }
	else if (j == 0) { printf("ȫ��Ϊ��ĸ"); return false; }
	else {  printf("��ȫΪ��ĸ"); return false;}
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
	for (int i = 0; i < len; i++)  //���������ַ���
	{
		if (array[i] <= 57 && array[i] >= 48)  //0~9��ASCII����48~57
		{
			j++;
		}  //�ҵ������˾�����++
	}
	//�����������ַ�������һ������ȫ�����֣�����Ϊ0���򶼲������֣���0~len֮�����в���������
#ifdef DEBUGMODE_1
	if (j == len) { printf("ȫΪ����"); return true; }
	else if (j == 0) { printf("ȫ��Ϊ����"); return false; }
	else { printf("��ȫΪ����");  return false;  }
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
	if (bl) { std::cout << "������ʽ:" << regex << "ƥ��ɹ�" << std::endl;  return true; }
	else { std::cout << "������ʽ:" << regex << "ƥ��ʧ��" << std::endl;  return false; }
#endif

#ifdef DEBUGMODE_0
	if (bl) {  return true; }
	else {   return false; }
#endif

}