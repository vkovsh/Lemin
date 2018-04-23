#include "lem_in.h"
struct s_lemin	*g_lemin;

static void	set_to_binary()
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_lemin->room_count)
	{
		j = -1;
		while (++j < g_lemin->room_count)
		{
			if (g_lemin->adjacency_matrix[i][j])
				g_lemin->adjacency_matrix[i][j] = 1;
		}
	}
}

static void	prepare_for_calculation()
{
	int		i;
	int		j;

	i = -1;
	set_to_binary();
	while (++i < g_lemin->room_count)
	{
		j = -1;
		while (++j < g_lemin->room_count)
			if ((i == g_lemin->start_id
				|| j == g_lemin->start_id) &&
				g_lemin->adjacency_matrix[i][j])
				g_lemin->adjacency_matrix[i][j]++;
	}
}	

bool	wave_row(int i, int d)
{
	int	k;
	int	j;

	j = -1;
	while (++j < g_lemin->room_count)
		if (g_lemin->adjacency_matrix[i][j] == d)
		{
			k = -1;
			while (++k < g_lemin->room_count)
			{
				if (k != i && g_lemin->adjacency_matrix[k][j] == 1)
				{
					g_lemin->adjacency_matrix[k][j] = d + 1;
					if (k == g_lemin->end_id)
						return (true);
				}
				if (k != j && g_lemin->adjacency_matrix[i][k] == 1)
				{
					g_lemin->adjacency_matrix[i][k]= d + 1;
					if (k == g_lemin->end_id)
						return (true);
				}
			}
		}
	return (false);
}

int		calculate_matrix()
{
	int	d;
	int	i;

	prepare_for_calculation();
	i = 0;
	d = 1;
	while (++d <= g_lemin->room_count)
	{
		i = -1;
		while (++i < g_lemin->room_count)
			if (wave_row(i, d))
				return (d + 1);
	}
	return (-1);
}