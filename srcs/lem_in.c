#include "lem_in.h"
#include <time.h>
struct s_lemin	*g_lemin;

int			main(void)
{
	clock_t CPU_time_1 = clock();
	readdata();
	if (g_lemin)
	{
		if (g_lemin->start_id == g_lemin->end_id ||
			!is_acyclic() ||
			!check_connectivity())
			force_quit();
		while (move_ants())
			ft_printf("\n");
	}
	clock_t CPU_time_2 = clock();
	ft_printf("CPU time is : %d\n", CPU_time_2 - CPU_time_1);
	return (0);
}