/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 01:42:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <get_next_line.h>
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
	cmd = NULL;
	while ((ret = get_next_line(0, &buf)))
	{
		dbg_var_str("loop", "buf", buf, 1);
		//ft_memdel(&(cmd));
		cmd = NULL;
		l = ft_strlen(buf);
		if (l != 0)
			cmd = clean_cmd(&buf);
		if (l == 0 || cmd == NULL)
		{
			dbg_info("loop", "cmd == NULL", 2);
			ft_putstr(sh->prompt);
			ft_strdel(&buf);
			continue ;
		}
		dbg_var_array_str("loop", "cmd", cmd, 2);
//		execute(sh, cmd);
		ft_strdel(&buf);
		if (get_prompt(sh))
			exit(EXIT_FAILURE);
		ft_putstr(sh->prompt);
	}
}
