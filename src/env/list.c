/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:55:19 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 03:59:11 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <tree.h>

char **env_list(t_tree *t)
{
	t_tree	*tmp;
	while (t)
	{
		tmp = t->left;
		while (tmp->left)//aller a fond a gauche
		{

		}
	}
}
