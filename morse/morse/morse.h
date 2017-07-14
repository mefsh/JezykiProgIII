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
			morse(const morse &);			//konstruktor kopiuj�cy

			//destruktory
			~morse();

			//set
			void setFrequency(int);			//metoda ustaw czestotliwosc dzwieku
			void setPause(int);				//metoda ustaw czas pauzy odpowiadajacej spacji
			void setDotTime(int);			//metoda ustaw czas trwania kropki
			void setDashTime(int);			//metoda ustaw czas trwania kreski
			void setCharPause(int);			//metoda ustaw czas przerwy mi�dzy znakami

			//get
			int getFrequency() const;				//metoda pobieraj�ca czestotliwosc dzwieku
			int getPause() const;					//metoda pobieraj�ca czas pauzy odpowiadaj�cej spacji
			int getDotTime() const;					//metoda pobieraj�ca czas trwania kropki
			int getDashTime() const;				//metoda pobieraj�ca czas trwania kreski
			int getCharPause() const;				//metoda pobieraj�ca czas przerwy mi�dzy znakami

			//operatory
			morse& morse::operator<<(const char *);			//przeci��ony operator dla tekstu
			morse& morse::operator<<(const long &);			//przeci��ony operator dla liczby long
			morse& morse::operator<<(const double &);		//przeci��ony operator dla liczby double
			morse& morse::operator<<(morse &(*)(morse &));	//przeci��ony operator dla pause
			morse& morse::operator=(const morse &);			//przeci��ony operator =
	};
	//manipulator
	morse& pause(morse &);

	//funkcja
	void CAB(std::string, morse &);	//funkcja (convert and beep) konwertuj�ca litery i liczby na morsa i beepuj�ca je

#endif