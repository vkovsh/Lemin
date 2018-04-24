/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:24:04 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:24:06 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

static void	del_room_data(char **room_data)
{
	ft_strdel(&room_data[0]);
	ft_strdel(&room_data[1]);
	ft_strdel(&room_data[2]);
	free(room_data);
}

static void	command_management(char **line, int flag, int id)
{
	if (flag == 1)
		g_lemin->start_id = id;
	else if (flag == 2)
		g_lemin->end_id = id;
	while (get_next_line(0, line) == 1 && (*line)[0] == '#')
	{
		add_line_to_output(*line);
		ft_strdel(line);
	}
}

static void	add_room_to_list(char **room_data, int flag, int id)
{
	t_room	room;

	ft_bzero(&room, sizeof(t_room));
	room.name = ft_strdup(room_data[0]);
	room.x = ft_atoi(room_data[1]);
	room.y = ft_atoi(room_data[2]);
	room.id = id;
	room.free = (flag == 1) ? false : true;
	ft_lstadd(&(g_lemin->rooms), ft_lstnew(&room, sizeof(t_room)));
}

int			parse_room(char *line, int flag, int id)
{
	char	**room_data;

	room_data = NULL;
	if (flag)
		command_management(&line, flag, id);
	if (*line)
	{
		if (!(room_data = validate_room(line)))
			force_quit();
		if (flag)
			add_line_to_output(line);
		add_room_to_list(room_data, flag, id);
		del_room_data(room_data);
	}
	return (1);
}
