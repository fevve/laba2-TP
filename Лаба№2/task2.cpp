#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "task2.h"
using namespace std;

void task2() {
	ifstream fin("task2.txt", ios::in);
	try {
		if (!fin.is_open()) {
			exception error("File didn't open");
			throw error;
		}
		if (fin.peek() == EOF) {
			exception empty("File is empty");
			throw empty;
		}
		string line;
		while (getline(fin, line)) {
			istringstream iss(line);
			string word;
			bool containsTwoDigitNumber = false;

			while (iss >> word) {
				try {
					int number = stoi(word);
					if (number >= 10 && number <= 99) {
						containsTwoDigitNumber = true;
						break;
					}
				}
				catch (invalid_argument&) {
				}
			}
			if (containsTwoDigitNumber) {
				cout << line << '\n';
			}
		}
	}
	catch (exception& error){
		cout << error.what() << endl;
		fin.close();
	}
}