#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_calc_complements_test_1) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 3, cols = 0, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_calc_complements(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 0, cols = 3, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_calc_complements(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = -1, cols = -1, res = -1, expected_code = ERROR_INPUT;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_calc_complements(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 3, cols = 2, res = -1, expected_code = ERROR_CALC;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_calc_complements(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows = 2, cols = 3, res = -1, expected_code = ERROR_CALC;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);

  res = s21_calc_complements(&input_matr, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, res = -1, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  input_matr.matrix[0][0] = 3;
  input_matr.matrix[0][1] = 2;
  input_matr.matrix[0][2] = 17;
  input_matr.matrix[1][0] = 18;
  input_matr.matrix[1][1] = 20;
  input_matr.matrix[1][2] = 11;
  input_matr.matrix[2][0] = 13;
  input_matr.matrix[2][1] = 10;
  input_matr.matrix[2][2] = 6;

  expected_matr.matrix[0][0] = 10.;
  expected_matr.matrix[0][1] = 35.;
  expected_matr.matrix[0][2] = -80.;
  expected_matr.matrix[1][0] = 158.;
  expected_matr.matrix[1][1] = -203.;
  expected_matr.matrix[1][2] = -4.;
  expected_matr.matrix[2][0] = -318.;
  expected_matr.matrix[2][1] = 273.;
  expected_matr.matrix[2][2] = 24.;

  res = s21_calc_complements(&input_matr, &res_matr);
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

START_TEST(s21_calc_complements_test_7) {
  matrix_t input_matr = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, res = -1, expected_code = OK;
  s21_create_matrix(rows, cols, &input_matr);
  s21_create_matrix(rows, cols, &res_matr);
  s21_create_matrix(rows, cols, &expected_matr);

  input_matr.matrix[0][0] = -5;
  input_matr.matrix[0][1] = 0;
  input_matr.matrix[0][2] = -12;
  input_matr.matrix[1][0] = -4;
  input_matr.matrix[1][1] = -7;
  input_matr.matrix[1][2] = -19;
  input_matr.matrix[2][0] = 0;
  input_matr.matrix[2][1] = -1;
  input_matr.matrix[2][2] = -12;

  expected_matr.matrix[0][0] = 65.;
  expected_matr.matrix[0][1] = -48.;
  expected_matr.matrix[0][2] = 4.;
  expected_matr.matrix[1][0] = 12.;
  expected_matr.matrix[1][1] = 60.;
  expected_matr.matrix[1][2] = -5.;
  expected_matr.matrix[2][0] = -84.;
  expected_matr.matrix[2][1] = -47.;
  expected_matr.matrix[2][2] = 35.;

  res = s21_calc_complements(&input_matr, &res_matr);
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

Suite *s21_calc_complements_suite_create() {
  Suite *suite = suite_create("s21_calc_complements_test");
  TCase *tc_core = tcase_create("tcase_core_s21_calc_complements_test");

  tcase_add_test(tc_core, s21_calc_complements_test_1);
  tcase_add_test(tc_core, s21_calc_complements_test_2);
  tcase_add_test(tc_core, s21_calc_complements_test_3);
  tcase_add_test(tc_core, s21_calc_complements_test_4);
  tcase_add_test(tc_core, s21_calc_complements_test_5);
  tcase_add_test(tc_core, s21_calc_complements_test_6);
  tcase_add_test(tc_core, s21_calc_complements_test_7);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_calc_complements_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
