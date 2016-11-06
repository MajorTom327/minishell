/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:10:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/06 05:45:55 by vthomas          ###   ########.fr       */
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
	int				(*f)(void *, char **);
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
	char			*prompt;
	int				ret;
}					t_sh;

int		hash(char *str);
t_sh	*init(char **env);

void	loop(t_sh *sh);
void	terminal(t_sh *sh);

void	input(char *str, int l);
char	*strdelete(char *dst, char *src);
int		get_command(char **line);
int		get_prompt(t_sh *e);

void	exit_mem(void *mem);
void	exit_success(void);

char	*get_pwd(t_sh *e);
int		pwd(void *v_par, char **cmd);
int		cd(void *env, char **cmd);

char	**clean_cmd(char **cmd);
int		execute(t_sh *sh, char **cmd);

#endif
