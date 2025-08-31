/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:45:05 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/31 00:44:21 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#ifndef LINMATH_H
# define LINMATH_H

# define EPS 1e-6f

// Float utils
int float_eq(float a, float b);

// Tuples: points and vectors
typedef struct s_tuple {
	float x;
	float y;
	float z;
	float w;
}	t_tuple;

float	*tuple_to_array(t_tuple t, float ar[4]);
t_tuple	tuple_set(float x, float y, float z, float w);
int		tuple_eq(t_tuple a, t_tuple b);

t_tuple	tuple_point(float x, float y, float z);
t_tuple	tuple_vector(float x, float y, float z);
int		tuple_is_point(t_tuple t);
int		tuple_is_vector(t_tuple t);

t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);

t_tuple	tuple_scale(t_tuple v, float n);
t_tuple	tuple_negate(t_tuple v);
t_tuple	tuple_magnitude(t_tuple v);
t_tuple	tuple_normalize(t_tuple v);

t_tuple	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);

#endif 
