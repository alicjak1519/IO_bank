#include <iostream>
#include "bank.h"
#include <ctime>

#define DLUGOSC_KONTA 26

using namespace std;

KontoBankowe::KontoBankowe(string typ) {
    saldo = 2000;
    typKonta = typ;
    int liczba;
    srand(time(NULL));
    for (int i = 0; i < DLUGOSC_KONTA; i++) {
        liczba = rand() % 9 + 0;
        string _str = to_string(liczba);
        numerKonta += _str;
    }
}


void KontoBankowe::wyplac(double kwota) {
    if (kwota < saldo) {
        saldo -= kwota;
        cout << "SALDO konta zmniejszone o: " << kwota << endl;
    } else
        cout << "Za malo na koncie" << endl;
}

void KontoBankowe::wplac(double kwota) {
    saldo += kwota;
    cout << "SALDO konta zwiekszone o: " << kwota << endl;

}




