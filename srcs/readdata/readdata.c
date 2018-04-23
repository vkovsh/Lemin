/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:24:16 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:24:19 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

static void	build_adjacency_matrix()
{
	int		**am;
	int 	i;
	int 	id1;
	int 	id2;
	t_list	*tmp;

	am = (int **)malloc(sizeof(int *) * g_lemin->room_count);
	ft_bzero(am, sizeof(int *) * g_lemin->room_count);
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

static void	set_ants()
{
	int 	i;
	t_ant 	**ants;

	i = 0;
	ants = (t_ant **)malloc(sizeof(t_ant *) * g_lemin->ant_count);
	ft_bzero(ants, sizeof(t_ant *) * g_lemin->ant_count);
	while (i < g_lemin->ant_count)
	{
		ants[i] = (t_ant *)malloc(sizeof(t_ant));
		ft_bzero(ants[i], sizeof(t_ant));
		ants[i]->room_id = g_lemin->start_id;
		ants[i]->id = i + 1;
		i++;
	}
	g_lemin->ants = ants;
}

void		readdata()
{
	int 	i;
	char	*line;
	int 	id;

	i = 0;
	id = 0;
	line = NULL;
	if (!(g_lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		return ;
	ft_bzero(g_lemin, sizeof(t_lemin));
	if (get_next_line(0, &line) != 1
		|| (g_lemin->ant_count = ft_atoi(line)) < 1)
		force_quit();
	while ((i = get_next_line(0, &line) == 1))
	{
		if (line[0] == '#')
		{
			if (!ft_strcmp(line, "##start"))
				parse_room(line, 1, id++);
			else if (!ft_strcmp(line, "##end"))
				parse_room(line, 2, id++);
		}
		else if (ft_strchr(line, '-'))
		{
			g_lemin->room_count = id;
			break ;
		}
		else
			parse_room(line, 0, id++);
		ft_strdel(&line);
	}
	if (i)
	{
		if (parse_link(line))
		{
			ft_strdel(&line);
			while ((i = get_next_line(0, &line) == 1))
			{
				if (line[0] == '#')
				{
					ft_strdel(&line);
					continue ;
				}
				if (!parse_link(line))
				{
					ft_strdel(&line);
					break ;
				}
				ft_strdel(&line);
			}
		}
		else
			ft_strdel(&line);
	}
	build_adjacency_matrix();
	set_ants();
}
