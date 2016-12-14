/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 00:49:03 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:59:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	env_search(t_sh *sh, const char *str)
{
	int i;

	i = 0;
	while (i < sh->env_l)
	{
		if (ft_strcmp(sh->env[i].key, str) == 0)
			break ;
		i++;
	}
	return ((i != sh->env_l) ? i : -1);
}
