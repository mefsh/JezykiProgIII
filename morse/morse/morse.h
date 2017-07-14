/*
Autor: Bartosz Stasiak
Program: Morse
Data utworzenia: 07.11.2016
*/
#pragma once
#ifndef _MORSE_H_
#define _MORSE_H_
#include <string>

	class morse 
	{
		//zmienne prywatne
			int freq;						//prywatna zmienna dla setFrequency
			int spause;						//prywatna zmienna dla setPause
			int tdot;						//prywatna zmienna dla setDotTime
			int tdash;						//prywatna zmienna dla setDashTime
			int chpause;					//prywatna zmienna dla setCharPause
		
		public:
			//konstruktory
			morse();						//pusty konstruktor
			morse(const morse &);			//konstruktor kopiuj¹cy

			//destruktory
			~morse();

			//set
			void setFrequency(int);			//metoda ustaw czestotliwosc dzwieku
			void setPause(int);				//metoda ustaw czas pauzy odpowiadajacej spacji
			void setDotTime(int);			//metoda ustaw czas trwania kropki
			void setDashTime(int);			//metoda ustaw czas trwania kreski
			void setCharPause(int);			//metoda ustaw czas przerwy miêdzy znakami

			//get
			int getFrequency() const;				//metoda pobieraj¹ca czestotliwosc dzwieku
			int getPause() const;					//metoda pobieraj¹ca czas pauzy odpowiadaj¹cej spacji
			int getDotTime() const;					//metoda pobieraj¹ca czas trwania kropki
			int getDashTime() const;				//metoda pobieraj¹ca czas trwania kreski
			int getCharPause() const;				//metoda pobieraj¹ca czas przerwy miêdzy znakami

			//operatory
			morse& morse::operator<<(const char *);			//przeci¹¿ony operator dla tekstu
			morse& morse::operator<<(const long &);			//przeci¹¿ony operator dla liczby long
			morse& morse::operator<<(const double &);		//przeci¹¿ony operator dla liczby double
			morse& morse::operator<<(morse &(*)(morse &));	//przeci¹¿ony operator dla pause
			morse& morse::operator=(const morse &);			//przeci¹¿ony operator =
	};
	//manipulator
	morse& pause(morse &);

	//funkcja
	void CAB(std::string, morse &);	//funkcja (convert and beep) konwertuj¹ca litery i liczby na morsa i beepuj¹ca je

#endif