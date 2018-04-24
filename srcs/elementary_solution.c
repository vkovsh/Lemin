/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementary_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:33:36 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 14:33:38 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin  *g_lemin;

void		elementary_solution()
{
	int		sid;
	int		eid;
	int		**am;
	int		i;
	t_room	*r;

	am = g_lemin->adjacency_matrix;
	sid = g_lemin->start_id;
	eid = g_lemin->end_id;
	if (am[sid][eid] || am[eid][sid])
	{
		i = -1;
		r = get_room_by_id(eid);
		while (++i < g_lemin->ant_count)
			ft_printf("L%d-%s ", i + 1, r->name);
		ft_printf("\n");
		exit(0);
	}
}
