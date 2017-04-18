#include "ppm.h"
#include <fstream>

ppm::ppm()
{
	nazwa = "obraz.ppm";
}

ppm::ppm(const ppm& a)
{
	nazwa = a.nazwa;
}

ppm::ppm(std::string a)
{
	nazwa = a;
	wczytaj(nazwa);
}

ppm::~ppm()
{

}

ppm& ppm::operator=(const ppm& a)
{
	return *this;
}

void ppm::wczytaj(std::string nazwa)
{
	std::ifstream plik;
	plik.open(nazwa);
	if (plik.good())
	{
		std::string sprawdz_typ;
		plik >> sprawdz_typ >> std::ws;
		if (sprawdz_typ == "P3")
		{
			{
				std::string pomin_linie;
				std::getline(plik, pomin_linie); 
			}
			unsigned int x, y, max_liczba_koloru;
			plik >> x >> y >> max_liczba_koloru; 
			for (unsigned long int i = 0; i < x*y; i++)
			{
				unsigned short int R, G, B;
				plik >> R >> G >> B; 
				unsigned int kolor = lacz_kolory(R, G, B); 
				kolory.insert(kolor); 
			}
		}
		plik.close();
	}
}

unsigned int ppm::lacz_kolory(const unsigned short int& R, const unsigned short int& G, const unsigned short int& B)
{
	return ((R * 1000000) + (G * 1000) + B);
}