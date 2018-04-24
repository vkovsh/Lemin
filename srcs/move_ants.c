/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:21:45 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:21:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

void		forward_ant(t_ant **ant)
{
	t_list	*tmp;
	t_room	*room;

	if ((*ant)->room_id != g_lemin->start_id)
	{
		room = get_room_by_id((*ant)->room_id);
		room->free = true;
		open_room(room->id);
	}
	tmp = (*ant)->path;
	(*ant)->path = tmp->next;
	free((int *)(tmp->content));
	free(tmp);
	(*ant)->last_room_id = (*ant)->room_id;
	(*ant)->room_id = *((int *)(((*ant)->path)->content));
	if (((*ant)->room_id != g_lemin->end_id))
	{
		room = get_room_by_id((*ant)->room_id);
		room->free = false;
		close_room(room->id);
	}
	print_move(*ant);
}

bool		path_is_free(t_ant *ant)
{
	int		next_id;

	next_id = *(int *)(((ant->path)->next)->content);
	if (next_id == g_lemin->end_id)
		return (true);
	return ((get_room_by_id(next_id))->free);
}

void		copy_path(t_ant *ant1, t_ant *ant2)
{
	t_list	*path;
	t_list	*new_elem;

	path = ant1->path;
	while (path)
	{
		new_elem = ft_lstnew((path->content), sizeof(int));
		ft_lstadd(&(ant2->path), new_elem);
		path = path->next;
	}
	ft_lstrev(&(ant2->path));
	new_elem = ft_lstnew(&(ant1->last_room_id), sizeof(int));
	ft_lstadd(&(ant2->path), new_elem);
}

int			move_ants(void)
{
	int		i;
	int		moved_ants;

	i = -1;
	moved_ants = 0;
	while (++i < g_lemin->ant_count)
	{
		if ((g_lemin->ants)[i]->room_id == g_lemin->end_id)
			continue ;
		if ((g_lemin->ants)[i]->path == NULL)
			if (!(g_lemin->ants[i]->path = find_shortest_way(g_lemin->ants[i])))
			{
				copy_path(g_lemin->ants[i - 1], g_lemin->ants[i]);
				break ;
			}
		if (path_is_free(g_lemin->ants[i]))
		{
			forward_ant(&(g_lemin->ants)[i]);
			moved_ants++;
		}
	}
	return (moved_ants);
}
