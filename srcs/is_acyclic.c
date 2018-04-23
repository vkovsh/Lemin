#include "lem_in.h"
struct s_lemin	*g_lemin;

bool	is_acyclic()
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