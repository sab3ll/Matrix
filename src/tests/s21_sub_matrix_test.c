#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_sub_matrix_test_test_1) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 0, rows_2 = 2, cols_2 = 2, res = -1,
      expected_code = ERROR_INPUT;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_2) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 2, rows_2 = 3, cols_2 = 0, res = -1,
      expected_code = ERROR_INPUT;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_3) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 3, rows_2 = 3, cols_2 = -1, res = -1,
      expected_code = ERROR_INPUT;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_4) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = -1, cols_1 = 3, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = ERROR_INPUT;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_5) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 3, rows_2 = 3, cols_2 = 2, res = -1,
      expected_code = ERROR_CALC;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_6) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 3, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = ERROR_CALC;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_7) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows_1 = 2, cols_1 = 2, rows_2 = 2, cols_2 = 2, res = -1,
      expected_code = OK;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);
  s21_create_matrix(rows_1, cols_2, &expected_matr);

  input_matr_1.matrix[0][0] = 7;
  input_matr_1.matrix[0][1] = -2;
  input_matr_1.matrix[1][0] = 3;
  input_matr_1.matrix[1][1] = 4;

  input_matr_2.matrix[0][0] = -2;
  input_matr_2.matrix[0][1] = -11;
  input_matr_2.matrix[1][0] = -4;
  input_matr_2.matrix[1][1] = 3;

  expected_matr.matrix[0][0] = 9;
  expected_matr.matrix[0][1] = 9;
  expected_matr.matrix[1][0] = 7;
  expected_matr.matrix[1][1] = 1;

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows_1; ++i)
    for (int j = 0; j < cols_1; ++j)
      ck_assert_double_eq_tol(res_matr.matrix[i][j], expected_matr.matrix[i][j],
                              EPS);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

START_TEST(s21_sub_matrix_test_test_8) {
  matrix_t input_matr_1 = {NULL, 0, 0};
  matrix_t input_matr_2 = {NULL, 0, 0};
  matrix_t res_matr = {NULL, 0, 0};
  matrix_t expected_matr = {NULL, 0, 0};
  int rows_1 = 3, cols_1 = 3, rows_2 = 3, cols_2 = 3, res = -1,
      expected_code = OK;
  s21_create_matrix(rows_1, cols_1, &input_matr_1);
  s21_create_matrix(rows_2, cols_2, &input_matr_2);
  s21_create_matrix(rows_1, cols_1, &res_matr);
  s21_create_matrix(rows_1, cols_2, &expected_matr);

  input_matr_1.matrix[0][0] = -9.43449;
  input_matr_1.matrix[0][1] = 7.38381;
  input_matr_1.matrix[0][2] = 7.57479;
  input_matr_1.matrix[1][0] = 6.47325;
  input_matr_1.matrix[1][1] = -2.01032;
  input_matr_1.matrix[1][2] = 3.36959;
  input_matr_1.matrix[2][0] = 6.23061;
  input_matr_1.matrix[2][1] = 9.24571;
  input_matr_1.matrix[2][2] = 5.53338;

  input_matr_2.matrix[0][0] = 1.78014;
  input_matr_2.matrix[0][1] = 0.01543;
  input_matr_2.matrix[0][2] = 3.24690;
  input_matr_2.matrix[1][0] = 2.12215;
  input_matr_2.matrix[1][1] = -2.28001;
  input_matr_2.matrix[1][2] = 9.00547;
  input_matr_2.matrix[2][0] = 8.23701;
  input_matr_2.matrix[2][1] = 8.15880;
  input_matr_2.matrix[2][2] = -4.54863;

  expected_matr.matrix[0][0] = -11.21463;
  expected_matr.matrix[0][1] = 7.36838;
  expected_matr.matrix[0][2] = 4.32789;
  expected_matr.matrix[1][0] = 4.3511;
  expected_matr.matrix[1][1] = 0.26969;
  expected_matr.matrix[1][2] = -5.63588;
  expected_matr.matrix[2][0] = -2.0064;
  expected_matr.matrix[2][1] = 1.08691;
  expected_matr.matrix[2][2] = 10.08201;

  res = s21_sub_matrix(&input_matr_1, &input_matr_2, &res_matr);
  ck_assert_int_eq(res, expected_code);

  for (int i = 0; i < rows_1; ++i)
    for (int j = 0; j < cols_1; ++j)
      ck_assert_double_eq_tol(res_matr.matrix[i][j], expected_matr.matrix[i][j],
                              EPS);

  s21_remove_matrix(&input_matr_1);
  s21_remove_matrix(&input_matr_2);
  s21_remove_matrix(&res_matr);
  s21_remove_matrix(&expected_matr);
}
END_TEST

Suite *s21_sub_matrix_test_suite_create() {
  Suite *suite = suite_create("s21_sub_matrix_test_test");
  TCase *tc_core = tcase_create("tcase_core_s21_sub_matrix_test_test");

  tcase_add_test(tc_core, s21_sub_matrix_test_test_1);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_2);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_3);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_4);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_5);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_6);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_7);
  tcase_add_test(tc_core, s21_sub_matrix_test_test_8);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_sub_matrix_test_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
