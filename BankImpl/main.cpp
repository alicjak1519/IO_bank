#include <iostream>
#include "BankImpl_lib/bank.h"
#include <stdio.h>
#include <cstdlib>
//#include <conio.h>
#include <time.h>
#include <vector>

using namespace std;
Uzytkownik *testowy = new Uzytkownik("Jan", "Kowalski", "1", "1", "1", "1");
vector<Uzytkownik *> listaKlientow;
Uzytkownik *zalogowany;
int wybor;

void stanKonta();

void przelewy();

void lokaty();

void kredyty();

void menuGlowne();

void logowanie();

void zalozKonto();

void start();

int main() {
    start();

    return 0;
}

void stanKonta() {
    // todo nie dziala na linuksie
//system("cls");
    cout << "----STANY KONT----" << endl;
    cout << endl;

    zalogowany->sprawdzStanKonta();

    cout << endl;
    cout << "1. Cofnij" << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;

    switch (wybor) {
        case 1:
            menuGlowne();
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
            getchar();
            getchar();
            stanKonta();
    };
};

void przelewy() {
    // todo nie dziala na linuksie
//system("cls");
    cout << "----PRZELEWY----" << endl;
    cout << endl;
    cout << "1. Wykonaj przelew" << endl;
    cout << "2. Zaplanuj przelew" << endl;
    cout << "3. Zaplanuj zlecenie stale" << endl;
    cout << "4. Historia" << endl;
    cout << "5. Cofnij" << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;

    switch (wybor) {
        case 1:
            string adresat, tytul;
            double kwota;
            int konto, nrKonta;
            cout << "Adresat: ";
            cin >> adresat;
            cout << "Kwota: ";
            cin >> kwota;
            cout << "Tytul: ";
            cin >> tytul;
            cout << "Podaj numer konta z kt�rego chcesz robic zlecenia stale: ";
            cin >> nrKonta;
            zalogowany->zrobPrzelew(adresat, nrKonta, tytul, kwota);
            break;
        case 2:
            zalogowany->zaplanujPrzelew();
            break;
        case 3:
            zalogowany->zlecPrzelewStaly();
            break;
        case 4:
            zalogowany->pokazHistorie();
            break;
        case 5:
            menuGlowne();
            break;
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
    };
    getchar();
    getchar();
    przelewy();
};

void lokaty() {
    // todo nie dziala na linuksie
//system("cls");
    cout << "----LOKATY----" << endl;
    cout << endl;
    cout << "1. Sprawdz stan lokaty" << endl;
    cout << "2. Zaloz lokate" << endl;
    cout << "3. Rozwiaz lokate" << endl;
    cout << "4. Cofnij" << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;

    switch (wybor) {
        case 1:
            zalogowany->sprawdzStanLokaty();
            break;
        case 2:
            double kwota;
            int czasTrwania;
            int nrKonta;
            float oprocentowanie;
            double saldo;

            cout << "Wprowadz kwote ktora chcialbys wplacic na lokate" << endl;
            cin >> kwota;
            cout << "Na jaki czas chcialbys zalozyc lokate? Podaj liczbe miesiecy" << endl;
            cin >> czasTrwania;
            oprocentowanie = rand() % 5 + 1.5;
            cout << "Twoje oprocentowanie to: " << oprocentowanie << endl;
            cout << "Oto twoje konta, wybierz z ktorego z nich chcialbys wplacic na lokate" << endl;
            zalogowany->sprawdzStanKonta();
            cin >> nrKonta;
            nrKonta -= nrKonta;
            saldo = zalogowany->zwrocKonta()[nrKonta]->zwrocSaldo();
            zalogowany->zalozLokate(nrKonta, kwota, oprocentowanie, czasTrwania, saldo);
            break;

        case 3:
            zalogowany->usunLokate();
            break;
        case 4:
            menuGlowne();
            break;
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
    };
    getchar();
    getchar();
    lokaty();
};

