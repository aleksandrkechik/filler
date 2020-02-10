/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:33:54 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 11:43:01 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	set_both(t_cell *cell, int val)
{
	cell->p1_value = val;
	cell->p2_value = val;
}

int		get_cell_value(t_cell cell, int num)
{
	if (num == 1)
		return (cell.p1_value);
	else
		return (cell.p2_value);
}
