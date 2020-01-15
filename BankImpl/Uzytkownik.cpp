#include <iostream>
#include "bank.h"

using namespace std;

Uzytkownik::Uzytkownik(string im, string naz, string pes, string nrDow, string nrKlienta, string pass)
{
	numerKlienta = nrKlienta;
	haslo = pass;
	Osoba(im, naz, pes, nrDow);
	zalozKonto();
}



void Uzytkownik::zalozKonto()			//Stworzyc menu zakladania konta 
{
	string typKonta;
	cout << "Typy kont: zwykle, walutowe," << endl;
	cout << "Podaj typ konta: "; cin >> typKonta;

	KontoBankowe* konto = new KontoBankowe(typKonta);
	konta.push_back(konto);
	cout << "Utworzyles nowe " << typKonta << " konto." << endl;
	
}

void Uzytkownik::sprawdzStanKonta() {

	for (size_t i = 0; i < konta.size(); i++) {
		cout << i << "-" << konta[i]->zwrocTypKonta() << ": " << konta[i]->zwrocNrKonta() << " SALDO:" << konta[i]->zwrocSaldo() << endl;
	}
}

void Uzytkownik::zrobPrzelew() {
	string adresat, nrKonta, tytul;
	double kwota;
	int konto;
	cout << "Adresat: ";		cin >> adresat;
	cout << "Numer konta: ";	cin >> nrKonta;
	cout << "Kwota: ";			cin >> kwota;
	cout << "Tytul: ";			cin >> tytul;
	cout << "Podaj numer konta z którego chcesz robic zlecenia stale: "; cin >> konto;
	Przelew* przelew = new Przelew(adresat, nrKonta, kwota, tytul);
	przelewy.push_back(przelew);
	konta[konto - 1]->wyplac(kwota);
};

void Uzytkownik::zaplanujPrzelew() {
	string adresat, nrKonta, tytul;
	double kwota;
	int konto;
	cout << "Adresat: ";		cin >> adresat;
	cout << "Numer konta: ";	cin >> nrKonta;
	cout << "Kwota: ";			cin >> kwota;
	cout << "Tytul: ";			cin >> tytul;
	cout << "Podaj numer konta z którego chcesz robic zlecenia stale: "; cin >> konto;
	Przelew* przelew = new Przelew(adresat, nrKonta, kwota, tytul, true);
	przelewy.push_back(przelew);
	konta[konto - 1]->wyplac(kwota);
};

void Uzytkownik::zlecPrzelewStaly() {
	string adresat, nrKonta, tytul, czesto;
	double kwota;
	int konto;
	cout << "Adresat: ";		cin >> adresat;
	cout << "Numer konta: ";	cin >> nrKonta;
	cout << "Kwota: ";			cin >> kwota;
	cout << "Tytul: ";			cin >> tytul;
	cout << "Podaj numer konta z którego chcesz robic zlecenia stale: "; cin >> konto;
	cout << "Czestotilowsc: ";	cin >> czesto;
	Przelew* zlecenieStale = new Przelew(adresat,nrKonta,kwota,tytul,czesto);
	przelewy.push_back(zlecenieStale);
	konta[konto - 1]->wyplac(kwota);
};

void Uzytkownik::pokazHistorie() {
	for (size_t i = 0; i < przelewy.size(); i++) {
		przelewy[i]->wyswietlDane();
	}
}

