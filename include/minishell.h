/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:57:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 09:19:19 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_shenv
{
	char		*prompt;
	int			cont;
	char		**path;
	char		*home;
	char		*user;
	char		**env;
}				t_shenv;

typedef struct dirent	t_dirent;

int		set_prompt(char *new, t_shenv *env);
void	set_baseprompt(t_shenv *e);

void	save_env(char **env, int i, t_shenv *e);
int		set_env(t_shenv *e, char **env);
char	**env_key(char *str);

char	**get_cmd(char *cmd);
int		command(char *cmd, t_shenv *e);
int		command_executor(char **cmd, t_shenv *e);

int		cd(char *path, t_shenv *e);
int		pwd(void);
int		env(t_shenv *e);
int		echo(char **cmd);

int		search_prog(char **cmd, t_shenv *e);
int		execute(char **av, t_shenv *e, char *prog);

void	sigint_handler(int i);

#endif
