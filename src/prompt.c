/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:58:02 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 06:54:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <debug.h>

int	set_prompt(char *new, t_shenv *env)
{
	if (ft_strlen(new) > 0)
	{
		if (env->prompt != NULL)
			ft_strdel(&(env->prompt));
		env->prompt = ft_strdup(new);
	}
	else
	{
		if (env->prompt != NULL)
			ft_strdel(&(env->prompt));
		env->prompt = "$>";
	}
	env->prompt = free_join(env->prompt, " ");
	return (0);
}

void	set_baseprompt(t_shenv *e)
{
	char	*str;

	str = ft_strdup("\033[90m");
	str = free_join(str, e->user);
	str = free_join(str, "\033[0m> ");
	e->prompt = ft_strdup(str);
	ft_strdel(&str);
}
