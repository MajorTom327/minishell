/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:30:02 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 10:44:38 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>
#include <builtin.h>
#include <pwd.h>

void	gethome(t_tree *t)
{
	char	*key;
	char	*value;

	if (tree_search(t, "HOME") != NULL)
		return ;
	key = ft_strdup("HOME=");
	value = ft_strdup(getpwuid(getuid())->pw_dir);
	key = ft_freejoin(key, value);
	add_env(t, key);
	ft_strdel(&value);
	ft_strdel(&key);
}

t_tree	*default_env()
{
	t_tree *t;
	t_env	*e;
	char	tmp[1024];
	char	*tmp2[2];

	dbg_info("default_env", "default env", 2);
	exit_mem((t = (t_tree *)ft_memalloc(sizeof(t_tree))));
	exit_mem((e = (t_env *)ft_memalloc(sizeof(t_env))));
	t->hash = hash("SHLVL");
	e->key = ft_strdup("SHLVL");
	e->value = ft_strdup("1");
	t->value = (void *)e;
	tmp2[0] = ft_strdup("SHLVL");
	tmp2[1] = NULL;
	important_var(tmp2, t);
	ft_strdel(&tmp2[0]);
	return (t);
}

t_tree	*init_env(char **env)
{
	t_tree	*t;
	t_env	*e;
	int		i;
	char	*key;
	char	*value;

	if (env[0] == NULL)
		return (default_env());
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
	{
		//dbg_var_str("init_env", "env[i]", env[i], 2);
		add_env(t, env[i]);
	}
	dbg_var_int("init_env", "i", i, 2);
	//important_var(env, t);
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

t_sh	*init(char **e)
{
	t_sh	*sh;
	t_cmd	*c;

	exit_mem((void *)(sh = (t_sh *)ft_memalloc(sizeof(t_sh))));
	exit_mem(sh->cmd = (t_tree *)ft_memalloc(sizeof(t_tree)));
	dbg_info("init", "Alloc success !", 1);
	sh->cmd->hash = hash("pwd");
	exit_mem(c = (t_cmd *)ft_memalloc(sizeof(t_cmd)));
	c->type = SH_BUILTIN;
	c->name = ft_strdup("pwd");
	c->f = &pwd;
	sh->cmd->value = c;
	add_cmd(sh->cmd, cmd_builtin("cd", &b_cd));
	add_cmd(sh->cmd, cmd_builtin("echo", NULL));
	add_cmd(sh->cmd, cmd_builtin("env", &b_env));
	add_cmd(sh->cmd, cmd_builtin("exit", &b_exit));
	sh->env = init_env(e);
	return (sh);
}
