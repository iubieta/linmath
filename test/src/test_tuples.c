#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include "../../src/linmath.h"

int main() {
	printf("Hello world");
}
//Test(tuples, tuple_to_array) {
//	t_tuple t;
//	float	ar[4];
//	float	check[4] = {0, 0, 0, 0};
//
//	t.x = 0;
//	t.y = 0;
//	t.z = 0;
//	t.w = 0;
//	tuple_to_array(t, ar);
//	for (int i = 0; i < 4; i++)
//		cr_expect(ar[i] == 0);
//	
//	t.x = 1;
//	t.y = 2;
//	t.z = 3;
//	t.w = 4;
//	tuple_to_array(t, ar);
//	for (int i = 0; i < 4; i++)
//		cr_expect(ar[i] == 1 + i);
//	
//	t.x = -1;
//	t.y = -2;
//	t.z = -3;
//	t.w = -4;
//	tuple_to_array(t, ar);
//	for (int i = 0; i < 4; i++)
//		cr_expect(ar[i] == 0 - 1 - i, "Expected: %i\tReturned: %f",-i, ar[i]);
//}
//
//Test(tuples, set) {
//	t_tuple	p;
//	t_tuple	v;
//
//	p = tuple_set(0,0,0,0);
//	cr_expect(p.x == 0, "Point x expected to be 0.");
//	cr_expect(p.y == 0, "Point y expected to be 0.");
//	cr_expect(p.z == 0, "Point z expected to be 0.");
//	cr_expect(p.w == 0, "Point w expected to be 0.");
//
//	p = tuple_set(1,1,1,1);
//	cr_expect(p.x == 1, "Point x expected to be 1.");
//	cr_expect(p.y == 1, "Point y expected to be 1.");
//	cr_expect(p.z == 1, "Point z expected to be 1.");
//	cr_expect(p.w == 1, "Point w expected to be 1.");
//	
//	p = tuple_set(-1,-1,-1,-1);
//	cr_expect(p.x == -1, "Point x expected to be -1.");
//	cr_expect(p.y == -1, "Point y expected to be -1.");
//	cr_expect(p.z == -1, "Point z expected to be -1.");
//	cr_expect(p.w == -1, "Point w expected to be -1.");
//
//}
//
//Test(tuples, point) {
//	t_tuple	p;
//	t_tuple	v;
//
//	p = tuple_point(0,0,0);
//	cr_expect(p.x == 0, "Point x expected to be 0.");
//	cr_expect(p.y == 0, "Point y expected to be 0.");
//	cr_expect(p.z == 0, "Point z expected to be 0.");
//	cr_expect(p.w == 1, "Point w expected to be 1.");
//
//	p = tuple_point(1,1,1);
//	cr_expect(p.x == 1, "Point x expected to be 0.");
//	cr_expect(p.y == 1, "Point y expected to be 0.");
//	cr_expect(p.z == 1, "Point z expected to be 0.");
//	cr_expect(p.w == 1, "Point w expected to be 1.");
//
//	p = tuple_point(-1,-1,-1);
//	cr_expect(p.x == -1, "Point x expected to be 0.");
//	cr_expect(p.y == -1, "Point y expected to be 0.");
//	cr_expect(p.z == -1, "Point z expected to be 0.");
//	cr_expect(p.w == 1, "Point w expected to be 1.");
//
//}

// Test(tuples, vector) {
// 	t_tuple	p;
// 	t_tuple	v;
//
// 	v = tuple_vector(0,0,0);
// 	cr_expect(v.x == 0, "Vector x expected to be 0.");
// 	cr_expect(v.y == 0, "Vector y expected to be 0.");
// 	cr_expect(v.z == 0, "Vector z expected to be 0.");
// 	cr_expect(v.w == 0, "Vector w expected to be 1.");
// 	
// 	v = tuple_vector(1,1,1);
// 	cr_expect(v.x == 1, "Vector x expected to be 0.");
// 	cr_expect(v.y == 1, "Vector y expected to be 0.");
// 	cr_expect(v.z == 1, "Vector z expected to be 0.");
// 	cr_expect(v.w == 0, "Vector w expected to be 1.");
// 	
// 	v = tuple_vector(-1,-1,-1);
// 	cr_expect(v.x == -1, "Vector x expected to be 0.");
// 	cr_expect(v.y == -1, "Vector y expected to be 0.");
// 	cr_expect(v.z == -1, "Vector z expected to be 0.");
// 	cr_expect(v.w == 0, "Vector w expected to be 1.");
// }
