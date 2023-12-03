#include "student.h"
#include <iostream>
#include <string>
using namespace std;

STUDENT::STUDENT() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ �� ��������� ��� ������ STUDENT" << endl << endl;
	fio = "";
	group = "";
	subject1 = subject2 = subject3 = subject4 = subject5 = "";
	mark1 = mark2 = mark3 = mark4 = mark5 = 0;
	ball = 0;
	size = 0;
}

STUDENT::STUDENT(int x) {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ � ���������� ��� ������ STUDENT" << endl << endl;
}

STUDENT::STUDENT(const STUDENT&) {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ ����������� ��� ������ STUDENT" << endl << endl;
}

STUDENT::~STUDENT() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ����������� ��� ������ STUDENT" << endl << endl;
}

string STUDENT::getName() {
	return this->fio;
}

string STUDENT::getGroup() {
	return this->group;
}

string STUDENT::getSubject1() {
	return this->subject1;
}

double STUDENT::getMark1() {
	return this->mark1;
}

double STUDENT::getBall() {
	return this->ball;
}

void STUDENT::setName(string fio) {
	this->fio = fio;
}

void STUDENT::setGroup(string group) {
	this->group = group;
}

void STUDENT::setSubject1(string subject1) {
	this->subject1 = subject1;
}

void STUDENT::setMark1(double mark1) {
	this->mark1 = mark1;
}

void STUDENT::setBall(double ball) {
	this->ball = ball;
}

void STUDENT::push() {
	STUDENT* temp = new STUDENT[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
	cin >> ptr[size];
	++size;
	cout << endl << endl << "����� ������ ��������" << endl << endl;
}

void STUDENT::pop(int num) {
	try {
		if (size == 0) {
			exception error("�����");
			throw error;
		}
		if (num < 0 || num >= size) {
			exception bug("�������� �����");
			throw bug;
		}
		STUDENT* temp = new STUDENT[size - 1];
		ptr[num] = ptr[size - 1];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
		--size;
		cout << endl << endl << "������ ������" << endl << endl;
	}
	catch (exception& error) {
		cout << error.what() << endl << endl;
	}
}

//void STUDENT::show() {
//	setlocale(LC_ALL, "Russian");
//
//
//	if (size == 0) {
//		cout << "�����" << endl << endl;
//	}
//	else {
//		for (int i = 0; i < size; ++i) {
//			cout << ptr[i] << endl;
//		}
//	}
//}

void STUDENT::show_students_have_mark_2() {
	setlocale(LC_ALL, "Russian");
	int kol = 0;
	if (size == 0) {
		cout << "�����" << endl << endl;
	}

	else {
		for (int i = 0; i < size; ++i) {
			if (ptr[i].mark1 == 2 || ptr[i].mark2 == 2 || ptr[i].mark3 == 2) {
				cout << ptr[i] << endl;
				kol++;
			}
		}
	}
	if (kol == 0) cout << "����� ��������� ���" << endl << endl;
}

void STUDENT::show_increase_ball() {
	setlocale(LC_ALL, "Russian");
	STUDENT* temp = new STUDENT[size + 1];

	if (size == 0) {
		cout << "�����" << endl << endl;
	}

	else {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size - 1; ++j) {
				if (ptr[j].ball > ptr[j + 1].ball) {
					temp[j] = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp[j];
				}
			}
		}

		for (int i = 0; i < size; ++i) {
			cout << ptr[i] << endl;
		}
	}

}

void STUDENT::edit(int change) {
	try {
		if (size == 0) {
			exception error("�����");
			throw error;
		}
		if (change < 0 || change >= size) {
			exception bug("�������� �����");
			throw bug;
		}
		cin >> ptr[change];
	}
	catch (exception& bug) {
		cout << bug.what() << endl << endl;
	}
}

STUDENT& STUDENT::operator=(STUDENT& copy) {
	this->fio = copy.fio;
	this->group = copy.group;
	this->subject1 = copy.subject1;
	this->subject2 = copy.subject2;
	this->subject3 = copy.subject3;
	this->subject4 = copy.subject4;
	this->subject5 = copy.subject5;
	this->mark1 = copy.mark1;
	this->mark2 = copy.mark2;
	this->mark3 = copy.mark3;
	this->mark4 = copy.mark4;
	this->mark5 = copy.mark5;
	this->ball = copy.ball;
	this->a = copy.a;
	return *this;
}

