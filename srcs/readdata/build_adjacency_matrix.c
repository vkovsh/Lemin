/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_adjacency_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:27:56 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 15:27:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin *g_lemin;

static int	**initialize_matrix(void)
{
	int		**am;

	am = (int **)malloc(sizeof(int *) * g_lemin->room_count);
	ft_bzero(am, sizeof(int *) * g_lemin->room_count);
	return (am);
}

void		build_adjacency_matrix(void)
{
	int		**am;
	int		i;
	int		id1;
	int		id2;
	t_list	*tmp;

	am = initialize_matrix();
	i = 0;
	while (i < g_lemin->room_count)
	{
		am[i] = (int *)malloc(sizeof(int) * g_lemin->room_count);
		ft_bzero(am[i], sizeof(int) * g_lemin->room_count);
		i++;
	}
	tmp = g_lemin->links;
	while (g_lemin->links)
	{
		id1 = ((t_link *)(g_lemin->links->content))->room1->id;
		id2 = ((t_link *)(g_lemin->links->content))->room2->id;
		am[id1][id2] = true;
		am[id2][id1] = true;
		g_lemin->links = g_lemin->links->next;
	}
	g_lemin->links = tmp;
	g_lemin->adjacency_matrix = am;
}
