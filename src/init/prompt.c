/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 00:32:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:58:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <libft.h>
#include <pwd.h>

char	*get_home(t_sh *sh)
{
	int i;

	i = env_search(sh, "HOME");
	ft_strdel(&(sh->home));
	if (i == -1)
	{
		sh->home = ft_strdup(getpwuid(getuid())->pw_dir);
	}
	else
		sh->home = ft_strdup(sh->env[i].value);
	return (sh->home);
}

int		get_prompt(t_sh *sh)
{
	char	buf[1024];
	int		l;

	ft_strdel(&(sh->prompt));
	sh->prompt = ft_strdup("\e[90mminishell");
	getcwd(buf, 1024);
	sh->prompt = ft_freejoin(sh->prompt, ((sh->ret) ? "\e[31m" : "\e[32m"));
	sh->prompt = ft_freejoin(sh->prompt, ":\e[34m");
	get_home(sh);
	l = (int)ft_strlen(sh->home);
	if (ft_strncmp(buf, sh->home, l) == 0)
		buf[l - 1] = '~';
	else
		l = 1;
	sh->prompt = ft_freejoin(sh->prompt, &(buf[l - 1]));
	sh->prompt = ft_freejoin(sh->prompt, "\033[90m>\e[0m ");
	return (0);
}
