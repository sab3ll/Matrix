#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (s21_check_matrix(A))
    code = ERROR_INPUT;
  else if (A->rows != A->columns)
    code = ERROR_CALC;
  else {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (determinant == 0)
      code = ERROR_CALC;
    else {
      matrix_t matr_alebgr_compl = {NULL, 0, 0},
               matr_alebgr_compl_transposed = {NULL, 0, 0};
      s21_calc_complements(A, &matr_alebgr_compl);
      s21_transpose(&matr_alebgr_compl, &matr_alebgr_compl_transposed);
      s21_mult_number(&matr_alebgr_compl_transposed, 1.0 / determinant, result);
      s21_remove_matrix(&matr_alebgr_compl);
      s21_remove_matrix(&matr_alebgr_compl_transposed);
    }
  }
  return code;
}
