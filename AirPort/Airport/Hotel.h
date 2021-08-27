#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
using namespace std;

class Hotel
{
	string nazwaHotelu, wyzywienie, aquapark, wielkoscPokoju, oferowaneWycieczki, odlegloscOdPlazy, liczbaBasenow, dodatkoweAtrakcje;
	size_t liczbaGwiazdek;
public:
	Hotel(size_t liczbaGwiazdek, string nazwaHotelu = "Brak", string wyzywienie = "Brak", string aquapark = "Brak", string wielkoscPokoju = "Brak",
		string oferowaneWycieczki = "Brak", string odlegloscOdPlazy = "Brak", string liczbaBasenow = "Brak", string dodatkoweAtrakcje = "Brak");

	void wyswietlMozliweHotele(size_t liczbaGwiazdek);
	void wyswietlDaneHoteli();
	void zmienSwojHotel(size_t liczbaGwiazdek);
};
#endif // !HOTEL_H
