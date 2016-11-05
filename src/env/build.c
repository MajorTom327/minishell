/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 00:15:14 by vthomas          ###   ########.fr       */
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
	if (t->left != NULL)
	{
		cnt++;
		sf_count(t->left, 0);
	}
	if (t->right != NULL)
	{
		cnt++;
		sf_count(t->right, 0);
	}
	return (cnt);
}

//static char	**sf_envbuild(t_tree *t, int st)
//{
//	static int	i;
//	static char	e;
//
//	if (st)
//	{
//		exit_mem((void *)(e = (char **)ft_memalloc(sizeof(char *) * st)));
//		i = 0;
//		return (NULL);
//	}
//	if (t->left)
//	{
//		e[i]
//	}
//}

char		**build(t_sh *e)
{
	int	cnt;

	sf_count(NULL, 1);
	cnt = sf_count(e->env, 0);
	dbg_var_int("build", "number of env", cnt, 2);
	return (NULL);
}
