/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_imp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:06:23 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:56:19 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

t_env		*add_env(t_sh *sh, const char *name, const char *value)
{
	int		i;
	t_env	*n_env;
	t_env	*env;

	i = 0;
	env = sh->env;
	while (i++ < sh->env_l)
		;
	exit_mem((n_env = (t_env *)ft_memalloc(sizeof(t_env) * (i + 2))));
	i = 0;
	while (i < sh->env_l)
	{
		n_env[i].key = env[i].key;
		n_env[i].value = env[i].value;
		n_env[i].hash = env[i].hash;
		i++;
	}
	n_env[i].key = ft_strdup(name);
	n_env[i].value = ft_strdup(value);
	n_env[i].hash = hash(name);
	sh->env_l++;
	ft_memdel((void **)&env);
	sh->env = n_env;
	return (n_env);
}

static void	sf_initshlvl(t_sh *sh)
{
	int i;
	int	value;

	i = 0;
	while (i < sh->env_l)
	{
		if (!ft_strcmp(sh->env[i].key, "SHLVL"))
			break ;
		i++;
	}
	value = ft_atoi(sh->env[i].value) + 1;
	ft_strdel(&(sh->env[i].value));
	sh->env[i].value = ft_itoa(value);
}

static void	sf_envimp(int found_var, t_sh *sh)
{
	char buf[1024];

	getcwd(buf, 1024);
	if (!(found_var & 0x01))
		sh->env = add_env(sh, "SHLVL", "1");
	else
		sf_initshlvl(sh);
	if (!(found_var & 0x02))
		sh->env = add_env(sh, "PWD", buf);
	if (!(found_var & 0x04))
		sh->env = add_env(sh, "OLDPWD", buf);
}

t_env		*env_imp(t_sh *sh)
{
	t_env	*env;
	int		found_var;
	int		i;

	found_var = 0;
	i = 0;
	env = sh->env;
	while (i < sh->env_l)
	{
		if (!ft_strcmp(env[i].key, "SHLVL"))
			found_var = found_var | 0x01;
		else if (!ft_strcmp(env[i].key, "PWD"))
			found_var = found_var | 0x02;
		else if (!ft_strcmp(env[i].key, "OLDPWD"))
			found_var = found_var | 0x04;
		i++;
	}
	dbg_var_int("env_imp", "after while", found_var, 3);
	sf_envimp(found_var, sh);
	return (env);
}
