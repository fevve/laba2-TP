#pragma once
#include "student.h"
void task1() {
	STUDENT s;
	int button;
	bool flag = true;
	int i;
	//system("cls");
	while (flag) {
		cout << "Меню: " << endl << endl;
		cout << "1 - Добавить студента" << endl;
		cout << "2 - Удаление студента" << endl;
		cout << "3 - Вывод студентов в порядке возрастания среднего балла" << endl;
		cout << "4 - Вывод студентовв, имеющих хотя бы одну оценку 2" << endl;
		cout << "5 - Редактирование данных студента" << endl;
		cout << "0 - Вернуться к выбору задания" << endl << endl;
		cout << "Выберите пункт: ";
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
			cout << "Выберите для удаления: ";
			cin >> i;
			s.pop(i);
			system("pause");
			break;
		case 3:
			s.show_increase_ball();
			system("pause");
			break;
		case 4:
			s.show_students_have_mark_2();
			system("pause");
			break;
		case 5:
			s.show_increase_ball();
			cout << "Выберите для изменения: ";
			cin >> i;
			s.edit(i);
			system("pause");
			break;
		case 0:
			flag = false;
			cout << "\nЗавершение работы программы" << endl;
			break;
		default:
			cout << endl << "Введите другое число!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
}