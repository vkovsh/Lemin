/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:55:27 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/24 16:55:28 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

void	print_move(t_ant *ant)
{
	t_room	*r;

	r = get_room_by_id(ant->room_id);
	ft_printf("L%d-%s ", ant->id, r->name);
}
