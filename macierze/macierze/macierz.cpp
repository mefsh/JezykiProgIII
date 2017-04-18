#include "macierz.h"

macierz::macierz() //konstruktor ustaw 0 gdy pusto
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrix[i][j] = 0;
}

void macierz::set(int x, int y, double w)
{
	matrix[x][y] = w;
}

/*
void macierz::wypisz()
{
	std::cout << std::endl << std::endl;
	std::cout << matrix[0][0] << ' ';
	std::cout << matrix[0][1] << std::endl;
	std::cout << matrix[1][0] << ' ';
	std::cout << matrix[1][1] << std::endl;
}
*/

const macierz& macierz::operator=(const macierz &B)
{
	matrix[0][0] = B.matrix[0][0];
	matrix[0][1] = B.matrix[0][1];
	matrix[1][0] = B.matrix[1][0];
	matrix[1][1] = B.matrix[1][1];

	return *this;
}

macierz macierz::operator*(const macierz &B) const
{
	macierz K;
	K.matrix[0][0] = (matrix[0][0] * B.matrix[0][0]) + (matrix[0][1] * B.matrix[1][0]);
	K.matrix[0][1] = (matrix[0][0] * B.matrix[0][1]) + (matrix[0][1] * B.matrix[1][1]);
	K.matrix[1][0] = (matrix[1][0] * B.matrix[0][0]) + (matrix[1][1] * B.matrix[1][0]);
	K.matrix[1][1] = (matrix[1][0] * B.matrix[0][1]) + (matrix[1][1] * B.matrix[1][1]);

	return K;
}



bool macierz::operator==(macierz B) const
{
	if (matrix[0][0] == B.matrix[0][0] && matrix[0][1] == B.matrix[0][1] && matrix[1][0] == B.matrix[1][0] && matrix[1][1] == B.matrix[1][1])
		return true;
	else
		return false;
}
