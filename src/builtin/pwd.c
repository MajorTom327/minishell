/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:31:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 05:44:55 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <env.h>

int		pwd(void *v_par, char **cmd)
{
	char	buf[1024];

	(void)v_par;
	(void)cmd;
	getcwd(buf, 1024);
	ft_putendl(buf);
	return (0);
}

char	*get_pwd(t_sh *e)
{
	char	*buf;
	int		l;
	char	*hm;

	if (env_search(e->env, "HOME") == NULL)
		hm = NULL;
	else
		hm = env_search(e->env, "HOME")->value;
	buf = ft_strnew(1024);
	if (buf == NULL)
		return (NULL);
	buf = getcwd(buf, 1024);
	if (hm == NULL)
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
