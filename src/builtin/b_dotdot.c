/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dotdot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 03:33:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:36:32 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>

int		b_dotdot(void *env, char **cmd)
{
	char **str;

	(void)cmd;
	str = ft_strsplit("cd ..", ' ');
	b_cd(env, str);
	ft_strdel(&str[0]);
	ft_strdel(&str[1]);
	ft_strdel(&str[2]);
	ft_memdel((void **)&str);
}
