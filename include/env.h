/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:38:24 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 04:39:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>
# include <tree.h>

void	add_env(t_tree *t, char *str);
t_env	*env_search(t_tree *env, char *str);

void	add_cmd(t_tree *tcmd, t_cmd cmd);
t_cmd	cmd(char *name, int type, char *exec, void *param);
t_cmd	cmd_builtin(char *name, void *p, int (*f)(void *));
#endif
