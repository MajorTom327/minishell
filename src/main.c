/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/15 03:14:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

int	main(int ac, char **av, char **env)
{
	t_sh sh;

	//dbg_title("init");
	init_env(&sh, env);
	sh.cmd = init_cmd(&sh);
	sh.progname = ft_strdup(av[0]);
	sh.home = NULL;
	//dbg_title("init finished");
	//dbg_var_str("main", "sh.progname", sh.progname, 1);
	//dbg_title("loop");
	loop(&sh);
	return (0);
}
