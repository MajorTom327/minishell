/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:39:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 22:13:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

static void	sf_inithash(t_cmd *cmd)
{
	cmd[e_echo].hash = hash("echo");
	cmd[e_setenv].hash = hash("setenv");
	cmd[e_unsetenv].hash = hash("unsetenv");
	cmd[e_env].hash = hash("env");
	cmd[e_cd].hash = hash("cd");
	cmd[e_pwd].hash = hash("pwd");
	cmd[e_exit].hash = hash("exit");
	cmd[e_builtin].hash = hash("builtin");
	cmd[e_dotdot].hash = hash("..");
}

static void	sf_initname(t_cmd *cmd)
{
	cmd[e_echo].name = ft_strdup("echo");
	cmd[e_setenv].name = ft_strdup("setenv");
	cmd[e_unsetenv].name = ft_strdup("unsetenv");
	cmd[e_env].name = ft_strdup("env");
	cmd[e_cd].name = ft_strdup("cd");
	cmd[e_pwd].name = ft_strdup("pwd");
	cmd[e_exit].name = ft_strdup("exit");
	cmd[e_builtin].name = ft_strdup("builtin");
	cmd[e_dotdot].name = ft_strdup("..");
}

static void		sf_initfunction(t_cmd *cmd)
{
	cmd[e_echo].f = b_echo;
	cmd[e_setenv].f = b_setenv;
	cmd[e_unsetenv].f = NULL;
	cmd[e_env].f = b_env;
	cmd[e_cd].f = b_cd;
	cmd[e_pwd].f = b_pwd;
	cmd[e_exit].f = b_exit;
	cmd[e_builtin].f = b_builtin;
	cmd[e_dotdot].f = b_dotdot;
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
	while (i < BUILTIN_NB)
	{
		dbg_var_str("init_cmd", "current builtin", cmd[i].name, 2);
		cmd[i++].param = (void *)sh;
	}
	return (cmd);
}
