#include <iostream>
#include <vector>
#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik() : imie("Brak"), nazwisko("Brak"), wiek(0), plec("Brak"), stanowisko("Brak"), Id_pracownika(0) 
{
    godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
                 "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nSobote: Wolna\nNiedziele: Wolna\n" };
}

Pracownik::Pracownik(string imie, string nazwisko, string plec, string stanowisko, int wiek, int Id_pracownika, string godzinyPracy) : imie(imie), nazwisko(nazwisko), plec(plec),
                     stanowisko(stanowisko), wiek(wiek), Id_pracownika(Id_pracownika)
{}

Pracownik::~Pracownik() {}

auto Pracownik::wyswietlDane(int nrLotu) noexcept -> void {

    cout << "Twoje imie: " << imie
        << "\nTwoje nazwisko: " << nazwisko
        << "\nTwoj wiek: " << wiek
        << "\nTwoja plec: " << plec
        << "\nTwoje stanowisko pracy: " << stanowisko << endl;
}
auto Pracownik::zmienDane() -> void {

    cout << "0 - zmien imie\n"
         << "1 - zmien nazwisko\n"
         << "2 - zmien plec\n"
         << "3 - zmien wiek\n"
         << "4 - zmien stanowisko\n"
         << ": ";

    size_t wybor{};
    cin >> wybor;

    switch (wybor)
    {
    case 0:
        cout << "Zmien imie: ";
        cin >> imie;
        break;
    case 1:
        cout << "Zmien nazwisko: ";
        cin >> nazwisko;
        break;
    case 2:
        cout << "Zmien plec: ";
        cin >> plec;
        break;
    case 3:
        cout << "Zmien wiek: ";
        cin >> wiek;
        break;
    case 4:
        cout << "Zmien stanowisko: ";
        cin >> stanowisko;
        break;
    }
}

auto Pracownik::wybierzHotel()->void {
    cout << "Hotel w ktorym bedziesz pracowac zostaje Ci przydzielony na podstawie twojego id oraz imienia\n";
    static vector<string> listaPracownikowNaEurope{"Artur", "Kuba", "Dawid", "Filip", "Karolina", "Mateusz", "HUBERT!!!", "Ola", "Patrycja", "Maciek", "Wieslaw", "Artiom"};

    auto gdziePracuje = find(listaPracownikowNaEurope.cbegin(), listaPracownikowNaEurope.cend(), this->imie); 
    if (gdziePracuje != listaPracownikowNaEurope.end() && this->Id_pracownika > 24)
        cout << "W tym miesiacu pracujesz w Europie\n";
    else
        cout << "W tym miesiacu pracujesz w Azji\n";
}

auto Pracownik::usunLot() -> void {
    cout << "Jezeli nie mozesz dzis pracowac podaj przyczyne: ";
    string przyczyna;
    cin >> przyczyna;
    static vector<string> przyczynaAkceptowana{ "choroba", "wirus", "goraczka", "covid"};
    auto zatwierdzenie = find(przyczynaAkceptowana.cbegin(), przyczynaAkceptowana.cend(), przyczyna);
    if (zatwierdzenie != przyczynaAkceptowana.cend()) {
        cout << "Dostajesz L4\n";
    }
    else
        cout << "Nie dostajesz L4\n";    
}

auto Pracownik::sprawdzGrafik() -> void {
    cout << "Twoje godziny pracy dla poszczegolnych dni: ";
    cout << godzinyPracy;
}

