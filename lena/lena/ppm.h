//Opis dzia�ania i zmian za��czony w obraz.h

#pragma once
#ifndef _PPM_H_
#define _PPM_H_

#include "obraz.h"
#include <vector>

//Klasa ppm
class ppm :public obraz
{
private:
	//funkcje prywatne
	static std::string link_text(const int &, const int &, const int &); //��czenie 3 liczb jako string
	static int read_int(const std::string &); //czytanie stringa jako int
	void load_file();	//�adowanie pliku do tablicy

protected:
	std::vector<int> tab2;	//zmienna typu vector przechowuj�ca tablic� wszystkich liczb
	char* file_name;	//zmienna prywatna przechowuj�ca nazw� pliku

public:
	//konstruktory
	ppm();					//konstruktor pusty
	ppm(const ppm &);		//konstruktor kopiuj�cy
	ppm(char *);			//konstruktor przyjmuj�cy nazw� pliku

	//destruktory
	virtual ~ppm();

	//operatory
	ppm& ppm::operator=(const ppm &);	//przeci��enie operatora =
};

#endif