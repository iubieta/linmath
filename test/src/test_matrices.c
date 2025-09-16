# include "../../src/linmath.h"
# include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <math.h>
#include <stdio.h>

Test(Matrix, set_2x2) {
	t_matrix matrix;
	float values[4] = {0.1, 0.2, 0.3, 0.4};

	matrix = matrix_set_2x2(values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(isnan(matrix.value[0][2]) == true);
	cr_expect(isnan(matrix.value[0][3]) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.3) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.4) == true);
	cr_expect(isnan(matrix.value[1][2]) == true);
	cr_expect(isnan(matrix.value[1][3]) == true);

	cr_expect(isnan(matrix.value[2][0]) == true);
	cr_expect(isnan(matrix.value[2][1]) == true);
	cr_expect(isnan(matrix.value[2][2]) == true);
	cr_expect(isnan(matrix.value[2][3]) == true);

	cr_expect(isnan(matrix.value[3][0]) == true);
	cr_expect(isnan(matrix.value[3][1]) == true);
	cr_expect(isnan(matrix.value[3][2]) == true);
	cr_expect(isnan(matrix.value[3][3]) == true);
}

Test(Matrix, set_3x3) {
	t_matrix matrix;
	float values[9] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

	matrix = matrix_set_3x3(values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(float_eq(matrix.value[0][2], 0.3) == true);
	cr_expect(isnan(matrix.value[0][3]) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.4) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.5) == true);
	cr_expect(float_eq(matrix.value[1][2], 0.6) == true);
	cr_expect(isnan(matrix.value[1][3]) == true);

	cr_expect(float_eq(matrix.value[2][0], 0.7) == true);
	cr_expect(float_eq(matrix.value[2][1], 0.8) == true);
	cr_expect(float_eq(matrix.value[2][2], 0.9) == true);
	cr_expect(isnan(matrix.value[2][3]) == true);

	cr_expect(isnan(matrix.value[3][0]) == true);
	cr_expect(isnan(matrix.value[3][1]) == true);
	cr_expect(isnan(matrix.value[3][2]) == true);
	cr_expect(isnan(matrix.value[3][3]) == true);
}

Test(Matrix, set_4x4) {
	t_matrix matrix;
	float values[16] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 
		0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16};

	matrix = matrix_set_4x4(values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(float_eq(matrix.value[0][2], 0.3) == true);
	cr_expect(float_eq(matrix.value[0][3], 0.4) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.5) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.6) == true);
	cr_expect(float_eq(matrix.value[1][2], 0.7) == true);
	cr_expect(float_eq(matrix.value[1][3], 0.8) == true);

	cr_expect(float_eq(matrix.value[2][0], 0.9) == true);
	cr_expect(float_eq(matrix.value[2][1], 0.10) == true);
	cr_expect(float_eq(matrix.value[2][2], 0.11) == true);
	cr_expect(float_eq(matrix.value[2][3], 0.12) == true);

	cr_expect(float_eq(matrix.value[3][0], 0.13) == true);
	cr_expect(float_eq(matrix.value[3][1], 0.14) == true);
	cr_expect(float_eq(matrix.value[3][2], 0.15) == true);
	cr_expect(float_eq(matrix.value[3][3], 0.16) == true);
}
