/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:50:47 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/02 23:23:32 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <get_next_line.h>
#include <stdlib.h>

static void	sf_deletecmd(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		ft_strdel(&cmd[i]);
		i++;
	}
	ft_memdel((void **)&cmd);
}

void		loop(t_sh *sh)
{
	int		ret;
	char	*buf;
	char	**cmd;
	size_t	l;

	if (get_prompt(sh))
		exit(EXIT_FAILURE);
	ft_putstr(sh->prompt);
	while ((ret = get_next_line(0, &buf)))
	{
		cmd = NULL;
		l = ft_strlen(buf);
		if (l != 0)
			cmd = clean_cmd(&buf);
		if (l == 0 || cmd == NULL)
		{
			ft_putstr(sh->prompt);
			ft_strdel(&buf);
			continue ;
		}
		execute(sh, cmd, 0);
		sf_deletecmd(cmd);
		ft_strdel(&buf);
		if (get_prompt(sh))
			exit(EXIT_FAILURE);
		ft_putstr(sh->prompt);
	}
}
