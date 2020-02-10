/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:39:06 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 14:44:32 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visual.h"

void		delay(int number_of_seconds)
{
	int			milli_seconds;
	clock_t		start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void		vis_loop(t_render_stuff *stuff)
{
	if (stuff->field->ready == 1)
	{
		render_field(stuff);
	}
}

int			possible_shut_down_on_escape_key(int key, void *n)
{
	n++;
	if (key == 53)
		exit(0);
	return (0);
}

void		mlx_flow(t_vfield *field, t_render_stuff *stuff)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	stuff->mlx = mlx;
	stuff->window = window;
	stuff->field = field;
	mlx_hook(window, 2, 0, possible_shut_down_on_escape_key, NULL);
	mlx_loop_hook(mlx, (int (*)()) &vis_loop, stuff);
	mlx_loop(mlx);
	if (field == NULL)
	{
		free(stuff);
		return ;
	}
}
