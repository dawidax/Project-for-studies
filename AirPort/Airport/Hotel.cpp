#include <iostream>
#include "Hotel.h"

using namespace std;

Hotel::Hotel(size_t liczbaGwiazdek, string nazwaHotelu, string wyzywienie, string aquapark, string wielkoscPokoju,
	string oferowaneWycieczki, string odlegloscOdPlazy, string liczbaBasenow, string dodatkoweAtrakcje) :
	nazwaHotelu(nazwaHotelu), wyzywienie(wyzywienie), aquapark(aquapark), wielkoscPokoju(wielkoscPokoju), oferowaneWycieczki(oferowaneWycieczki),
	liczbaGwiazdek(liczbaGwiazdek), liczbaBasenow(liczbaBasenow), dodatkoweAtrakcje(dodatkoweAtrakcje), odlegloscOdPlazy(odlegloscOdPlazy)
{}

void Hotel::wyswietlMozliweHotele(size_t liczbaGwiazdek) {

	enum RodzajeHoteli {
		zero, HotelParadise, HotelCitadines, HotelDiamond, HotelDomZdrojowy, HotelBB  //HotelParadise  = 1, HotelCitadines = 2, HotelJakisTam = 3
	};
	int wybor{};
	switch (liczbaGwiazdek)
	{
	case HotelParadise:
		cout << "Wybrano Hotel Paradise\n";
		nazwaHotelu = "Hotel Paradise";
		cout << " Wybierz rodzaj pokoju:\n";
		cout << "1 - pokoj 1 - osobowy\n";
		cout << "2 - pokoj 2 - osobowy\n";
		cout << "3 - pokoj 3 - osobowy\n";
		cout << "4 - pokoj 4 - osobowy\n";
		cin >> wybor;

		if (wybor == 1) {

			wielkoscPokoju = "pokoj 1 - osobowy\n";
		}
		if (wybor == 2) {

			wielkoscPokoju = "pokoj 2 - osobowy\n";
		}
		if (wybor == 3) {

			wielkoscPokoju = "pokoj 3 - osobowy\n";
		}
		if (wybor == 4) {

			wielkoscPokoju = "pokoj 4 - osobowy\n";
		}

		cout << " Wybierz pobyt z wyzywieniem lub bez: \n";
		cout << "1 - pobyt z wyzywieniem\n";
		cout << "2 - pobyt bez wyzywienia\n";
		cin >> wybor;

		if (wybor == 1) {


			wyzywienie = "pobyt z wyzywieniem\n";
		}
		else {
			wyzywienie = "pobyt bez wyzywienia\n";
		}

		aquapark = "brak";
		odlegloscOdPlazy = "500 metrow";
		dodatkoweAtrakcje = "SPA, plac zabaw dla dzieci, boisko do siatkowki";
		break;


	case HotelCitadines:
		cout << "Wybrano Hotel Citadines\n";
		nazwaHotelu = "Hotel Citadines";
		cout << " Wybierz rodzaj pokoju:\n";
		cout << "1 - pokoj 1 - osobowy\n";
		cout << "2 - pokoj 2 - osobowy\n";
		cout << "3 - pokoj 3 - osobowy\n";
		cout << "4 - pokoj 4 - osobowy\n";
		cin >> wybor;

		if (wybor == 1) {

			wielkoscPokoju = "pokoj 1 - osobowy\n";
		}
		if (wybor == 2) {

			wielkoscPokoju = "pokoj 2 - osobowy\n";
		}
		if (wybor == 3) {

			wielkoscPokoju = "pokoj 3 - osobowy\n";
		}
		if (wybor == 4) {

			wielkoscPokoju = "pokoj 4 - osobowy\n";
		}

		cout << " Wybierz pobyt z wyzywieniem lub bez: \n";
		cout << "1 - pobyt z wyzywieniem\n";
		cout << "2 - pobyt bez wyzywienia\n";
		cin >> wybor;

		if (wybor == 1) {


			wyzywienie = "pobyt z wyzywieniem\n";
		}
		else {
			wyzywienie = "pobyt bez wyzywienia\n";
		}
		aquapark = "Tak";
		liczbaBasenow = "4";
		odlegloscOdPlazy = "2 kilometry";
		dodatkoweAtrakcje = "SPA, plac zabaw dla dzieci, boisko do siatkowki i koszykowki";

		break;

	case HotelDiamond:
		cout << "Wybrano Hotel Diamond\n";
		nazwaHotelu = "Hotel Diamond";
		cout << " Wybierz rodzaj pokoju:\n";
		cout << "1 - pokoj 1 - osobowy\n";
		cout << "2 - pokoj 2 - osobowy\n";
		cout << "3 - pokoj 3 - osobowy\n";
		cout << "4 - pokoj 4 - osobowy\n";
		cin >> wybor;

		if (wybor == 1) {

			wielkoscPokoju = "pokoj 1 - osobowy\n";
		}
		if (wybor == 2) {

			wielkoscPokoju = "pokoj 2 - osobowy\n";
		}
		if (wybor == 3) {

			wielkoscPokoju = "pokoj 3 - osobowy\n";
		}
		if (wybor == 4) {

			wielkoscPokoju = "pokoj 4 - osobowy\n";
		}

		cout << " Wybierz pobyt z wyzywieniem lub bez: \n";
		cout << "1 - pobyt z wyzywieniem\n";
		cout << "2 - pobyt bez wyzywienia\n";
		cin >> wybor;

		if (wybor == 1) {


			wyzywienie = "pobyt z wyzywieniem\n";
		}
		else {
			wyzywienie = "pobyt bez wyzywienia\n";
		}
		aquapark = "Tak";
		liczbaBasenow = "4";
		odlegloscOdPlazy = "1 kilometr";
		dodatkoweAtrakcje = "SPA, jacuzzi, sauna, kort tenisowy";

		break;

	case HotelDomZdrojowy:
		cout << "Wybrano Hotel Dom Zdrojowy\n";
		nazwaHotelu = "Hotel Dom Zdrojowy";
		cout << " Wybierz rodzaj pokoju:\n";
		cout << "1 - pokoj 1 - osobowy\n";
		cout << "2 - pokoj 2 - osobowy\n";
		cout << "3 - pokoj 3 - osobowy\n";
		cout << "4 - pokoj 4 - osobowy\n";
		cin >> wybor;

		if (wybor == 1) {

			wielkoscPokoju = "pokoj 1 - osobowy\n";
		}
		if (wybor == 2) {

			wielkoscPokoju = "pokoj 2 - osobowy\n";
		}
		if (wybor == 3) {

			wielkoscPokoju = "pokoj 3 - osobowy\n";
		}
		if (wybor == 4) {

			wielkoscPokoju = "pokoj 4 - osobowy\n";
		}

		cout << " Wybierz pobyt z wyzywieniem lub bez: \n";
		cout << "1 - pobyt z wyzywieniem\n";
		cout << "2 - pobyt bez wyzywienia\n";
		cin >> wybor;

		if (wybor == 1) {


			wyzywienie = "pobyt z wyzywieniem\n";
		}
		else {
			wyzywienie = "pobyt bez wyzywienia\n";
		}
		aquapark = "Tak";
		liczbaBasenow = "4";
		odlegloscOdPlazy = "1,5 kilometra";
		dodatkoweAtrakcje = "SPA, jacuzzi, sauna, sala zabaw dla dzieci";

		break;

	case HotelBB:
		cout << "Wybrano Hotel BB\n";
		nazwaHotelu = "Hotel BB";
		cout << " Wybierz rodzaj pokoju:\n";
		cout << "1 - pokoj 1 - osobowy\n";
		cout << "2 - pokoj 2 - osobowy\n";
		cout << "3 - pokoj 3 - osobowy\n";
		cout << "4 - pokoj 4 - osobowy\n";
		cin >> wybor;

		if (wybor == 1) {

			wielkoscPokoju = "pokoj 1 - osobowy\n";
		}
		if (wybor == 2) {

			wielkoscPokoju = "pokoj 2 - osobowy\n";
		}
		if (wybor == 3) {

			wielkoscPokoju = "pokoj 3 - osobowy\n";
		}
		if (wybor == 4) {

			wielkoscPokoju = "pokoj 4 - osobowy\n";
		}

		cout << " Wybierz pobyt z wyzywieniem lub bez: \n";
		cout << "1 - pobyt z wyzywieniem\n";
		cout << "2 - pobyt bez wyzywienia\n";
		cin >> wybor;

		if (wybor == 1) {


			wyzywienie = "pobyt z wyzywieniem\n";
		}
		else {
			wyzywienie = "pobyt bez wyzywienia\n";
		}
		aquapark = "Tak";
		liczbaBasenow = "5";
		odlegloscOdPlazy = "300 metrow";
		dodatkoweAtrakcje = "SPA, jacuzzi, sauna, sala zabaw dla dzieci, prywatna plaza, kort tenisowy";

		break;
	default:
		break;

	}
}
void Hotel::zmienSwojHotel(size_t liczbaGwiazdek) {
	wyswietlMozliweHotele(liczbaGwiazdek);
}


void Hotel::wyswietlDaneHoteli() {
	cout << "\nPobyt odbywa sie w hotelu: " << nazwaHotelu;
	cout << "\nRodzaj pokoju: " << wielkoscPokoju
		<< "Wyzywienie: " << wyzywienie
		<< "Dodatkowe informacje o hotelu: \n"
		<< " Aquapark: " << aquapark << "\n"
		<< " Liczba besenow: " << liczbaBasenow << "\n"
		<< " Odleglosc od plazy: " << odlegloscOdPlazy << "\n"
		<< " Dodatkowe atrakcje: " << dodatkoweAtrakcje << "\n";
}