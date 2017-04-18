/* 
Bartosz Stasiak
Data utworzenia 02/2017
Funkcjonalnoœæ: Program dostaje nazwê pliku, otwiera go a nastêpnie wczytuje dane do kontenera set.
Co zawiera:
- Klasa ppm posiadaj¹ca funkcjê do wczytywania danych z pliku o rozszerzeniu .ppm - dzia³a tylko z P3.
- metodê ³¹cz¹c¹ 3 liczby 1/2/3 cyfrowe w jedn¹ max 9 cyfrow¹
*/
#pragma once
#ifndef _PPM_H_
#define _PPM_H_

#include "obraz.h"
#include <string>

class ppm : public obraz
{
protected:
	std::string nazwa;
	void wczytaj(std::string);

public:
	//konstruktory
	ppm();
	ppm(const ppm&);
	explicit ppm(std::string);
	~ppm();

	//operatory
	ppm& ppm::operator=(const ppm&);

	//metoda ³¹cz¹ca kolory
	static unsigned int lacz_kolory(const unsigned short int&, const unsigned short int&, const unsigned short int&);
};

#endif