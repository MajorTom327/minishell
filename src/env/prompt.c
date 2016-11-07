/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:28:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/07 02:41:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env.h>
#include <libft.h>

static int	get_prompt_noenv(t_sh *e)
{
	char *prompt;
	char *col;
	char *pwd;

	pwd = get_pwd(e);
	col = (e->ret == 0) ? "\033[32m:\033[34m" : "\033[33m:\033[34m";
	prompt = ft_strdup("\033[90mminishell");
	prompt = ft_freejoin(prompt, col);
	prompt = ft_freejoin(prompt, pwd);
	prompt = ft_freejoin(prompt, "\033[90m>\033[0m ");
	e->prompt = ft_strdup(prompt);
	ft_strdel(&prompt);
	return ((e->prompt == NULL));
}

static int	get_prompt_env(t_sh *e)
{
	char	*prompt;
	char	*pwd;
	char	*col;
	char	*username;

	pwd = get_pwd(e);
	gethome(e->env);
	if (env_search(e->env, "USER") != NULL)
		username = (env_search(e->env, "USER"))->value;
	else
		username = NULL;
	col = (e->ret == 0) ? "\033[32m:\033[34m" : "\033[33m:\033[34m";
	if (username != NULL && ft_strlen(username) > 0)
	{
		prompt = ft_strdup("\033[90m");
		prompt = ft_freejoin(prompt, username);
		prompt = ft_freejoin(prompt, col);
		prompt = ft_freejoin(prompt, pwd);
		prompt = ft_freejoin(prompt, "\033[90m>\033[0m ");
	}
	e->prompt = ft_strdup(prompt);
	ft_strdel(&prompt);
	return ((e->prompt == NULL));
}

int	get_prompt(t_sh *e)
{
	if (env_search(e->env, "USER") != NULL)
		return (get_prompt_env(e));
	return (get_prompt_noenv(e));
}
