/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:40:12 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/10 05:38:23 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <builtin.h>
#include <minishell.h>

static int	sf_enverror(char *cmd)
{
	ft_putstr("env: illegal option -");
	ft_putendl(cmd);
	ft_putendl("usage: env [-i]");
	return (1);
}

int			b_env(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	(void)cmd;
	sh = (t_sh *)env;
	i = 0;
	if (cmd[1] && !ft_strcmp(cmd[1], "-i"))
	{
		if (ft_strcmp(cmd[2], "env"))
			return (execute(sh, &cmd[2], 1));
		return (0);
	}
	else if (cmd[1])
		return (sf_enverror(cmd[1]));
	while (i < sh->env_l)
	{
		ft_putstr((sh->env[i]).key);
		ft_putchar('=');
		ft_putendl((sh->env[i]).value);
		i++;
	}
	return (0);
}
