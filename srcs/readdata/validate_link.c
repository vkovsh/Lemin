/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:24:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 14:24:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
