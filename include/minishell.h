/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:10:50 by vthomas           #+#    #+#             */
/*   Updated: 2017/01/02 23:23:05 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define VK_UP		65
# define VK_LEFT	68
# define VK_RIGHT	67
# define VK_DOWN	66

# include <termios.h>
# include <debug.h>
# include <dirent.h>

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
	char			*progname;
	char			*prompt;
	char			*home;
	int				ret;
	int				env_l;
}					t_sh;

typedef struct dirent	t_dirent;

int		hash(const char *str);

t_env	*init_env(t_sh *sh, char **environ);
t_cmd	*init_cmd(t_sh *sh);

int		get_prompt(t_sh *sh);
char	*get_home(t_sh *sh);

t_env	*env_imp(t_sh *sh);
t_env	*add_env(t_sh *sh, const char *name, const char *value);
int		env_search(t_sh *sh, const char *str);
int		cmd_search(t_sh *sh, const char *str);
int		prog_search(t_sh *sh, char **cmd);

void	loop(t_sh *sh);
char	**clean_cmd(char **cmd);
int		execute(t_sh *sh, char **cmd, int st);
int		execute_exe(t_sh *sh, char **cmd, int st);

void	exit_mem(void *mem);
void	exit_success(void);

#endif
