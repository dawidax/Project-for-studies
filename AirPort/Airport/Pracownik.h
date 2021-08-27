#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <iostream>
#include "UzytkownikLotniska.h"
using namespace std;

class Pracownik : public UzytkownikLotniska
{
	string imie, nazwisko, plec, stanowisko, godzinyPracy;
	int  wiek, Id_pracownika;
public:
	friend auto dodajDaneDlaPracownika(Pracownik** ST, int id_pracownika) -> void;
	Pracownik();
	Pracownik(string imie, string nazwisko, string plec, string stanowisko, int wiek, int Id_pracownika, string godzinyPracy = " ");
	~Pracownik();

	auto wyswietlDane(int nrLotu) noexcept -> void override;
	auto zmienDane() -> void override;
	auto wybierzHotel()->void override;
	auto usunLot() -> void override;
	auto sprawdzGrafik() -> void;
	auto zmienGrafik() -> void;
	auto czyPremia() -> void;
	auto sprawdzWynagrodzenie(int Id_pracownika) -> void;

	// metody ktore musza byc zdeklarowane ale nie ma jak ich zaimplementowac do pracownika
	auto zmienMiejsceSiedzenia() -> void override {};
	auto sprawdzZmiany_w_Lotach(int nrLotu) -> void override {};
	auto zmienSwojHotel() -> void override {};
};
#endif // !PRACOWNIK_H

