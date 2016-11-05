/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 05:20:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/05 23:55:33 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>


void	input(char *str, int l)
{
	if (str[0] == 12)
	{
		ft_putstr("\033[2J\033[0;0f");
		ft_strclr(str);
	}
	else if (str[0] == 4 || str[0] == 3)
		exit_success();
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

char	*strdelete(char *dst, char *src)
{
	if (src[0] == 127)
		dst[ft_strlen(dst) - 1] = '\0';
	else
		return (ft_freejoin(dst, src));
	return (dst);
}
