/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 00:11:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 07:30:05 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <debug.h>

void	save_env(char **env, int i, t_shenv *e)
{
	int t;

	if (e->env != NULL)
		ft_memdel(e->env);
	e->env = (char **)ft_memalloc(sizeof(char *) * i + 1);
	t = 0;
	while (t < i)
	{
		e->env[t] = ft_strdup(env[t]);
		t++;
	}
}

int		set_env(t_shenv *e, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			e->path = env_key(env[i]);
		else if (ft_strncmp(env[i], "HOME", 4) == 0)
			e->home = ft_strdup(ft_strchr(env[i], '=') + 1);
		else if (ft_strncmp(env[i], "USER", 4) == 0)
			e->user = ft_strdup(ft_strchr(env[i], '=') + 1);
		i++;
	}
	if (i == 0)
	{
		ft_putendl("\033[31mEnvironment failure\033[0m");
		exit(EXIT_FAILURE);
	}
	save_env(env, i, e);
	set_baseprompt(e);
	e->cont = 1;
}

char	**env_key(char *str)
{
	char	**key;
	char	*tmp;
	int		i;
	int		c;

	i = 0;
	tmp = str;
	while ((tmp = ft_strchr(tmp, ':')) != NULL)
	{
		i++;
		tmp++;
	}
	i++;
	dbg_var_int("env_key", "number of arg", i, 3);
	key = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	if (key == NULL)
		return (NULL);
	tmp = ft_strchr(str, '=') + 1;
	c = 0;
	while (c < i)
	{
		str = ft_strchr(tmp, ':');
		key[c] = ft_memalloc(sizeof(char) * ((str != NULL) ? str - tmp : ft_strlen(tmp)));
		key[c] = ft_strncpy(key[c], tmp, ((str != NULL) ? str - tmp : ft_strlen(tmp)));
		c++;
		tmp = ft_strchr(tmp, ':');
		tmp++;
	}
	return (key);
}
