/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_dotdot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 03:33:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 04:25:21 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>

int		b_dotdot(void *env, char **cmd)
{
	char	**str;
	int		r;

	(void)cmd;
	str = ft_strsplit("cd ..", ' ');
	r = b_cd(env, str);
	ft_strtabdel(str);
	ft_memdel((void **)&str);
	return (r);
}
