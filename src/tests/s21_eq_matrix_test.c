#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_eq_matrix_test_1) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 1, rows_2 = 1, cols_2 = 2, res = -1,
      expected_code = FAILURE;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 2, rows_2 = 1, cols_2 = 2, res = -1,
      expected_code = FAILURE;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 1, rows_2 = 2, cols_2 = 2, res = -1,
      expected_code = FAILURE;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 2, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = FAILURE;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 2, rows_2 = 2, cols_2 = 2, res = -1,
      expected_code = SUCCESS;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  input_matr_1.matrix[0][0] = -12;
  input_matr_1.matrix[0][1] = 0;
  input_matr_1.matrix[1][0] = 5;
  input_matr_1.matrix[1][1] = -7;

  input_matr_2.matrix[0][0] = -12;
  input_matr_2.matrix[0][1] = 0;
  input_matr_2.matrix[1][0] = 5;
  input_matr_2.matrix[1][1] = -7;

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows_1; ++i)
    for (int j = 0; j < cols_1; ++j)
      ck_assert_double_eq_tol(input_matr_1.matrix[i][j],
                              input_matr_2.matrix[i][j], EPS);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 3, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = SUCCESS;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  input_matr_1.matrix[0][0] = -5;
  input_matr_1.matrix[0][1] = 0;
  input_matr_1.matrix[0][2] = -12;
  input_matr_1.matrix[1][0] = -4;
  input_matr_1.matrix[1][1] = -7;
  input_matr_1.matrix[1][2] = -19;
  input_matr_1.matrix[2][0] = 0;
  input_matr_1.matrix[2][1] = -1;
  input_matr_1.matrix[2][2] = -12;

  input_matr_2.matrix[0][0] = -5;
  input_matr_2.matrix[0][1] = 0;
  input_matr_2.matrix[0][2] = -12;
  input_matr_2.matrix[1][0] = -4;
  input_matr_2.matrix[1][1] = -7;
  input_matr_2.matrix[1][2] = -19;
  input_matr_2.matrix[2][0] = 0;
  input_matr_2.matrix[2][1] = -1;
  input_matr_2.matrix[2][2] = -12;

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows_1; ++i)
    for (int j = 0; j < cols_1; ++j)
      ck_assert_double_eq_tol(input_matr_1.matrix[i][j],
                              input_matr_2.matrix[i][j], EPS);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 3, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = FAILURE;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);

  input_matr_1.matrix[0][0] = 5;
  input_matr_1.matrix[0][1] = 0;
  input_matr_1.matrix[0][2] = -12;
  input_matr_1.matrix[1][0] = -4;
  input_matr_1.matrix[1][1] = -7;
  input_matr_1.matrix[1][2] = -19;
  input_matr_1.matrix[2][0] = 0;
  input_matr_1.matrix[2][1] = -1;
  input_matr_1.matrix[2][2] = -12;

  input_matr_2.matrix[0][0] = 4;
  input_matr_2.matrix[0][1] = 0;
  input_matr_2.matrix[0][2] = -12;
  input_matr_2.matrix[1][0] = -4;
  input_matr_2.matrix[1][1] = -7;
  input_matr_2.matrix[1][2] = -19;
  input_matr_2.matrix[2][0] = 0;
  input_matr_2.matrix[2][1] = -1;
  input_matr_2.matrix[2][2] = -12;

  res = s21_eq_matrix(&input_matr_1, &input_matr_2);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
}
END_TEST

Suite *s21_eq_matrix_suite_create() {
  Suite *suite = suite_create("s21_eq_matrix_test");
  TCase *tc_core = tcase_create("tcase_core_s21_eq_matrix_test");

  tcase_add_test(tc_core, s21_eq_matrix_test_1);
  tcase_add_test(tc_core, s21_eq_matrix_test_2);
  tcase_add_test(tc_core, s21_eq_matrix_test_3);
  tcase_add_test(tc_core, s21_eq_matrix_test_4);
  tcase_add_test(tc_core, s21_eq_matrix_test_5);
  tcase_add_test(tc_core, s21_eq_matrix_test_6);
  tcase_add_test(tc_core, s21_eq_matrix_test_7);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_eq_matrix_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
