/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:50:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 06:24:33 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

int	main(int ac, char **av, char **env)
{
	t_shenv	e;
	char	*cmd;
	int		ret;

	set_env(&e, env);
	dbg_title("ENV DONE");
	dbg_var_array_str("main", "env", env, 0);
	while (e.cont)
	{
		ft_putstr_fd(e.prompt, 0);
		ret = get_next_line(0, &cmd);
		if (ret < 0)
			return (0);
		command(cmd, &e);
		if (ft_strcmp(cmd, "exit") == 0)
			exit(EXIT_SUCCESS);
	}
	return (0);
}
