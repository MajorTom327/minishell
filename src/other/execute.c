/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:40:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/15 03:12:29 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>

int	execute_exe(t_sh *sh, char **cmd)
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
	ft_putendl("EXTERNAL PROGRAM");
	ft_putendl(cmd[0]);
	return (0);
}

int	execute(t_sh *sh, char **cmd)
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
