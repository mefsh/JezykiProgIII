#include "morse.h"
#include <windows.h>
#include <string>

//konstruktory
morse::morse()
{
	freq = 1000;
	spause = 500;
	tdot = 100;
	tdash = 200;
	chpause = 100;
}

morse::morse(const morse& a)
{
	freq = a.freq;
	spause = a.spause;
	tdot = a.tdot;
	tdash = a.tdash;
	chpause = a.chpause;
}

//destruktory
morse::~morse()
{
}

//set
void morse::setFrequency(int a)
{
	freq = a;
}

void morse::setPause(int a)
{
	spause = a;
}

void morse::setDotTime(int a)
{
	tdot = a;
}

void morse::setDashTime(int a)
{
	tdash = a;
}

void morse::setCharPause(int a)
{
	chpause = a;
}

//get
int morse::getFrequency() const
{
	return freq;
}

int morse::getPause() const
{
	return spause;
}

int morse::getDotTime() const
{
	return tdot;
}

int morse::getDashTime() const
{
	return tdash;
}

int morse::getCharPause() const
{
	return chpause;
}

//operatory
morse& morse::operator<<(const char* a)
{
	std::string sa = std::string(a);
	CAB(sa, *this);
	return *this;
}

morse& morse::operator<<(const long& a)
{
	std::string sa = std::to_string(a);
	CAB(sa, *this);
	return *this;
}

morse& morse::operator<<(const double& a)
{
	std::string sa = std::to_string(a);
	CAB(sa, *this);
	return *this;
}

morse& morse::operator<<(morse&(*m)(morse&))
{
	return (*m)(*this);
}

morse& morse::operator=(const morse& a)
{
	return *this;
}

//manipulator
morse& pause(morse& _o)
{
	Sleep(_o.getPause());
	return _o;
}

//funkcja
void CAB(std::string a, morse& m)
{
	for (unsigned int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case 'a': case 'A':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'b': case 'B':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'c': case 'C':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'd': case 'D':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'e': case 'E':
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'f': case 'F':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'g': case 'G':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'h': case 'H':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'i': case 'I':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'j': case 'J':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'k': case 'K':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'l': case 'L':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'm': case 'M':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'n': case 'N':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'o': case 'O':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'p': case 'P':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 'q': case 'Q':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'r': case 'R':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 's': case 'S':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case 't': case 'T':
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'u': case 'U':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'v': case 'V':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'w': case 'W':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'x': case 'X':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'y': case 'Y':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case 'z': case 'Z':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case ' ':
			Sleep(m.getPause());
			break;
		case '1':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case '2':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case '3':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case '4':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case '5':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case '6':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case '7':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case '8':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case '9':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Sleep(m.getCharPause());
			break;
		case '0':
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		case '.':
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Beep(m.getFrequency(), m.getDotTime());
			Beep(m.getFrequency(), m.getDashTime());
			Sleep(m.getCharPause());
			break;
		default:
			Beep(1000, 1000);
		}
	}
}
