/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:22:35 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 02:01:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

/*
** function name: hash
** params: char *
** return: int
** objectif:
** 		hash the string for have an value to add in the binaries tree and
** 		speed up the search.
*/

int	hash(char *str)
{
	int l;
	int i;

	l = 0;
	i = 0;
	while (str[i])
	{
		l += str[i];
		i++;
	}
	return (l);
}
