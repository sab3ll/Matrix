#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_determinant_test_1) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = -1, cols = -1, res = -1, expected_code = ERROR_INPUT;
  double det = 0;
  s21_create_matrix(rows, cols, &input_matr);

  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 3, cols = 0, res = -1, expected_code = ERROR_INPUT;
  double det = 0;
  s21_create_matrix(rows, cols, &input_matr);

  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 0, cols = 4, res = -1, expected_code = ERROR_INPUT;
  double det = 0;
  s21_create_matrix(rows, cols, &input_matr);

  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 2, cols = 4, res = -1, expected_code = ERROR_CALC;
  double det = 0;
  s21_create_matrix(rows, cols, &input_matr);

  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 6, cols = 3, res = -1, expected_code = ERROR_CALC;
  double det = 0;
  s21_create_matrix(rows, cols, &input_matr);

  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 1, cols = 1, res = -1, expected_code = OK;
  double det = 0, expected_det = 5;
  s21_create_matrix(rows, cols, &input_matr);

  input_matr.matrix[0][0] = 5;
  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);
  ck_assert_double_eq_tol(det, expected_det, EPS);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_7) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 2, cols = 2, res = -1, expected_code = OK;
  double det = 0, expected_det = -138;
  s21_create_matrix(rows, cols, &input_matr);

  input_matr.matrix[0][0] = 6;
  input_matr.matrix[0][1] = 12;
  input_matr.matrix[1][0] = 19;
  input_matr.matrix[1][1] = 15;
  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);
  ck_assert_double_eq_tol(det, expected_det, EPS);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_8) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 2, cols = 2, res = -1, expected_code = OK;
  double det = 0, expected_det = 84;
  s21_create_matrix(rows, cols, &input_matr);

  input_matr.matrix[0][0] = -12;
  input_matr.matrix[0][1] = 0;
  input_matr.matrix[1][0] = 5;
  input_matr.matrix[1][1] = -7;
  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);
  ck_assert_double_eq_tol(det, expected_det, EPS);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_9) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, res = -1, expected_code = OK;
  double det = 0, expected_det = -1260;
  s21_create_matrix(rows, cols, &input_matr);

  input_matr.matrix[0][0] = 3;
  input_matr.matrix[0][1] = 2;
  input_matr.matrix[0][2] = 17;
  input_matr.matrix[1][0] = 18;
  input_matr.matrix[1][1] = 20;
  input_matr.matrix[1][2] = 11;
  input_matr.matrix[2][0] = 13;
  input_matr.matrix[2][1] = 10;
  input_matr.matrix[2][2] = 6;
  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);
  ck_assert_double_eq_tol(det, expected_det, EPS);

  s21_remove_matrix(&input_matr);
}
END_TEST

START_TEST(s21_determinant_test_10) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 3, cols = 3, res = -1, expected_code = OK;
  double det = 0, expected_det = -373;
  s21_create_matrix(rows, cols, &input_matr);

  input_matr.matrix[0][0] = -5;
  input_matr.matrix[0][1] = 0;
  input_matr.matrix[0][2] = -12;
  input_matr.matrix[1][0] = -4;
  input_matr.matrix[1][1] = -7;
  input_matr.matrix[1][2] = -19;
  input_matr.matrix[2][0] = 0;
  input_matr.matrix[2][1] = -1;
  input_matr.matrix[2][2] = -12;
  res = s21_determinant(&input_matr, &det);
  ck_assert_int_eq(res, expected_code);
  ck_assert_double_eq_tol(det, expected_det, EPS);

  s21_remove_matrix(&input_matr);
}
END_TEST

Suite *s21_determinant_suite_create() {
  Suite *suite = suite_create("s21_determinant_test");
  TCase *tc_core = tcase_create("tcase_core_s21_determinant_test");

  tcase_add_test(tc_core, s21_determinant_test_1);
  tcase_add_test(tc_core, s21_determinant_test_2);
  tcase_add_test(tc_core, s21_determinant_test_3);
  tcase_add_test(tc_core, s21_determinant_test_4);
  tcase_add_test(tc_core, s21_determinant_test_5);
  tcase_add_test(tc_core, s21_determinant_test_6);
  tcase_add_test(tc_core, s21_determinant_test_7);
  tcase_add_test(tc_core, s21_determinant_test_8);
  tcase_add_test(tc_core, s21_determinant_test_9);
  tcase_add_test(tc_core, s21_determinant_test_10);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_determinant_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