auto Pracownik::zmienGrafik() ->void {

    cout << "Wybierz dzien tygodnia w ktorym chcesz wprowadzic zmiany\n"
        << "1 - Poniedzialek\n"
        << "2 - Wtorek\n"
        << "3 - Sroda\n"
        << "4 - Czwartek\n"
        << "5 - Piatek\n"
        << "6 - Sobota\n"
        << "7 - Niedziela\n"
        << ": ";


    int x{}, a{};
    cin >> x;
    switch (x) {

    case 1:
        cout << "Wybrales Poniedzialek " << " Wybierz godziny pracy: \n"
            << "1. 7:00 - 15:00\n"
            << "2. 8:00 - 17:00\n"
            << "3. 12:00 - 20:00\n"
            << "4. 10:00 - 18:00\n"
            << "5. 13:00 - 19:00\n"
            << "6. 10:00 - 15:00\n" << endl;

        cin >> a;
        switch (a) {


        case 1:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 2:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 8:00 - 17:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 3:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 12:00 - 20:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 4:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 18:00 \nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 5:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 13:00 - 19:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 6:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 15:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        default:
            cout << "Wybrales niepoprawna liczbe\n";
            break;
        }
        break;

    case 2:
        cout << "Wybrales Wtorek" << " Wybierz godziny pracy: \n"
            << "1. 7:00 - 15:00\n"
            << "2. 8:00 - 17:00\n"
            << "3. 12:00 - 20:00\n"
            << "4. 10:00 - 18:00\n"
            << "5. 13:00 - 19:00\n"
            << "6. 10:00 - 15:00\n" << endl;

        cin >> a;
        switch (a) {
        case 1:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 7:00 - 15:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 2:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 8:00 - 17:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 3:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 12:00 - 20:00\nPracujesz we Wtorek: 12:00 - 20:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 4:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 18:00 \nPracujesz we Wtorek: 10:00 - 18:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 5:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 13:00 - 19:00\nPracujesz weWtorek: 13:00 - 19:00\nPracujesz w Srode: 12:00 - 20:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 6:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 15:00\nPracujesz we Wtorek: 10:00 - 15:00\nPracujesz w Srode: 12:00 - 20:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        default:
            cout << "Wybrales niepoprawna liczbe\n";
            break;
        }
        break;

    case 3:
        cout << "Wybrales Sroda" << " Wybierz godziny pracy: \n"
            << "1. 7:00 - 15:00\n"
            << "2. 8:00 - 17:00\n"
            << "3. 12:00 - 20:00\n"
            << "4. 10:00 - 18:00\n"
            << "5. 13:00 - 19:00\n"
            << "6. 10:00 - 15:00\n" << endl;

        cin >> a;
        switch (a)
        {

        case 1:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 7:00 - 15:00\nPracujesz w Srode: 7:00 - 15:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 2:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 8:00 - 17:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 8:00 - 17:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 3:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 12:00 - 20:00\nPracujesz we Wtorek: 12:00 - 20:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 4:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 18:00 \nPracujesz we Wtorek: 10:00 - 18:00\nPracujesz w Srode: 10:00 - 18:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 5:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 13:00 - 19:00\nPracujesz weWtorek: 13:00 - 19:00\nPracujesz w Srode: 13:00 - 19:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 6:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 15:00\nPracujesz we Wtorek: 10:00 - 15:00\nPracujesz w Srode: 10:00 - 15:00"
           "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        default:
            cout << "Wybrales niepoprawna liczbe\n";
        }
            break;


    case 4:
        cout << "Wybrales Czwartek" << " Wybierz godziny pracy: \n"
            << "1. 7:00 - 15:00\n"
            << "2. 8:00 - 17:00\n"
            << "3. 12:00 - 20:00\n"
            << "4. 10:00 - 18:00\n"
            << "5. 13:00 - 19:00\n"
            << "6. 10:00 - 15:00\n" << endl;

        cin >> a;
        switch (a)
        {

        case 1:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 7:00 - 15:00\nPracujesz w Srode: 7:00 - 15:00"
            "\nPracujesz w Czwartek: 7:00 - 15:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 2:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 8:00 - 17:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 8:00 - 17:00"
            "\nPracujesz w Czwartek: 8:00 - 17:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 3:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 12:00 - 20:00\nPracujesz we Wtorek: 12:00 - 20:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 12:00 - 20:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 4:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 18:00 \nPracujesz we Wtorek: 10:00 - 18:00\nPracujesz w Srode: 10:00 - 18:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 5:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 13:00 - 19:00\nPracujesz weWtorek: 13:00 - 19:00\nPracujesz w Srode: 13:00 - 19:00"
           "\nPracujesz w Czwartek: 13:00 - 19:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 6:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 15:00\nPracujesz we Wtorek: 10:00 - 15:00\nPracujesz w Srode: 10:00 - 15:00"
           "\nPracujesz w Czwartek: 10:00 - 15:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        default:
            cout << "Wybrales niepoprawna liczbe\n";
        }
        break;

    case 5:
        cout << "Wybrales Piatek" << " Wybierz godziny pracy: \n"
            << "1. 7:00 - 15:00\n"
            << "2. 8:00 - 17:00\n"
            << "3. 12:00 - 20:00\n"
            << "4. 10:00 - 18:00\n"
            << "5. 13:00 - 19:00\n"
            << "6. 10:00 - 15:00\n" << endl;

        cin >> a;
        switch (a)
        {

        case 1:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 7:00 - 15:00\nPracujesz we Wtorek: 7:00 - 15:00\nPracujesz w Srode: 7:00 - 15:00"
            "\nPracujesz w Czwartek: 7:00 - 15:00\nPracujesz w Piatek: 13:00 - 19:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 2:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 8:00 - 17:00\nPracujesz we Wtorek: 8:00 - 17:00\nPracujesz w Srode: 8:00 - 17:00"
            "\nPracujesz w Czwartek: 8:00 - 17:00\nPracujesz w Piatek: 8:00 - 17:00 \nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 3:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 12:00 - 20:00\nPracujesz we Wtorek: 12:00 - 20:00\nPracujesz w Srode: 12:00 - 20:00"
            "\nPracujesz w Czwartek: 12:00 - 20:00\nPracujesz w Piatek: Piatek: 12:00 - 20:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 4:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 18:00 \nPracujesz we Wtorek: 10:00 - 18:00\nPracujesz w Srode: 10:00 - 18:00"
            "\nPracujesz w Czwartek: 10:00 - 18:00\nPracujesz w Piatek: 10:00 - 18:00\nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 5:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 13:00 - 19:00\nPracujesz weWtorek: 13:00 - 19:00\nPracujesz w Srode: 13:00 - 19:00"
           "\nPracujesz w Czwartek: 13:00 - 19:00\nPracujesz w Piatek: 13:00 - 19:00 \nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        case 6:
            godzinyPracy = { "\nPracujesz w Poniedzialek: 10:00 - 15:00\nPracujesz we Wtorek: 10:00 - 15:00\nPracujesz w Srode: 10:00 - 15:00"
           "\nPracujesz w Czwartek: 10:00 - 15:00\nPracujesz w Piatek: 10:00 - 15:00 \nPracujesz w Sobote: 7:00 - 15:00\nPracujesz w  Niedziele: 10:00 - 15:00\n" };
            break;
        default:
            cout << "Wybrales niepoprawna liczbe\n";
        }
        break;
    }
}

