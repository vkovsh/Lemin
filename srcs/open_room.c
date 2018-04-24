/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:20:46 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 17:20:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

void		open_room(int room_id)
{
	t_list	*links;
	t_link	*link;
	int		id1;
	int		id2;

	links = g_lemin->links;
	while (links)
	{
		link = (t_link *)(links->content);
		id1 = link->room1->id;
		id2 = link->room2->id;
		if (id1 == room_id || id2 == room_id)
		{
			g_lemin->adjacency_matrix[id1][id2] = 1;
			g_lemin->adjacency_matrix[id2][id1] = 1;
		}
		links = links->next;
	}
}
