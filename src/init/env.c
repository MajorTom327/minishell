/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:13:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/06 07:04:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
//#include <builtin.h>
#include <debug.h>

t_env	*init_env(t_sh *sh, char **environ)
{
	char	*tmp;
	int		i;

	i = 0;
	while (environ[i++])
		;
	//TODO: If no environ
	i = 0;
	exit_mem((void *)(sh->env = (t_env *)ft_memalloc(sizeof(t_env) * (i + 1))));
	while (environ[i])//tant que l'on est pas arriver a NULL
	{
		exit_mem((void *)(tmp = ft_strchr(environ[i], '=')));//Trouve le egal separateur
		*tmp = '\0';//remplace le egal par 0
		tmp++;//avance sur le premier char de la valeur
		sh->env[i].hash = hash(environ[i]);//set le hash actuel
		sh->env[i].key = ft_strdup(environ[i]);//set la cle avec une duplication de environ
		sh->env[i].value = ft_strdup(tmp);//set la valeur
		dbg_var_str("init_env", "current var", sh->env[i].key, 2);
		dbg_var_str("init_env", "current env", environ[i], 2);
		i++;//passe a la variable suivant
	}
	sh->env[i].key = NULL;
	dbg_info("init_env", "init ended", 4);
	i = 0;//reset de i
	while (sh->env[i].key)//tant que pas a la fin
	{
		ft_putstr("\033[32m");
		ft_putstr(sh->env[i].key);
		ft_putstr("\033[90m");
		ft_putchar('=');
		ft_putstr("\033[34m");
		ft_putstr(sh->env[i].value);
		ft_putendl("\033[0m");
		i++;
	}
	//b_env(env, NULL);
	dbg_info("init_env", "ended with success !", 2);
	//env = env_imp(env);
	return (sh->env);
}
