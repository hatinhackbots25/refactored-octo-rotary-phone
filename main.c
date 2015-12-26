#include "gauss.h"
#include "add_crypt_clear.h"

int main(int argc, char* argv[]){
	FILE* fcipher;
	fcipher = fopen("cipher1","r");
	char cipher[100];
	int i;
	for(i = 0; i < 100; i++){
		char c = getc(fcipher);
		if(c == EOF){
			printf("Cipher txt is too small\n");
			return 3;
		}
		cipher[i] = c;
	}
	for(i = 0; i < 100; i++){
		printf("%c", cipher[i]);
	}
	printf("\n");
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
	int* osef1 = text_to_bits(cipher, 2);
	int* osef2 = text_to_bits(msg, 1);
	int* osef = xor_cipher_clear(osef1, osef2);
	
	return 0;
}
