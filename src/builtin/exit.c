/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:01:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 05:09:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtin.h>
#include <stdlib.h>

int		b_exit(void *env, char **cmd)
{
	(void)env;
	(void)cmd;
	exit(EXIT_SUCCESS);
}
