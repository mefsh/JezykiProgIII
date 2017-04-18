/*
Autor: Bartosz Stasiak
Program: Lena
Data utworzenia: 18.12.2016
Opis dzia�ania: Program wczytuje pliki ppm, a nast�pnie zlicza unikaln� ilo�� ich kolor�w

Daty modyfikacji i elementy modyfikowane:
18.12.2016	utworzenie projektu
2.01.2017 podzia� dw�ch klas na osobne pliki, zmiana sposobu zliczania unikalnych kolor�w,
w celu poprawienia szybko�ci dzia�ania programu , dodanie wirtualnego destruktora,
dodanie dw�ch nowych funkcji link_text i read_int, ukrycie funkcji, kt�re nie s� do u�ytku dla u�ytkownika
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
	std::map<int, int> tab1;	//zmienna typu wektor przechowuj�ca unikalne klucze

public:
	//konstruktory
	obraz();					//konstruktor pusty
	obraz(const obraz &);		//konstruktor kopiuj�cy

								//destruktory
	virtual ~obraz();

	//get
	const std::map<int, int> getTab();	//metoda umo�liwiaj�ca pobranie tablicy z liczbami dla funkcji

										//operatory
	obraz& obraz::operator=(const obraz &);	//przeci��ony operator =
};

//Funkcja liczkolory
int liczkolory(obraz &);	//funkcja liczkolory
#endif