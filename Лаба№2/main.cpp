#include <iostream>
#include "student.h"
using namespace std;



void task1() {
	STUDENT s;
	int button;
	bool flag = true;
	int i;
	//system("cls");
	while (flag) {
		cout << "����: " << endl << endl;
		cout << "1 - �������� ��������" << endl;
		cout << "2 - �������� ��������" << endl;
		cout << "3 - ����� ���������" << endl;
		cout << "4 - ����� ��������� � ������� ����������� �������� �����" << endl;
		cout << "5 - ����� ����������, ������� ���� �� ���� ������ 2" << endl;
		cout << "6 - �������������� ������ ��������" << endl;
		cout << "0 - ��������� � ������ �������" << endl << endl;
		cout << "�������� �����: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			s.push();
			system("pause");
			break;
		case 2:
			cout << "�������� ��� ��������: ";
			cin >> i;
			s.pop(i);
			system("pause");
			break;
		case 3:
			s.show();
			system("pause");
			break;
		case 4:
			s.show_increase_ball();
			system("pause");
			break;
		case 5:
			s.show_students_have_mark_2();
			system("pause");
			break;
		case 6:
			s.show();
			cout << "�������� ��� ���������: ";
			cin >> i;
			s.edit(i);
			system("pause");
			break;
		case 0:
			flag = false;
			cout << "\n���������� ������ ���������" << endl;
			break;
		default:
			cout << endl << "������� ������ �����!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
}





void task2() {


	ifstream in;       // ����� ��� ������
	in.open("task2.txt"); // �������� ���� ��� ������

	char* ptr;
	bool flag = true;


	if (!in.is_open())
		cout << "������ �������� �����!" << endl;
	else {
		cout << "���� ������" << endl << endl << endl;
		string str;
		while (!in.eof()) {


			str = "";
			getline(in, str);


			cout << str << endl;

		}
	}
	in.close();             // ��������� ����
}


int main() {
	setlocale(LC_ALL, "Russian");
	string menu = "����:\n1 - ������ �������\n2 - ������ �������\n0 - ���������� ������\n>";
	int knopka;
	bool mode = true;
	while (mode) {
		cout << menu;
		cin >> knopka;
		if (cin.fail()) {
			knopka = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (knopka) {
		case 1:
			task1();
			system("pause");
			break;
		case 2:
			task2();
			system("pause");
			break;
		case 0:
			mode = false;
			cout << "\n���������� ������" << endl;
			break;
		default:
			cout << endl << "������� ������ �����!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
	return 0;
}