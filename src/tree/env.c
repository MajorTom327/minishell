/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 02:12:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 06:12:48 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <minishell.h>
#include <env.h>
#include <libft.h>

void	add_env(t_tree *t, char *str)
{
	int		m_hash;
	char	*key;
	char	*value;
	t_tree	*tmp;
	t_env	*env;

	dbg_var_str("add_env", "env str", str, 2);
	key = ft_strdup(str);
	value = ft_strchr(key, '=') + 1;
	*(value - 1) = '\0';
	m_hash = hash(key);
	tmp = tree_add(t, m_hash);
	tmp->hash = m_hash;
	exit_mem(env = (t_env *)ft_memalloc(sizeof(t_env)));
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	tmp->value = (void *)env;
	ft_strdel(&key);
}

t_env	*env_search(t_tree *env, char *str)
{
	int	m_hash;

	m_hash = hash(str);
	while (env->hash != m_hash && ft_strcmp(((t_env *)env->value)->key, str))
	{
		env = tree_search(env, str);
		if (env == NULL)
			return (NULL);
	}
	return ((t_env *)env->value);
}

void	env_array_free(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_strdel(&env[i]);
		i++;
	}
	ft_memdel((void **)&env);
}
