/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:54:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 14:11:58 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			parse_for_size(char **temp, t_piece *piece)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	j = 0;
	while (j < piece->dimensions.y)
	{
		while (i < piece->dimensions.x)
		{
			if (temp[j][i] == '*')
				size++;
			i++;
		}
		i = 0;
		j++;
	}
	return (size);
}

char		**get_piece_size(t_piece *piece, char **temp, char **row)
{
	int		i;

	temp = (char**)malloc((piece->dimensions.y + 1) * sizeof(char*));
	temp[piece->dimensions.y] = 0;
	i = 0;
	while (i < piece->dimensions.y)
	{
		get_next_line(STDIN_FILENO, row);
		temp[i] = ft_strdup((*row));
		free(*row);
		i++;
	}
	piece->cell_num = parse_for_size(temp, piece);
	return (temp);
}

void		parse_for_coords(t_piece *piece, char **temp)
{
	int			i;
	int			j;
	int			c;

	i = 0;
	j = 0;
	c = 0;
	piece->place = (t_coord){0, 0};
	while (j < piece->dimensions.y)
	{
		while (i < piece->dimensions.x)
		{
			if (temp[j][i] == '*')
			{
				piece->shape[c] = (t_coord){i, j};
				c++;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void		read_piece(char **temp, char **row, t_piece *piece)
{
	int			i;

	get_next_line(STDIN_FILENO, row);
	i = 0;
	while (!ft_isdigit((*row)[i]))
		i++;
	piece->dimensions.y = ft_atoi(&(*row)[i]);
	while (ft_isdigit((*row)[i]))
		i++;
	piece->dimensions.x = ft_atoi(&(*row)[i]);
	free(*row);
	temp = get_piece_size(piece, temp, row);
	piece->shape = (t_coord*)malloc(piece->cell_num * sizeof(t_coord));
	parse_for_coords(piece, temp);
	free_temp_arr(temp);
}