void kredyty() {
    // todo nie dziala na linuksie
//system("cls");
    cout << "----KREDYTY----" << endl;
    cout << endl;
    cout << "1. Pokaz kredyty" << endl;
    cout << "2. Zaplac rate" << endl;
    cout << "3. Wez kredyt" << endl;
    cout << "4. Splac kredyt" << endl;
    cout << "5. Cofnij" << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;

    switch (wybor) {
        case 1:
            zalogowany->pokazKredyty();
            break;
        case 2:
            zalogowany->zaplacRate();
            break;
        case 3:
            zalogowany->wezKredyt();
            break;
        case 4:
            zalogowany->splacKredyt();
            break;
        case 5:
            menuGlowne();
            break;
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
    };
    getchar();
    getchar();
    kredyty();
};

void menuGlowne() {
    // todo nie dziala na linuksie
//system("cls");
    cout << "Zalogowany: ";
    zalogowany->zwrocDane();
    cout << endl;
    cout << "----MENU----" << endl;
    cout << endl;
    cout << "1. Stan konta" << endl;
    cout << "2. Przelewy" << endl;
    cout << "3. Lokaty" << endl;
    cout << "4. Kredyty" << endl;
    cout << "5. Wyloguj" << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;

    switch (wybor) {
        case 1:
            stanKonta();
            break;
        case 2:
            przelewy();
            break;
        case 3:
            lokaty();
            break;
        case 4:
            kredyty();
            break;
        case 5:
            start();
            break;
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
    };
    getchar();
    getchar();
    menuGlowne();
}

void logowanie() {
    string nrklienta, haslo;
    cout << "Podaj numer klienta: ";
    cin >> nrklienta;
    cout << "Podaj haslo: ";
    cin >> haslo;

    bool check = false;
    for (size_t i = 0; i < listaKlientow.size(); i++) {
        if (listaKlientow[i]->getNrKlienta() == nrklienta && listaKlientow[i]->getHaslo() == haslo) {
            zalogowany = listaKlientow[i];
            check = true;
            break;
        }
    }
    if (check) {
        menuGlowne();
    } else {
        cout << endl << "Blędne dane. Sprobuj jeszcze raz." << endl;
        logowanie();
    }
}

void zalozKonto() {
    string imie, nazwisko, pesel, nrDowodu, numerKlienta, haslo;
    cout << "Wprowadz dane" << endl;
    cout << "Imie: ";
    cin >> imie;
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "Pesel: ";
    cin >> pesel;
    cout << "Numer dowodu: ";
    cin >> nrDowodu;

    srand(time(NULL));
    for (int i = 0; i < 1; i++) {
        int liczba = rand() % 9 + 0;
        string _str = to_string(liczba);
        numerKlienta += _str;
    }

    cout << endl << "Witamy Cie " << imie << " w naszym banku." << endl << endl;
    cout << "To twoj nowy numer klienta: " << numerKlienta << endl;
    cout << "Podaj haslo: ";
    cin >> haslo;


    Uzytkownik *user = new Uzytkownik(imie, nazwisko, pesel, nrDowodu, numerKlienta, haslo);
    listaKlientow.push_back(user);
    cout << endl << "Zaloguj sie teraz do twojego nowego konta.";
    getchar();
    getchar();
    start();

}

void start() {
    listaKlientow.push_back(testowy);
    // todo nie dziala na linuksie
//system("cls");
    cout << "----MENU----" << endl;
    cout << endl;
    cout << "1. Logowanie." << endl;
    cout << "2. Zaloz konto." << endl;
    cout << endl;
    cout << "Podaj numer komendy: ";
    cin >> wybor;


    switch (wybor) {
        case 1:
            logowanie();
            break;
        case 2:
            zalozKonto();
            break;
        default:
            cout << "Bledny numer komendy!! Wpisz ponownie.";
            getchar();
            getchar();
            start();
    };
};