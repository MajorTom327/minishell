/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subcommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 08:49:20 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 09:23:50 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <dirent.h>
#include <unistd.h>

int	search_prog(char **cmd, t_shenv *e)
{
	int			i;
	DIR			*d;
	t_dirent	*t;
	char		*prog;

	i = 0;
	while (e->path[i])
	{
		d = opendir((const char *)e->path[i]);
		dbg_var_str("search_prog", "current dir", e->path[i], 4);
		while ((t = readdir(d)) != NULL)
		{
			if (ft_strcmp(t->d_name, cmd[0]) == 0)
			{
				closedir(d);
				prog = ft_strnew(ft_strlen(e->path[i]) + ft_strlen(cmd[0]) + 1);
				prog = ft_strcat(prog, e->path[i]);
				if (prog[ft_strlen(prog) - 1] != '/')
					prog = ft_strcat(prog, "/");
				prog = ft_strcat(prog, cmd[0]);
				ft_putendl(prog);
				execute(&cmd[0], e, prog);
				return (0);
			}
		}
		closedir(d);
		i++;
	}
	return (1);
}

int	execute(char **av, t_shenv *e, char *prog)
{
	pid_t	parent;

	parent = fork();
	if (parent > 0)
	{
		wait(parent);
	}
	else
	{
		dbg_var_array_str("execute", "av", av, 4);
		execve(prog, av, NULL);
	}
}
