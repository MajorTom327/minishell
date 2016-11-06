/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:20:46 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 03:44:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <env.h>
#include <tree.h>

char	*get_key(t_env *env)
{
	char *str;

	str = ft_strdup(env->key);
	str = ft_freejoin(str, "=");
	str = ft_freejoin(str, env->value);
	return (str);
}
