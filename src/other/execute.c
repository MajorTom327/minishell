/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:40:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 04:45:11 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

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
	ft_putstr(sh->progname);
	ft_putstr(": command not found: ");
	ft_putendl(cmd[0]);
	return (sh->ret = 1);
}