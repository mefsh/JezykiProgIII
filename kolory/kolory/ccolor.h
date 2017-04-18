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
			int Length;			//prywatna zmienna dla max d³. tekstu
			std::string text;	//prywatna zmienna dla tekstu
			int TextC;			//prywatna zmienna dla koloru tekstu
			int BgColor;		//prywatna zmienna dla koloru t³a tekstu

		public:
			//konstruktory
			Edit();					//konstruktor pusty
			Edit(const Edit &);		//konstruktor kopiuj¹cy

			//destruktory
			~Edit();

			//set
			void setPosition(int, int);		//metoda ustaw pozycjê kursora (x,y)
			void setLength(int);			//metoda ustaw max d³. tekstu/(d³ okienka)
			void setText(char *);			//metoda ustaw tekst
			void setTextColor(int);			//metoda ustaw kolor tekstu
			void setBackgroundColor(int);	//metoda ustaw kolor t³a tekstu

			//get
			int getPosX() const;			//metoda pobieraj¹ca wartoœæ koordynatu X
			int getPosY() const;			//metoda pobieraj¹ca wartoœæ koordynatu Y
			int getLength() const;			//metoda pobieraj¹ca wartoœæ max d³. tekstu(d³ okienka)
			std::string getText() const;	//metoda pobieraj¹ca tekst
			int getTextColor() const;		//metoda pobieraj¹ca wartoœæ koloru tekstu
			int getBackgroundColor() const;	//metoda pobieraj¹ca wartoœæ koloru t³a tekstu

			//operatory
			Edit& Edit::operator=(const Edit &);		//przeci¹¿ony operator =
			Edit& Edit::operator<<(Edit &(*)(Edit &));	//przeci¹¿ony operator dla manipulatorów kolorów

			//funkcje
			void display() const;		//funkcja wyœwietlaj¹ca tekst
			void userText();	/*funkcja kasuj¹ca tekst, a nastêpnie daj¹ca u¿ytkownikowi mo¿liwoœæ
								wpisania w³asnego tekstu ograniczonego max d³. tekstu (szer. okienka)*/

			//enumerator
			enum color			//enumerator z kolorami dla tekstu i t³a tekstu
			{
				Black=0, DarkBlue, DarkGreen, DarkCyan,
				DarkRed, DarkViolet, DarkYellow, DarkWhite,
				Grey, Blue, Green, Cyan,
				Red, Violet, Yellow, White
			};
	};

	//manipulatory
	std::ostream &red(std::ostream &);		//manipulator ustawiaj¹cy kolor tekstu na czerwony
	std::ostream &green(std::ostream &);	//manipulator ustawiaj¹cy kolor tekstu na zielony
	std::ostream &blue(std::ostream &);		//manipulator ustawiaj¹cy kolor tekstu na niebieski
	std::ostream &white(std::ostream &);	//manipulator ustawiaj¹cy kolor tekstu na bia³y

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//KLASA setColor
	class setColor
	{
		int ab;
		public:
			//konstruktory
			setColor(int = 0);			//konstruktor przypisuj¹cy wartoœæ (gdy brak wartoœci przypisuje 0)
			setColor(const setColor &);	//konstruktor kopiuj¹cy

			//destruktory
			~setColor();

			//operatory
			setColor& setColor::operator=(const setColor &); //przeci¹¿ony operator =

			//funkcje
			void setCol(std::ostream &) const;	//funkcja u¿ywana przez manipulator, do ustawienia koloru tekstu
	};
	//manipulator
	std::ostream& operator<<(std::ostream&, setColor const &);	/*manipulator przeci¹¿aj¹cy operator << z ostream na klasê,
	jednoczeœnie wewn¹trz wywo³uj¹cy funkcjê setCol odpowiedzialn¹ za zmianê koloru tekstu i t³a tekstu*/
#endif