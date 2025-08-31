/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:16:57 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/31 00:45:36 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	*tuple_to_array(t_tuple t, float ar[4])
{
	ar[0] = t.x;
	ar[1] = t.y;
	ar[2] = t.z;
	ar[3] = t.w;
	return ar;
}

t_tuple	tuple_set(float x, float y, float z, float w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return t;
}

int	tuple_eq(t_tuple a, t_tuple b)
{
	if (!float_eq(a.x, b.x))
		return 0;
	if (!float_eq(a.y, b.y))
		return 0;
	if (!float_eq(a.z, b.z))
		return 0;
	if (!float_eq(a.w, b.w))
		return 0;
	return 1;
}

t_tuple	tuple_point(float x, float y, float z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1;
	return t;
}
	
t_tuple	tuple_vector(float x, float y, float z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0;
	return t;
}

int tuple_is_point(t_tuple t)
{
	return (t.w == 1);
}

int tuple_is_vector(t_tuple t)
{
	return (t.w == 0);
}

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	t.w = a.w + b.w;
	return t;
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x - b.x;
	t.y = a.y - b.y;
	t.z = a.z - b.z;
	t.w = a.w - b.w;
	return t;
}

t_tuple	tuple_scale(t_tuple v, float n)
{
	t_tuple	t;

	t.x = v.x * n;
	t.y = v.y * n;
	t.z = v.z * n;
	t.w = v.w;
	return t;
}

t_tuple	tuple_negate(t_tuple v)
{
	t_tuple	t;

	t.x = -v.x;
	t.y = -v.y;
	t.z = -v.z;
	t.w = v.w;
	return t;
}

// t_tuple	tuple_magnitude(t_tuple v);
// t_tuple	tuple_normalize(t_tuple v);
// t_tuple	tuple_dot(t_tuple a, t_tuple b);
// t_tuple	tuple_cross(t_tuple a, t_tuple b);
