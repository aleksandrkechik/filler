/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:34:49 by hturkatr          #+#    #+#             */
/*   Updated: 2019/12/09 13:21:50 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/visual.h"

int		main(void)
{
	t_vfield			*field;
	t_render_stuff		*stuff;
	int					status;
	int					status_addr;
	pthread_t			thread;

	stuff = (t_render_stuff*)malloc(sizeof(t_render_stuff));
	field = (t_vfield*)malloc(sizeof(t_vfield));
	status = pthread_create(&thread, NULL,
			(void *(*)(void *))&player_flow, field);
	if (status != 0)
		exit(0);
	mlx_flow(field, stuff);
	free(stuff);
	status = pthread_join(thread, (void**)&status_addr);
	if (status != 0)
		exit(0);
	return (0);
}
