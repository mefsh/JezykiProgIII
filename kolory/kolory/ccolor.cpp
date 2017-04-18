#include "ccolor.h"

//konstruktory
Edit::Edit()
{
	PosX=0;
	PosY=0;
	Length=27;
	text="Nie podano zadnego tekstu!";
	TextC=White;
	BgColor=Black;
}

Edit::Edit(const Edit &a)
{
	PosX = a.PosX;
	PosY = a.PosY;
	Length = a.Length;
	text = a.text;
	TextC = a.TextC;
	BgColor = a.BgColor;
}

//destruktor
Edit::~Edit() { }

//set
void Edit::setPosition(int a, int b)
{
	PosX = a;
	PosY = b;
}

void Edit::setLength(int a)
{
	Length = a;
}

void Edit::setText(char *a)
{
	text = a;
}

void Edit::setTextColor(int a)
{
	TextC = a;
}

void Edit::setBackgroundColor(int a)
{
	a = 16 * a;
	BgColor = a;
}

//get
int Edit::getPosX() const
{
	return PosX;
}

int Edit::getPosY() const
{
	return PosY;
}

int Edit::getLength() const
{
	return Length;
}

std::string Edit::getText() const
{
	return text;
}

int Edit::getTextColor() const
{
	return TextC;
}

int Edit::getBackgroundColor() const
{
	return BgColor;
}

//operatory
Edit& Edit::operator=(const Edit &a)
{
	return *this;
}

Edit & Edit::operator<<(Edit &(*a)(Edit &))
{
	return (*a)(*this);
}

//manipulatory
std::ostream &red(std::ostream &_o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, Edit::Red);
	return _o;
}
std::ostream &green(std::ostream &_o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, Edit::Green);
	return _o;
}
std::ostream &blue(std::ostream &_o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, Edit::Blue);
	return _o;
}
std::ostream &white(std::ostream &_o)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, Edit::White);
	return _o;
}

//funkcje
void Edit::display() const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE);
	system("cls");

	HANDLE hc;
	COORD c;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, getBackgroundColor()+getTextColor());

	c.X = getPosX();
	c.Y = getPosY();
	SetConsoleCursorPosition(hc, c);


	if (getText().length() <= getLength())
	{
		for (int i = 0; i < text.length(); i++)
			std::cout << getText()[i];
		for (int i = getText().length(); i < getLength() ;i++)
			std::cout << " ";
	}
	else
	{
		for (int i = 0; i < getLength(); i++)
			std::cout << getText()[i];
	}
	std::cout << std::endl;
}

void Edit::userText()
{
	HANDLE hc;
	COORD c;

	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, Red);

	c.X = getPosX();
	c.Y = getPosY()-1;
	SetConsoleCursorPosition(hc, c);

	std::cout << "Podaj tekst (zostanie zapisane TYLKO [" << getLength() << "] znakow!)\n";

	SetConsoleTextAttribute(hc, getBackgroundColor() + getTextColor());
	c.X = getPosX();
	c.Y = getPosY();
	SetConsoleCursorPosition(hc, c);

	std::string a;
	std::getline(std::cin, a);
	int count = a.length() - getLength();
	if(count > 0)
		a.erase(getLength(), count);	//ucinam stringa do wartoœci narzuconej przez setLength, dopiero potem zapis

	text = a;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//KLASA setColor
//konstruktory
setColor::setColor(int a)
{
	ab = a;
}

setColor::setColor(const setColor &a)
{
	ab = a.ab;
}

//destruktor
setColor::~setColor() {};

//operatory
setColor& setColor::operator=(const setColor &a)
{
	return *this;
}

//funkcja
void setColor::setCol(std::ostream & os) const
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, ab);
}

//manipulatory
std::ostream& operator<<(std::ostream &_o, setColor const &col)
{
	col.setCol(_o);
	return _o;
}