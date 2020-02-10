/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:19:53 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 15:02:54 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			big_bool1(t_hmap *map, t_piece piece, t_player player, int i)
{
	if (get_cell_value(map->field[piece.shape[i].y][piece.shape[i].x],
	player.num) == player.my_place_cell || get_cell_value(map->
	field[piece.shape[i].y][piece.shape[i].x], player.num) ==
	player.my_center_cell || get_cell_value(map->
	field[piece.shape[i].y][piece.shape[i].x], player.num) ==
	player.my_recent_cell)
		return (1);
	else
		return (0);
}

int			big_bool2(t_hmap *map, t_piece piece, t_player player, int i)
{
	if (get_cell_value(map->field[piece.shape[i].y][piece.shape[i].x]
	, player.num) == player.enemy_place_cell || get_cell_value(map->
	field[piece.shape[i].y][piece.shape[i].x], player.num) ==
	player.enemy_center_cell || get_cell_value(
	map->field[piece.shape[i].y][piece.shape[i].x], player.num) ==
	player.enemy_recent_cell)
		return (1);
	else
		return (0);
}

int			check_placeability(t_hmap *map, t_piece piece, t_player player)
{
	int i;
	int cross;
	int score;

	i = 0;
	cross = 0;
	score = 0;
	while (i < piece.cell_num)
	{
		if (big_bool1(map, piece, player, i))
			cross++;
		else if (big_bool2(map, piece, player, i))
			cross++;
		else
			score += get_cell_value(map->field[piece.shape[i].y]
									[piece.shape[i].x], player.num);
		i++;
	}
	if (cross != 1)
		score = 0;
	free(piece.shape);
	return (score);
}

void		put(t_hmap *map, t_piece *piece, t_coord place_loc, t_player player)
{
	int i;

	i = 0;
	piece->place = place_loc;
	while (i < piece->cell_num)
	{
		piece->shape[i] = (t_coord){piece->shape[i].x + piece->place.x,
				piece->shape[i].y + piece->place.y};
		i++;
	}
	i = 0;
	while (i < piece->cell_num)
	{
		set_both(&(map->field[piece->shape[i].y][piece->shape[i].x]),
				get_by_num(*map, player.num).my_recent_cell);
		i++;
	}
}

int			place_piece(t_hmap *map, t_piece piece, t_coord place_loc,
					t_player player)
{
	int			i;
	t_piece		new;

	i = 0;
	new = copy_piece(piece);
	new.place = place_loc;
	while (i < new.cell_num)
	{
		new.shape[i] = (t_coord){new.shape[i].x + new.place.x,
							new.shape[i].y + new.place.y};
		if ((new.shape[i].x >= map->size_x || new.shape[i].y >= map->size_y)
			|| new.shape[i].x < 0 || new.shape[i].y < 0)
		{
			free(new.shape);
			return (0);
		}
		i++;
	}
	return (check_placeability(map, new, player));
}
