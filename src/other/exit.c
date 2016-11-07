/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:32:39 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 02:45:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

/*
** function name: exit_mem
** params: void *
** return: void
** objectif:
** 		check memory allocation and exit if failure.
*/

void	exit_mem(void *mem)
{
	if (mem == NULL)
	{
		ft_putendl("An memory error occured !");
		exit(EXIT_FAILURE);
	}
}

void	exit_success(void)
{
	ft_putchar('\n');
	exit(EXIT_SUCCESS);
}
