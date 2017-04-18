/*
Autor: Bartosz Stasiak
Program: Edit
Data utworzenia: 21.11.2016
*/
#pragma once
#ifndef _CCOLOR_H_
#define _CCOLOR_H_

#include <windows.h>
#include <iostream>
#include <string>

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//KLASA Edit
	class Edit
	{
		private:
			//zmienne prywatne
			int PosX;			//prywatna zmienna dla koordynatu X
			int PosY;			//prywatna zmienna dla koordynatu Y
			int Length;			//prywatna zmienna dla max d�. tekstu
			std::string text;	//prywatna zmienna dla tekstu
			int TextC;			//prywatna zmienna dla koloru tekstu
			int BgColor;		//prywatna zmienna dla koloru t�a tekstu

		public:
			//konstruktory
			Edit();					//konstruktor pusty
			Edit(const Edit &);		//konstruktor kopiuj�cy

			//destruktory
			~Edit();

			//set
			void setPosition(int, int);		//metoda ustaw pozycj� kursora (x,y)
			void setLength(int);			//metoda ustaw max d�. tekstu/(d� okienka)
			void setText(char *);			//metoda ustaw tekst
			void setTextColor(int);			//metoda ustaw kolor tekstu
			void setBackgroundColor(int);	//metoda ustaw kolor t�a tekstu

			//get
			int getPosX() const;			//metoda pobieraj�ca warto�� koordynatu X
			int getPosY() const;			//metoda pobieraj�ca warto�� koordynatu Y
			int getLength() const;			//metoda pobieraj�ca warto�� max d�. tekstu(d� okienka)
			std::string getText() const;	//metoda pobieraj�ca tekst
			int getTextColor() const;		//metoda pobieraj�ca warto�� koloru tekstu
			int getBackgroundColor() const;	//metoda pobieraj�ca warto�� koloru t�a tekstu

			//operatory
			Edit& Edit::operator=(const Edit &);		//przeci��ony operator =
			Edit& Edit::operator<<(Edit &(*)(Edit &));	//przeci��ony operator dla manipulator�w kolor�w

			//funkcje
			void display() const;		//funkcja wy�wietlaj�ca tekst
			void userText();	/*funkcja kasuj�ca tekst, a nast�pnie daj�ca u�ytkownikowi mo�liwo��
								wpisania w�asnego tekstu ograniczonego max d�. tekstu (szer. okienka)*/

			//enumerator
			enum color			//enumerator z kolorami dla tekstu i t�a tekstu
			{
				Black=0, DarkBlue, DarkGreen, DarkCyan,
				DarkRed, DarkViolet, DarkYellow, DarkWhite,
				Grey, Blue, Green, Cyan,
				Red, Violet, Yellow, White
			};
	};

	//manipulatory
	std::ostream &red(std::ostream &);		//manipulator ustawiaj�cy kolor tekstu na czerwony
	std::ostream &green(std::ostream &);	//manipulator ustawiaj�cy kolor tekstu na zielony
	std::ostream &blue(std::ostream &);		//manipulator ustawiaj�cy kolor tekstu na niebieski
	std::ostream &white(std::ostream &);	//manipulator ustawiaj�cy kolor tekstu na bia�y

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//KLASA setColor
	class setColor
	{
		int ab;
		public:
			//konstruktory
			setColor(int = 0);			//konstruktor przypisuj�cy warto�� (gdy brak warto�ci przypisuje 0)
			setColor(const setColor &);	//konstruktor kopiuj�cy

			//destruktory
			~setColor();

			//operatory
			setColor& setColor::operator=(const setColor &); //przeci��ony operator =

			//funkcje
			void setCol(std::ostream &) const;	//funkcja u�ywana przez manipulator, do ustawienia koloru tekstu
	};
	//manipulator
	std::ostream& operator<<(std::ostream&, setColor const &);	/*manipulator przeci��aj�cy operator << z ostream na klas�,
	jednocze�nie wewn�trz wywo�uj�cy funkcj� setCol odpowiedzialn� za zmian� koloru tekstu i t�a tekstu*/
#endif