/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 05:46:19 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 04:26:25 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>

void	oldpwdset(t_sh *e)
{
	char buff[1024];

	getcwd(buff, 1024);
	env_search(e->env, "OLDPWD")->value = ft_strdup(buff);
}

int		cd(void *env, char **cmd)
{
	int		ret;
	char	*path;
	t_sh	*e;

	e = (t_sh *)env;
	gethome(e->env);
	if (cmd[1] == NULL || ft_strcmp(cmd[1], "--") == 0)
		path = ft_strdup(env_search(e->env, "HOME")->value);
	else
	{
		dbg_info("cd", "in the else", 3);
		if (cmd[1][0] == '~')
		{
			path = ft_strdup(env_search(e->env, "HOME")->value);
			path = ft_freejoin(path, &cmd[1][1]);
		}
		if (cmd[1][0] == '-' && cmd[1][1] == '\0')
		{
			path = ft_strdup(env_search(e->env, "OLDPWD")->value);
			ft_strdel(&(env_search(e->env, "OLDPWD")->value));
			ft_strdel(&(env_search(e->env, "PWD")->value));
			ft_putendl(path);
		}
		else
			path = ft_strdup(cmd[1]);
	}
	oldpwdset(e);
	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
		return (ret);
	}
	ft_strdel(&(env_search(e->env, "PWD")->value));
	env_search(e->env, "PWD")->value = ft_strdup(path);
	ft_strdel(&path);
	return (ret);
}
