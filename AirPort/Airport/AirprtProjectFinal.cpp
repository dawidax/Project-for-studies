#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include "UzytkownikLotniska.h"
#include "Pasazer.h"
#include "Pracownik.h"

using namespace std;

auto dodajDaneDlaPasazera(Pasazer** ST, int nrLotu) -> void; // zaprzyjazniona funkcja dodajaca pasazera
auto dodajDaneDlaPracownika(Pracownik** ST, int id_pracownika) -> void; // zaprzyjazniona funkcja dodajaca pracownika
int menuDlaPasazera();
int menuDlaPracownika();	

int main()
{

	UzytkownikLotniska* Uzytkownicy = nullptr;
	Pasazer* nowyPasazer[100]{};
	Pracownik* nowyPracownik[100]{};

	int odpowiedzPasazer_Pracownik{}, zakoncz{}, zakonczDlaPasazera{}, zakonczDlaPracownika{};
	int nrLotu{}, Id_pracownika{};
	do
	{
		cout << "Jezeli jestes pasazerem wybierz - 1\n"
			 << "Jezeli jestes pracownikiem lotniska wybierz - 2\n"
			 << "Wyjscie - 0\n";
		cin >> odpowiedzPasazer_Pracownik;
		switch (odpowiedzPasazer_Pracownik)
		{
		case 1:
			enum WyborDlaPasazera
			{
				Wyjscie, WprowadzDane, WyswietlDane, ZmienDane, WybierzHotel, UsunLot, zmienMiejsceSiedzenia, Sprawdz_zmiany_w_lotach, ZmienHotel
			};
			do
			{
				switch (menuDlaPasazera())
				{
				case WprowadzDane:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					dodajDaneDlaPasazera(nowyPasazer, nrLotu);
					Uzytkownicy = nowyPasazer[nrLotu];
					break;
				case WyswietlDane:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->wyswietlDane(nrLotu);
					else
						cout << "Nie ma takiego nr lotu!\n";
					break;
				case ZmienDane:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->zmienDane();
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
					break;
				case WybierzHotel:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->wybierzHotel();
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
				case UsunLot:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->usunLot();
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
				case zmienMiejsceSiedzenia:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->zmienMiejsceSiedzenia();
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
				case Sprawdz_zmiany_w_lotach:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->sprawdzZmiany_w_Lotach(nrLotu);
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
				case ZmienHotel:
					cout << "Wprowadz swoj nr lotu: ";
					cin >> nrLotu;
					Uzytkownicy = nowyPasazer[nrLotu];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->zmienSwojHotel();
					else
						cout << "Nie ma takiego numeru lotu!\n";
					break;
				case Wyjscie:
					cout << "Wychodzisz z menu dla Pasazera. Bye!\n";
					zakonczDlaPasazera = 1;
					break;
				default:
					cout << "Wybrano niepoprawna liczbe!!\n";
					break;
				}
			} while (!zakonczDlaPasazera);
			break;

		case 2:
			enum WyborDlaPracownika
			{
				WyjscieP, WprowadzDaneP, WyswietlDaneP, ZmienDaneP, sprawdz_hotel, Odwolaj_swoj_lot, sprawdz_swoj_grafik, Zmien_grafik, sprawdz_premie, sprawdz_wynagrodzenie, Sprawdz_zmiany_w_lotach_p
			};
			do
			{
				switch (menuDlaPracownika())
				{
				case WprowadzDaneP:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					dodajDaneDlaPracownika(nowyPracownik, Id_pracownika);
					Uzytkownicy = nowyPracownik[Id_pracownika];
					break;
				case WyswietlDaneP:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					Uzytkownicy = nowyPracownik[Id_pracownika];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->wyswietlDane(Id_pracownika);
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case ZmienDaneP:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					Uzytkownicy = nowyPracownik[Id_pracownika];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->zmienDane();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case sprawdz_hotel:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					Uzytkownicy = nowyPracownik[Id_pracownika];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->wybierzHotel();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case Odwolaj_swoj_lot:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					Uzytkownicy = nowyPracownik[Id_pracownika];
					if (Uzytkownicy != nullptr)
						Uzytkownicy->usunLot();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case sprawdz_swoj_grafik:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					if (nowyPracownik[Id_pracownika] != nullptr)
						nowyPracownik[Id_pracownika]->sprawdzGrafik();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case Zmien_grafik:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					if (nowyPracownik[Id_pracownika] != nullptr)
						nowyPracownik[Id_pracownika]->zmienGrafik();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case sprawdz_premie:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					if (nowyPracownik[Id_pracownika] != nullptr)
						nowyPracownik[Id_pracownika]->czyPremia();
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case sprawdz_wynagrodzenie:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					if (nowyPracownik[Id_pracownika] != nullptr)
						nowyPracownik[Id_pracownika]->sprawdzWynagrodzenie(Id_pracownika);
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case Sprawdz_zmiany_w_lotach_p:
					cout << "Wprowadz swoje Id pracownika: ";
					cin >> Id_pracownika;
					if (nowyPracownik[Id_pracownika] != nullptr)
						nowyPracownik[Id_pracownika]->sprawdzZmiany_w_Lotach(Id_pracownika);
					else
						cout << "Nie ma cie w bazie danych\n";
					break;
				case WyjscieP:
					cout << "Wychodzisz z menu dla Pasazera. Bye!\n";
					zakonczDlaPracownika = 1;
					break;
				default:
					cout << "Wybrano niepoprawna liczbe!!\n";
					break;
				}
			} while (!zakonczDlaPracownika);
			break;

		case 0:
			cout << "Do widzenia :)\n";
			zakoncz = 1;
			break;
		default:
			cout << "Wprowadzono nieprawidlowa liczbe!!\n";
			break;
		}
	} while (!zakoncz);

	delete[] nowyPracownik;
	delete[] nowyPracownik;
}

