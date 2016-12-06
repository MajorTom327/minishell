/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:10:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/07 00:36:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUILTIN_NB	6
# define VK_UP		65
# define VK_LEFT	68
# define VK_RIGHT	67
# define VK_DOWN	66

#include <termios.h>
#include <debug.h>

typedef struct		s_cmd
{
	int				hash;
	char			*name;
	int				(*f)(void *, char **);
	void			*param;
}					t_cmd;

typedef struct		s_env
{
	int				hash;
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_sh
{
	t_env			*env;
	t_cmd			*cmd;
	char			*prompt;
	int				ret;
	int				env_l;
}					t_sh;

int		hash(const char *str);

t_env	*init_env(t_sh *sh, char **environ);
t_cmd	*init_cmd(t_sh *sh);

int	get_prompt(t_sh *sh);

t_env	*env_imp(t_sh *sh);
t_env	*add_env(t_sh *sh, const char *name, const char *value);

void	loop(t_sh *sh);
void	terminal(t_sh *sh);

void	exit_mem(void *mem);
void	exit_success(void);

#endif
