#include <iostream>
#include "ppm.h"

int main()
{
	obraz *ob = new ppm("lena.ppm");
	int kolor;
	kolor = liczkolory(*ob);

	std::cout << "kolorow: " << kolor;

	delete ob;
	system("pause");
	return 0;
}