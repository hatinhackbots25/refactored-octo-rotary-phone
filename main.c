#include "gauss.h"

int main(int argc, char* argv[]){
	int test[3][4] = {
		{1, 0, 1, 1},
		{0, 0, 1, 0},
		{1, 1, 1, 0}
	};
	Matrix testM = convert(3, 4, test);
	printm(testM);
	Pivot_Gauss(testM);
	printf("======================================\n");
	printm(testM);
	return 0;
}
