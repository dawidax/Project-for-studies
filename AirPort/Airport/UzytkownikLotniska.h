#ifndef UZYTKOWNIKLOTNIKSKA_H
#define UZYTKOWNIKLOTNIKSKA_H

#include <iostream>
using namespace std;

class UzytkownikLotniska // klasa wirtualna nie posiada zadnych atrybutow
{
public:
	virtual ~UzytkownikLotniska() {}
	virtual auto wyswietlDane(int nrLotu) noexcept -> void = 0;
	virtual auto zmienDane() -> void = 0;
	virtual auto wybierzHotel()->void = 0;
	virtual auto usunLot() -> void = 0;
	virtual auto zmienMiejsceSiedzenia() -> void = 0;
	virtual auto sprawdzZmiany_w_Lotach(int nrLotu) -> void = 0;
	virtual auto zmienSwojHotel() -> void = 0;
};
#endif // !UZYTKOWNIKLOTNIKSKA_H