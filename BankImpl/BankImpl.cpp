#include <iostream>
#include "bank.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int wybor;
void start();
void menuGlowne();

void stanKonta() {
	system("cls");
	cout << "----STANY KONT----" << endl;
	cout << endl;



	cout << endl;
	cout << "1. Cofnij" << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:
		menuGlowne();
	};
};

void przelewy() {
	system("cls");
	cout << "----PRZELEWY----" << endl;
	cout << endl;
	cout << "1. Wykonaj przelew" << endl;
	cout << "2. Zaplanuj przelew" << endl;
	cout << "3. Zaplanuj zlecenie stale" << endl;
	cout << "4. Historia" << endl;
	cout << "5. Cofnij" << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:
		menuGlowne();
	};
};

void lokaty() {
	system("cls");
	cout << "----LOKATY----" << endl;
	cout << endl;
	cout << "1. Sprawdz stan lokaty" << endl;
	cout << "2. Zaloz lokate" << endl;
	cout << "3. Wplac na lokate" << endl;
	cout << "4. Rozwiaz lokate" << endl;
	cout << "5. Cofnij" << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:
		menuGlowne();
	};
};

void kredyty() {
	system("cls");
	cout << "----KREDYTY----" << endl;
	cout << endl;
	cout << "1. Pokaz kredyty" << endl;
	cout << "2. Zaplac rate" << endl;
	cout << "3. Otworz kredyt" << endl;
	cout << "4. Zamknij kredyt" << endl;
	cout << "5. Cofnij" << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:
		menuGlowne();
	};
};

void menuGlowne() {
	system("cls");
	cout << "----MENU----" << endl;
	cout << endl;
	cout << "1. Stan konta" << endl;
	cout << "2. Przelewy" << endl;
	cout << "3. Lokaty" << endl;
	cout << "4. Kredyty" << endl;
	cout << "5. Wyloguj" << endl;
	cout << endl;
	cout << "Podaj numer komendy: ";
	cin >> wybor;

	switch (wybor) {
	case 1:
		stanKonta();
		break;
	case 2:
		przelewy();
		break;
	case 3:
		lokaty();
		break;
	case 4:
		kredyty();
		break;
	case 5:
		start();
	};
}

void zalozKonto() {
	string imie, nazwisko, pesel, nrDowodu;
	cout << "Wprowadz dane" << endl;
	cout << "Imie: ";			cin >> imie;
	cout << "Nazwisko: ";		cin >> imie;
	cout << "Pesel: ";			cin >> imie;
	cout << "Numer dowodu: ";	cin >> imie;

	Uzytkownik* user = new Uzytkownik(imie, nazwisko, pesel, nrDowodu);

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
		menuGlowne();
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

