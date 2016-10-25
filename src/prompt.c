/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:58:02 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 00:09:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	set_prompt(char *new, t_shenv *env)
{
	if (ft_strlen(new) > 0)
	{
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
