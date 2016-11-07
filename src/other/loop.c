/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 02:54:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <env.h>
#include <stdlib.h>

void	loop(t_sh *sh)
{
	int ret;
	char *buf;
	char	**cmd;

	dbg_info("loop", "loop start", 1);
	if (get_prompt(sh))
		exit(EXIT_FAILURE);
	ft_putstr(sh->prompt);
	while ((ret = get_command(&buf, sh)))
	{
		dbg_var_str("loop", "buf", buf, 1);
		if (ft_strlen(buf) == 0 || (cmd = clean_cmd(&buf)) == NULL)
		{
			ft_putstr(sh->prompt);
			ft_strdel(&buf);
			continue ;
		}
		//cmd = clean_cmd(&buf);
//		dbg_var_array_str("loop", "cmd", cmd, 2);
		execute(sh, cmd);
		ft_strdel(&buf);
		if (get_prompt(sh))
			exit(EXIT_FAILURE);
		ft_putstr(sh->prompt);
	}
}
