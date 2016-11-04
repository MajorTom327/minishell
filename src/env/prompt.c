/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:28:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/04 01:43:51 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env.h>
#include <libft.h>

int	get_prompt(t_sh *e)
{
	char	*prompt;
	char	*pwd;
	char	*col;

	pwd = get_pwd(e);
	col = (e->ret == 0) ? "\033[32m:\033[34m" : "\033[33m:\033[34m";
	if ((env_search(e->env, "USER"))->value != NULL &&\
	ft_strlen((env_search(e->env, "USER"))->value) > 0)
	{
		prompt = ft_strdup("\033[90m");
		prompt = ft_freejoin(prompt, (env_search(e->env, "USER"))->value);
		prompt = ft_freejoin(prompt, col);
		prompt = ft_freejoin(prompt, pwd);
		prompt = ft_freejoin(prompt, "\033[0m> ");
	}
	if ((env_search(e->env, "USER"))->value == NULL ||\
	ft_strlen((env_search(e->env, "USER"))->value) <= 0 || prompt == NULL)
	{
		prompt = ft_strdup("\033[90mminishell");
		prompt = ft_freejoin(prompt, col);
		prompt = ft_freejoin(prompt, pwd);
		prompt = ft_freejoin(prompt, "\033[0m> ");
	}
	e->prompt = ft_strdup(prompt);
	ft_strdel(&prompt);
	//ft_strdel(&pwd);//TODO: a ajouter un cleanup si ~/**
	return ((e->prompt == NULL));
}
