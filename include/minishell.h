/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:10:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 03:33:30 by vthomas          ###   ########.fr       */
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

#include <termios.h>
#include <debug.h>

typedef struct		s_cmd
{
	int				type;
	int				hash;
	char			*name;
	char			*exec;
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
}					t_sh;

int		hash(const char *str);

t_env	*init_env(char **environ);

void	loop(t_sh *sh);
void	terminal(t_sh *sh);

char	**clean_cmd(char **cmd);
void	input(char *str, int l, char *line, t_sh *sh);
char	*strdelete(char *dst, char *src);
int		get_command(char **line, t_sh *sh);

void	exit_mem(void *mem);
void	exit_success(void);

#endif
