/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:19:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:20:01 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf.h"
# include <stdbool.h>

extern struct s_lemin	*g_lemin;

typedef struct	s_room
{
	char		*name;
	int			id;
	bool		free;
	int			x;
	int			y;
}				t_room;

typedef struct	s_link
{
	t_room		*room1;
	t_room		*room2;
}				t_link;

typedef struct	s_ant
{
	int			id;
	int			room_id;
	int			last_room_id;
	t_list		*path;
}				t_ant;

typedef struct	s_lemin
{
	int			start_id;
	int			end_id;
	int			ant_count;
	int			room_count;
	int			**etalon_matrix;
	int			**adjacency_matrix;
	t_ant		**ants;
	t_list		*rooms;
	t_list		*links;
	char		*hex_str;
}				t_lemin;

void			readdata(void);
t_room			*get_room_by_id(int id);
t_room			*get_room_by_name(char *name);
t_list			*find_shortest_way(t_ant *ant);
int				calculate_matrix(void);
bool			check_connectivity(void);
bool			is_acyclic(void);
int				move_ants(void);
bool			validate_link(char *line);
bool			parse_link(char *line);
char			**validate_room(char *line);
int				parse_room(char *line, int flag, int id);
void			force_quit(void);
void			copy_etalon_matrix(void);
void			add_line_to_output(const char *line);
void			elementary_solution(void);
void			build_adjacency_matrix(void);
void			set_ants(void);
#endif
