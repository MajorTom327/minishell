/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 03:52:57 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 09:00:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <debug.h>

char	**get_cmd(char *cmd)
{
	int		i;
	int		p;
	char	**str;

	p = 0;
	i = 0;
	str = (char **)ft_memalloc(sizeof(char *) * 32);
	if (str == NULL)
		exit(EXIT_FAILURE);
	while (cmd[i])
	{
		while (*cmd && (*cmd == ' ' || *cmd == '\t'))
			cmd++;
		i = 0;
		if (*cmd != '"')
			while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
				i++;
		else
		{
			cmd++;
			while (cmd[i] && cmd[i] != '"')
				i++;
		}
		str[p] = ft_strnew(i);
		ft_strncpy(str[p], (const char *)cmd, (unsigned int)i);
		p++;
		cmd += i;
	}
	return (str);
}

int	command(char *cmd, t_shenv *e)
{
	char **fcmd;

	fcmd = get_cmd(cmd);
	fcmd[0] = ft_strlower(fcmd[0]);
	//dbg_var_array_str("command", "fcmd", fcmd, 1);
	command_executor(fcmd, e);
	return (0);
}

int	command_executor(char **cmd, t_shenv *e)
{
	char	*buf;

	if (ft_strcmp(cmd[0], "echo") == 0)
		echo(cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		cd(cmd[1], e);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(cmd[0], "env") == 0)
		env(e);
	else if (ft_strcmp(cmd[0], "clear") == 0)
		ft_putstr("\033[2J\033[0;0f");
	else if (ft_strcmp(cmd[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (search_prog(cmd, e))
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(cmd[0]);
	}
}
