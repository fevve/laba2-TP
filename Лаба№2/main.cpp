#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "menu_task1.h"
#include "task2.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	string menu = "Меню:\n1 - Первое задание\n2 - Второе задание\n0 - Завершение работы\n>";
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
			cout << "\nЗавершение работы" << endl;
			break;
		default:
			cout << endl << "Введите другое число!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
	return 0;
}