#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_transpose_test_1) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 3, cols = 0, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 0, cols = 3, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = -1, cols = -1, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 1, cols = 1, res = -1, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  input_matr.matrix[0][0] = 7;

  expected_matr.matrix[0][0] = 7;

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 2, cols = 2, res = -1, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  input_matr.matrix[0][0] = 7;
  input_matr.matrix[0][1] = -2;
  input_matr.matrix[1][0] = 3;
  input_matr.matrix[1][1] = 4;

  expected_matr.matrix[0][0] = 7;
  expected_matr.matrix[0][1] = 3;
  expected_matr.matrix[1][0] = -2;
  expected_matr.matrix[1][1] = 4;

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      ck_assert_double_eq_tol(res_matr.matrix[i][j], expected_matr.matrix[i][j],
                              EPS);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

START_TEST(s21_transpose_test_6) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, res = -1, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  input_matr.matrix[0][0] = -9.43449;
  input_matr.matrix[0][1] = 7.38381;
  input_matr.matrix[0][2] = 7.57479;
  input_matr.matrix[1][0] = 6.47325;
  input_matr.matrix[1][1] = -2.01032;
  input_matr.matrix[1][2] = 3.36959;
  input_matr.matrix[2][0] = 6.23061;
  input_matr.matrix[2][1] = 9.24571;
  input_matr.matrix[2][2] = 5.53338;

  expected_matr.matrix[0][0] = -9.43449;
  expected_matr.matrix[0][1] = 6.47325;
  expected_matr.matrix[0][2] = 6.23061;
  expected_matr.matrix[1][0] = 7.38381;
  expected_matr.matrix[1][1] = -2.01032;
  expected_matr.matrix[1][2] = 9.24571;
  expected_matr.matrix[2][0] = 7.57479;
  expected_matr.matrix[2][1] = 3.36959;
  expected_matr.matrix[2][2] = 5.53338;

  res = s21_transpose(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      ck_assert_double_eq_tol(res_matr.matrix[i][j], expected_matr.matrix[i][j],
                              EPS);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

Suite *s21_transpose_suite_create() {
  Suite *suite = suite_create("s21_transpose_test");
  TCase *tc_core = tcase_create("tcase_core_s21_transpose_test");

  tcase_add_test(tc_core, s21_transpose_test_1);
  tcase_add_test(tc_core, s21_transpose_test_2);
  tcase_add_test(tc_core, s21_transpose_test_3);
  tcase_add_test(tc_core, s21_transpose_test_4);
  tcase_add_test(tc_core, s21_transpose_test_5);
  tcase_add_test(tc_core, s21_transpose_test_6);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_transpose_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
