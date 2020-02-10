/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:46:45 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 11:45:01 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visual.h"

void			draw_grid2(void *mlx, void *window, t_vfield field)
{
	INIT_COUNTER(i);
	INIT_COUNTER(j);
	j = field.cells[0][0].top_left.y;
	while (i < field.dimenisons.x)
	{
		while (j <= field.cells[field.dimenisons.y - 1][field.dimenisons.x -
		1].bottom_right.y)
		{
			mlx_pixel_put(mlx, window, field.cells[0][i].top_left.x, j, GRID);
			if (i == field.dimenisons.x - 1)
				mlx_pixel_put(mlx, window, field.cells[0][i].top_right.x, j,
						GRID);
			j++;
		}
		j = field.cells[0][0].top_left.y;
		i++;
	}
}

void			draw_grid(void *mlx, void *window, t_vfield field)
{
	INIT_COUNTER(i);
	INIT_COUNTER(j);
	j = field.cells[0][0].top_left.x - STEP;
	while (i < field.dimenisons.y)
	{
		while (j <= field.cells[field.dimenisons.y - 1]
		[field.dimenisons.x - 1].top_right.x)
		{
			mlx_pixel_put(mlx, window, j, field.cells[i][0].top_left.y, GRID);
			if (i == field.dimenisons.y - 1)
				mlx_pixel_put(mlx, window, j, field.cells[i][0].bottom_left.y,
						GRID);
			j++;
		}
		j = field.cells[0][0].top_left.x;
		i++;
	}
	draw_grid2(mlx, window, field);
}

void			draw_cell(void *mlx, void *window, t_vcell cell)
{
	int i;
	int j;

	i = cell.top_left.y + 1;
	j = cell.top_left.x + 1;
	while (i < cell.bottom_left.y)
	{
		while (j < cell.top_right.x)
		{
			if (cell.color != 0)
				mlx_pixel_put(mlx, window, j, i, cell.color);
			j++;
		}
		j = cell.top_left.x + 1;
		i++;
	}
}

void			render_field(t_render_stuff *stuff)
{
	draw_grid(stuff->mlx, stuff->window, *(stuff->field));
	draw_field(stuff->mlx, stuff->window, *(stuff->field));
}

void			draw_field(void *mlx, void *window, t_vfield field)
{
	INIT_COUNTER(i);
	INIT_COUNTER(j);
	while (i < field.dimenisons.y)
	{
		while (j < field.dimenisons.x)
		{
			draw_cell(mlx, window, field.cells[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
