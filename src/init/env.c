/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:13:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 05:27:29 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>
#include <debug.h>

t_env	*init_env(char **environ)
{
	t_env	*env;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (environ[i++])
		;
// SET THE DEFAULT ENV IF ```env -i```
//	if (i == 0)
//		return (default_env());
	i = 0;
	exit_mem((env = ft_memalloc(sizeof(t_env) * (i + 2))));
	while (environ[i])
	{
		dbg_var_str("init_env", "current var", environ[i], 2);
		tmp = ft_strdup(environ[i]);
		if (tmp == NULL)
			break;
		tmp2 = ft_strchr(tmp, '=');
		if (tmp2 != NULL)
		{
			*tmp2 = '\0';
			tmp2++;
		}
		env[i].hash = hash(tmp);
		dbg_var_str("init_env", "after hash", tmp, 2);
		env[i].key = ft_strdup(tmp);
		dbg_var_str("init_env", "after set key", tmp, 2);
		env[i].value = (tmp2 != NULL) ? ft_strdup(tmp2) : ft_strdup("");
		ft_strdel(&tmp);
		dbg_var_str("init_env", "env[i].key", env[i].key, 2);
		dbg_breakpoint("init_env", 2);
		i++;
	}
	dbg_info("init_env", "init ended", 4);
	i = 0;
	while (env[i].key)
	{
		ft_putstr(env[i].key);
		ft_putchar('=');
		ft_putendl(env[i].value);
		i++;
	}
	//b_env(env, NULL);
	dbg_info("init_env", "ended with success !", 2);
	//env = env_imp(env);
	return (env);
}
