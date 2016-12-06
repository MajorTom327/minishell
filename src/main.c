/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 03:55:53 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	main(int ac, char **av, char **env)
{
	t_sh sh;

	dbg_title("init");
	sh.env = init_env(env);
	sh.cmd = init_cmd(&sh);
	dbg_title("terminal init");
	//terminal(sh);
	dbg_title("loop");
	//loop(sh);
	return (0);
}
