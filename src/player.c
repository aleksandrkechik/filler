/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:13:29 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 11:43:01 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		init_player(t_hmap *map)
{
	map->player1.my_center_cell = P1_CENTER_CELL;
	map->player1.my_place_cell = P1_PLACE_CELL;
	map->player1.my_recent_cell = P1_RECENT_CELL;
	map->player1.enemy_recent_cell = P2_RECENT_CELL;
	map->player1.enemy_center_cell = P2_CENTER_CELL;
	map->player1.enemy_place_cell = P2_PLACE_CELL;
	map->player1.num = 1;
	map->player2.my_center_cell = P2_CENTER_CELL;
	map->player2.my_place_cell = P2_PLACE_CELL;
	map->player2.my_recent_cell = P2_RECENT_CELL;
	map->player2.enemy_recent_cell = P1_RECENT_CELL;
	map->player2.enemy_center_cell = P1_CENTER_CELL;
	map->player2.enemy_place_cell = P1_PLACE_CELL;
	map->player2.num = 2;
}

t_player	get_by_num(t_hmap map, int num)
{
	if (num == 1)
		return (map.player1);
	else
		return (map.player2);
}

void		set_current_player(t_hmap *map, int num)
{
	if (num == 2)
		map->current_player = map->player1;
	if (num == 1)
		map->current_player = map->player2;
}

void		get_player(t_hmap *map, char **line)
{
	get_next_line(STDIN_FILENO, line);
	if (ft_strstr((*line), "p1") != NULL)
		set_current_player(map, 2);
	if (ft_strstr((*line), "p2") != NULL)
		set_current_player(map, 1);
	free(*line);
}
