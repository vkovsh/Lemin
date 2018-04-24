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

static void	initialize(void)
{
	g_lemin = (t_lemin *)malloc(sizeof(t_lemin));
	ft_bzero(g_lemin, sizeof(t_lemin));
	g_lemin->hex_str = ft_strnew(0);
}

static void	try_to_read_input(void)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while ((i = get_next_line(0, &line)) == 1 && line[0] == '#')
	{
		add_line_to_output(line);
		if (!ft_strcmp(line, "##start") ||
			!ft_strcmp(line, "##end"))
			force_quit();
		ft_strdel(&line);
	}
	if (i != 1 || (g_lemin->ant_count = ft_atoi(line)) < 1)
		force_quit();
	else
		add_line_to_output(line);
	ft_strdel(&line);
}

int			read_rooms(char **line)
{
	int		i;
	int		id;

	i = 0;
	id = 0;
	while ((i = get_next_line(0, line) == 1))
	{
		add_line_to_output(*line);
		if ((*line)[0] == '#')
		{
			if (!ft_strcmp(*line, "##start"))
				parse_room(*line, 1, id++);
			else if (!ft_strcmp(*line, "##end"))
				parse_room(*line, 2, id++);
		}
		else if (ft_strchr(*line, '-'))
		{
			g_lemin->room_count = id;
			break ;
		}
		else
			parse_room(*line, 0, id++);
		ft_strdel(line);
	}
	return (i);
}

void		read_links(char **line)
{
	if (parse_link(*line))
	{
		ft_strdel(line);
		while (get_next_line(0, line) == 1)
		{
			add_line_to_output(*line);
			if (!((*line)[0] == '#'))
			{
				if (!parse_link(*line))
				{
					ft_strdel(line);
					break ;
				}
			}
			ft_strdel(line);
		}
	}
	else
		ft_strdel(line);
}

void		readdata(void)
{
	char	*line;

	line = NULL;
	initialize();
	try_to_read_input();
	if (read_rooms(&line) == 1)
		read_links(&line);
	build_adjacency_matrix();
	set_ants();
}
