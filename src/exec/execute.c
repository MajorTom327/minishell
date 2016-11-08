/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:07:39 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 06:01:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env.h>
#include <libft.h>

/*
**
*/

int	execute(t_sh *sh, char **cmd)
{
	t_tree	*t;
	t_cmd	*cmdtmp;

	t = tree_search(sh->cmd, cmd[0]);
	if (!(t = tree_search(sh->cmd, cmd[0])))
	{
		cmd[0] = ft_strlower(cmd[0]);
		if (!(t = tree_search(sh->cmd, cmd[0])))
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(cmd[0]);
			return (sh->ret = 1);
		}
	}
	dbg_info("execute", "Command found", 2);
	cmdtmp = (t_cmd *)t->value;
	if (cmdtmp->f != NULL)
	{
		dbg_info("execute", "executing...", 2);
		cmdtmp->f((void *)sh, cmd);
	}
	return (sh->ret = 0);
}
