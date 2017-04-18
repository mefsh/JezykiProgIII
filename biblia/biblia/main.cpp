#include "freqcounter.h"

int main()
{
	//zmienna na dane ze strumienia
	std::ifstream in;
	
	//Litery
	//otworzenie pliku z danymi wejœciowymi i wczytanie do zmiennej
	in.open("pliki\\biblia-en.txt");
	freqcounter <char> f_ch;
	char c;
		if (in.is_open())
		{
			while (!in.eof())
			{
				in.get(c);
				f_ch.addData(c);
			}
			in.close();
		}
	f_ch.create();

	//Wyrazy
	//otworzenie pliku z danymi wejœciowymi i wczytanie do zmiennej
	in.open("pliki\\biblia-en.txt");
	std::string wyraz;
	freqcounter <std::string> f_s;
		if (in.is_open())
		{
			while (!in.eof())
			{
				in >> wyraz;
				f_s.addData(wyraz);
			}
			in.close();
		}
	f_s.create();

	//Liczby
	freqcounter <int> f_i;
	for(int i=0;i<1000000;i++)
		f_i.addData(rand() % 1001);
	f_i.create();

	//Kolory
	freqcounter <double> f_c;
	ppm ob("lena.ppm");
	for (int i = 0; i<512; i++)
		for (int j = 0; j<512; j++)
			f_c.addData(ob.getColor(i, j));
	f_c.create();

	return 0;
}