/*
Autor: Bartosz Stasiak
Program: Biblia
Data utworzenia: 30.12.2016
Opis programu: Program przyjmuje dane ró¿nych typów do tablicy(char, int, string, color), nastêpnie w odpowiedni 
sposób zlicza je i wyrzuca do odpowiednich plików zliczone elementy(s³owa/litery/cyfry/kolory) oraz iloœæ ich wyst¹pieñ.

Daty modyfikacji i elementy modyfikowane:
30.12.2016	utworzenie projektu, stworzenie template dla typów string/char/int
1.12.2016	dodanie do template'a interpretacji nowego typu color, dodanie komentarzy
*/

#pragma once
#ifndef _FREQCOUNTER_H_
#define _FREQCOUNTER_H_

#include <fstream>
#include <string>
#include <map>
#include <typeinfo> 
#include <cmath>

#include "ppm.h"

template <typename Type>	//tworzenie template
class freqcounter
{
	private:
		void drawGraph();		//prywatna metoda rysuj¹ca wykres w .ppm, zabroniona dla u¿ytkownika
	protected:
		std::map<Type, int> tab1;	//mapa z kluczami i wartoœciami
	public:
		//konstruktory
		freqcounter() {};										//konstruktor pusty
		freqcounter(const freqcounter &a) { tab1 = a.tab1; };	//konstruktor kopiuj¹cy

		//destruktor
		virtual ~freqcounter() {};

		//operatory
		freqcounter& freqcounter::operator=(const freqcounter &) { return *this; };	//przeci¹¿ony operator =
		//metody
		virtual void addData(Type a) { tab1[a]++; };	/*metoda inkrementuj¹ca iloœæ wyst¹pieñ danego
														klucza w mapie (gdy klucz nie istnieje, to automatycznie jest tworzony)*/

		virtual void create();				/*metoda tworzy odpowiedni plik, z informacjami o nazwie klucza i 
											iloœci jego wyst¹pieñ*/
};

template <typename Type>
void freqcounter<Type>::create()
{
	std::ofstream out;
	//Sprawdzanie typów danych i otwieranie odpowiedniego pliku
	if (typeid(Type) == typeid(char))
	{
		out.open("pliki\\letter_result.txt");
		drawGraph();
	}
	else if (typeid(Type) == typeid(std::string))
		out.open("pliki\\word_result.txt");
	else if (typeid(Type) == typeid(int))
		out.open("pliki\\rand_result.txt");
	else if (typeid(Type) == typeid(double))
		out.open("pliki\\color_result.txt");
	///////////////////////////////////////////////////////////
	//Zapis danych do pliku
	if (out.is_open())
	{
		for (auto& mymap : tab1)
		{
			out << "'" << mymap.first << "': " << mymap.second << std::endl;
		}
	}

	out.close();
}

template <typename Type>
void freqcounter<Type>::drawGraph()
{
	std::ofstream wykres;
	wykres.open("pliki\\wykres.ppm");
	if (wykres.is_open())
	{
		wykres << "P3" << std::endl << "#Creator: FreqCounter" << std::endl << 800 << " " << 100 << std::endl << 255 << std::endl;
		for (auto& mymap : tab1)
		{
			if (mymap.second > 0)
			{
				//najwiêksza wartoœæ
				int x = (int)(floor(800000 / 800));
				int y = (int)(floor(mymap.second / x));

				for (int i = 0; i < y; i++)
				{
					wykres << 0 << " " << 0 << " " << 0 << " ";
				}
				for (int i = y; i < 800; i++)
				{
					wykres << 255 << " " << 255 << " " << 255 << " ";
				}
			}
			else
			{
				for (int i = 0; i < 800; i++)
				{
					wykres << 255 << " " << 255 << " " << 255 << " ";
				}
			}
		}
		int m = 100 - tab1.size();
		if (m < 0) m = 0;
		for (int i = 0; i < m; i++)
		{
			for (int i = 0; i < 800; i++)
			{
				wykres << 255 << " " << 255 << " " << 255 << " ";
			}
		}
	}
	wykres.close();
}
#endif