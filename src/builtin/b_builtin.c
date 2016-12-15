/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:38:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/15 02:58:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <minishell.h>
#include <libft.h>

int	b_builtin(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	sh = (t_sh *)env;
	(void)cmd;
	i = 0;
	while (i < BUILTIN_NB)
	{
		ft_putstr(sh->cmd[i].name);
		if (i < BUILTIN_NB - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putchar('\n');
	return (0);
}
