/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:42:16 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 16:42:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

t_list		*build_path(int d)
{
	t_list	*path;
	int		room_id;
	int		j;

	path = NULL;
	room_id = g_lemin->end_id;
	while (room_id != g_lemin->start_id)
	{
		ft_lstadd(&path, ft_lstnew(&room_id, sizeof(int)));
		j = -1;
		while (++j < g_lemin->room_count)
		{
			if (g_lemin->adjacency_matrix[room_id][j] == d ||
			g_lemin->adjacency_matrix[j][room_id] == d)
			{
				d--;
				room_id = j;
				break ;
			}
			if (j == g_lemin->room_count - 1)
				return (NULL);
		}
	}
	ft_lstadd(&path, ft_lstnew(&(g_lemin->start_id), sizeof(int)));
	return (path);
}
