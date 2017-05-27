#pragma once
#include <iostream>
#include <string>
using namespace std;
class postac
{
public:
	virtual void wybierzPostac()=0;
	virtual void poczatkoweStaty(int w,int p)=0;
	virtual void ekwipunekPostaci(string postac)=0;
};