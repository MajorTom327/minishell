/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 07:58:24 by vthomas          ###   ########.fr       */
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
	static char	**e = NULL;

	if (st)
	{
		ft_memdel((void **)&e);
		exit_mem((void *)(e = (char **)ft_memalloc(sizeof(char *) * (st + 1))));
		i = 0;
		return (NULL);
	}
	e[i] = get_key((t_env *)t->value);
	i++;
	if (t->left != NULL)
		sf_envbuild(t->left, 0);
	if (t->right != NULL)
		sf_envbuild(t->right, 0);
	return (e);
}

char		**build(t_sh *e)
{
	int	cnt;
	char **env;

	sf_count(NULL, 1);
	cnt = sf_count(e->env, 0);
	sf_envbuild(NULL, cnt);
	env = sf_envbuild(e->env, 0);
	ft_strdel(&env[cnt]);
	//env[cnt] = NULL;
	return (env);
}
