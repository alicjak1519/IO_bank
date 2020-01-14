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