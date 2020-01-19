#define BOOST_TEST_MODULE Suite_example

#include <boost/test/unit_test.hpp>
#include "../BankImpl_lib/bank.h"

BOOST_AUTO_TEST_SUITE(UzytkownikTest)


    BOOST_AUTO_TEST_CASE(testLiczbaKont) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        BOOST_CHECK_EQUAL(u.zwrocKonta().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(testZalozenieLokatyNOK) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zalozLokate(nrKonta, saldo + 1, 1, 1, saldo);
        BOOST_CHECK_EQUAL(u.zwrocLokaty().size(), 0);
    }


    BOOST_AUTO_TEST_CASE(testZalozenieLokatyOK) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zalozLokate(nrKonta, saldo - 1, 1, 1, saldo);
        BOOST_CHECK_EQUAL(u.zwrocLokaty().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(testZakladanieWieluKont) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        u.zalozKonto("zwykle");
        u.zalozKonto("zwykle");
        u.zalozKonto("walutowe");
        BOOST_CHECK_EQUAL(u.zwrocKonta().size(), 4);
    }


    BOOST_AUTO_TEST_CASE(testZalozenieWieluLokat) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zalozLokate(nrKonta, 1, 1, 1, saldo);
        u.zalozLokate(nrKonta, 1, 1, 1, saldo);
        u.zalozLokate(nrKonta, 1, 1, 1, saldo);
        BOOST_CHECK_EQUAL(u.zwrocLokaty().size(), 3);
    }



    BOOST_AUTO_TEST_CASE(wyplacenieGotowkiOK) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zwrocKonta()[nrKonta]->wyplac(15);

        BOOST_CHECK_EQUAL(u.zwrocKonta()[nrKonta]->zwrocSaldo(), saldo-15);
    }


    BOOST_AUTO_TEST_CASE(wplacenieGotowkiOK) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zwrocKonta()[nrKonta]->wplac(15);

        BOOST_CHECK_EQUAL(u.zwrocKonta()[nrKonta]->zwrocSaldo(), saldo+15);

    }


    BOOST_AUTO_TEST_CASE(wyplacenieGotowkiNOK) {
        Uzytkownik u = Uzytkownik();
        u.zalozKonto("zwykle");
        int nrKonta = 0;
        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
        u.zwrocKonta()[nrKonta]->wyplac(15);

        BOOST_CHECK_EQUAL(u.zwrocKonta()[nrKonta]->zwrocSaldo(), saldo);
    }

//    BOOST_AUTO_TEST_CASE(wykonaniePrzelewu) {
//        Uzytkownik u = Uzytkownik();
//        u.zalozKonto("zwykle");
//        int nrKonta = 0;
//        double saldo = u.zwrocKonta()[nrKonta]->zwrocSaldo();
//        u.zrobPrzelew("1", 1, "Przelew testowy", saldo - 1);
//        BOOST_CHECK_EQUAL(u.zwrocKonta()[nrKonta]->zwrocSaldo(), 1);
//    }

BOOST_AUTO_TEST_SUITE_END()