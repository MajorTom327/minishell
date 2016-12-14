/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:38:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:53:27 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <minishell.h>
#include <libft.h>

//TODO: remove color
int	b_builtin(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	sh = (t_sh *)env;
	(void)cmd;
	i = 0;
	while (i < BUILTIN_NB)
	{
		if (sh->cmd[i].f != NULL)
			ft_putstr("\033[32m");
		else
			ft_putstr("\033[33m");
		ft_putendl(sh->cmd[i].name);
		i++;
	}
	ft_putstr("\033[0m");
}
