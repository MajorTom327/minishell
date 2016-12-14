/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:13:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/14 03:58:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

static void	sf_parseenv(char *e, char **key, char **value)
{
	int i;

	i = 0;
	while (e[i] != '=')
		i++;
	e[i] = '\0';
	*key = ft_strdup(e);
	*value = ft_strdup(&e[i + 1]);
}

t_env		*init_env(t_sh *sh, char **environ)
{
	int		i;

	i = 0;
	while (environ[i++])
		;
	exit_mem((void *)(sh->env = (t_env *)ft_memalloc(sizeof(t_env) * (i + 1))));
	i = 0;
	while (environ[i])
	{
		sf_parseenv(environ[i], &(sh->env[i].key), &(sh->env[i].value));
		i++;
	}
	sh->env_l = i;
	dbg_info("init_env", "init ended", 4);
	dbg_info("init_env", "ended with success !", 2);
	env_imp(sh);
	return (sh->env);
}
