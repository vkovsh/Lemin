/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:23:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:23:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

int	main(void)
{
	g_lemin = NULL;
	readdata();
	if (g_lemin)
	{
		if (g_lemin->start_id == g_lemin->end_id || !is_acyclic())
			force_quit();
		if (!check_connectivity())
			if (calculate_matrix() == -1)
				force_quit();
		ft_printf("%s\n", g_lemin->hex_str);
		elementary_solution();
		while (move_ants())
			ft_printf("\n");
	}
	return (0);
}
