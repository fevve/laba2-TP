#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class STUDENT {
private:
	string fio;       //���
	string group;     //������
	string subject1, subject2, subject3, subject4, subject5; //��������
	double mark1, mark2, mark3, mark4, mark5; //������
	double ball;      //������� ����
	int a;            //���������� ���������
	STUDENT* ptr;
	int size;
public:
	STUDENT();
	STUDENT(int x);
	STUDENT(const STUDENT&);
	~STUDENT();

	void push();  //���������� ��������
	void pop(int);
	//void show();  //�����
	void show_increase_ball(); //����� ��������� �� ����������� �������� �����
	void show_students_have_mark_2(); //����� ���������, ������� ���� �� ���� ������ 2
	void edit(int); //�������������� ��������

	friend ostream& operator << (ostream& out, STUDENT& obj); //���������� ������
	friend istream& operator >> (istream& in, STUDENT& obj);  //���������� �����
	STUDENT& operator =(STUDENT& copy);

	string getName();
	string getGroup();
	string getSubject1();
	double getMark1();
	double getBall();

	void setName(string fio);
	void setGroup(string group);
	void setSubject1(string subject1);
	void setMark1(double mark1);
	void setBall(double ball);
};