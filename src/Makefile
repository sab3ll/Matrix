CORE=$(shell uname -s | tr '[:upper:]' '[:lower:]')
CLANG_MODE=-i
OPEN_CMD=open
CC=gcc
CFFLAGS=-Wall -Wextra -Werror -std=c11
DEBUG=-g
GLFLAGS=--coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage
SOURCE_FILES=*/*.c *.c *.h
CLANG_PATH=../materials/linters/
CLANG_COPY=cp $(CLANG_PATH).clang-format .clang-format
CLANG_REMOVE=rm .clang-format


ifdef CORE
	ifeq ($(CORE), linux)
		CHECKFLAGS=-pthread -lcheck_pic -lrt -lm -lsubunit -lgsl -lgslcblas
	endif

	ifeq ($(CORE), darwin)
		CHECKFLAGS=$(shell pkg-config --cflags --libs check)
	endif
endif

s21_matrix.a: s21_matrix.o
	ar r s21_matrix.a *.o

s21_matrix.o:
	$(CC) $(CFFLAGS) ./lib/*.c -c

s21_matrix.a_debug:
	$(CC) $(CFFLAGS) $(DEBUG) ./lib/*.c -c
	ar r s21_matrix.a *.o

all: clean s21_matrix.a test

clean: clean_all

clean_common:
	rm -rf *.o
	rm -rf *.gch
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno

clean_tests:
	rm -rf tests/output
	rm -rf tests/report
	rm -rf tests.info

clean_dev:
	rm -rf sandbox
	rm -rf valgrind
	rm -rf valgrind-out.txt

clean_all: clean_common clean_tests clean_dev

test: build_tests run_tests clean_tests

gcov_report: clean_all test run_tests
	lcov -o tests.info -c -d .
	genhtml -o tests/report tests.info
	$(OPEN_CMD) tests/report/index.html

build_tests: clean_all s21_matrix.a
	mkdir tests/output
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_calc_complements_test.c lib/s21_calc_complements.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_calc_complements_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_create_matrix_test.c lib/s21_create_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_create_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_determinant_test.c lib/s21_determinant.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_determinant_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_eq_matrix_test.c lib/s21_eq_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_eq_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_inverse_matrix_test.c lib/s21_inverse_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_inverse_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_mult_matrix_test.c lib/s21_mult_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_mult_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_mult_number_test.c lib/s21_mult_number.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_mult_number_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_remove_matrix_test.c lib/s21_remove_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_remove_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_sub_matrix_test.c lib/s21_sub_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_sub_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_sum_matrix_test.c lib/s21_sum_matrix.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_sum_matrix_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) tests/s21_transpose_test.c lib/s21_transpose.c -L. s21_matrix.a $(CHECKFLAGS) -o ./tests/output/s21_transpose_test

run_tests:
	tests/output/s21_calc_complements_test
	tests/output/s21_create_matrix_test
	tests/output/s21_determinant_test
	tests/output/s21_eq_matrix_test
	tests/output/s21_inverse_matrix_test
	tests/output/s21_mult_matrix_test
	tests/output/s21_mult_number_test
	tests/output/s21_remove_matrix_test
	tests/output/s21_sub_matrix_test
	tests/output/s21_sum_matrix_test
	tests/output/s21_transpose_test

clang:
	$(CLANG_COPY) && clang-format $(CLANG_MODE) $(SOURCE_FILES) && $(CLANG_REMOVE)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --force *.h *.c ./lib/*.c ./tests/*.c

sandbox.o:
	$(CC) $(CFFLAGS) $(DEBUG) ./sandbox.c -c

sandbox: clean
	clear
	make sandbox.o
	make s21_matrix.a_debug
	$(CC) $(CFFLAGS) $(DEBUG) -o sandbox sandbox.o -L. s21_matrix.a -lm

valgrind.o:
	$(CC) $(CFFLAGS) $(DEBUG) ./valgrind.c -c

valgrind_tests: clean_dev
	clear
	make valgrind.o
	make s21_matrix.a_debug
	$(CC) $(CFFLAGS) $(DEBUG) -o valgrind valgrind.o -L. s21_matrix.a -lm

valgrind: valgrind_tests
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./valgrind

valgrind_deep: valgrind_tests
	valgrind --leak-check=full --tool=memcheck --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --show-leak-kinds=all --verbose ./valgrind

valgrind_log: valgrind_tests
	valgrind --leak-check=full --tool=memcheck --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind-out.txt ./valgrind

s: sandbox
	./sandbox

c: clean_all
	make clang
	clear

g: gcov_report
