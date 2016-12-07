/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 01:13:08 by vthomas          ###   ########.fr       */
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
	sh.home = NULL;
	//b_env((void *)&sh, NULL);
	dbg_title("loop");
	loop(&sh);
	return (0);
}
