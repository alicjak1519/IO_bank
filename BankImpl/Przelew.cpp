#include <iostream>
#include "bank.h"

using namespace std;

Przelew::Przelew(string adresat, string nrKonta, double kwota, string tyt) {
	data = new Data(2020, 1, 1, 7, 0, 0);
	odbiorca = adresat;
	numerKontaOdiorcy = nrKonta;
	wysokoscPrzelewu = kwota;
	tytul = tyt;
	

};