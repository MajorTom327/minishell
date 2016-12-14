/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:14:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:59:22 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtin.h>
#include <libft.h>

int	cmd_search(t_sh *sh, const char *str)
{
	int i;

	i = 0;
	while (i < BUILTIN_NB)
	{
		if (ft_strcmp(sh->cmd[i].name, str) == 0)
		{
			break ;
		}
		i++;
	}
	return ((i < BUILTIN_NB) ? i : -1);
}
