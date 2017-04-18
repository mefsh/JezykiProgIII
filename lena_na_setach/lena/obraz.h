/* 
Bartosz Stasiak
Data utworzenia 02/2017
Funkcjonalność: Program zlicza unikalne kolory zawarte w tablicy (mogą one być one pobrane np. z pliku za pomocą klasy ppm).

Co zawiera:
- Klasa obraz posiadająca kontener set na kolory, metodę zwracającą tablicę.
- Funkcja zliczająca ilość unikalnych kolorów na obrazie.
*/
#pragma once
#ifndef _OBRAZ_H_
#define _OBRAZ_H_

#include <set>

class obraz
{
protected:
	std::set<int> kolory;
public:
	//konstruktory
	obraz();
	obraz(const obraz&);
	virtual ~obraz();

	std::set<int> pobierz() const; //pobieranie

	//operatory
	obraz& obraz::operator=(const obraz&);
};

//Funkcja liczkolory
int liczkolory(obraz&);
#endif