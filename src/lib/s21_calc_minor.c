#include "../s21_matrix.h"

void s21_calc_minor(matrix_t *A, int row, int column, matrix_t *result) {
  s21_create_matrix(A->columns - 1, A->rows - 1, result);
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      if (i < row && j < column)
        result->matrix[i][j] = A->matrix[i][j];
      else if (i > row && j < column)
        result->matrix[i - 1][j] = A->matrix[i][j];
      else if (i < row && j > column)
        result->matrix[i][j - 1] = A->matrix[i][j];
      else if (i > row && j > column)
        result->matrix[i - 1][j - 1] = A->matrix[i][j];
    }
  }
}
