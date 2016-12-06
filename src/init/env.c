/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:13:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 08:29:18 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
//#include <builtin.h>
#include <debug.h>

static void	sf_parseenv(char *e, char **key, char **value)
{
	int i;
	char *tmp;

	i = 0;
	while (e[i] != '=')
		i++;
	e[i] = '\0';
	*key = ft_strdup(e);
	*value = ft_strdup(&e[i + 1]);
}

t_env	*init_env(t_sh *sh, char **environ)
{
	char	*tmp;
	int		i;

	i = 0;
	while (environ[i++])
		;
	//TODO: If no environ
	exit_mem((void *)(sh->env = (t_env *)ft_memalloc(sizeof(t_env) * (i + 1))));
	i = 0;
	while (environ[i])//tant que l'on est pas arriver a NULL
	{
		sf_parseenv(environ[i], &(sh->env[i].key), &(sh->env[i].value));
		dbg_var_str("init_env", "current var", (sh->env[i]).key, 2);
		dbg_var_str("init_env", "current env", environ[i], 2);
		i++;//passe a la variable suivante
	}
	sh->env_l = i;
	dbg_info("init_env", "init ended", 4);
//	i = 0;//reset de i
//	while (i < sh->env_l)//tant que pas a la fin
//	{
//		ft_putstr("\033[32m");
//		ft_putstr(sh->env[i].key);
//		ft_putstr("\033[90m");
//		ft_putchar('=');
//		ft_putstr("\033[34m");
//		ft_putstr(sh->env[i].value);
//		ft_putendl("\033[0m");
//		i++;
//	}
	b_env(sh, NULL);
	dbg_info("init_env", "ended with success !", 2);
	//env = env_imp(env);
	return (sh->env);
}
