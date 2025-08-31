/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:34:12 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/31 00:47:12 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <float.h>
#include <math.h>
#include "../../src/linmath.h"

void expect_tuple_eq(t_tuple a, t_tuple b, char *flag, int i) {
	cr_expect(float_eq(a.x, b.x), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_expect(float_eq(a.y, b.y), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	cr_expect(float_eq(a.z, b.z), "%s %i: expected z:%f, returned z:%f.", flag, i, b.z, a.z);
	cr_expect(float_eq(a.w, b.w), "%s %i: expected w:%f, returned w:%f.", flag, i, b.w, a.w);
}

void assert_tuple_eq(t_tuple a, t_tuple b, char *flag, int i) {
	cr_assert(float_eq(a.x, b.x), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_assert(float_eq(a.y, b.y), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	cr_assert(float_eq(a.z, b.z), "%s %i: expected z:%f, returned z:%f.", flag, i, b.z, a.z);
	cr_assert(float_eq(a.w, b.w), "%s %i: expected w:%f, returned w:%f.", flag, i, b.w, a.w);
}

Test(tuples, tuple_to_4f_array) {
	t_tuple t;
	float	ar[4];

	t.x = 0;
	t.y = 0;
	t.z = 0;
	t.w = 0;
	tuple_to_array(t, ar);
	for (int i = 0; i < 4; i++)
		cr_expect(ar[i] == 0, "Expected: %i\tReturned: %f",-i, ar[i]);

	t.x = 1;
	t.y = 2;
	t.z = 3;
	t.w = 4;
	tuple_to_array(t, ar);
	for (int i = 0; i < 4; i++)
		cr_expect(ar[i] == 1 + i, "Expected: %i\tReturned: %f",-i, ar[i]);

	t.x = -1;
	t.y = -2;
	t.z = -3;
	t.w = -4;
	tuple_to_array(t, ar);
	for (int i = 0; i < 4; i++)
		cr_expect(ar[i] == 0 - 1 - i, "Expected: %i\tReturned: %f",-i, ar[i]);

	t.x = 0.000001;
	t.y = 0.000001;
	t.z = 0.000001;
	t.w = 0.000001;
	tuple_to_array(t, ar);
	for (int i = 0; i < 4; i++)
		cr_expect(float_eq(ar[i], 0.000001), "Expected: %f\tReturned: %f",0.000001, ar[i]);
}

Test(tuples, equals) {
	char *flag = "Equals";
	int i = 1;
	
	t_tuple	a;
	t_tuple b;
	int	ret;
	int	expec;
	
	a = tuple_set(0, 0, 0, 0);
	b = tuple_set(0.00000, 0.00000, 0.00000, 0.00000);
	ret = tuple_eq(a, b);
	expec = 1;
	expect_tuple_eq(a, b, flag, i++);
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(0, 0, 0, 0);
	b = tuple_set(0.00001, 0.00001, 0.00001, 0.00001);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);

	a = tuple_set(0.00001, 0.00001, 0.00001, 0.00001);
	b = tuple_set(0.00001, 0.00001, 0.00001, 0.00001);
	ret = tuple_eq(a, b);
	expec = 1;
	expect_tuple_eq(a, b, flag, i++);
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(FLT_MIN, FLT_MAX, -FLT_MIN, -FLT_MAX);
	b = tuple_set(FLT_MIN, FLT_MAX, -FLT_MIN, -FLT_MAX);
	ret = tuple_eq(a, b);
	expec = 1;
	expect_tuple_eq(a, b, flag, i++);
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(FLT_MIN, FLT_MAX, -FLT_MIN, -FLT_MAX);
	b = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(INFINITY, -INFINITY, NAN, -NAN);
	b = tuple_set(INFINITY, -INFINITY, NAN, -NAN);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(float_eq(a.x, b.x), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_expect(float_eq(a.y, b.y), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	cr_expect(isnan(a.z), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.z);
	cr_expect(isnan(a.w), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.w);
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);

	a = tuple_set(INFINITY, -INFINITY, NAN, -NAN);
	b = tuple_set(-INFINITY, INFINITY, -NAN, NAN);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(!float_eq(a.x, b.x), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_expect(!float_eq(a.y, b.y), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	cr_expect(isnan(a.z), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.z);
	cr_expect(isnan(a.w), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.w);
	cr_assert(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);

}

Test(tuples, point) {
	t_tuple	p;
	t_tuple check;
	char *flag = "Point:";
	int i = 1;

	p = tuple_point(0,0,0);
	check = tuple_set(0,0,0,1);
	expect_tuple_eq(p, check, flag, i++);

	p = tuple_point(0.01,0.01,0.01);
	check = tuple_set(0.01,0.01,0.01,1);
	expect_tuple_eq(p, check, flag, i++);
}

Test(tuples, vector) {
	t_tuple	v;
	t_tuple check;
	char *flag = "Vector:";
	int i = 1;

	v = tuple_vector(0,0,0);
	check = tuple_set(0,0,0,0);
	expect_tuple_eq(v, check, flag, i++);

	v = tuple_vector(0.01,0.01,0.01);
	check = tuple_set(0.01,0.01,0.01,0);
	expect_tuple_eq(v, check, flag, i++);
}

Test(tuples, is_point) {
	char *flag = "Is point:";
	int i = 1;
	
	t_tuple a;
	int	ret;
	int	expec;
	
	a = tuple_set(0,0,0,0);
	ret = tuple_is_point(a);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);

	a = tuple_set(0,0,0,1);
	ret = tuple_is_point(a);
	expec = 1;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
}

Test(tuples, is_vector) {
	char *flag = "Is vector:";
	int i = 1;
	
	t_tuple a;
	int	ret;
	int	expec;
	
	a = tuple_set(0,0,0,0);
	ret = tuple_is_vector(a);
	expec = 1;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);

	a = tuple_set(0,0,0,1);
	ret = tuple_is_vector(a);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
}

Test(tuples, add) {
	char *flag = "add";
	int i = 1;
	
	t_tuple a;
	t_tuple b;
	t_tuple c1;
	t_tuple c2;
	int	ret;
	int	expec;
	
	a = tuple_set(100,100,100,100);
	b = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	c1 = tuple_add(a, b);
	c2 = tuple_set(100,-FLT_MAX,100,FLT_MAX);
	expect_tuple_eq(c1, c2, flag, i++);
	
	a = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	b = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	c1 = tuple_add(a, b);
	c2 = tuple_set(0,-INFINITY,0,INFINITY);
	expect_tuple_eq(c1, c2, flag, i++);
	
	a = tuple_set(-INFINITY, INFINITY, INFINITY, -INFINITY);
	b = tuple_set(-INFINITY, INFINITY, -INFINITY, INFINITY);
	a = tuple_add(a, b);
	b = tuple_set(-INFINITY, INFINITY, NAN, NAN);
	cr_expect(float_eq(a.x, b.x), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_expect(float_eq(a.y, b.y), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	cr_expect(isnan(a.z), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.z);
	cr_expect(isnan(a.w), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.w);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(100,100,100,100);
	b = tuple_set(NAN, NAN, NAN, NAN);
	a = tuple_add(a, b);
	b = tuple_set(NAN, NAN, NAN, NAN);
	cr_expect(isnan(a.x), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.x);
	cr_expect(isnan(a.y), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.y);
	cr_expect(isnan(a.z), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.z);
	cr_expect(isnan(a.w), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.w);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
}

Test(tuples, sub) {
	char *flag = "sub";
	int i = 1;
	
	t_tuple a;
	t_tuple b;
	t_tuple c1;
	t_tuple c2;
	int	ret;
	int	expec;
		
	a = tuple_set(100,100,100,100);
	b = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	c1 = tuple_sub(a, b);
	c2 = tuple_set(100,FLT_MAX,100,-FLT_MAX);
	expect_tuple_eq(c1, c2, flag, i++);
	
	a = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	b = tuple_set(-FLT_MIN, -FLT_MAX, FLT_MIN, FLT_MAX);
	c1 = tuple_sub(a, b);
	c2 = tuple_set(0, 0, 0, 0);
	expect_tuple_eq(c1, c2, flag, i++);
	
	a = tuple_set(-INFINITY, INFINITY, INFINITY, -INFINITY);
	b = tuple_set(-INFINITY, INFINITY, -INFINITY, INFINITY);
	a = tuple_sub(a, b);
	b = tuple_set(NAN, NAN, INFINITY, -INFINITY);
	cr_expect(isnan(a.x), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.x);
	cr_expect(isnan(a.y), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.y);
	cr_expect(float_eq(a.z, b.z), "%s %i: expected x:%f, returned x:%f.", flag, i, b.x, a.x);
	cr_expect(float_eq(a.w, b.w), "%s %i: expected y:%f, returned y:%f.", flag, i, b.y, a.y);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
	
	a = tuple_set(100,100,100,100);
	b = tuple_set(NAN, NAN, NAN, NAN);
	a = tuple_sub(a, b);
	cr_expect(isnan(a.x), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.x);
	cr_expect(isnan(a.y), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.y);
	cr_expect(isnan(a.z), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.z);
	cr_expect(isnan(a.w), "%s %i: expected x:%f, returned x:%f.", flag, i, NAN, a.w);
	b = tuple_set(NAN, NAN, NAN, NAN);
	ret = tuple_eq(a, b);
	expec = 0;
	cr_expect(ret == expec, "%s %i: ret expected to be %i.", flag, i++, expec);
}
