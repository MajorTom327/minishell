/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:11:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/11 03:27:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

int	b_echo(void *env, char **cmd)
{
	int i;
	int param;

	i = 1;
	if (cmd[i] != NULL && cmd[i][0] == '-')
	{
		param = (cmd[i][1] == 'n') ? 1 : 0;
		i++;
	}
	else
		param = 0;
	while (cmd[i])
	{
		ft_putstr(cmd[i]);
		i++;
		if (cmd[i])
			ft_putchar(' ');
	}
	if (!param)
		ft_putchar('\n');
	return (0);
}
