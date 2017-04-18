/* 
Bartosz Stasiak
Data utworzenia 02/2017
Funkcjonalno��: Program dostaje nazw� pliku, otwiera go a nast�pnie wczytuje dane do kontenera set.
Co zawiera:
- Klasa ppm posiadaj�ca funkcj� do wczytywania danych z pliku o rozszerzeniu .ppm - dzia�a tylko z P3.
- metod� ��cz�c� 3 liczby 1/2/3 cyfrowe w jedn� max 9 cyfrow�
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

	//metoda ��cz�ca kolory
	static unsigned int lacz_kolory(const unsigned short int&, const unsigned short int&, const unsigned short int&);
};

#endif