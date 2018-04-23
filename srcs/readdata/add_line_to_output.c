/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:08:23 by vkovsh            #+#    #+#             */
/*   Updated: 2018/04/23 18:08:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

struct s_lemin	*g_lemin;

void        add_line_to_output(const char *line)
{
    char    *line_with_break;

    line_with_break = ft_strjoin(line, "\n");
    g_lemin->hex_str = ft_strjoin_free(g_lemin->hex_str,
    line_with_break, TRUE, TRUE);
}
