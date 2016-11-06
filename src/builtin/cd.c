/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 05:46:19 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 06:00:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>

int	cd(void *env, char **cmd)
{
	int		ret;
	char	*path;
	t_sh	*e;

	e = (t_sh *)env;
	if (cmd[1] == NULL)
		path = ft_strdup(env_search(e->env, "HOME")->value);
	else
	{
		dbg_info("cd", "in the else", 3);
		if (cmd[1][0] == '~')
		{
			path = ft_strdup(env_search(e->env, "HOME")->value);
			path = ft_freejoin(path, &cmd[1][1]);
		}
		else
			path = ft_strdup(cmd[1]);
	}
	ret = chdir(path);
	if (ret != 0)
		ft_putendl("An error occured !");
	ft_strdel(&path);
	return (ret);
}
