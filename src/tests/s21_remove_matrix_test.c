#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define SHOW_FAILED TRUE

START_TEST(s21_remove_matrix_test_1) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 0, cols = 0;

  s21_create_matrix(rows, cols, &input_matr);
  s21_remove_matrix(&input_matr);
  s21_remove_matrix(&input_matr);

  ck_assert_ptr_eq(input_matr.matrix, NULL);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 0, cols = 0;

  s21_create_matrix(rows, cols, &input_matr);
  s21_remove_matrix(&input_matr);

  ck_assert_ptr_eq(input_matr.matrix, NULL);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 1, cols = 1;

  s21_create_matrix(rows, cols, &input_matr);
  input_matr.matrix[0][0] = 10;
  s21_remove_matrix(&input_matr);

  ck_assert_ptr_eq(input_matr.matrix, NULL);
}
END_TEST

START_TEST(s21_remove_matrix_test_4) {
  matrix_t input_matr = {NULL, 0, 0};
  int rows = 2, cols = 2;

  s21_create_matrix(rows, cols, &input_matr);
  input_matr.matrix[0][0] = 7;
  input_matr.matrix[0][1] = -1;
  input_matr.matrix[1][0] = 2;
  input_matr.matrix[1][1] = 5;
  s21_remove_matrix(&input_matr);

  ck_assert_ptr_eq(input_matr.matrix, NULL);
}
END_TEST

Suite *s21_remove_matrix_suite_create() {
  Suite *suite = suite_create("s21_remove_matrix_test");
  TCase *tc_core = tcase_create("tcase_core_s21_remove_matrix_test");

  tcase_add_test(tc_core, s21_remove_matrix_test_1);
  tcase_add_test(tc_core, s21_remove_matrix_test_2);
  tcase_add_test(tc_core, s21_remove_matrix_test_3);
  tcase_add_test(tc_core, s21_remove_matrix_test_4);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_remove_matrix_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