ostream& operator<<(ostream& out, STUDENT& obj) {   //����� ������
	setlocale(LC_ALL, "Russian");
	out << "������� � ��������: " << obj.fio << endl;
	out << "����� ������: " << obj.group << endl;


	if (obj.a == 1) {
		out << "�������: " << obj.subject1 << endl;
		out << "������: " << obj.mark1 << endl;
	}
	if (obj.a == 2) {
		out << "�������: " << obj.subject1 << endl;
		out << "������: " << obj.mark1 << endl;
		out << "�������: " << obj.subject2 << endl;
		out << "������: " << obj.mark2 << endl;
	}
	if (obj.a == 3) {
		out << "�������: " << obj.subject1 << endl;
		out << "������: " << obj.mark1 << endl;
		out << "�������: " << obj.subject2 << endl;
		out << "������: " << obj.mark2 << endl;
		out << "�������: " << obj.subject3 << endl;
		out << "������: " << obj.mark3 << endl;
	}
	if (obj.a == 4) {
		out << "�������: " << obj.subject1 << endl;
		out << "������: " << obj.mark1 << endl;
		out << "�������: " << obj.subject2 << endl;
		out << "������: " << obj.mark2 << endl;
		out << "�������: " << obj.subject3 << endl;
		out << "������: " << obj.mark3 << endl;
		out << "�������: " << obj.subject4 << endl;
		out << "������: " << obj.mark4 << endl;
	}
	if (obj.a == 5) {
		out << "�������: " << obj.subject1 << endl;
		out << "������: " << obj.mark1 << endl;
		out << "�������: " << obj.subject2 << endl;
		out << "������: " << obj.mark2 << endl;
		out << "�������: " << obj.subject3 << endl;
		out << "������: " << obj.mark3 << endl;
		out << "�������: " << obj.subject4 << endl;
		out << "������: " << obj.mark4 << endl;
		out << "�������: " << obj.subject5 << endl;
		out << "������: " << obj.mark5 << endl;
	}
	out << "������� ����: " << obj.ball << endl;
	return out;
}

istream& operator>>(istream& in, STUDENT& obj) {   //���� ������
	setlocale(LC_ALL, "Russian");
	cout << "������� ������:" << endl << endl;
	cout << "������� � ��������: ";
	getchar();
	getline(cin, obj.fio);
	cout << "����� ������: ";
	getchar();
	getline(cin, obj.group);
	double s = 0;
	cout << "������� ���������� ���������:";
	cin >> obj.a;

	if (obj.a == 1) {
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject1);
		while (1) {
			cout << "������: ";
			cin >> obj.mark1;
			if (obj.mark1 <= 0 || obj.mark1 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
	}
	if (obj.a == 2) {
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject1);
		while (1) {
			cout << "������: ";
			cin >> obj.mark1;
			if (obj.mark1 <= 0 || obj.mark1 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject2);
		while (1) {
			cout << "������: ";
			cin >> obj.mark2;
			if (obj.mark2 <= 0 || obj.mark2 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
	}
	if (obj.a == 3) {
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject1);
		while (1) {
			cout << "������: ";
			cin >> obj.mark1;
			if (obj.mark1 <= 0 || obj.mark1 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject2);
		while (1) {
			cout << "������: ";
			cin >> obj.mark2;
			if (obj.mark2 <= 0 || obj.mark2 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject3);
		while (1) {
			cout << "������: ";
			cin >> obj.mark3;
			if (obj.mark3 <= 0 || obj.mark3 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
	}
	if (obj.a == 4) {
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject1);
		while (1) {
			cout << "������: ";
			cin >> obj.mark1;
			if (obj.mark1 <= 0 || obj.mark1 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject2);
		while (1) {
			cout << "������: ";
			cin >> obj.mark2;
			if (obj.mark2 <= 0 || obj.mark2 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject3);
		while (1) {
			cout << "������: ";
			cin >> obj.mark3;
			if (obj.mark3 <= 0 || obj.mark3 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject4);
		while (1) {
			cout << "������: ";
			cin >> obj.mark4;
			if (obj.mark4 <= 0 || obj.mark4 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
	}
	if (obj.a == 5) {
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject1);
		while (1) {
			cout << "������: ";
			cin >> obj.mark1;
			if (obj.mark1 <= 0 || obj.mark1 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject2);
		while (1) {
			cout << "������: ";
			cin >> obj.mark2;
			if (obj.mark2 <= 0 || obj.mark2 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject3);
		while (1) {
			cout << "������: ";
			cin >> obj.mark3;
			if (obj.mark3 <= 0 || obj.mark3 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject4);
		while (1) {
			cout << "������: ";
			cin >> obj.mark4;
			if (obj.mark4 <= 0 || obj.mark4 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
		cout << "�������: ";
		getchar();
		getline(cin, obj.subject5);
		while (1) {
			cout << "������: ";
			cin >> obj.mark5;
			if (obj.mark5 <= 0 || obj.mark5 > 5) cout << "������������ ������!!!\n������� ������!!!" << endl;
			else break;
		}
	}
	s = obj.mark1 + obj.mark2 + obj.mark3 + obj.mark4 + obj.mark5;
	obj.ball = s / obj.a;
	return in;
}