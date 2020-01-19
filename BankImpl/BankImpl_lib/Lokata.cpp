#include <iostream>
#include "bank.h"

using namespace std;

Lokata::Lokata()
{
	wysokoscOprocentowania = 1.0;
	czasTrwaniaLokaty = 1;
	saldoLokaty = 0;
}

Lokata::Lokata(const Lokata& lokata)
{
	wysokoscOprocentowania = lokata.wysokoscOprocentowania;
	czasTrwaniaLokaty = lokata.czasTrwaniaLokaty;
	saldoLokaty = lokata.saldoLokaty;
}

Lokata::Lokata(short czas, double kwota, float oprocentowanie) :
	czasTrwaniaLokaty(czas), saldoLokaty(kwota), wysokoscOprocentowania(oprocentowanie)
{}