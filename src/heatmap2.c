/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:17:48 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 13:02:49 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_min2(t_hmap *map, int x, int y, int num)
{
	int		i;
	int		j;
	int		way;
	int		temp;

	i = 0;
	j = 0;
	way = 0;
	temp = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (map->CELL.p1_value == P2_PLACE_CELL && num == map->player1.num)
				do_cool_stuff(temp, (t_coord){j, i}, (t_coord){x, y}, &way);
			if (map->CELL.p1_value == P1_PLACE_CELL && num == map->player2.num)
				do_cool_stuff(temp, (t_coord){j, i}, (t_coord){x, y}, &way);
			j++;
		}
		i++;
		j = 0;
	}
	return (way);
}

void		make_heatmap(t_hmap *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (map->field[i][j].p1_value == -1)
			{
				map->field[i][j].p1_value = get_min2(map, i, j, 1);
				map->field[i][j].p2_value = get_min2(map, i, j, 2);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void		destroy_field(t_hmap *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->field[i]);
		i++;
	}
	free(map->field);
}
