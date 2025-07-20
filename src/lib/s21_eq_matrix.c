#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns || s21_check_matrix(A) ||
      s21_check_matrix(B))
    code = FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
          code = FAILURE;
          break;
        }
      }
    }
  }
  return code;
}
