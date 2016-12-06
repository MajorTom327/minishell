/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:13:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 03:32:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
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
	exit_mem((env = ft_memalloc(sizeof(t_env) * i)));
	i = 0;
	while (environ[i])
	{
		dbg_var_str("init_env", "current var", environ[i], 2);
		tmp = ft_strdup(environ[i]);
		tmp2 = ft_strchr(tmp, '=');
		*tmp2 = '\0';
		tmp2++;
		if (ft_strcmp(tmp, "SHLVL") == 0)
			tmp2 = ft_itoa(ft_atoi(tmp2) + 1);
		env[i].hash = hash(tmp);
		env[i].key = ft_strdup(tmp);
		env[i].value = ft_strdup(tmp2);
		if (ft_strcmp(tmp, "SHLVL") == 0)
			ft_strdel(&tmp2);
		ft_strdel(&tmp);
		i++;
	}
	return (env);
}
