/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:10:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 00:59:00 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SH_BUILTIN	1
# define SH_ALIAS	2
# define VK_UP		65
# define VK_LEFT	68
# define VK_RIGHT	67
# define VK_DOWN	66

#include <tree.h>
#include <termios.h>
#include <debug.h>

typedef struct		s_cmd
{
	int				type;
	char			*name;
	char			*exec;
	int				(*f)(void *);
	void			*param;
}					t_cmd;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct		s_sh
{
	t_tree			*env;
	t_tree			*cmd;
}					t_sh;

int		hash(char *str);
t_sh	*init(char **env);

void	loop(t_sh *sh);
void	terminal(t_sh *sh);

void	input(char *str);
char	*strdelete(char *dst, char *src);
int		get_command(char **line);

void	exit_mem(void *mem);

#endif
