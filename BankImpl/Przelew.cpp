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
Przelew::Przelew(string adresat, string nrKonta, double kwota, string tyt, string czesto) {
	data = new Data(2020, 1, 1, 7, 0, 0);
	odbiorca = adresat;
	numerKontaOdiorcy = nrKonta;
	wysokoscPrzelewu = kwota;
	tytul = tyt;
	czestotliwosc = czesto;
};

Przelew::Przelew(string adresat, string nrKonta, double kwota, string tyt, bool check) {
	data = new Data(2020, 1, 1, 7, 0, 0);
	data->ustawDate();
	odbiorca = adresat;
	numerKontaOdiorcy = nrKonta;
	wysokoscPrzelewu = kwota;
	tytul = tyt;
};
void Przelew::wyswietlDane() {
	data->wyswietlDate();
	cout << " " << odbiorca << " " << tytul << " " << wysokoscPrzelewu << endl;
}