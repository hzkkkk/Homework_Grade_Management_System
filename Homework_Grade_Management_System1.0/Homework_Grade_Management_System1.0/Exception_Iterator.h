#pragma once
#include "Config.h"
using namespace std;
class IteratorMisMatchException : public exception
{
public:
	IteratorMisMatchException(const char * inf) : info(inf) {}
	string what()
	{
		return info;
	}
private:
	string info;
};