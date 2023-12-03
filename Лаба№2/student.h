#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class STUDENT {
private:
	string fio;       //ФИО
	string group;     //Группа
	string subject1, subject2, subject3, subject4, subject5; //Предметы
	double mark1, mark2, mark3, mark4, mark5; //Оценки
	double ball;      //Средний балл
	int a;            //Количество предметов
	STUDENT* ptr;
	int size;
public:
	STUDENT();
	STUDENT(int x);
	STUDENT(const STUDENT&);
	~STUDENT();

	void push();  //Добавление студента
	void pop(int);
	//void show();  //Вывод
	void show_increase_ball(); //Вывод студентов по возрастанию среднего балла
	void show_students_have_mark_2(); //Вывод студентов, имеющих хотя бы одну оценку 2
	void edit(int); //Редоктирование объектов

	friend ostream& operator << (ostream& out, STUDENT& obj); //Перегрузка вывода
	friend istream& operator >> (istream& in, STUDENT& obj);  //Перегрузка ввода
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