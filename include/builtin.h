/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:02:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 22:16:16 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define BUILTIN_NB 9

enum	e_builtin
{
	e_echo,
	e_setenv,
	e_unsetenv,
	e_env,
	e_cd,
	e_pwd,
	e_exit,
	e_builtin,
	e_dotdot
};

char	**parseenv(char **cmd);

int		b_cd(void *env, char **cmd);
int		b_exit(void *env, char **cmd);
int		b_echo(void *env, char **cmd);
int		b_pwd(void *env, char **cmd);
int		b_env(void *env, char **cmd);
int		b_setenv(void *env, char **cmd);
int		b_builtin(void *env, char **cmd);
int		b_dotdot(void *env, char **cmd);

#endif
