#include "lem_in.h"

bool		validate_link(char *line)
{
	char	*second;

	if (!(second = ft_strchr(line, '-')))
		return (false);
	if (second != ft_strrchr(line, '-'))
		return (false);
	return (true);
}