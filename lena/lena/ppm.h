//Opis dzia³ania i zmian za³¹czony w obraz.h

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
	static std::string link_text(const int &, const int &, const int &); //³¹czenie 3 liczb jako string
	static int read_int(const std::string &); //czytanie stringa jako int
	void load_file();	//³adowanie pliku do tablicy

protected:
	std::vector<int> tab2;	//zmienna typu vector przechowuj¹ca tablicê wszystkich liczb
	char* file_name;	//zmienna prywatna przechowuj¹ca nazwê pliku

public:
	//konstruktory
	ppm();					//konstruktor pusty
	ppm(const ppm &);		//konstruktor kopiuj¹cy
	ppm(char *);			//konstruktor przyjmuj¹cy nazwê pliku

	//destruktory
	virtual ~ppm();

	//operatory
	ppm& ppm::operator=(const ppm &);	//przeci¹¿enie operatora =
};

#endif