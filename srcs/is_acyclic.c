/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_acyclic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:21:24 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:21:30 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

bool	is_acyclic(void)
{
	int	count;
	int	i;

	count = g_lemin->room_count;
	i = -1;
	while (++i < count)
		if (g_lemin->adjacency_matrix[i][i] == true)
			return (false);
	return (true);
}
