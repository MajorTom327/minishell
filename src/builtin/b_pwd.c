/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:00:45 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/11 03:08:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <builtin.h>

int		b_pwd(void *env, char **cmd)
{
	char buff[1024];

	(void)env;
	(void)cmd;
	getcwd(buff, 1024);
	ft_putendl(buff);
	return (0);
}
