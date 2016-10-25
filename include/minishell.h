/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:57:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 01:38:51 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_shenv
{
	char		*prompt;
	int			cont;
}				t_shenv;

int		set_prompt(char *new, t_shenv *env);
int		set_env(t_shenv *e);

void	sigint_handler(int i);

#endif
