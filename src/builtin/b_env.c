/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:40:12 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/11 05:02:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <builtin.h>
#include <minishell.h>

int		b_env(void *env, char **cmd)
{
	t_sh	*sh;
	int		i;

	(void)cmd;
	sh = (t_sh *)env;
	i = 0;
	dbg_title("b_env");
	while (i < sh->env_l)
	{
		//dbg_var_str("b_env", "current key", (sh->env[i]).key, 3);
		ft_putstr((sh->env[i]).key);
		ft_putchar('=');
		ft_putendl((sh->env[i]).value);
		i++;
	}
	dbg_title("b_env finished");
	return (0);
}
