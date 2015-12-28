#include "lfsr.h"

Matrix create_equations(int* xored){
	Matrix m = CreateNewMatrix(131,132);
	int i, j;
	for(i = 0; i < 131; i++)
		m.matrix[i][131] = xored[i];
	
	return m;
}
