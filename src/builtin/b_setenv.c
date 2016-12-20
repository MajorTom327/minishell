/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:53:14 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/20 14:26:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <minishell.h>
#include <libft.h>

int	b_setenv(void *env, char **cmd)
{
	t_sh	*sh;
	char	**d;
	int		tmp;

	sh = (t_sh *)env;
	d = parseenv(cmd);
	if ((tmp = env_search(sh, d[0])) == -1)
		sh->env = add_env(sh, d[0], d[1]);
	else
	{
		ft_strdel(&(sh->env[tmp].value));
		sh->env[tmp].value = ft_strdup(d[1]);
	}
	ft_strtabdel(d);
	ft_memdel((void **)&d);
	return (0);
}
