#include "lem_in.h"
struct s_lemin	*g_lemin;

static int	dfs(int u, bool **visited)
{
	int		visitedVerticles;
	int		j;

	visitedVerticles = 1;
	(*visited)[u] = true;
	j = -1;
	while (++j < g_lemin->room_count)
	{
		if ((g_lemin->adjacency_matrix)[u][j])
			if ((*visited)[j] == false)
				visitedVerticles += dfs(j, visited);
	}
	return (visitedVerticles);
}

bool		check_connectivity()
{
	bool	*visited;
	bool	flag;

	visited = (bool *)malloc(sizeof(bool) * g_lemin->room_count);
	ft_bzero(visited, sizeof(bool) * g_lemin->room_count);
	flag = (dfs(0, &visited) == g_lemin->room_count) ? true : false;
	free(visited);
	return (flag);
}