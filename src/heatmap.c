/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:26:04 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 13:00:25 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_cell		**init_field(t_hmap *map, char **line)
{
	t_cell		**field;
	int			i;

	field = NULL;
	get_next_line(STDIN_FILENO, line);
	i = 0;
	while (!ft_isdigit((*line)[i]))
		i++;
	map->size_y = ft_atoi(&(*line)[i]);
	while (ft_isdigit((*line)[i]))
		i++;
	map->size_x = ft_atoi(&(*line)[i]);
	free(*line);
	get_next_line(STDIN_FILENO, line);
	free(*line);
	field = init_field2(map, field, line);
	return (field);
}

t_cell		**init_field2(t_hmap *map, t_cell **field, char **line)
{
	int i;
	int j;

	field = (t_cell**)malloc(sizeof(t_cell*) * map->size_y);
	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		field[i] = (t_cell*)malloc(sizeof(t_cell) * map->size_x);
		get_next_line(STDIN_FILENO, line);
		while (j < map->size_x)
		{
			if ((*line)[j + 4] == 'O' || (*line)[j + 4] == 'o')
				set_both(&(field[i][j]), P1_PLACE_CELL);
			else if ((*line)[j + 4] == 'X' || (*line)[j + 4] == 'x')
				set_both(&(field[i][j]), P2_PLACE_CELL);
			else
				set_both(&(field[i][j]), -1);
			j++;
		}
		j = 0;
		i++;
		free(*line);
	}
	return (field);
}

int			abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void		do_cool_stuff(int temp, t_coord ij, t_coord yx, int *way)
{
	int y;
	int x;
	int i;
	int j;

	y = yx.y;
	x = yx.x;
	i = ij.y;
	j = ij.x;
	temp = abs(y - j) * abs(y - j) + abs(x - i) * abs(x - i);
	if ((*way) == 0)
		(*way) = temp;
	if ((*way) > temp)
		(*way) = temp;
}