auto Pracownik::czyPremia() -> void
{   
    cout << "Sprawdz jaka premie dostaniesz" << endl;
    cout << "Czy miales dni urlpopu w ostatnim miesiacu pracy? (t/n): " << endl;
    char odp{};
    cin >> odp;

    if (odp == 't')
    {
        cout << "Do nastepnego wynagrodzenia nie przysluguje Ci premia." << endl;
    }
    else if (odp == 'n')
    {
        cout << "Czy spozniles sie do pracy w ostatnim miesiacu? (t/n)" << endl;
        cin >> odp;
        if (odp == 'n')
        {
            cout << "Przy nastepnym wynagrodzeniu przysluguje Ci premia w wysokosci: 500zl." << endl;
        }
        else
        {
            cout << "Ile razy spozniles sie do pracy?: " << endl;
            int liczbaSpoznien{};
            cin >> liczbaSpoznien;
            if (liczbaSpoznien <= 2) {
                cout << "Przy nastepnym wynagrodzeniu przysluguje Ci premia w wysokosci: 200zl." << endl;
            }
            else if (liczbaSpoznien > 2) {
                cout << "Przy nastepnym wynagrodzeniu nie przysluguje Ci premia. :(" << endl;
            }
            else {
                cout << "podano nieprawidlowa litere!!" << endl;
            }
        }
    }
    else {
        cout << "podano nieprawidlowa litere!!" << endl;
    }
}
auto Pracownik::sprawdzWynagrodzenie(int Id_pracownika) -> void {
    if (Id_pracownika > 59)
        cout << "Twoje wynagrodzenie wynosi 4200 zl w tym miesiacu\n";
    else if (Id_pracownika <= 59 && Id_pracownika >= 24)
        cout << "Twoje wynagrodzenie wynosi 3200 zl w tym miesiacu\n";
    else
        cout << "Twoje wynagrodzenie wynosci 2500 zl w tm tygodniu\n";
}



