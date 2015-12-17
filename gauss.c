#include "gauss.h"

void Pivot_Gauss(Matrix m){
	int r = 0;
	int j,i, max, k;
	for(j = 0; j < m.col; j++){
		max = 0;
		for( i = r; i < m.row; i++){
			if(m.matrix[i][j] > max){
				max = m.matrix[i][j];
				k = i;
			}
			/* k est la position du pivot */
		}
		/*printf("K = %d\n", k);*/
		if(m.matrix[k][j] != 0){
			/*r++;*/
			/* division par 1 inutile */
			/* echange de ligne */
			int tmp;
			int i_tmp, j_tmp;
			if(r != k){
				for(j_tmp = 0; j_tmp < m.col; j_tmp++){
					tmp = m.matrix[r][j_tmp];
					m.matrix[r][j_tmp] = m.matrix[k][j_tmp];
					m.matrix[k][j_tmp] = tmp;
				}
			}
			/*printm(m);
			  printf("======================================\n");*/
			for(i = 0; i < m.row; i++){
				if(i != r){
					/* soustraction à ligne i de r times matrix[i][j]*/
					int fact = m.matrix[i][j];
					for(j_tmp = 0; j_tmp < m.col; j_tmp++)
						m.matrix[i][j_tmp] -= m.matrix[r][j_tmp]*fact;
				}
			}
			/*printm(m);
			  printf("======================================\n");*/
			r++;
		}
	}
}
