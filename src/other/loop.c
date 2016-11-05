/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/05 22:43:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

void	loop(t_sh *sh)
{
	int ret;
	char *buf;
	char	path[1024];

	dbg_info("loop", "loop start", 1);
	if (get_prompt(sh))
		exit(EXIT_FAILURE);
	ft_putstr(sh->prompt);
	while ((ret = get_command(&buf)))
	{
		dbg_var_str("loop", "buf", buf, 1);
		build(sh);
		ft_memdel(&buf);
		if (get_prompt(sh))
			exit(EXIT_FAILURE);
		ft_putstr(sh->prompt);
	}
}
