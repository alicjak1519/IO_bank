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

    void ustawDate();

    void wyswietlDate();
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
    float wysokoscOprocentowania;
    short czasTrwaniaLokaty;
    double saldoLokaty;

    Lokata();

public:
    Lokata(const Lokata &lokata);

    Lokata(short czas, double saldo, float oprocentowanie);

    void kapitalizacjaOdsetek() {};

    double zwrocSaldoLokaty() { return saldoLokaty; }

    short zwrocCzasTrwaniaLokaty() { return czasTrwaniaLokaty; }

    float zwrocWysokoscOprocentowania() { return wysokoscOprocentowania; }

    void wplac(double kwota) { saldoLokaty += kwota; }
};

class Kredyt {
private:
    double wysokoscKredytu;
    float wysokoscOprocentowania;
    double wysokoscRaty;
    int dlugoscTrwania;
    double kwotaSplacona;
    double kwotaDoSplacenia;
    string tytul;
public:
    Kredyt(string temat, double kwota, int lata);

    void wyswietlKredyt();

    double obliczRate(double K, int l);

    void przelejSrodki();

    double zwrocRate() { return wysokoscRaty; };

    double splacKredyt() { return kwotaDoSplacenia; };
};

class KontoBankowe {
private:
    double saldo;
    string numerKonta;
    string typKonta;
    vector<Kredyt> kredyty;
    vector<Lokata> lokaty;

    KontoBankowe() {};
public:
    KontoBankowe(string typ);

    KontoBankowe(const KontoBankowe &konto);

    double zwrocSaldo() { return saldo; };

    string zwrocNrKonta() { return numerKonta; };

    string zwrocTypKonta() { return typKonta; };

    void wplac(double kwota);

    void wyplac(double kwota);

};

class Przelew {
private:
    double wysokoscPrzelewu;
    Data *data;
    string odbiorca;
    string tytul;
    string numerKontaOdiorcy;
    string czestotliwosc;
public:
    Przelew(string adresat, string nrKonta, double kwota, string tyt);

    Przelew(string adresat, string nrKonta, double kwota, string tyt, string czesto);

    Przelew(string adresat, string nrKonta, double kwota, string tyt, bool check);

    void wyswietlDane();
};

class Osoba {
private:
    string imie;
    string nazwisko;
    string pesel;
    string nrDowodu;
public:
    Osoba() {};

    Osoba(string im, string naz, string pes, string nrDow);

    string zwrocImie() { return imie; }

    string zwrocNazwisko() { return nazwisko; }
};

class Uzytkownik : public Osoba {
private:
    vector<KontoBankowe *> konta;
    vector<Przelew *> przelewy;
    vector<Przelew *> zleceniaStale;
    vector<Lokata *> lokaty;
    vector<Kredyt *> kredyty;
    string numerKlienta;
    string haslo;
public:
    Uzytkownik() {}

    Uzytkownik(string im, string naz, string pes, string nrDow, string nrKlienta, string pass);

    string getNrKlienta() { return numerKlienta; }

    string getHaslo() { return haslo; }

    void zwrocDane() {
        string im = zwrocImie();
        string naz = zwrocNazwisko();
        cout << im;
        cout << naz;
    }

    void sprawdzStanKonta();

    void wezKredyt();

    void pokazKredyty();

    void zaplacRate();

    void splacKredyt();

    void zalozLokate(int wybor, double kwota, float oprocentowanie, int czasTrwania, double saldo);

    void sprawdzStanLokaty();

    void usunLokate();

    void pokazHistorie();

    void zrobPrzelew(string adresat, int nrKonta,string tytul, double kwota);

    void zaplanujPrzelew();

    void zlecPrzelewStaly();

    void zalozKonto(string typKonta);

    vector<KontoBankowe *> zwrocKonta();

    vector<Lokata *> zwrocLokaty();

    vector<Kredyt *> zwrocKredyty();

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