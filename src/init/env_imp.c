/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_imp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:06:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 04:46:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

t_env	*add_env(t_env *env, const char *name, const char *value)
{
	int		i;
	t_env	*n_env;

	i = 0;
	while (env[i++].key != NULL)
		;
	exit_mem((n_env = (t_env *)ft_memalloc(sizeof(t_env) * (i + 2))));
	i = 0;
	while (env[i].key != NULL)
	{
		n_env[i].key = env[i].key;
		n_env[i].value = env[i].value;
		n_env[i].hash = env[i].hash;
		i++;
	}
	n_env[i].key = ft_strdup(name);
	n_env[i].value = ft_strdup(value);
	n_env[i].hash = hash(name);
	ft_memdel((void **)&env);
	return (n_env);
}

static void	sf_initshlvl(t_env *env)
{
	int i;
	int	value;

	i = 0;
	while (env[i].key != NULL)
	{
		if (env[i].hash == hash("SHLVL") && !ft_strcmp(env[i].key, "SHLVL"))
			break;
		i++;
	}
	value = ft_atoi(env[i].value) + 1;
	ft_strdel(&(env[i].value));
	env[i].value = ft_itoa(value);
}

t_env	*env_imp(t_env *env)
{
	int	found_var;
	int	i;

	found_var = 0;
	i = 0;
	while (env[i].key != NULL)
	{
		if (env[i].hash == hash("SHLVL") && !ft_strcmp(env[i].key, "SHLVL"))
			found_var = found_var | 0x01;
		else if (env[i].hash == hash("PWD") && !ft_strcmp(env[i].key, "PWD"))
			found_var = found_var | 0x02;
		else if (env[i].hash == hash("OLDPWD") &&
		!ft_strcmp(env[i].key, "OLDPWD"))
			found_var = found_var | 0x04;
		i++;
	}
	if (!(found_var & 0x01))
		env = add_env(env, "SHLVL", "1");
	else
		sf_initshlvl(env);
	if (!(found_var & 0x02))
		env = add_env(env, "PWD", "/Users/vthomas");
	if (!(found_var & 0x04))
		env = add_env(env, "OLDPWD", "/Users/vthomas");
	return (env);
}
