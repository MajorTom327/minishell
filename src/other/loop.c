/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 00:58:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	loop(t_sh *sh)
{
	int ret;
	int m_hash;
	char *buf;

	while ((ret = get_command(&buf)))
	{
		dbg_var_str("loop", "buf", buf, 1);
		ft_memdel(&buf);
	}
}
