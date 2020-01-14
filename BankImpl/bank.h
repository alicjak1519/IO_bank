
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Data {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Data(int y, int m, int d, int h, int min, int s) : year(y), month(m), day(d), hour(h), minute(min), second(s) {};
};


class ZlecenieStale {
private:
	int czestotliwosc;
	Data dataRozpoczecia;
public:
	ZlecenieStale();
	void ustawCzestotliwosc() {};
	void ustawDateRozpoczecia() {};
};

class Lokata {
private:
	short wysokoscOprocentowania;
	int czasTrwaniaLokaty;
public:
	Lokata() {};
	void kapitalizacjaOdsetek() {};
	void otwarcieLokaty() {};
	void zamkniecieLokaty() {};
};

class Kredyt {
private:
	double wysokoscKredytu;
	float wysokoscOprocentowania;
	double wysokoscRaty;
	double dlugoscTrwania;
	double kwotaSplacona;
	double kwotaDoSplacenia;
public:
	Kredyt() {};
	void obliczRate() {};
	void przelejSrodki() {};
	void otworzKredyt() {};
	void zamknijKredyt() {};
	void zatwierdzKredyt() {};
};

class KontoBankowe {
private:
	double saldo;
	string numerKonta;
	string typKonta;
	vector <Kredyt> kredyty;
	vector <Lokata> lokaty;
	KontoBankowe() {};
public:
	KontoBankowe(string typ);
	KontoBankowe(const KontoBankowe &konto);
	void sprawdzSaldo() {};
	void wp³ac() {};
	void wyplac() {};

};

class Przelew {
private:
	double wysokoscPrzelewu;
	Data data;
	string odbiorca;
	string tytul;
	long numerKontaOdiorcy;
public:
	Przelew();
	void wplacNaKonto(KontoBankowe konto) {};
	void pobierzZKonta(KontoBankowe konto) {};
	void sprawdzMozliwoscWykonania(KontoBankowe konto) {};
};

class Osoba {
private:
	string imie;
	string nazwisko;
	string pesel;
	string nrDowodu;
public:
	Osoba(){}
	Osoba(string im, string naz, string pes, string nrDow);
};

class Uzytkownik : public Osoba {
private:
	vector <KontoBankowe*> konta;
public:
	Uzytkownik();
	Uzytkownik(string im, string naz, string pes, string nrDow);
	void sprawdzStanKonta() {};
	void wezKredyt() {};
	void zalozLokate() {};
	void zrobPrzelew() {};
	void zlecPrzelewStaly() {};
	void zalozKonto();

};
class Pracownik : public Osoba {
private:
	string idPracownika;
	string stanowisko;
	double wynagrodzenie;
public:
	Pracownik();
	void zatwierdzKredyty() {};
	void sprawdzZdolnosc() {};
};