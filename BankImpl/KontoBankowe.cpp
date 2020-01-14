#include <iostream>
#include "bank.h"
#include <ctime>
#define DLUGOSC_KONTA 26

using namespace std;

KontoBankowe::KontoBankowe(string typ)
{
	saldo = 0;
	typKonta = typ;
	int liczba;
	srand(time(NULL));
	for (int i = 0; i < DLUGOSC_KONTA; i++) {
		liczba = rand() % 9 + 0;
		numerKonta += liczba;
	}
}

KontoBankowe::KontoBankowe(const KontoBankowe& konto):
	numerKonta(konto.numerKonta), saldo(konto.saldo), typKonta(konto.typKonta)
{}