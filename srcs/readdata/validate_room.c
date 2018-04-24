/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:24:50 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:24:54 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

static inline bool	is_unique(char **rd)
{
	t_list			*rooms;
	t_room			*room;

	rooms = g_lemin->rooms;
	while (rooms)
	{
		room = (t_room *)(rooms->content);
		if (!ft_strcmp(room->name, rd[0]) ||
			(room->x == ft_atoi(rd[1]) &&
				room->y == ft_atoi(rd[2])))
			return (false);
		rooms = rooms->next;
	}
	return (true);
}

static inline bool	is_input_correct(char *line)
{
	char			*first_space;
	char			*second_space;

	if (*line == 'L' ||
	!(first_space = ft_strchr(line, ' ')) ||
		!(second_space = ft_strchr(first_space + 1, ' ')))
		return (false);
	if (*(++first_space) == '-')
		first_space++;
	if (*(++second_space) == '-')
		second_space++;
	while (*first_space != ' ')
		if (!ft_isdigit(*first_space++))
			return (false);
	while (*second_space)
		if (!ft_isdigit(*second_space++))
			return (false);
	return (true);
}

char				**validate_room(char *line)
{
	char			**rd;

	rd = NULL;
	if (is_input_correct(line))
	{
		rd = ft_strsplit(line, ' ');
		if (!is_unique(rd))
			return (NULL);
	}
	return (rd);
}
