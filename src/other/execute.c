/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:40:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/11 05:38:45 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	execute_exe(t_sh *sh, char **cmd)
{
	ft_putendl("EXTERNAL PROGRAM");
	ft_putendl(cmd[0]);
	return ((sh->ret = 0));
}

int	execute(t_sh *sh, char **cmd)
{
	int i;

	i = cmd_search(sh, cmd[0]);
	if (i != -1)
	{
		dbg_info("execute", "Command found", 2);
		if (sh->cmd[i].f != NULL)
			sh->cmd[i].f((void *)sh, cmd);
		return (sh->ret = 0);
	}
	if (!prog_search(sh, cmd))
		return (execute_exe(sh, cmd));
	ft_putstr(sh->progname);
	ft_putstr(": command not found: ");
	ft_putendl(cmd[0]);
	return (sh->ret = 1);
}
