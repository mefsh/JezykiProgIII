#include "ppm.h"

//Klasa PPM
//konstruktory
ppm::ppm()
{
	file_name = "NULL";
}

ppm::ppm(const ppm &a)
{
	number = a.number;
	tab2 = a.tab2;
	file_name = a.file_name;
}

ppm::ppm(char *a)
{
	file_name = a;
	load_file();
}
ppm::ppm(int a)
{
	number = a;
	load_file();
}

//destruktor
ppm::~ppm() { }

//operatory
ppm& ppm::operator=(const ppm &a)
{
	return *this;
}

//funkcje prywatne klasy ppm
std::string ppm::link_text(const int &x, const int &y, const int &z)
{
	std::ostringstream oss;
	oss << x << y << z;
	std::string s = oss.str();
	return s;
}

int ppm::read_int(const std::string &s)
{
	std::stringstream sbuffer(s);
	int i;
	sbuffer >> i;
	return i;
}

void ppm::load_file()
{
	std::ifstream in(file_name);
	if (in.is_open())
	{
		char check_p3[2];
		in >> check_p3[0] >> check_p3[1];
		if (check_p3[0] == 'P' && check_p3[1] == '3')
		{
			std::string dummyLine;
			std::getline(in, dummyLine);
			std::getline(in, dummyLine);
			int pixels[2];
			in >> pixels[0] >> pixels[1] >> std::ws;
			int skipper;
			in >> skipper >> std::ws;
			tab2.resize(pixels[0] * pixels[1]);
			for (int i = 0; i < pixels[0] * pixels[1]; i++)
			{
				int x, y, z;
				in >> x >> y >> z >> std::ws;
				tab2[i] = read_int(link_text(x, y, z));
				tab1[tab2[i]]++;
			}
		}
		in.close();
	}
}

int ppm::getColor(int x, int y)
{
	value = tab2[x*y];
	return tab2[x*y];
}