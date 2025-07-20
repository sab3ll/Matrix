#include <time.h>

#include "s21_matrix.h"

void s21_rand_matrix(matrix_t *A) {
  srand(time(NULL));
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++)
      A->matrix[i][j] = -10.0 + ((double)rand() / RAND_MAX) * 20.0;
  }
}

/* void s21_print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) printf("% .7lf", A->matrix[i][j]);
    printf("\n\n");
  }
} */

int main() {
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  matrix_t matrix_res = {NULL, 0, 0};
  double det = 0.0;

  // s21_calc_complements

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        if (!s21_calc_complements(&matrix_1, &matrix_res)) {
          s21_remove_matrix(&matrix_1);
          s21_remove_matrix(&matrix_res);
        } else
          s21_remove_matrix(&matrix_1);
      }
    }
  }

  // s21_create_matrix  s21_remove_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        s21_remove_matrix(&matrix_1);
      }
    }
  }

  // s21_determinant

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        s21_determinant(&matrix_1, &det);
        s21_remove_matrix(&matrix_1);
      }
    }
  }

  // s21_eq_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      for (int m = -1; m < 5; m++) {
        for (int n = -1; n < 5; n++) {
          if (!s21_create_matrix(i, j, &matrix_1)) {
            if (!s21_create_matrix(m, n, &matrix_2)) {
              s21_rand_matrix(&matrix_1);
              s21_rand_matrix(&matrix_2);
              s21_eq_matrix(&matrix_1, &matrix_2);
              s21_remove_matrix(&matrix_1);
              s21_remove_matrix(&matrix_2);
            } else {
              s21_remove_matrix(&matrix_1);
              s21_remove_matrix(&matrix_2);
            }
          } else
            s21_remove_matrix(&matrix_1);
        }
      }
    }
  }

  // s21_inverse_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        if (!s21_inverse_matrix(&matrix_1, &matrix_res)) {
          s21_remove_matrix(&matrix_1);
          s21_remove_matrix(&matrix_res);
        } else
          s21_remove_matrix(&matrix_1);
      } else
        s21_remove_matrix(&matrix_1);
    }
  }

  // s21_mult_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      for (int m = -1; m < 5; m++) {
        for (int n = -1; n < 5; n++) {
          if (!s21_create_matrix(i, j, &matrix_1)) {
            if (!s21_create_matrix(m, n, &matrix_2)) {
              s21_rand_matrix(&matrix_1);
              s21_rand_matrix(&matrix_2);
              if (!s21_mult_matrix(&matrix_1, &matrix_2, &matrix_res)) {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
                s21_remove_matrix(&matrix_res);
              } else {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
              }
            } else {
              s21_remove_matrix(&matrix_1);
              s21_remove_matrix(&matrix_2);
            }
          } else
            s21_remove_matrix(&matrix_1);
        }
      }
    }
  }

  // s21_mult_number

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        double number = -10.0 + ((double)rand() / RAND_MAX) * 20.0;
        s21_mult_number(&matrix_1, number, &matrix_res);
        s21_remove_matrix(&matrix_1);
        s21_remove_matrix(&matrix_res);
      } else
        s21_remove_matrix(&matrix_1);
    }
  }

  // s21_sub_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      for (int m = -1; m < 5; m++) {
        for (int n = -1; n < 5; n++) {
          if (!s21_create_matrix(i, j, &matrix_1)) {
            if (!s21_create_matrix(m, n, &matrix_2)) {
              s21_rand_matrix(&matrix_1);
              s21_rand_matrix(&matrix_2);
              if (!s21_sub_matrix(&matrix_1, &matrix_2, &matrix_res)) {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
                s21_remove_matrix(&matrix_res);
              } else {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
              }
            } else {
              s21_remove_matrix(&matrix_1);
              s21_remove_matrix(&matrix_2);
            }
          } else
            s21_remove_matrix(&matrix_1);
        }
      }
    }
  }

  // s21_sum_matrix

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      for (int m = -1; m < 5; m++) {
        for (int n = -1; n < 5; n++) {
          if (!s21_create_matrix(i, j, &matrix_1)) {
            if (!s21_create_matrix(m, n, &matrix_2)) {
              s21_rand_matrix(&matrix_1);
              s21_rand_matrix(&matrix_2);
              if (!s21_sum_matrix(&matrix_1, &matrix_2, &matrix_res)) {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
                s21_remove_matrix(&matrix_res);
              } else {
                s21_remove_matrix(&matrix_1);
                s21_remove_matrix(&matrix_2);
              }
            } else {
              s21_remove_matrix(&matrix_1);
              s21_remove_matrix(&matrix_2);
            }
          } else
            s21_remove_matrix(&matrix_1);
        }
      }
    }
  }

  // s21_transpose

  for (int i = -1; i < 5; i++) {
    for (int j = -1; j < 5; j++) {
      if (!s21_create_matrix(i, j, &matrix_1)) {
        s21_rand_matrix(&matrix_1);
        if (!s21_transpose(&matrix_1, &matrix_res)) {
          s21_remove_matrix(&matrix_1);
          s21_remove_matrix(&matrix_res);
        } else
          s21_remove_matrix(&matrix_1);
      }
    }
  }

  return 0;
}
