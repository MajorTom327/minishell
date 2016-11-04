/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:31:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 01:34:01 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <env.h>

int		pwd(t_sh *e)
{
	char	*buf;
	int		l;
	char	*hm;

	hm = env_search(e->env, "HOME")->value;
	buf = ft_strnew(1024);
	if (buf == NULL)
		return (1);
	buf = getcwd(buf, 1024);
	l = ft_strlen(hm);
	if (ft_strncmp(buf, hm, l) == 0 && ft_strcmp(buf, hm) != 0)
	{
		buf[l - 1] = '~';
		ft_putendl(&buf[l - 1]);
	}
	else
		ft_putendl(buf);
	ft_strdel(&buf);
	return (0);
}

char	*get_pwd(t_sh *e)
{
	char	*buf;
	int		l;
	char	*hm;

	hm = env_search(e->env, "HOME")->value;
	buf = ft_strnew(1024);
	if (buf == NULL)
		return (NULL);
	buf = getcwd(buf, 1024);
	if (hm== NULL)
		return (buf);
	l = ft_strlen(hm);
	if (ft_strncmp(buf, hm, l) == 0)
	{
		buf[l - 1] = '~';
		return(&buf[l - 1]);
	}
	else
		return (buf);
}
