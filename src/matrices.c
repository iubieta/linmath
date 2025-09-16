/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:39:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/17 00:11:08 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"
#include <stdlib.h>
void	matrix_fill_limits(t_matrix *m)
{
	int	i;
	int j;
	int size;

	size = m->size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i >= size || j >= size)
				m->value[i][j] = NAN;
			j++;
		}
		i++;
	}
}

t_matrix	matrix_set_2x2(float values[4])
{
	t_matrix m;

	m.size = 2;
	m.value[0][0] = values[0];
	m.value[0][1] = values[1];
	m.value[1][0] = values[2];
	m.value[1][1] = values[3];
	matrix_fill_limits(&m);
	return (m);
}

t_matrix	matrix_set_3x3(float values[9])
{
	t_matrix m;

	m.size = 3;
	m.value[0][0] = values[0];
	m.value[0][1] = values[1];
	m.value[0][2] = values[2];
	m.value[1][0] = values[3];
	m.value[1][1] = values[4];
	m.value[1][2] = values[5];
	m.value[2][0] = values[6];
	m.value[2][1] = values[7];
	m.value[2][2] = values[8];
	matrix_fill_limits(&m);
	return (m);
}

t_matrix	matrix_set_4x4(float values[9])
{
	t_matrix m;

	m.size = 4;
	m.value[0][0] = values[0];
	m.value[0][1] = values[1];
	m.value[0][2] = values[2];
	m.value[0][3] = values[3];
	m.value[1][0] = values[4];
	m.value[1][1] = values[5];
	m.value[1][2] = values[6];
	m.value[1][3] = values[7];
	m.value[2][0] = values[8];
	m.value[2][1] = values[9];
	m.value[2][2] = values[10];
	m.value[2][3] = values[11];
	m.value[3][0] = values[12];
	m.value[3][1] = values[13];
	m.value[3][2] = values[14];
	m.value[3][3] = values[15];
	return (m);
}
