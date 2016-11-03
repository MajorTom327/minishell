/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:37:04 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 02:29:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef	struct		s_tree
{
	int				hash;
	void			*value;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

t_tree	*tree(int hash, void *value);
t_tree	*tree_search(t_tree *t, char *str);
t_tree	*tree_add(t_tree *t, int hash);

#endif
