/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 02:48:21 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:53:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <minishell.h>
#include <libft.h>
#include <unistd.h>

static int	sf_chdir(char *dir, t_sh *sh)
{
	char	buf[1024];
	int		i;

	if (access(dir, F_OK) == -1)
		return (-1);
	getcwd(buf, 1024);
	i = env_search(sh, "OLDPWD");
	if (i != -1)
	{
		ft_strdel(&(sh->env[i].value));
		sh->env[i].value = ft_strdup(buf);
	}
	else
		sh->env = add_env(sh, "OLDPWD", buf);
	chdir(dir);
	getcwd(buf, 1024);
	i = env_search(sh, "PWD");
	if (i != -1)
	{
		ft_strdel(&(sh->env[i].value));
		sh->env[i].value = ft_strdup(buf);
	}
	else
		sh->env = add_env(sh, "PWD", buf);
	return (0);
}

int			b_cd(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;
	char	*dir;

	sh = (t_sh *)env;
	if (cmd[1] == NULL || !ft_strcmp(cmd[1], "--") || !ft_strcmp(cmd[1], "~"))
		i = sf_chdir(sh->home, sh);
	else if (!ft_strcmp(cmd[1], "-"))
	{
		i = env_search(sh, "OLDPWD");
		i = sf_chdir(sh->env[i].value, sh);
	}
	else
		i = sf_chdir(cmd[1], sh);
	if (i == -1)
	{
		sh->ret = -1;
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(cmd[1]);
	}
}
