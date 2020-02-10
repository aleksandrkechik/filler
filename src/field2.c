/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:33:28 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 13:20:16 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visual.h"

void			convert_cell(t_hmap map, t_vfield *field, int i, int j)
{
	field->cells[i][j].v_size = (800 / field->dimenisons.y);
	field->cells[i][j].h_size = (800 / field->dimenisons.x);
	field->cells[i][j].loc = (t_coord){i, j};
	if (get_cell_value(map.CELL, 1) == P1_PLACE_CELL ||
		get_cell_value(map.CELL, 1) == P1_CENTER_CELL)
		field->cells[i][j].color = RED;
	else if (get_cell_value(map.CELL, 1) == P1_RECENT_CELL)
		field->cells[i][j].color = LIGHT_RED;
	else if (get_cell_value(map.CELL, 1) == P2_PLACE_CELL ||
			get_cell_value(map.CELL, 1) == P2_CENTER_CELL)
		field->cells[i][j].color = BLUE;
	else if (get_cell_value(map.CELL, 1) == P2_RECENT_CELL)
		field->cells[i][j].color = LIGHT_BLUE;
	else
		field->cells[i][j].color = 0;
}

void			init_field_arr(t_vfield *field)
{
	INIT_COUNTER(i);
	field->cells = (t_vcell**)malloc(field->dimenisons.y *
				sizeof(t_vcell*));
	while (i < field->dimenisons.y)
	{
		field->cells[i] = (t_vcell*)malloc(field->dimenisons.x *
				sizeof(t_vcell));
		i++;
	}
}

void			create_field(t_hmap map, t_vfield *field)
{
	field->dimenisons = (t_coord){map.size_x, map.size_y};
	init_field_arr(field);
	INIT_COUNTER(i);
	INIT_COUNTER(j);
	while (i < map.size_y)
	{
		while (j < map.size_x)
		{
			convert_cell(map, field, i, j);
			field->cells[i][j].top_left = (t_coord){100 + j *
	field->cells[i][j].h_size, 100 + i * field->cells[i][j].v_size};
			field->cells[i][j].top_right = (t_coord){100 + (j + 1) *
	field->cells[i][j].h_size, 100 + i * field->cells[i][j].v_size};
			field->cells[i][j].bottom_right = (t_coord){100 + (j + 1) *
	field->cells[i][j].h_size, 100 + (i + 1) * field->cells[i][j].v_size};
			field->cells[i][j].bottom_left = (t_coord){100 + j *
	field->cells[i][j].h_size, 100 + (i + 1) * field->cells[i][j].v_size};
			j++;
		}
		j = 0;
		i++;
	}
	field->ready = 1;
}

void			update_field(t_hmap map, t_vfield *field)
{
	INIT_COUNTER(i);
	INIT_COUNTER(j);
	while (i < map.size_y)
	{
		while (j < map.size_x)
		{
			convert_cell(map, field, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void			free_vfield(t_vfield *field)
{
	int i;

	i = 0;
	while (i < field->dimenisons.y)
	{
		free(field->cells[i]);
		i++;
	}
	free(field->cells);
	free(field);
	field = NULL;
}
