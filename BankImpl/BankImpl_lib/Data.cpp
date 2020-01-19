#include <iostream>
#include "bank.h"

using namespace std;


void Data::ustawDate() {
	cout << "Podaj rok: "; cin >> year;
	cout << "Podaj miesiac: "; cin >> month;
	cout << "Podaj dzien: "; cin >> day;
	cout << "Podaj godzine: "; cin >> hour;
	cout << "Podaj minute: "; cin >> minute;

	cout << "Data ustawiona na: " << day << "." << month << "." << year << ", godzina " << hour << ":" << minute << endl;
}
void Data::wyswietlDate() {
	cout << day << "." << month << "." << year << " " << hour << ":" << minute;
}