int menuDlaPasazera() {
	cout << "                                              MENU DLA PASAZERA                              " << endl;
	cout << "1 - Wprowadz dane\n"
		 << "2 - Wyswietl dane\n"
		 << "3 - Zmien dane\n"
		 << "4 - wybierzHotel\n"
		 << "5 - Usun lot\n"
		 << "6 - Zmien miejsce siedzenia w samolocie\n"
		 << "7 - Sprawdz zmiany w lotach\n"
		 << "8 - Zmien Hotel\n"
		 << "0 - Wyjscie\n"
		 << ": ";
	int wyborMenu{};
	cin >> wyborMenu;
	return wyborMenu;
}


int menuDlaPracownika() {
	cout << "                                              MENU DLA Pracownika                              " << endl;
	cout << "1 - Wprowadz dane\n"
		 << "2 - Wyswietl dane\n"
		 << "3 - Zmien dane\n"
		 << "4 - sprawdz hotel w ktorym bedziesz pracowal\n"
		 << "5 - Odwolaj swoj lot. Podaj przyczyne\n"
		 << "6 - sprawdz swoj grafik na najblizszy miesiac\n"
		 << "7 - Zmien grafik\n"
		 << "8 - sprawdz czy przysluguje ci premia\n"
		 << "9 - sprawdz czy swoje wynagrodzenie\n"
		 << "10 - Sprawdz zmiany w lotach\n"
		 << "0 - Wyjscie\n"
		 << ": ";

	int wyborMenu{};
	cin >> wyborMenu;
	return wyborMenu;
}


auto dodajDaneDlaPasazera(Pasazer** ST, int nrLotu) -> void {
	string imie{}, nazwisko{}, linieLotnicze{}, plec{};
	size_t wiek{}, cenaBiletu{}, miejsce_w_samolocie{}, dlugoscLotu{};
	bool covid_check{ true };

	if (ST[nrLotu] == nullptr) {
		ST[nrLotu] = new Pasazer;
		cout << "Podaj swoje imie: ";
		cin >> ST[nrLotu]->imie;
		cout << "Podaj swoje nazwisko: ";
		cin >> ST[nrLotu]->nazwisko;
		cout << "Podaj sowja plec: ";
		cin >> ST[nrLotu]->plec;
		cout << "Podaj swoj wiek: ";
		cin >> ST[nrLotu]->wiek;
		cout << "Jakimi liniami lotniczymi podrozujesz: ";
		cin >> ST[nrLotu]->linieLotnicze;
		cout << "Koszt twojego lotu (zl) : ";
		cin >> ST[nrLotu]->cenaBiletu;
		cout << "Jakie masz miejsce w samolocie (miejsce powinno zaczynac sie od 0): ";
		cin >> ST[nrLotu]->miejsce_w_Samolocie;
		cout << "Dlugosc twojego lotu (min): ";
		cin >> ST[nrLotu]->dlugoscLotu;
		cout << "Czy jestes zaszczepiony \n  1 - Tak \n 0 - Nie ";
		cin >> ST[nrLotu]->covid_check;
		ST[nrLotu]->nrLotu = nrLotu;

		fstream BazaPasazerow;
		BazaPasazerow.open("BazaPasazerow.txt", ios_base::app);
		BazaPasazerow << ST[nrLotu]->nrLotu << "," << ST[nrLotu]->imie << ","
			<< ST[nrLotu]->nazwisko << "," << ST[nrLotu]->wiek << "," << ST[nrLotu]->plec << ","
			<< ST[nrLotu]->linieLotnicze << "," << ST[nrLotu]->cenaBiletu << ","
			<< ST[nrLotu]->miejsce_w_Samolocie << "," << ST[nrLotu]->dlugoscLotu << ",";
		if (ST[nrLotu]->covid_check == true)
			BazaPasazerow << "Jest zaszczepiony" << ";";
		else
			BazaPasazerow << "Nie jest zaszczepiony" << ";";
		BazaPasazerow << endl;
	}
	else {
		cout << "Twoje dane juz sa wprowadzone\n";
	}
}

auto dodajDaneDlaPracownika(Pracownik** ST, int id_pracownika) -> void {
	string imie, nazwisko, plec, stanowisko;
	int  wiek, Id_pracownika;

	if (ST[id_pracownika] == nullptr) {
		ST[id_pracownika] = new Pracownik;
		cout << "Podaj swoje imie: ";
		cin >> ST[id_pracownika]->imie;
		cout << "Podaj swoje nazwisko: ";
		cin >> ST[id_pracownika]->nazwisko;
		cout << "Podaj sowja plec: ";
		cin >> ST[id_pracownika]->plec;
		cout << "Podaj swoj wiek: ";
		cin >> ST[id_pracownika]->wiek;
		cout << "Podaj swoje stanowisko: ";
		cin >> ST[id_pracownika]->stanowisko;
		ST[id_pracownika]->Id_pracownika = id_pracownika;


		fstream BazaPracownik;
		BazaPracownik.open("BazaPracownik.txt", ios_base::app);
		BazaPracownik << ST[id_pracownika]->Id_pracownika << "," << ST[id_pracownika]->imie << ","
			<< ST[id_pracownika]->nazwisko << "," << ST[id_pracownika]->wiek << "," << ST[id_pracownika]->plec << ","
			<< ST[id_pracownika]->stanowisko << ";"
			<< endl;
	}
	else {
		cout << "Twoje dane juz sa wprowadzone\n";
	}
}