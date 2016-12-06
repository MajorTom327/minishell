/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:39:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 03:57:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

static void	sf_inithash(t_cmd *cmd)
{
	cmd[0].hash = hash("echo");
	cmd[1].hash = hash("setenv");
	cmd[2].hash = hash("unsetenv");
	cmd[3].hash = hash("env");
	cmd[4].hash = hash("cd");
	cmd[5].hash = hash("pwd");
}

static void	sf_initname(t_cmd *cmd)
{
	cmd[0].name = ft_strdup("echo");
	cmd[1].name = ft_strdup("setenv");
	cmd[2].name = ft_strdup("unsetenv");
	cmd[3].name = ft_strdup("env");
	cmd[4].name = ft_strdup("cd");
	cmd[5].name = ft_strdup("pwd");
}

//TODO: Add function
static void	sf_initfunction(t_cmd *cmd)
{
//	cmd[0]->f = ;
//	cmd[1]->f = ;
//	cmd[2]->f = ;
//	cmd[3]->f = ;
//	cmd[4]->f = ;
//	cmd[5]->f = ;
}

t_cmd	*init_cmd(t_sh *sh)
{
	t_cmd	*cmd;
	int		i;

	exit_mem((cmd = (t_cmd *)ft_memalloc(sizeof(t_cmd) * BUILTIN_NB)));
	sf_initname(cmd);
	sf_inithash(cmd);
	sf_initfunction(cmd);
	i = 0;
	while (i < BUILTIN_NB)//INIT PARAM
	{
		dbg_var_str("init_cmd", "current builtin", cmd[i].name, 2);
		cmd[i++].param = (void *)sh;
	}
	return (cmd);
}
