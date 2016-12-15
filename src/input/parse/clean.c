/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:47:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/15 03:43:54 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

static void	sf_cleantab(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

char		**clean_cmd(char **cmd)
{
	char	**command;

	sf_cleantab(*cmd);
	command = ft_strsplit(*cmd, ' ');
	ft_strdel(cmd);
	return (command);
}
