#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (s21_check_matrix(A) || s21_check_matrix(B))
    code = ERROR_INPUT;
  else if ((A->columns != B->columns) || (A->rows != B->rows)) {
    code = ERROR_CALC;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return code;
}
