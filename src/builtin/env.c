/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:23:07 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 07:48:39 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env.h>
#include <tree.h>
#include <builtin.h>
#include <libft.h>

int	b_env(void *env, char **cd)
{
	char	**e;
	t_sh	*sh;
	int		i;

	sh = (t_sh *)env;
	if (sh == NULL)
		dbg_info("env", "sh is NULL !", 3);
	e = build(sh);
	i = 0;
	if (e == NULL)
		dbg_info("env", "Env is NULL !", 3);
	dbg_info("env", "Env will be print", 3);
	while (e[i])
	{
		ft_putendl(e[i]);
		ft_strdel(&e[i]);
		i++;
	}
	ft_memdel((void **)&e);
	return (sh->ret = 0);
}
