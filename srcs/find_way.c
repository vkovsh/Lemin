/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:20:40 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:20:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

static bool	is_isolated(t_ant *ant)
{
	int		i;
	int		j;
	int		id;

	i = -1;
	id = ant->room_id;
	while (++i < g_lemin->room_count)
	{
		j = -1;
		while (++j < g_lemin->room_count)
		{
			if (i == id || j == id)
				if (g_lemin->adjacency_matrix[i][j])
					return (false);
		}
	}
	return (true);
}

t_list		*find_shortest_way(t_ant *ant)
{
	int		d;
	t_list	*path;

	path = NULL;
	if (is_isolated(ant))
		return (NULL);
	d = calculate_matrix();
	if (d != -1)
	{
		path = build_path(d);
	}
	return (path);
}
