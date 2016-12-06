/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 06:33:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

int	main(int ac, char **av, char **env)
{
	t_sh sh;

	dbg_title("init");
	init_env(&sh, env);
	sh.cmd = init_cmd(&sh);
	dbg_title("init finished");
	//terminal(sh);
//	int		i;
//
//	i = 0;
//	dbg_info("b_env", "Start show env", 3);
//	while (sh.env[i].key != NULL)
//	{
//		dbg_var_str("b_env", "current key", sh.env[i].key, 3);
//		ft_putstr(sh.env[i].key);
//		ft_putchar('=');
//		ft_putendl(sh.env[i].value);
//		i++;
//	}
	//b_env((void *)&sh, NULL);
	dbg_title("loop");
	//loop(sh);
	return (0);
}
