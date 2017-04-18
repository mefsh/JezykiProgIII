#include "morse.h"

int main()
{

	morse m;
	m.setFrequency(1000);
	m.setPause(400);
	m.setDotTime(100);
	m.setDashTime(200);
	m.setCharPause(50);

	m << "Ala ma kota";

	long i = 0x5A5A5A5A;	//liczba w postaci hex
	double d = 1.23456789;

	m << i << pause << d;

	return 0;
}