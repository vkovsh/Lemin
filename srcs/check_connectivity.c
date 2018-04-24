/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connectivity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:22:07 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:22:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

static int	dfs(int u, bool **visited)
{
	int		visited_verticles;
	int		j;

	visited_verticles = 1;
	(*visited)[u] = true;
	j = -1;
	while (++j < g_lemin->room_count)
	{
		if ((g_lemin->adjacency_matrix)[u][j])
			if ((*visited)[j] == false)
				visited_verticles += dfs(j, visited);
	}
	return (visited_verticles);
}

bool		check_connectivity(void)
{
	bool	*visited;
	bool	flag;

	visited = (bool *)malloc(sizeof(bool) * g_lemin->room_count);
	ft_bzero(visited, sizeof(bool) * g_lemin->room_count);
	flag = (dfs(0, &visited) == g_lemin->room_count) ? true : false;
	free(visited);
	return (flag);
}
