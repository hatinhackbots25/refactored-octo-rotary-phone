#include "gauss.h"

void Pivot_Gauss(Matrix m){
	/*int r = 0;
	  int j,i, max, k;
	  for(j = 0; j < m.col; j++){
	  max = 0;
	  for( i = r; i < m.row; i++){
	  if(m.matrix[i][j] > max){
	  max = m.matrix[i][j];
	  k = i;
	  }
	  /* k est la position du pivot */
	/*}
	  /*printf("K = %d\n", k);*/
	/*if(m.matrix[k][j] != 0){
	  /*r++;*/
	/* division par 1 inutile */
	/* echange de ligne */
	/*int tmp;
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
	/*for(i = 0; i < m.row; i++){
	  if(i != r){
	  /* soustraction à ligne i de r times matrix[i][j]*/
	/*int fact = m.matrix[i][j];
	  for(j_tmp = 0; j_tmp < m.col; j_tmp++)
	  m.matrix[i][j_tmp] -= m.matrix[r][j_tmp]*fact;
	  }
	  }
	  /*printm(m);
	  printf("======================================\n");*/
	/*r++;
	  }
	  }*/
	
	int i,j,k,n;
    float c,x[150],sum=0.0;
	n = m.col - 1;
    
    for(j = 0; j < n; j++){
		for(i = 0; i < n; i++){
			if(i > j){
				if(m.matrix[j][j] > 0){
					c = m.matrix[i][j]/m.matrix[j][j];
				}
				for(k = 0; k < n+1; k++){
					m.matrix[i][k] = m.matrix[i][k]- c*m.matrix[j][k];
				}
			}
		}
	}
	int col = n - 1;
	
    x[col]=m.matrix[col][col+1]/m.matrix[col][col];
    /* this loop is for backward substitution*/
    for(i=col-1; i>=0; i--){
		sum=0;
		for(j=i+1; j<=col; j++){
			sum=sum+m.matrix[i][j]*x[j];
		}
		x[i]=(m.matrix[i][n]-sum)/m.matrix[i][i];
	}
    printf("\nThe solution is: \n");
    for(i=0; i<n; i++){
		printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
	}
	printf("\n");
}
