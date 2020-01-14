#include <iostream>
#include "bank.h"
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <vector>

using namespace std;

vector <Uzytkownik*> listaKlientow;
Uzytkownik* zalogowany;
int wybor;

void stanKonta();
void przelewy();
void lokaty();
void kredyty();
void menuGlowne();
void logowanie();
void zalozKonto();
void start();
int main()
{
	start();

	return 0;
}


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

void logowanie() {
	string nrklienta, haslo;
	cout << "Podaj numer klienta: ";	cin >> nrklienta;
	cout << "Podaj haslo: ";			cin >> haslo;



}

void zalozKonto() {
	string imie, nazwisko, pesel, nrDowodu, numerKlienta, haslo;
	cout << "Wprowadz dane" << endl;
	cout << "Imie: ";			cin >> imie;
	cout << "Nazwisko: ";		cin >> nazwisko;
	cout << "Pesel: ";			cin >> pesel;
	cout << "Numer dowodu: ";	cin >> nrDowodu;

	srand(time(NULL));
	for (int i = 0; i < 8; i++) {
		int liczba = rand() % 9 + 0;
		string _str = to_string(liczba);
		numerKlienta += _str;
	}

	cout << endl << "Witamy Cie " << imie << " w naszym banku." << endl << endl;
	cout << "To twoj nowy numer klienta: " << numerKlienta << endl;
	cout << "Podaj haslo: ";	cin >> haslo;


	Uzytkownik* user = new Uzytkownik(imie, nazwisko, pesel, nrDowodu, numerKlienta, haslo);
	listaKlientow.push_back(user);
	cout << endl << "Zaloguj sie teraz do twojego nowego konta.";
	getchar(); getchar();
	start();

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
		zalozKonto();
		break;
	default:
		break;

	};

};
