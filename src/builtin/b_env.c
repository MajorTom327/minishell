/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:40:12 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 05:06:29 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <builtin.h>
#include <minishell.h>
#include <debug.h>

int		b_env(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	(void)cmd;
	sh = (t_sh *)env;
	i = 0;
	dbg_info("b_env", "Start show env", 3);
	while (sh->env[i].key != NULL)
	{
		dbg_var_str("b_env", "current key", sh->env[i].key, 3);
		ft_putstr(sh->env[i].key);
		ft_putchar('=');
		ft_putendl(sh->env[i].value);
		i++;
	}
	dbg_info("b_env", "end show env", 3);
	return (0);
}
