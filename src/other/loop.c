/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 00:38:49 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

void	loop(t_sh *sh)
{
	int		ret;
	char	*buf;
	char	**cmd;
	size_t	l;

	dbg_info("loop", "loop start", 1);
	if (get_prompt(sh))
		exit(EXIT_FAILURE);
	ft_putstr(sh->prompt);
	while ((ret = get_next_line(0, &buf)))
	{
		dbg_var_str("loop", "buf", buf, 1);
		l = ft_strlen(buf);
		if (l != 0)
			cmd = clean_cmd(&buf);
		if (l == 0 || cmd == NULL)
		{
			ft_putstr(sh->prompt);
			ft_strdel(&buf);
			continue ;
		}
		//dbg_var_array_str("loop", "cmd", cmd, 2);
		//execute(sh, cmd);
		ft_strdel(&buf);
		if (get_prompt(sh))
			exit(EXIT_FAILURE);
		ft_putstr(sh->prompt);
	}
}
