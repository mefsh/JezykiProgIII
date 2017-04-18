#include "obraz.h"

//Klasa obraz
//konstruktory
obraz::obraz() {}
obraz::obraz(const obraz &a) { tab1 = a.tab1; }

//destruktor
obraz::~obraz() { }

//get
const std::map<int, int> obraz::getTab()
{
	return tab1;
}

//operatory
obraz& obraz::operator=(const obraz &a)
{
	return *this;
}

//Funkcja liczkolory
int liczkolory(obraz &a)
{
	return a.getTab().size();;
}