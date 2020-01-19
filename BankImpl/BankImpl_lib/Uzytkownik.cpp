#include <iostream>
#include "bank.h"

using namespace std;

Uzytkownik::Uzytkownik(string im, string naz, string pes, string nrDow, string nrKlienta, string pass) {
    numerKlienta = nrKlienta;
    haslo = pass;
    Osoba(im, naz, pes, nrDow);
    string typKonta;
    cout << "Typy kont: zwykle, walutowe," << endl;
    cout << "Podaj typ konta: ";
    cin >> typKonta;
    string kont = typKonta;
    zalozKonto(kont);
}

void Uzytkownik::zalozKonto(string typKonta)            //Stworzyc menu zakladania konta
{
    KontoBankowe *konto = new KontoBankowe(typKonta);
    konta.push_back(konto);
    cout << "Utworzyles nowe " << typKonta << " konto." << endl;

}

void Uzytkownik::sprawdzStanKonta() {

    for (size_t i = 0; i < konta.size(); i++) {
        cout << i + 1 << "- Typ konta: " << konta[i]->zwrocTypKonta() << "\t Numer konta: " << konta[i]->zwrocNrKonta()
             << " \t SALDO:" << konta[i]->zwrocSaldo() << endl;
    }
}

void Uzytkownik::zrobPrzelew(string adresat, int nrKonta, string tytul, double kwota) {

    string konto = this->zwrocKonta()[nrKonta]->zwrocNrKonta();
    Przelew *przelew = new Przelew(adresat, konto, kwota, tytul);
    przelewy.push_back(przelew);
    konta[nrKonta]->wyplac(kwota);
};

void Uzytkownik::zaplanujPrzelew() {
    string adresat, nrKonta, tytul;
    double kwota;
    int konto;
    cout << "Adresat: ";
    cin >> adresat;
    cout << "Numer konta: ";
    cin >> nrKonta;
    cout << "Kwota: ";
    cin >> kwota;
    cout << "Tytul: ";
    cin >> tytul;
    cout << "Podaj numer konta z kt�rego chcesz robic zlecenia stale: ";
    cin >> konto;
    Przelew *przelew = new Przelew(adresat, nrKonta, kwota, tytul, true);
    przelewy.push_back(przelew);
    konta[konto - 1]->wyplac(kwota);
};

void Uzytkownik::zlecPrzelewStaly() {
    string adresat, nrKonta, tytul, czesto;
    double kwota;
    int konto;
    cout << "Adresat: ";
    cin >> adresat;
    cout << "Numer konta: ";
    cin >> nrKonta;
    cout << "Kwota: ";
    cin >> kwota;
    cout << "Tytul: ";
    cin >> tytul;
    cout << "Podaj numer konta z kt�rego chcesz robic zlecenia stale: ";
    cin >> konto;
    cout << "Czestotilowsc: ";
    cin >> czesto;
    Przelew *zlecenieStale = new Przelew(adresat, nrKonta, kwota, tytul, czesto);
    przelewy.push_back(zlecenieStale);
    konta[konto - 1]->wyplac(kwota);
};

void Uzytkownik::pokazHistorie() {
    for (size_t i = 0; i < przelewy.size(); i++) {
        przelewy[i]->wyswietlDane();
    }
}

void
Uzytkownik::zalozLokate(int wybor, double kwota, float oprocentowanie,
                        int czasTrwania, double saldo)  //TESTY za�o�y� lokat� gdy za ma�e �rodki, oraz gdy wszystko ok
{
    if (saldo < kwota) {
        cout << "Zbyt malo srodkow na koncie, nie mozna zalozyc lokaty" << endl;
    } else {
        konta[wybor]->wyplac(kwota);

        Lokata *lokata = new Lokata(czasTrwania, kwota, oprocentowanie);
        lokaty.push_back(lokata);
        cout << "Zalozono lokate pomyslnie" << endl;
    }
    //system("PAUSE");
}

