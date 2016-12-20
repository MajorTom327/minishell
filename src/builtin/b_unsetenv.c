/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unsetenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 01:39:22 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/20 15:37:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <minishell.h>
#include <libft.h>

int		b_unsetenv(void *env, char **cmd)
{
	t_sh	*sh;
	int		x;
	int		y;
	int		z;
	t_env	*environ;

	sh = (t_sh *)env;
	if (cmd[1] == NULL || (x = env_search(sh, cmd[1])) == -1)
		return (-1);
	ft_strdel(&(sh->env[x].key));
	ft_strdel(&(sh->env[x].value));
	sh->env_l--;
	environ = (t_env *)ft_memalloc(sizeof(t_env) * sh->env_l);
	y = -1;
	z = 0;
	while (++y <= sh->env_l)
	{
		if (y == x)
			continue;
		environ[z].key = ft_strdup(sh->env[y].key);
		ft_strdel(&(sh->env[y].key));
		environ[z].value = ft_strdup(sh->env[y].value);
		ft_strdel(&(sh->env[y].value));
		environ[z].hash = sh->env[y].hash;
		z++;
	}
	ft_memdel((void **)&(sh->env));
	sh->env = environ;
	return (0);
}
