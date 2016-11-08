/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 05:20:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 09:12:07 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

static void	clearscreen(t_sh *sh, char *line, char *str)
{
	ft_putstr("\033[2J\033[0;0f");
	ft_putstr(sh->prompt);
	ft_putstr(line);
	ft_strclr(str);
}

void		input(char *str, int l, char *line, t_sh *sh)
{
	if (str[0] == 12)
		clearscreen(sh, line, str);
	else if (str[0] == 4 || str[0] == 3)
		b_exit((void *)sh, NULL);
	else if (ft_strncmp(str, "\033[", 2) == 0)
	{
		if (str[2] == VK_UP)
			ft_putstr("\033[1B");
		else if (str[2] == VK_LEFT)
			ft_putstr("\033[1C");
		else if (str[2] == VK_RIGHT)
			ft_putstr("\033[1D");
		else if (str[2] == VK_DOWN)
			ft_putstr("\033[1A");
		ft_strclr(str);
	}
	else if (ft_strchr(str, 127) != NULL)
	{
		if (l)
			ft_putstr("\033[2D \033[1D");
		else
			ft_putstr("\033[1D");
	}
}

char		*strdelete(char *dst, char *src)
{
	if (src[0] == 127)
	{
		if (dst[ft_strlen(dst) - 1] == '\t')
			ft_putstr("\033[3D");
		dst[ft_strlen(dst) - 1] = '\0';
	}
	else
		return (ft_freejoin(dst, src));
	return (dst);
}
