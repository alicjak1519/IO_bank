#include <iostream>
#include "bank.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int wybor;
void start();

void logowanie() {
	system("cls");
	cout << "----MENU----" << endl;
	cout << endl;
	cout << "1. Przelew." << endl;
	cout << "2. Saldo." << endl;
	cout << "3. Wyloguj." << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:
		cout << "przelew" << endl;
		break;
	case 2:
		cout << "saldo" << endl;
		break;
	case 3:
		start();
	};
}

void zalozKonto() {

}

void start() {
	system("cls");
	cout << "----MENU----" << endl;
	cout << endl;
	cout << "1. Logowanie." << endl;
	cout << "2. Zaloz konto." << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	
	switch (wybor) {
	case 1:
		logowanie();
		break;
	case 2:
		cout << "kon" << endl;
		break;
	default:
		break;

	};

};

int main()
{
	start();

	return 0;
}

