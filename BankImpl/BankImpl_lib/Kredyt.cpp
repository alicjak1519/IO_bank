#include <iostream>
#include "bank.h"
#include <math.h>

using namespace std;

double Kredyt::obliczRate(double K, int l) {
	int lata = (double)l;
	double q = 1.0 + (wysokoscOprocentowania / 12)/100;
	
	double qq = pow(q, lata * 12);
	double r = K * qq * ((q - 1.0) / (qq - 1.0));
	//cout << lata << " " << q << " " << qq << " " << r << endl;
	return r;
}

Kredyt::Kredyt(string temat, double kwota, int lata) {
	tytul = temat;
	wysokoscKredytu = kwota;
	dlugoscTrwania = lata;
	wysokoscOprocentowania = 6.0;
	wysokoscRaty = obliczRate(kwota, lata);
	kwotaSplacona = 0.0;
	kwotaDoSplacenia = (wysokoscRaty * 12 * lata);
	cout << "Roczna stopa procentowa: " << wysokoscOprocentowania << endl;
	cout << "Wysokosc raty: " << wysokoscRaty << endl;
	cout << "Calkowity koszt kredytu: " << ((wysokoscRaty * 12 * lata) - kwota) << endl;
}

void Kredyt::wyswietlKredyt() {
	cout << "Tytul:					" << tytul << endl;
	cout << "Wysokosc kredytu:			" << wysokoscKredytu << endl;
	cout << "Czas trwania (lata):			" << dlugoscTrwania << endl;
	cout << "Roczna stopa procentowa:		" << wysokoscOprocentowania << "%" << endl;
	cout << "Wysokosc raty:				" << wysokoscRaty << endl;
	cout << "Splacono:				" << kwotaSplacona << endl;
	cout << "Do splacenia:				" << kwotaDoSplacenia << endl;
}

void Kredyt::przelejSrodki() {
	kwotaDoSplacenia -= wysokoscRaty;
	kwotaSplacona += wysokoscRaty;
	cout << "Splacono rate w wysokosci: " << wysokoscRaty << endl;
}
