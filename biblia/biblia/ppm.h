#pragma once
#ifndef _PPM_H_
#define _PPM_H_

#include "obraz.h"

//Klasa ppm
class ppm : public obraz
{
private:
	//funkcje prywatne
	std::string link_text(const int &, const int &, const int &); //��czenie 3 liczb jako string
	int read_int(const std::string &); //czytanie stringa jako int
	void load_file();	//�adowanie pliku do tablicy

protected:
	std::vector <int> tab2;	//zmienna typu vector przechowuj�ca tablic� wszystkich liczb
	char* file_name;	//zmienna prywatna przechowuj�ca nazw� pliku
	int number;

public:
	int value;
	//konstruktory
	ppm();					//konstruktor pusty
	ppm(const ppm &);		//konstruktor kopiuj�cy
	ppm(char *);			//konstruktor przyjmuj�cy nazw� pliku
	ppm(int);				////konstruktor przyjmuj�cy int

	//destruktory
	virtual ~ppm();

	//operatory
	ppm& ppm::operator=(const ppm &);	//przeci��enie operatora =

	//get
	int getColor(int, int);
};

#endif