#ifndef PASAZER_H
#define PASAZER_H

#include "UzytkownikLotniska.h"
#include "Hotel.h"
#include <iostream>
#include <vector>

using namespace std;

class Pasazer : public UzytkownikLotniska // pierwsza klasa pochodna
{
	string imie, nazwisko, linieLotnicze, plec;
	bool covid_check;
	size_t wiek, cenaBiletu, miejsce_w_Samolocie, dlugoscLotu, nrLotu;
	Hotel* HotelDlaPasazera;

public:
	friend auto dodajDaneDlaPasazera(Pasazer** ST, int nrLotu) -> void;
	Pasazer();
	~Pasazer() { delete HotelDlaPasazera; }
	Pasazer(string imie, string nazwisko, string linieLotnicze, string plec, size_t wiek, size_t cenaBiletu, size_t miejsce_w_Samolocie, size_t dlugoscLotu, size_t nrLotu, bool covid_check);
	auto wyswietlDane(int nrLotu) noexcept -> void override;
	auto zmienDane() -> void override;
	auto wybierzHotel()->void override;
	auto usunLot() -> void override;
	auto zmienMiejsceSiedzenia() -> void override;
	auto sprawdzZmiany_w_Lotach(int nrLotu) -> void override;
	auto zmienSwojHotel() -> void;
};

#endif // !PASAZER_H
