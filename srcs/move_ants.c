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

void		print_move(t_ant *ant)
{
	t_room	*r;

	r = get_room_by_id(ant->room_id);
	ft_printf("L%d-%s ", ant->id, r->name);
}

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

void		print_path(t_ant *ant)
{
	t_list	*tmp;
	int		room_id;

	ft_printf("\nAnt #%d's path:\n", ant->id);
	tmp = ant->path;
	if (!tmp)
		ft_printf("Not exist yet!\n");
	while (tmp)
	{
		room_id = *((int *)(tmp->content));
		if (tmp->next)
			ft_printf("Room #%d --> ", room_id);
		else
			ft_printf("Checkpoint #%d\n", room_id);
		tmp = tmp->next;
	}
}

int		move_ants()
{
	int	i;
	int	moved_ants;

	i = -1;
	moved_ants = 0;
	while (++i < g_lemin->ant_count)
	{
		if ((g_lemin->ants)[i]->room_id == g_lemin->end_id)
			continue ;
		if ((g_lemin->ants)[i]->path == NULL)
		{
			if (!(g_lemin->ants[i]->path = find_shortest_way(g_lemin->ants[i])))
				break ;
		}
		if ((g_lemin->ants)[i]->path != NULL)
		{
			if (path_is_free(g_lemin->ants[i]))
			{
				forward_ant(&(g_lemin->ants)[i]);
				moved_ants++;
			}
		}
	}
	return (moved_ants);
}
