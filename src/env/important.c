/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   important.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:12:43 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 04:53:18 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>
#include <minishell.h>
#include <libft.h>

static void	sf_pwdenv(t_tree *t, char *type)
{
	char *str;
	char buf[1024];

	str = ft_strdup(type);
	str = ft_freejoin(str, "=");
	getcwd(buf, 1024);
	str = ft_freejoin(str, buf);
	add_env(t, str);
}

void	important_var(char **env, t_tree *t)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "PWD") == 0)
			a = a | 0x01;
		else if (ft_strcmp(env[i], "OLDPWD") == 0)
			a = a | 0x02;
		else if (ft_strcmp(env[i], "SHLVL") == 0)
			a = a | 0x04;
		else if (ft_strcmp(env[i], "HOME") == 0)
			a = a | 0x08;
		i++;
	}
	if (!(a & 0x01))
		sf_pwdenv(t, "PWD");
	if (!(a & 0x02))
		sf_pwdenv(t, "OLDPWD");
	if (!(a & 0x04))
		add_env(t, ft_strdup("SHLVL=1"));
	if (!(a & 0x08))
		gethome(t);
}
