/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:47:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 07:29:23 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char	**clean_cmd(char **cmd)
{
	char	**command;

	command = ft_strsplit(*cmd, ' ');
	dbg_var_array_str("clean", "command", (const char **)command, 3);
	ft_strdel(cmd);
	return (command);
}
