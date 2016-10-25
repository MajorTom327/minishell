/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:50:41 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 01:55:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

int	main(int ac, char **av)
{
	t_shenv	e;
	char	*cmd;
	int		ret;

	set_env(&e);
	dbg_title("ENV DONE");
	while (e.cont)
	{
		ft_putstr_fd(e.prompt, 0);
		ret = get_next_line(0, &cmd);
		if (ret < 0)
			return (0);
		dbg_var_str("main", "cmd", cmd, 0);
		if (ft_strcmp(cmd, "exit") == 0)
		{
			ft_putendl("EXIT OK BANANE FLUTE");
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
