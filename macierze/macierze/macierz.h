/*Autor, data utworzenia, daty modyfikacji, nazwa programu*/
#pragma once
#ifndef _MACIERZ_H_
#define _MACIERZ_H_

	class macierz
	{
		double matrix[2][2]; //macierz 2x2

		public:
			//konstruktory
			macierz();									//pusty konstruktor
			//void wypisz();							//konstruktor wypisz dane	
			//destruktor

			//settery
			void set(int, int, double);					//metoda ustaw dane
			//gettery

			//operatory
			const macierz& operator=(const macierz &);	//operator przypisania jednej macierzy drugiej		
			macierz operator*(const macierz &) const;			//operator mno¿enia macierzy
			bool operator==(macierz) const;					//operator porównania macierzy
			
			//friend macierz operator*(const macierz &A, const macierz &B); //druga mo¿liwoœæ mno¿enia wykonywana jako funkcja zaprzyjaŸniona
	};

#endif