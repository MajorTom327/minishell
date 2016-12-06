/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 00:32:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 00:45:21 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <libft.h>

int	get_prompt(t_sh *sh)
{
	char	buf[1024];

	ft_strdel(&(sh->prompt));
	sh->prompt = ft_strdup("\e[90mminishell");//change by username
	getcwd(buf, 1024);
	sh->prompt = ft_freejoin(sh->prompt, ((sh->ret) ? "\e[31m" : "\e[32m"));
	sh->prompt = ft_freejoin(sh->prompt, ":\e[34m");
	sh->prompt = ft_freejoin(sh->prompt, buf);
	sh->prompt = ft_freejoin(sh->prompt, "\033[90m>\e[0m ");
	return (0);
}
