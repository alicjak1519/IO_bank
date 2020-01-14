#include <iostream>
#include "bank.h"

using namespace std;

Uzytkownik::Uzytkownik(string im, string naz, string pes, string nrDow)
{
	Osoba(im, naz, pes, nrDow);
	zalozKonto();
}



void Uzytkownik::zalozKonto()			//Stworzyc menu zakladania konta 
{
	string typKonta = "zwykle";
	
	KontoBankowe* konto = new KontoBankowe(typKonta);
	konta.push_back(konto);
}