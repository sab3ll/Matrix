#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (s21_check_matrix(A))
    code = ERROR_INPUT;
  else if (A->columns != A->rows)
    code = ERROR_CALC;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor_determinant = 0;
        matrix_t minor_matr = {NULL, 0, 0};
        s21_calc_minor(A, i, j, &minor_matr);
        s21_determinant(&minor_matr, &minor_determinant);
        result->matrix[i][j] = minor_determinant * pow(-1, i + j);
        s21_remove_matrix(&minor_matr);
      }
    }
  }
  return code;
}
