/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:32:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/20 15:14:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <unistd.h>
#include <stdlib.h>

int		b_exit(void *env, char **cmd)
{
	(void)env;
	(void)cmd;
	exit(0);
}
