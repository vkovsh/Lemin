/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 15:43:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_ants(void)
{
	int		i;
	t_ant	**ants;

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
