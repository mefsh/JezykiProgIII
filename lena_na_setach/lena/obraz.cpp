#include "obraz.h"

obraz::obraz()
{
}
obraz::obraz(const obraz& a)
{
	kolory = a.kolory;
}

obraz::~obraz()
{
}

std::set<int> obraz::pobierz() const
{
	return kolory;
}

obraz& obraz::operator=(const obraz& a)
{
	return *this;
}

int liczkolory(obraz & a)
{
	return a.pobierz().size();
}