/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 05:20:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 23:55:19 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>


void	input(char *str)
{
	if (str[0] == 12)
	{
		ft_putstr("\033[2J\033[0;0f");
		ft_strclr(str);
	}
	else if (str[0] == 4 || str[0] == 3)
		exit(EXIT_SUCCESS);
	else if (ft_strncmp(str, "\033[", 2) == 0)
	{
		//MOTION
		if (str[2] == VK_UP)
			dbg_info("input", "up pressed", 1);
		else if (str[2] == VK_LEFT)
			dbg_info("input", "left pressed", 1);
		else if (str[2] == VK_RIGHT)
			dbg_info("input", "right pressed", 1);
		else if (str[2] == VK_DOWN)
			dbg_info("input", "down pressed", 1);
		ft_strclr(str);
	}
	else if (ft_strchr(str, 127) != NULL)
	{
		dbg_info("input", "delete found", 1);
		ft_putstr("\033[2D \033[1D");
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
