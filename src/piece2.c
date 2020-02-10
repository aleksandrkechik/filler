/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:18:54 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 14:26:49 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		free_temp_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void		find_the_most_bestest2(t_hmap *map, t_piece *piece, t_player player,
						t_s s)
{
	while (*(s.j) < map->size_x)
	{
		if (map->field[(*s.i)][(*s.j)].p1_value == P2_RECENT_CELL)
			set_both(&(map->field[(*s.i)][(*s.j)]), P2_PLACE_CELL);
		if (map->field[(*s.i)][(*s.j)].p1_value == P1_RECENT_CELL)
			set_both(&(map->field[(*s.i)][(*s.j)]), P1_PLACE_CELL);
		if (get_cell_value(map->field[(*s.i)][(*s.j)], player.num) == M)
		{
			while ((*s.c) < piece->cell_num)
			{
				(*s.temp) = place_piece(map, *piece, (t_coord) {(*s.j) -
		piece->shape[(*s.c)].x, (*s.i) - piece->shape[(*s.c)].y}, player);
				if (((*s.bestest) == 0 && (*s.temp) != 0) ||
					((*s.temp) != 0 && (*s.bestest) > (*s.temp)))
				{
					(*s.bestest) = (*s.temp);
					(*s.loc) = (t_coord) {(*s.j) - piece->shape[(*s.c)].x,
						(*s.i) - piece->shape[(*s.c)].y};
				}
				(*s.c)++;
			}
			(*s.c) = 0;
		}
		(*s.j)++;
	}
}

t_coord		find_the_most_bestest(t_hmap *map, t_piece *piece, t_player player,
								t_coord *loc)
{
	int		i;
	int		j;
	int		c;
	int		bestest;
	int		temp;

	i = 0;
	j = 0;
	c = 0;
	*loc = (t_coord){-1000, -1000};
	bestest = 0;
	while (i < map->size_y)
	{
		find_the_most_bestest2(map, piece, player, ((t_s){&i, &j, &c,
							&bestest, &temp, loc}));
		i++;
		j = 0;
	}
	if (bestest != 0)
	{
		put(map, piece, *loc, player);
		make_heatmap(map);
		return (*loc);
	}
	return (*loc);
}

t_piece		copy_piece(t_piece piece)
{
	t_piece new;

	new.cell_num = piece.cell_num;
	new.place = piece.place;
	new.dimensions = piece.dimensions;
	new.shape = ft_memdup(piece.shape, new.cell_num * sizeof(t_coord));
	return (new);
}

void		freepiece(t_piece *piece)
{
	free(piece->shape);
	free(piece);
}
