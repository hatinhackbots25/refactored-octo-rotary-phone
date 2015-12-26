#include "gauss.h"
#include "add_crypt_clear.h"

int main(int argc, char* argv[]){
	int test[3][4] = {
		{1, 1, 1, 1},
		{0, 1, 1, 0},
		{1, 0, 1, 1}
	};
	char msg[100] = "****BEGINNINGOFMESSAGE***";
	
	Matrix testM = convert(3, 4, test);
	printm(testM);
	Pivot_Gauss(testM);
	printf("======================================\n");
	printm(testM);
	free_matrix(testM);
	int* osef1 = hex_to_bits("cipher1");
	int* osef2 = text_to_bits(msg);
	int* osef = xor_cipher_clear(osef1, osef2);
	free(osef1);
	free(osef2);
	free(osef);
	
	return 0;
}
