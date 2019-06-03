#include "Stud.h"
#include "Config.h"
#include <iostream>
#include <conio.h>

int Stud::getSid()
{
	return _sid;
}


void Stud::setSid(uint16_t sid)
{
	_sid = sid;
}


string Stud::getSname()
{
	return _sname;
}


void Stud::setSname(string sname)
{
	_sname = sname;
}


uint16_t Stud::getSnumber()
{
	return _snumber;
}


void Stud::setSnumber(uint16_t snumber)
{
	_snumber = snumber;
}


uint16_t Stud::getMode_fitter()
{
	return _mode_fitter;
}


void Stud::setMode_fitter(uint16_t mode_fitter)
{
	_mode_fitter = mode_fitter;
}


/******************************************************** 
	*  @brief    :  更新匹配器 
	*  @param    :  uint16_t mode_fitter外部输入匹配器
	*  @return   :  void
	*  @see      :  getMatchPattern_by_user
	*  @note     :  
	
	*  @author   :  HZK  2019/06/02 16:54 
********************************************************/  
void Stud::updateMode_fitter(uint16_t mode_fitter, update_mode mode)
{
#ifdef DEBUG_OUTPUT_FITTER_1
	char _mode_fitter_binary[10], mode_fitter_binary[10];
	itoa(_mode_fitter, _mode_fitter_binary, 2);
	itoa(mode_fitter, mode_fitter_binary, 2);

	printf("_mode_fitter:%s\n", _mode_fitter_binary);
	printf("mode_fitter:%s\n", mode_fitter_binary);
#endif
	if (mode == ADD)
	{
		_mode_fitter |= mode_fitter;
	}
	else if(mode == REMOVE)
	{
		//昨晚写到这里,明天测试这个语句
		//
		_mode_fitter &= (~mode_fitter);
	}
	else //防止意外
	{
		_mode_fitter |= mode_fitter;
	}
	
#ifdef DEBUG_OUTPUT_FITTER_1
	cout << "Turn to..."<< endl;
	itoa(_mode_fitter, _mode_fitter_binary, 2);
	
	printf("_mode_fitter:%s\n", _mode_fitter_binary);
#endif
}


Stud Stud::getMatchPattern_by_user()
{
	Stud match_pattern;
#ifdef DEBUG_INPUT_0
	//TODO
	printf("请输入要删除的学生的序号\n");
	cin >> match_pattern._snumber;
	
#endif
#ifdef DEBUG_INPUT_1
	match_pattern.setSid(0);
#endif
	match_pattern.setMode_fitter(0);
	uint16_t find_by_what = 0;
	//TODO:
	uint16_t input_uint16_user = 0;
	uint16_t input2_uint16_user = 0;
	string input_string_user = "0";

	bool exit_flag = false;
	do{
		cout << "请输入要查找的字段所在属性" << endl;
		cout << "如:1学号 2名字 3班级序号 4结束输入 5删除匹配位\n" << endl;
		cin >> find_by_what;
		switch (find_by_what)
		{
			case 1:
			{
				//sid
			match_pattern.updateMode_fitter(search_stu_sid,ADD);
				cout << "请输入要查找属性的学号" << endl;
				cin >> input_uint16_user;

				if (Stud::cin_check(cin, "16位整数以内"))
				{
					match_pattern.setSid(input_uint16_user);
				}
				else {}
				break;
			}
			case 2:
			{
				//sname
			match_pattern.updateMode_fitter(search_stu_sname,ADD);
				cout << "请输入要查找属性的姓名" << endl;
				cin >> input_string_user;
				
				if (Stud::cin_check(cin, "文本类型"))
				{
					match_pattern.setSname(input_string_user);
				}
				else{}
				break;
			}
			case 3:
			{
			match_pattern.updateMode_fitter(search_stu_snumber,ADD);
				cout << "请输入要查找属性的序号" << endl;
				cin >> input2_uint16_user;

				if (Stud::cin_check(cin, "16位整数以内"))
				{
					match_pattern.setSnumber(input2_uint16_user);
				}
				else {}
				break;
			}
			case 4:
			{
				cout << "结束输入" << endl;
				exit_flag = true;
				break;
			}
			case 5:
			{
				cout << "请输入要删除的匹配位的序号" << endl;
				cout << "如:1学号 2名字 3班级序号 9返回" << endl;
				uint16_t select_user;
				cin >> select_user;

				switch (select_user)
				{
				case 1:
				{
					match_pattern.updateMode_fitter(search_stu_sid,REMOVE);
					break;
				}
				case 2:
				{
					match_pattern.updateMode_fitter(search_stu_sname,REMOVE);
					break;
				}
				case 3:
				{
					match_pattern.updateMode_fitter(search_stu_snumber,REMOVE);
					break;
				}
				case 9:
				{
					cout << "退出" << endl;
					exit_flag = true;
					break;
				}
				default:
					break;
				}
				
			}
			default:
			{
				break;
			}
		}
		match_pattern.show_table();
		
	} while (!exit_flag);

	return match_pattern;
}


