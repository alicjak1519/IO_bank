#include <iostream>
#include "bank.h"
#include <ctime>
#define DLUGOSC_KONTA 26

using namespace std;

KontoBankowe::KontoBankowe(string typ)
{
	saldo = 2000;
	typKonta = typ;
	int liczba;
	srand(time(NULL));
	for (int i = 0; i < DLUGOSC_KONTA; i++) {
		liczba = rand() % 9 + 0;
		string _str = to_string(liczba);
		numerKonta += _str;
	}
}

KontoBankowe::KontoBankowe(const KontoBankowe& konto):
	numerKonta(konto.numerKonta), saldo(konto.saldo), typKonta(konto.typKonta)
{}
