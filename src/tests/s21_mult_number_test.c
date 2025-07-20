#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_mult_number_test_1) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 0, cols = 0, mult = 2, res = 0, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  res = s21_mult_number(&input_matr, mult, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int mult = 2, res = 0, expected_code = ERROR_INPUT;

  res = s21_mult_number(&input_matr, mult, &res_matr);
  ck_assert_int_eq(res, expected_code);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 5, cols = 1, mult = 2, res = 0, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      input_matr.matrix[i][j] = 2 * i;
      expected_matr.matrix[i][j] = 2 * i * mult;
    }
  }
  res = s21_mult_number(&input_matr, mult, &res_matr);
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

START_TEST(s21_mult_number_test_4) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, mult = 2, res = 0, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      input_matr.matrix[i][j] = 2 * i;
      expected_matr.matrix[i][j] = 2 * i * mult;
    }
  }
  res = s21_mult_number(&input_matr, mult, &res_matr);
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

START_TEST(s21_mult_number_test_5) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 1, cols = 5, mult = -3, res = 0, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      input_matr.matrix[i][j] = 2 * i;
      expected_matr.matrix[i][j] = 2 * i * mult;
    }
  }
  res = s21_mult_number(&input_matr, mult, &res_matr);
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

Suite *s21_mult_number_suite_create() {
  Suite *suite = suite_create("s21_mult_number_test");
  TCase *tc_core = tcase_create("tcase_core_s21_mult_number_test");

  tcase_add_test(tc_core, s21_mult_number_test_1);
  tcase_add_test(tc_core, s21_mult_number_test_2);
  tcase_add_test(tc_core, s21_mult_number_test_3);
  tcase_add_test(tc_core, s21_mult_number_test_4);
  tcase_add_test(tc_core, s21_mult_number_test_5);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_mult_number_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