bool Stud::operator==(const Stud &stud)
{
	return equal(stud);
}


bool Stud::equal(const Stud &stud)
{
	uint16_t mode_select = stud._mode_fitter;
	bool match_select = false;
	if (mode_select & search_stu_sid)
	{
#ifdef DEBUGMODE_FOR_Studcpp_1
		cout << "检测学号检测位开启,开始尝试匹配学号" << endl;
#endif
		//核心
		match_select |= (_sid == stud._sid);
#ifdef DEBUGMODE_FOR_Studcpp_1
		if (match_select == false)
		{
			cout << "学号检测不通过" << endl;
		}
		else
		{
			cout << "学号检测通过" << endl;
		}
#endif
	}
	if (mode_select & search_stu_sname)
	{
		cout << "检测姓名检测位开启,开始尝试匹配姓名" << endl;
		//核心
		match_select |= (_sname == stud._sname);
#ifdef DEBUGMODE_FOR_Studcpp_1
		if (match_select == false)
		{
			cout << "姓名检测不通过" << endl;
		}
		else
		{
			cout << "姓名检测通过" << endl;
		}
#endif
	}
	if (mode_select & search_stu_snumber)
	{
		cout << "检测序号检测位开启,开始尝试匹配序号" << endl;
		//核心
		match_select |= (_snumber == stud._snumber);
#ifdef DEBUGMODE_FOR_Studcpp_1
		if (match_select == false)
		{
			cout << "序号检测不通过" << endl;
		}
		else
		{
			cout << "序号检测通过" << endl;
		}
#endif
	}
	return match_select;
}


void Stud::show_table()
{
	//第一行标题
	cout << endl << setw(8) << left << " "
		<< setw(6) << left << "学号"
		<< setw(6) << left << "姓名"
		<< setw(6) << left << "序号" << endl;
	//第二行数据
	cout << setw(8) << left << "数据:";
	if (_mode_fitter & search_stu_sid)
	{
		cout << setw(6) << left << _sid;
	}
	else
	{
		cout << setw(6) << left << "N/A";
	}
	if (_mode_fitter & search_stu_sname)
	{
		cout << setw(6) << left << _sname;
	}
	else
	{
		cout << setw(6) << left << "N/A";
	}
	if (_mode_fitter & search_stu_snumber)
	{
		cout << setw(6) << left << _snumber;
	}
	else
	{
		cout << setw(6) << left << "N/A";
	}
	cout << endl;
	//第三行匹配位
	cout << setw(8) << left << "匹配位";
	if (_mode_fitter & search_stu_sid)
	{
		cout << setw(6) << left << "Y";
	}
	else
	{
		cout << setw(6) << left << "N";
	}
	if (_mode_fitter & search_stu_sname)
	{
		cout << setw(6) << left << "Y";
	}
	else
	{
		cout << setw(6) << left << "N";
	}
	if (_mode_fitter & search_stu_snumber)
	{
		cout << setw(6) << left << "Y";
	}
	else
	{
		cout << setw(6) << left << "N";
	}
	cout << endl;
}


bool Stud::cin_check(istream & _cin,string error_range)
{
	if (_cin.fail())
	{
		cout << "输入数据需为" << error_range << ",您的输入不符合" << endl;
		_cin.clear();
		_cin.ignore(1024, '\n');
		return false;
		//_cin.sync();//清空缓冲区,以及输出缓冲区
	}
	else
	{
		cout << "输入成功" << endl << endl;
		return true;
	}

}


ostream &operator<<(ostream & _cout, Stud & _stud)
{
	_cout << setw(6) << left << _stud._sid
		<< setw(6) << left << _stud._sname
		<< setw(6) << left << _stud._snumber;
	return _cout;
}


/********************************************************
*  @brief    :  用户输入数据
*  @param    :  istream & _cin 标准输入流
*  @param    :  Stud & _stud
*  @see      :  StudManager::mode_select
*  @note     :  友元函数,重载运算符
*  @return   :  屏幕输出

*  @author   :  HZK  2019/06/03 11:16
********************************************************/
istream &operator >> (istream & _cin, Stud & _stud)
{
	cout << "请输入学号 (16位整数以内)" << endl;
	_cin >> _stud._sid;
	Stud::cin_check(_cin, "16位整数以内");

	cout << "请输入姓名 (文本)" << endl;
	_cin >> _stud._sname;
	Stud::cin_check(_cin, "文本类型");

	cout << "请输入序号 (16位整数以内)" << endl;
	_cin >> _stud._snumber;
	Stud::cin_check(_cin, "16位整数以内");

	return _cin;
}
