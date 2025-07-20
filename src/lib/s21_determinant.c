#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  *result = 0.0;
  if (s21_check_matrix(A))
    code = ERROR_INPUT;
  else if (A->columns != A->rows)
    code = ERROR_CALC;
  else if (A->rows == 1)
    *result = A->matrix[0][0];
  else if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor_matr = {NULL, 0, 0};
      s21_calc_minor(A, 0, i, &minor_matr);
      double sum = 0.0;
      s21_determinant(&minor_matr, &sum);
      *result += pow(-1, i) * A->matrix[0][i] * sum;
      s21_remove_matrix(&minor_matr);
    }
  }
  return code;
}
