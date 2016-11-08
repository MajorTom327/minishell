/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:01:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 05:59:29 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <libft.h>
#include <stdlib.h>

int			b_exit(void *env, char **cmd)
{
	(void)env;
	if (cmd == NULL)
		ft_putchar('\n');
	exit(EXIT_SUCCESS);
}
