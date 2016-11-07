/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:01:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 07:51:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtin.h>
#include <libft.h>
#include <stdlib.h>

static void	sf_cmddel(t_cmd *cmd)
{
	dbg_var_str("sf_cmddel", "cmd->name", cmd->name, 3);
	ft_strdel(&(cmd->name));
	dbg_info("sf_cmddel", "cmd->name freed !", 3);
	//ft_strdel(&(cmd->exec));
	dbg_info("sf_cmddel", "cmd->exec freed !", 3);
	ft_memdel((void **)&cmd);
}

static void	sf_envdel(t_env *env)
{
	dbg_var_str("sf_envdel", "env->name", env->key, 3);
	ft_strdel(&(env->key));
	ft_strdel(&(env->value));
	ft_memdel((void **)&env);
}

static void	sf_free(t_tree *t, int type)
{
	dbg_var_int("sf_free", "hash", t->hash, 2);
	if (t->left != NULL)
		sf_free(t->left, type);
	if (t->right != NULL)
		sf_free(t->right, type);
	if (type)
		sf_envdel((t_env *)t->value);
	else
		sf_cmddel((t_cmd *)t->value);
	ft_memdel((void **)&t);
}

int			b_exit(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	sh = (t_sh *)env;
	if (sh)
	{
		sf_free(sh->env, 1);
		sf_free(sh->cmd, 0);
		ft_strdel(&(sh->prompt));
		ft_memdel((void **)&sh);
	}
	if (cmd)
	{
		i = -1;
		while (cmd[++i])
			ft_strdel(&cmd[i]);
		ft_memdel((void **)&cmd);
	}
	else
		ft_putchar('\n');
	exit(EXIT_SUCCESS);
}
