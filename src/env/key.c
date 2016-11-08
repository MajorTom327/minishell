/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:20:46 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 07:49:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <env.h>
#include <tree.h>

char	*get_key(t_env *env)
{
	char *str;

	dbg_var_str("get_key", "key", env->key, 2);
//	dbg_var_str("get_key", "value", env->value, 2);
	str = ft_strdup(env->key);
	str = ft_freejoin(str, "=");
	str = ft_freejoin(str, env->value);
	return (str);
}

void	*set_key(t_env *env, char *str)
{
	char *key;
	char *value;

	dbg_var_str("set_key", "str", str, 2);
	key = str;
	value = ft_strdup(ft_strchr(str, '=') + 1);
	*(ft_strchr(str, '=')) = '\0';
	env->key = key;
	env->value = value;
}
