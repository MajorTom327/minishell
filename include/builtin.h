/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:02:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/11 03:19:38 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		b_cd(void *env, char **cmd);
int		b_exit(void *env, char **cmd);
int		b_echo(void *env, char **cmd);
int		b_pwd(void *env, char **cmd);
int		b_env(void *env, char **cmd);

#endif