void
Uzytkownik::sprawdzStanLokaty()                                //TESTY: Sprawdzi� lokat� pust�, oraz tak� kt�ra istnieje
{
    if (lokaty.empty()) {
        cout << "Brak lokat" << endl;
    } else {
        for (size_t i = 0; i < lokaty.size(); i++) {
            cout << i << " \t Saldo lokaty:" << lokaty[i]->zwrocSaldoLokaty() << "\t czas trwania lokaty: "
                 << lokaty[i + 1]->zwrocCzasTrwaniaLokaty() << "\t Wysokosc oprocentowania: "
                 << lokaty[i]->zwrocWysokoscOprocentowania() << endl;
        }
    }
    //system("PAUSE");
}

void Uzytkownik::usunLokate()                                    //TESTY: Usun�� lokat� kt�ra jest, oraz kt�rej nie ma
{
    int wybor;
    cout << "Oto twoje lokaty, ktora z nich chcesz usunac?" << endl;
    sprawdzStanLokaty();
    cin >> wybor;
    wybor -= wybor;
    if (!lokaty.empty()) {
        if (lokaty[wybor] != NULL) {
            lokaty.erase(lokaty.begin() + wybor);
            cout << "Usunieto" << endl;
        }
    } else {
        cout << "Nie ma takiej lokaty" << endl;
    }
    //system("PAUSE");
}


//void wybor() {
//
//};

void Uzytkownik::wezKredyt() {
    int lata, nrKonta;
    double kwota;
    string temat;
    KontoBankowe *temp_konto;
    cout << "Podaj cel kredytu: ";
    cin >> temat;
    cout << "Wysokosc kredytu: ";
    cin >> kwota;
    cout << "Na ile lat: ";
    cin >> lata;

    Kredyt *kredyt = new Kredyt(temat, kwota, lata);
    char check;
    cout << "Czy definytywnie chcesz wziac ten kredyt.(T/N)";
    cin >> check;
    switch (check) {
        case 'T':
            kredyty.push_back(kredyt);
            cout << "Wybierz konto:";
            cin >> nrKonta;
            temp_konto = konta[nrKonta - 1];
            temp_konto->wplac(kwota);
            cout << "Kredyt zrealizowany." << endl;
            break;
        case 'N':
            delete kredyt;
            cout << "Kredyt porzucony." << endl;
            break;
    }

}

void Uzytkownik::pokazKredyty() {
    for (size_t i = 0; i < kredyty.size(); i++) {
        cout << "	----" << i + 1 << "----	" << endl;
        kredyty[i]->wyswietlKredyt();
        cout << endl;
    }
}

void Uzytkownik::zaplacRate() {
    int nrKonta, nrKredytu;
    cout << "Wybierz konto:";
    cin >> nrKonta;
    KontoBankowe *temp_konto = konta[nrKonta - 1];

    cout << "Wybierz kredyt:";
    cin >> nrKredytu;
    Kredyt *temp_kredyt = kredyty[nrKredytu - 1];

    temp_kredyt->przelejSrodki();
    double rata = temp_kredyt->zwrocRate();
    temp_konto->wyplac(rata);
}

void Uzytkownik::splacKredyt() {
    int nrKonta, nrKredytu;
    cout << "Wybierz konto:";
    cin >> nrKonta;
    KontoBankowe *temp_konto = konta[nrKonta - 1];

    cout << "Wybierz kredyt:";
    cin >> nrKredytu;
    Kredyt *temp_kredyt = kredyty[nrKredytu - 1];
    double kwota = temp_kredyt->splacKredyt();
    temp_konto->wyplac(kwota);
    kredyty.erase(kredyty.begin() + nrKredytu - 1);

    cout << "Kredyt nr " << nrKredytu << " zostal splacony." << endl;
}


vector<KontoBankowe *> Uzytkownik::zwrocKonta() {
    return this->konta;
}

vector<Lokata *> Uzytkownik::zwrocLokaty() {
    return this->lokaty;
}

vector<Kredyt *> Uzytkownik::zwrocKredyty(){
    return this->kredyty;
};