#include "lem_in.h"
struct s_lemin	*g_lemin;

t_room		*get_room_by_id(int id)
{
	t_room	*r;
	t_list	*tmp;

	tmp = g_lemin->rooms;
	while (tmp)
	{
		r = (t_room *)(tmp->content);
		if (id == r->id)
			return (r);
		tmp = tmp->next;
	}
	return (NULL);
}