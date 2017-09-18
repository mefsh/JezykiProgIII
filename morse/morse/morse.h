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
			morse(const morse &);			//konstruktor kopiujący

			//destruktory
			~morse();

			//set
			void setFrequency(int);			//metoda ustaw czestotliwosc dzwieku
			void setPause(int);				//metoda ustaw czas pauzy odpowiadajacej spacji
			void setDotTime(int);			//metoda ustaw czas trwania kropki
			void setDashTime(int);			//metoda ustaw czas trwania kreski
			void setCharPause(int);			//metoda ustaw czas przerwy między znakami

			//get
			int getFrequency() const;				//metoda pobierająca czestotliwosc dzwieku
			int getPause() const;					//metoda pobierająca czas pauzy odpowiadającej spacji
			int getDotTime() const;					//metoda pobierająca czas trwania kropki
			int getDashTime() const;				//metoda pobierająca czas trwania kreski
			int getCharPause() const;				//metoda pobierająca czas przerwy między znakami

			//operatory
			morse& morse::operator<<(const char *);			//przeciążony operator dla tekstu
			morse& morse::operator<<(const long &);			//przeciążony operator dla liczby long
			morse& morse::operator<<(const double &);		//przeciążony operator dla liczby double
			morse& morse::operator<<(morse &(*)(morse &));	//przeciążony operator dla pause
			morse& morse::operator=(const morse &);			//przeciążony operator =
	};
	//manipulator
	morse& pause(morse &);

	//funkcja
	void CAB(std::string, morse &);	//funkcja (convert and beep) konwertująca litery i liczby na morsa i beepująca je

#endif