#include "matrix.h"

Matrix CreateNewMatrix(int r, int c){
  Matrix mat;
  mat.row = r;
  mat.col = c;
  mat.matrix = (int**)malloc(r * sizeof(int*));
  int i;
  for(i = 0; i < r; i++){
    mat.matrix[i] = (int*)calloc(c, sizeof(int));
  }
  int j;
  for(i=0; i < r; i++){
    for(j=0; j< c; j++){
      mat.matrix[i][j] = j;
    }
  }
  
  return mat;
}

void free_matrix(Matrix mat){
  int i;
  for(i = 0; i < mat.row; i++){
    free(mat.matrix[i]);
  }
  free(mat.matrix);
}

void printm(Matrix mat){
  int x, y;
  for(x = 0; x < mat.row; x++){
    for(y = 0; y < mat.col; y++){
      printf("%d", (mat.matrix[x][y]));
    }
    printf("\n");
  }
}

Matrix times_Matrix(Matrix mat1, Matrix mat2){
  Matrix result = CreateNewMatrix(mat1.row, mat2.col);
  int i,j;
  int n,k,sum;
  for(i = 0; i < result.row; i++){
    for(j = 0; j < result.col; j++){
      sum = 0;
      for(n = 0; n < mat1.col; n++){
	sum += mat1.matrix[i][n] * mat2.matrix[n][j];
      }
      result.matrix[i][j] = sum % 2;
    }
  }
  
  return result;
}


Matrix convert(int r, int c, int mat[r][c]){
  Matrix result = CreateNewMatrix(r,c);
  int i,j;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      result.matrix[i][j] = mat[i][j];
    }
  }
  return result;
}

void copy_Matrix(Matrix mat1, Matrix mat2){
  int i,j;
  for(i = 0; i < mat1.row; i++){
    for(j = 0; j < mat1.col; j++){
      mat2.matrix[i][j] = mat1.matrix[i][j];
    }
  }
}

Matrix random_Matrix(int r, int c){
  Matrix result = CreateNewMatrix(r,c);
  int i,j;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      result.matrix[i][j] = rand() % 2;
    }
  }
  return result;
}

int are_equals(Matrix mat1, Matrix mat2){
  int i,j;
  for(i = 0; i < mat1.row; i++){
    for(j = 0; j < mat1.col; j++){
      if(mat1.matrix[i][j] != mat2.matrix[i][j])
	return 0;
    }
  }
  return 1;
}
