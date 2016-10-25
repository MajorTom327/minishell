/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 07:02:46 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 08:48:07 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <unistd.h>
#include <libft.h>

int	cd(char *path, t_shenv *e)
{
	int ret;

	if (path == NULL)
		ret = chdir(e->home);
	else
		ret = chdir(path);
	if (ret == 0)
		return (0);
	ft_putstr("cd: Cannot access to: ");
	ft_putendl(path);
	return (1);
}

int	pwd(void)
{
	char buff[1024];

	getcwd(buff, 1024);
	ft_putendl(buff);
	return (0);
}

int	env(t_shenv *e)
{
	int i;

	i = -1;
	while (e->env[++i])
		ft_putendl(e->env[i]);
	return (0);
}

int	echo(char **cmd)
{
	ft_putendl("\033[33mThis builtin can have incorrect output\033[0m");
	int i;
	int f;

	i = 0;
	f = 0;
	while (cmd[++i])
	{
		if (cmd[i][0] != '-')
			break ;
		if (cmd[i][1] == 'e')//Print les char non affichable (\n)
			f = f | 0x01;
		else if (cmd[i][1] == 'E')//converti les char spec comme chaine de char
			f = f | 0x02;
		else if (cmd[i][1] == 'n')//Ne met pas \n a la fin
			f = f | 0x04;
	}
	if (!(f & 0x01))
	{
		*(ft_strchr(cmd[i], '\n')) = '$';
	}
	ft_putendl(cmd[i]);
}
