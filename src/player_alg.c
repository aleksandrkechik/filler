/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:43:07 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 13:23:40 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visual.h"

t_coord	prepare_data(t_hmap *map, char *line, char **temp)
{
	t_coord loc;
	t_piece *piece;

	piece = (t_piece*)malloc(sizeof(t_piece));
	delay(DELAY);
	map->field = init_field(map, &line);
	make_heatmap(map);
	read_piece(temp, &line, piece);
	loc = find_the_most_bestest(map, piece, map->current_player, &loc);
	freepiece(piece);
	return (loc);
}

void	handle_vfield(int *started, t_hmap map, t_vfield *field)
{
	if (*started == 0)
	{
		create_field(map, field);
		*started = 1;
	}
	else
		update_field((map), field);
}

void	print_coord(t_coord loc)
{
	ft_putnbr(loc.y);
	ft_putchar(' ');
	ft_putnbr(loc.x);
	ft_putchar('\n');
}

void	player_flow(t_vfield *field)
{
	t_hmap		map;
	char		**temp;
	t_coord		loc;
	char		*line;

	temp = NULL;
	init_player(&map);
	get_player(&map, &line);
	INIT_COUNTER(started);
	while (1)
	{
		loc = prepare_data(&map, line, temp);
		handle_vfield(&started, map, field);
		destroy_field(&map);
		if (loc.x != -1000 && loc.y != -1000)
			print_coord(loc);
		else
		{
			free_vfield(field);
			exit(0);
		}
	}
}
