/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:47:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 05:25:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char	**clean_cmd(char **cmd)
{
	char	**command;

	command = ft_strsplit(ft_strtrim(*cmd), ' ');
	ft_strdel(cmd);
	return (command);
}
