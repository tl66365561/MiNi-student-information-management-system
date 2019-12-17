#ifndef STUINFO_H
#define STUINFO_H

#include <fstream>
#include<string>
#include <vector>
#include <iostream>
#include<windows.h>
#include <fcntl.h>
#include<stdio.h>
using namespace std;


const string PATH = "D:\\学生信息.txt";


class UI{

public:
	void Menu();
	bool Search();
	void Show();
	bool Add();
	void Modify();
	void Delete();



private:
	vector<string> _stuinfo;

};



class Stu{

public:
	char _name[5];
	char _sex[3];
	short _age;
	short _num;
	char _address[12];
	short _score;

public:
	Stu();
	~Stu();
};













#endif
