/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:43:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 04:43:42 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <tree.h>
#include <libft.h>
#include <env.h>

/*
** function name: cmd
** objectif: constructor
*/

t_cmd	cmd(char *name, int type, char *exec, void *param)
{
	t_cmd	cmd;

	cmd.name = name;
	cmd.type = type;
	cmd.exec = exec;
	cmd.param = param;
	return (cmd);
}

t_cmd	cmd_builtin(char *name, void *p, int (*f)(void *))
{
	t_cmd	cmd;

	dbg_info("cmd_builtin", name, 1);
	cmd.name = name;
	cmd.type = SH_BUILTIN;
	cmd.f = f;
	cmd.param = p;
	return (cmd);
}

/*
** function name: add_cmd
** params: t_tree *, t_cmd
** return: void
** objectif:
** 		found the good location for add a cmd in the cmd tree and add the cmd
*/

void	add_cmd(t_tree *tcmd, t_cmd cmd)
{
	int		m_hash;
	t_tree	*ttmp;
	t_cmd	*m_cmd;

	dbg_var_str("add_cmd", "Command to add", cmd.name, 2);
	m_hash = hash(cmd.name);
	ttmp = tree_add(tcmd, m_hash);
	ttmp->hash = m_hash;
	exit_mem(m_cmd = (t_cmd *)ft_memalloc(sizeof(t_cmd)));
	m_cmd->type = cmd.type;
	m_cmd->name = cmd.name;
	m_cmd->exec = cmd.exec;
	m_cmd->param = cmd.param;
	ttmp->value = (void *)m_cmd;
}

t_cmd	*cmd_search(t_tree *cmd, char *str)
{
	int m_hash;

	m_hash = hash(str);
	while (cmd->hash != m_hash && ft_strcmp(((t_cmd *)cmd->value)->name, str))
		cmd = tree_search(cmd, str);
	return ((t_cmd *)cmd->value);
}
