/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:06:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/20 14:30:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>

char	**parseenv(char **cmd)
{
	char **env;

	env = ft_memalloc(sizeof(char *) * 3);
	env[0] = ft_strdup(cmd[1]);
	if (ft_strchr(env[0], '='))
	{
		env[1] = ft_strdup(ft_strchr(env[0], '=') + 1);
		*(ft_strchr(env[0], '=')) = '\0';
		return (env);
	}
	else if (cmd[2] != NULL)
	{
		env[1] = ft_strdup(cmd[2]);
		return (env);
	}
	env[1] = ft_strnew(0);
	return (env);
}
