/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 01:17:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>
#include <tree.h>

static int	sf_count(t_tree *t, int st)
{
	static int	cnt;

	if (st)
		return (cnt = 0);
	cnt++;
	if (t->left != NULL)
		sf_count(t->left, 0);
	if (t->right != NULL)
		sf_count(t->right, 0);
	return (cnt);
}

static char	**sf_envbuild(t_tree *t, int st)
{
	static int	i;
	static char	**e;

	if (st)
	{
		exit_mem((void *)(e = (char **)ft_memalloc(sizeof(char *) * (st + 1))));
		i = 0;
		return (NULL);
	}
	e[i] = get_key((t_env *)t->value);
	i++;
	if (t->left != NULL)
	{
		dbg_info("sf_envbuild", "goto left", 3);
		sf_envbuild(t->left, 0);
	}
	if (t->right != NULL)
	{
		dbg_info("sf_envbuild", "goto right", 3);
		sf_envbuild(t->right, 0);
	}
	return (e);
}

char		**build(t_sh *e)
{
	int	cnt;
	char **env;

	sf_count(NULL, 1);
	cnt = sf_count(e->env, 0);
	dbg_var_int("build", "number of env", cnt, 2);
	sf_envbuild(NULL, cnt);
	dbg_info("build", "init sf_envbuild OK", 2);
	env = sf_envbuild(e->env, 0);
	env[cnt] = NULL;
	dbg_var_array_str("ENV", "env", env, 2);
	return (NULL);
}
