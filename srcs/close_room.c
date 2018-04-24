/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:15:50 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 17:15:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

void		close_room(int room_id)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_lemin->room_count)
	{
		j = -1;
		while (++j < g_lemin->room_count)
		{
			if (i == room_id || j == room_id)
				g_lemin->adjacency_matrix[i][j] = 0;
		}
	}
}
