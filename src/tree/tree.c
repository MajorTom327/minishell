/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:36:27 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 03:57:25 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <minishell.h>
#include <libft.h>

t_tree	*tree(int hash, void *value)
{
	t_tree	*m_tree;

	exit_mem((void *)(m_tree = (t_tree *)ft_memalloc(sizeof(t_tree))));
	m_tree->hash = hash;
	m_tree->value = value;
	return (m_tree);
}

t_tree	*tree_search(t_tree *t, char *str)
{
	int m_hash;

	m_hash = hash(str);
	while (t)
	{
		if (t->hash > m_hash)
			t = t->left;
		else if (t->hash < m_hash)
			t = t->right;
		else
			return (t);
	}
}

t_tree	*tree_add(t_tree *t, int hash)
{
	t_tree *tmp;

	while (t)
	{
		if (t->hash > hash)
		{
			if (t->left == NULL)
				break;
			else
				t = t->left;
		}
		else if (t->hash <= hash)
		{
			if (t->right == NULL)
				break;
			else
				t = t->right;
		}
	}
	exit_mem((tmp = (t_tree *)ft_memalloc(sizeof(t_tree))));
	if (t->hash > hash)
		t->left = tmp;
	else
		t->right = tmp;
	tmp->parent = t;
	return (tmp);
}
