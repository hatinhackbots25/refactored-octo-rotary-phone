#include "gauss.h"
#include "add_crypt_clear.h"
#include "lfsr.h"

int main(int argc, char* argv[]){
	int test[3][4] = {
		{1, 1, 1, 1},
		{0, 1, 1, 0},
		{1, 0, 1, 1}
	};
	
	char msg[100] = "****BEGINNINGOFMESSAGE***";
	int* osef1 = hex_to_bits("cipher1");
	int* osef2 = text_to_bits(msg);
	int* osef = xor_cipher_clear(osef2, osef1);
	
	Lfsr reg1 = create_reg(41);
	Lfsr reg2 = create_reg(43);
	Lfsr reg3 = create_reg(47);
	Matrix lf = create_equations(osef, reg1, reg2, reg3);
	int i;
	for(i = 0; i < 131; i++){
		if(osef[i] != lf.matrix[i][131])
		   printf("ERROR: %d != %d at %d\n", osef[i], lf.matrix[i][131], i);
	}
	printm(lf);
	Pivot_Gauss(lf);
	
	free_matrix(lf);
	free_reg(reg1);
	free_reg(reg2);
	free_reg(reg3);
	free(osef1);
	free(osef2);
	free(osef);
	
	return 0;
}
