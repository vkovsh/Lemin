#include "lem_in.h"
struct s_lemin	*g_lemin;

t_room		*get_room_by_name(char *name)
{
	t_room	*r;
	t_list	*rooms;

	rooms = g_lemin->rooms;
	while (rooms)
	{
		r = (t_room *)(rooms->content);
		if (!ft_strcmp(r->name, name))
			return (r);
		rooms = rooms->next;
	}
	return (NULL);
}