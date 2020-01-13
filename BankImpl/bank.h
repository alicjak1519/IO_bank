
#include <iostream>
#include <string>


using namespace std;

class Data {
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	Data(int y, int m, int d, int h, int min, int s) : year(y), month(m), day(d), hour(h), minute(min), second(s) {};
};

class Przelew {
public:
	double wysokoscPrzelewu;
	Data data;
	string odbiorca;
	string tytul;
	long numerKontaOdiorcy;
	Przelew() {};
	void wplacNaKonto(KontoBankowe konto) {};
	void pobierzZKonta(KontoBankowe konto) {};
	void sprawdzMozliwoscWykonania(KontoBankowe konto) {};
};

class ZlecenieStale {
public:
	int czestotliwosc;
	Data dataRozpoczecia;
	ZlecenieStale() {};
	void ustawCzestotliwosc() {};
	void ustawDateRozpoczecia() {};
};

class Lokata {
public:
	short wysokoscOprocentowania;
	int czasTrwaniaLokaty;
	Lokata() {};
	void kapitalizacjaOdsetek() {};
	void otwarcieLokaty() {};
	void zamkniecieLokaty() {};
};

class Kredyt {
public:
	double wysokoscKredytu;
	float wysokoscOprocentowania;
	double wysokoscRaty;
	double dlugoscTrwania;
	double kwotaSplacona;
	double kwotaDoSplacenia;
	Kredyt() {};
	void obliczRate() {};
	void przelejSrodki() {};
	void otworzKredyt() {};
	void zamknijKredyt() {};
	void zatwierdzKredyt() {};
};
class KontoBankowe {
public:
	long numerKonta;
	double saldo;
	string typKonta;
	KontoBankowe() {};
	void sprawdzSaldo() {};
	void wp³ac() {};
	void wyplac() {};

};

class Osoba {
public:
	string imie;
	string nazwisko;
	string pesel;
	string nrDowodu;
	Osoba(string im, string naz, string pes, string nrDow) {
		imie = im;
		nazwisko = naz;
		pesel = pes;
		nrDowodu = nrDow;
	};
};

class U¿ytkownik : public Osoba {
public:
	KontoBankowe konto;
	U¿ytkownik() {};
	void sprawdzStanKonta() {};
	void wezKredyt() {};
	void zalozLokate() {};
	void zrobPrzelew() {};
	void zlecPrzelewStaly() {};

};
class Pracownik : public Osoba {
	string idPracownika;
	string stanowisko;
	double wynagrodzenie;
	Pracownik() {};
	void zatwierdzKredyty() {};
	void sprawdzZdolnosc() {};
};