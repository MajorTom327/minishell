/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:30:02 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 04:42:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>

t_tree	*init_env(char **env)
{
	t_tree	*t;
	t_env	*e;
	int		i;
	char	*key;
	char	*value;

	if (env[0] == NULL)
		dbg_info("init_env", "env is empty. Must create an env.", 3);
	exit_mem((t = (t_tree *)ft_memalloc(sizeof(t_tree))));
	exit_mem((e = (t_env *)ft_memalloc(sizeof(t_env))));
	i = 0;
	key = env[i];
	value = ft_strchr(key, '=') + 1;
	*(value - 1) = '\0';
	t->hash = hash(key);
	e->key = ft_strdup(key);
	e->value = ft_strdup(value);
	t->value = (void *)e;
	while (env[++i])
		add_env(t, env[i]);
	return (t);
}

/*
** function name: init
** params: char **
** return: t_sh *
** objectif:
** 		init the sh var and the binaries tree with the environment value
** 		and the builtin or eventualy alias
*/

t_sh	*init(char **env)
{
	t_sh	*sh;
	t_cmd	*c;

	dbg_title("init");
	exit_mem((void *)(sh = (t_sh *)ft_memalloc(sizeof(t_sh))));
	exit_mem(sh->cmd = (t_tree *)ft_memalloc(sizeof(t_tree)));
	dbg_info("init", "Alloc success !", 1);
	sh->cmd->hash = hash("pwd");
	exit_mem(c = (t_cmd *)ft_memalloc(sizeof(t_cmd)));
	c->type = SH_BUILTIN;
	c->name = ft_strdup("pwd");
	add_cmd(sh->cmd, cmd_builtin("cd", sh, NULL));
	add_cmd(sh->cmd, cmd_builtin("echo", sh, NULL));
	add_cmd(sh->cmd, cmd_builtin("env", sh, NULL));
	add_cmd(sh->cmd, cmd_builtin("exit", sh, NULL));
	sh->cmd->value = c;
	sh->env = init_env(env);
	dbg_title("back to main");
	return (sh);
}
