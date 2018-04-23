#include "lem_in.h"
struct s_lemin	*g_lemin;

static inline void	del_pair(char **pair)
{
	ft_strdel(&pair[0]);
	ft_strdel(&pair[1]);
	free(pair);
}

bool				parse_link(char *line)
{
	t_link			link;
	char			**pair;

	if (!validate_link(line))
		return (false);
	ft_bzero(&link, sizeof(link));
	pair = ft_strsplit(line, '-');
	if(!(link.room1 = get_room_by_name(pair[0])) ||
		!(link.room2 = get_room_by_name(pair[1])))
		return (false);
	del_pair(pair);
	ft_lstadd(&(g_lemin->links), ft_lstnew(&link, sizeof(t_link)));
	return (true);
}