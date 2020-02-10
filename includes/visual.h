/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:44:14 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/01 11:43:15 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <math.h>
# include "../printflib/ft_printf.h"
# include "mlx.h"
# include <OpenGL/OpenGL.h>
# include "filler.h"
# include <pthread.h>
# include <time.h>

# define RED 0xDA2C2C
# define LIGHT_RED 0xE89090
# define BLUE 0x3F39DB
# define LIGHT_BLUE 0x7774CD
# define GRID 0xDADAEC
# define STEP 1
# define DELAY 300

typedef struct		s_vcell
{
	t_coord		top_left;
	t_coord		top_right;
	t_coord		bottom_left;
	t_coord		bottom_right;
	t_coord		loc;
	int			color;
	int			v_size;
	int			h_size;
}					t_vcell;

typedef struct		s_vfield
{
	t_vcell		**cells;
	t_coord		dimenisons;
	int			ready;
}					t_vfield;

typedef struct		s_render_stuff
{
	void		*mlx;
	void		*window;
	t_vfield	*field;
}					t_render_stuff;

void				free_vfield(t_vfield *field);
void				create_field(t_hmap map, t_vfield *field);
void				draw_grid(void *mlx, void *window, t_vfield field);
void				draw_cell(void *mlx, void *window, t_vcell cell);
void				draw_field(void *mlx, void *window, t_vfield field);
void				render_field(t_render_stuff *stuff);
void				update_field(t_hmap map, t_vfield *field);
void				delay(int number_of_seconds);
void				vis_loop(t_render_stuff *stuff);
void				mlx_flow(t_vfield *field, t_render_stuff *stuff);
void				player_flow(t_vfield *field);
void				draw_cell(void *mlx, void *window, t_vcell cell);

#endif
