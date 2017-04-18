/*
Autor: Bartosz Stasiak
Program: Lena
Data utworzenia: 18.12.2016
Opis dzia³ania: Program wczytuje pliki ppm, a nastêpnie zlicza unikaln¹ iloœæ ich kolorów

Daty modyfikacji i elementy modyfikowane:
18.12.2016	utworzenie projektu
2.01.2017 podzia³ dwóch klas na osobne pliki, zmiana sposobu zliczania unikalnych kolorów,
w celu poprawienia szybkoœci dzia³ania programu , dodanie wirtualnego destruktora,
dodanie dwóch nowych funkcji link_text i read_int, ukrycie funkcji, które nie s¹ do u¿ytku dla u¿ytkownika
*/

#pragma once
#ifndef _OBRAZ_H_
#define _OBRAZ_H_

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

//Klasa obraz
class obraz
{
protected:
	std::map<int, int> tab1;	//zmienna typu wektor przechowuj¹ca unikalne klucze

public:
	//konstruktory
	obraz();					//konstruktor pusty
	obraz(const obraz &);		//konstruktor kopiuj¹cy

								//destruktory
	virtual ~obraz();

	//get
	const std::map<int, int> getTab();	//metoda umo¿liwiaj¹ca pobranie tablicy z liczbami dla funkcji

										//operatory
	obraz& obraz::operator=(const obraz &);	//przeci¹¿ony operator =
};

//Funkcja liczkolory
int liczkolory(obraz &);	//funkcja liczkolory
#endif