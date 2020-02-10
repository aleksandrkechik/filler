/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:14:35 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 13:21:16 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../printflib/ft_printf.h"
# include <fcntl.h>

# define BUFF_SIZE 2048
# define CELL field[i][j]
# define P1_CENTER_CELL -3
# define P1_RECENT_CELL -5
# define P1_PLACE_CELL -2
# define P2_CENTER_CELL -4
# define P2_RECENT_CELL -6
# define P2_PLACE_CELL 0
# define M player.my_place_cell

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_cell
{
	int			p1_value;
	int			p2_value;
}				t_cell;

typedef struct	s_player
{
	int		enemy_place_cell;
	int		my_center_cell;
	int		my_recent_cell;
	int		my_place_cell;
	int		enemy_center_cell;
	int		enemy_recent_cell;
	int		num;
}				t_player;

typedef struct	s_hmap
{
	t_player	player1;
	t_player	player2;
	t_player	current_player;
	t_cell		**field;
	int			size_x;
	int			size_y;
}				t_hmap;

typedef struct	s_piece
{
	t_coord		place;
	t_coord		*shape;
	t_coord		dimensions;
	int			cell_num;
}				t_piece;

typedef struct	s_s
{
	int		*i;
	int		*j;
	int		*c;
	int		*bestest;
	int		*temp;
	t_coord	*loc;
}				t_s;

typedef struct	s_info
{
	t_hmap	*map;
	char	**line;
	t_piece	piece;
	char	**temp;
	t_coord	loc;
}				t_info;

int				get_next_line(const int fd, char **line);
t_cell			**init_field(t_hmap *map, char **line);
t_cell			**init_field2(t_hmap *map, t_cell **field, char **line);
void			make_heatmap(t_hmap *map);
char			**get_piece_size(t_piece *piece, char **temp, char **row);
void			read_piece(char **temp, char **row, t_piece *piece);
int				place_piece(t_hmap *map, t_piece piece, t_coord place_loc,
					t_player player);
t_coord			find_the_most_bestest(t_hmap *map, t_piece *piece, t_player
					player, t_coord *loc);
void			put(t_hmap *map, t_piece *piece, t_coord place_loc, t_player
					player);
t_piece			copy_piece(t_piece piece);
int				check_placeability(t_hmap *map, t_piece piece, t_player player);
void			init_player(t_hmap *map);
t_player		get_by_num(t_hmap map, int num);
void			set_both(t_cell *cell, int val);
int				get_cell_value(t_cell cell, int num);
void			get_player(t_hmap *map, char **line);
void			destroy_field(t_hmap *map);
void			free_temp_arr(char **arr);
void			freepiece(t_piece *piece);
void			do_cool_stuff(int temp, t_coord ij, t_coord yx, int *way);

#endif
