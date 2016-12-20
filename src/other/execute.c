/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:40:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/20 15:12:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>

static int	sf_execute(t_sh *sh, char **cmd)
{
	pid_t	fd;
	char	**env;
	int		i;

	fd = fork();
	if (fd != 0)
	{
		wait(&(sh->ret));
	}
	else
	{
		env = ft_memalloc(sizeof(char *) * (sh->env_l + 1));
		i = 0;
		while (i < sh->env_l)
		{
			env[i] = ft_strdup(sh->env[i].key);
			env[i] = ft_freejoin(env[i], "=");
			env[i] = ft_freejoin(env[i], sh->env[i].value);
			i++;
		}
		execve(cmd[0], cmd, env);
		ft_strtabdel(env);
		ft_memdel((void **)&env);
	}
	return (sh->ret);
}

int			execute_exe(t_sh *sh, char **cmd)
{
	if (access(cmd[0], X_OK) == -1 || access(cmd[0], F_OK) == -1)
	{
		ft_putstr(sh->progname);
		if (access(cmd[0], F_OK) == -1)
			ft_putstr(": no such file or directory: ");
		else
			ft_putstr(": permission denied: ");
		ft_putendl(cmd[0]);
		return (1);
	}
	return (sf_execute(sh, cmd));
}

int			execute(t_sh *sh, char **cmd)
{
	int i;

	i = cmd_search(sh, cmd[0]);
	if (i != -1)
	{
		if (sh->cmd[i].f != NULL)
			return ((sh->ret = sh->cmd[i].f((void *)sh, cmd)));
		return (sh->ret = 0);
	}
	if (!prog_search(sh, cmd))
		return (sh->ret = execute_exe(sh, cmd));
	else if (access(cmd[0], F_OK) != -1 || access(cmd[0], F_OK) == -1)
		return (sh->ret = execute_exe(sh, cmd));
	ft_putstr(sh->progname);
	ft_putstr(": command not found: ");
	ft_putendl(cmd[0]);
	return (sh->ret = 1);
}
