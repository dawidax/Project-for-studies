#include <iostream>
#include "UzytkownikLotniska.h"
#include "Pasazer.h"
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

Pasazer::Pasazer() : imie(" "), nazwisko(" "), linieLotnicze(" "), plec(" "), wiek(0), cenaBiletu(0), miejsce_w_Samolocie(0), dlugoscLotu(0), nrLotu(0), covid_check(false),
HotelDlaPasazera(new Hotel(0, "Brak", "Brak", "Brak", "Brak", "Brak", "Brak", "Brak", "Brak")) {} // inlicjalizacja klasy HotelDlaPasazera. Pelna inicjalizacja odbywa sie w metodzie wybierzHotel 

Pasazer::Pasazer(string imie, string nazwisko, string linieLotnicze, string plec, size_t wiek, size_t cenaBiletu, size_t miejsce_w_Samolocie, size_t dlugoscLotu, size_t nrLotu, bool covid_check)
    : imie(imie), nazwisko(nazwisko), linieLotnicze(linieLotnicze), plec(plec), wiek(wiek), cenaBiletu(cenaBiletu), miejsce_w_Samolocie(miejsce_w_Samolocie), dlugoscLotu(dlugoscLotu), nrLotu(nrLotu), covid_check(covid_check)
    , HotelDlaPasazera(new Hotel(0, "Brak", "Brak", "Brak", "Brak", "Brak", "Brak", "Brak", "Brak"))
{} // tu robimy to samo tylko dla konstruktora z argumentami 

auto Pasazer::wyswietlDane(int nrLotu) noexcept -> void {

    cout << "Twoje imie: " << this->imie
        << "\nTwoje nazwisko: " << nazwisko
        << "\nTwoj wiek: " << wiek
        << "\nTwoja plec: " << plec
        << "\nNazwa lini lotniczych: " << linieLotnicze
        << "\nCena za bilet: " << cenaBiletu
        << "\nMiejsce w samolocie: " << miejsce_w_Samolocie
        << "\nDlugosc lotu: " << dlugoscLotu
        << "\nNr lotu: " << nrLotu
        << "\nZaszczepiony na Covid: " << boolalpha << covid_check;
    HotelDlaPasazera->wyswietlDaneHoteli(); // wyswietlamy dane hotelu dla konkretnego pasazera
}
auto Pasazer::zmienDane() -> void { // metoda pozwalajaca zmienic dane pasazera. Mamy inna metode dla klasy hotel
    cout << "0 - zmien imie\n"
        << "1 - zmien nazwisko\n"
        << "2 - zmien plec\n"
        << "3 - zmien wiek\n"
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
    }
}
auto Pasazer::wybierzHotel()->void { // tu odbywa sie wybor konkretnego hotelu. inicjalizujemy ... liczba gwazdek jest przekazywana do funkcji wyswietlMozliweHotele i tam uruchamiamy odpoweidni case
    cout << "Ile chcesz gwiazdek? ";
    size_t liczbaGwiazdek{};
    cin >> liczbaGwiazdek;
    HotelDlaPasazera = new Hotel(liczbaGwiazdek);
    HotelDlaPasazera->wyswietlMozliweHotele(liczbaGwiazdek);
}
auto Pasazer::usunLot() -> void { // metoda pozwalajaca usunac lot. Zerujemy odpowiednie wartosci dla pasazera
    cout << "1 - Jezeli chcesz usunac swoj lot"
         << "\n0 - Wyjscie"
         << ": ";
    size_t x{ 1 };
    cin >> x;
    if (x == 1) {
        this->cenaBiletu = 0;
        this->miejsce_w_Samolocie = 0;
        this->dlugoscLotu = 0;
        this->nrLotu = 0;
        cout << "Lot zostal usuniety\n";
    }
    else {
        cout << "Nasze linie lotnicze sa najlepsze!!\n";
    }


}
auto Pasazer::zmienMiejsceSiedzenia() -> void {
    cout << "0 - zmien miejsce: ";
    size_t liczba{};
    cin >> liczba;
    if (liczba == 0) {
        int klasa, q;
        cout << "\n0 - Lot w pierwszej klasie";
        cout << "\n1 - Lot w klasie ekonomicznej";
        cout << "\n2 - Lot w Business class"
             << ": ";
        cin >> klasa;

        switch (klasa) {
        case 0:
            cout << "\n0 - jesli wolisz przy oknie";
            cout << "\n1 - jesli wolisz w srodku"
                 << ": ";
            cin >> q;
            if (q == 0) {
                cenaBiletu = 1500; // cena biletu
                miejsce_w_Samolocie = 0001; //0001 - id dla okna, 0 - na przodzie to klasa pierwszej
            }
            else if (q == 1) {
                cenaBiletu = 1450; //cena biletu
                miejsce_w_Samolocie = 0000; // 0000 - id dla œrodka, 0 - na przodzie to klasa pierwszej
            }
            else
                cout << "B³¹d";
            break;
        case 1:
            cout << "\n0 - jesli wolisz przy oknie";
            cout << "\n1 - jesli wolisz w srodku"
                 << ": ";
            cin >> q;
            if (q == 0) {
                cenaBiletu = 500; // cena biletu
                miejsce_w_Samolocie = 1001; //1001 - id dla okna, 1 - na przodnie to klasa ekonomiczna
            }
            else if (q == 1) {
                cenaBiletu = 450; //cena biletu
                miejsce_w_Samolocie = 1000; // 1000 - id dla œrodka, 1 - na przodzie to klasa ekonomiczna
            }
            else
                cout << "B³¹d";
            break;
        case 2:
            cout << "\n0 - jesli wolisz przy oknie";
            cout << "\n1 - jesli wolisz w srodku"
                 << ": ";
            cin >> q;
            if (q == 0) {
                cenaBiletu = 2500; // cena biletu
                miejsce_w_Samolocie = 2001; //2001 - id dla okna, 2 - na przodzie to klasa business
            }
            else if (q == 1) {
                cenaBiletu = 2450; //cena biletu
                miejsce_w_Samolocie = 2000; // 2000 - id dla œrodka, 2 - na przodzie to klasa business
            }
            else
                cout << "B³¹d";
            break;
        }
    }
}
auto Pasazer::sprawdzZmiany_w_Lotach(int nrLotu) -> void {
    srand(time(NULL));
    auto pseudoLosowanie = [=]() { return rand() % 100 + 1 - nrLotu; };
    if (pseudoLosowanie() > 49 && pseudoLosowanie() < 53)
        cout << "Twoj lot jest opozniony\n";
    else
        cout << "Twoj lot nie jest opozniony\n";

}
auto Pasazer::zmienSwojHotel() -> void {
    cout << "Jezeli chcesz zmienic swoj hotel wprowadz odpowiednia ilosc gwiazdek: ";
    int iloscGwiazdek{};
    cin >> iloscGwiazdek;
    HotelDlaPasazera->zmienSwojHotel(iloscGwiazdek);
}