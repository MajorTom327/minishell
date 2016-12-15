/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:30:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/12/15 03:27:39 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <dirent.h>

static char	*sf_dirsearch(DIR *m_dir, char *name)
{
	t_dirent	*m_dirent;

	while ((m_dirent = readdir(m_dir)))
	{
		if (ft_strcmp(m_dirent->d_name, name) == 0)
			return (ft_strdup(m_dirent->d_name));
	}
	return (NULL);
}

int			prog_search(t_sh *sh, char **cmd)
{
	char	**dir;
	char	*tmp;
	int		i;
	DIR		*m_dir;

	if ((i = env_search(sh, "PATH")) == -1)
		return (-1);
	dir = ft_strsplit(sh->env[i].value, ':');
	i = -1;
	while (dir[++i])
	{
		//
		m_dir = opendir(dir[i]);
		//
		if ((tmp = sf_dirsearch(m_dir, cmd[0])))
			break ;
		closedir(m_dir);
		m_dir = NULL;
	}
	if (m_dir != NULL)
		closedir(m_dir);
	if (tmp)
	{
		ft_strdel(&cmd[0]);
		cmd[0] = ft_strdup(dir[i]);
		cmd[0] = ft_freejoin(cmd[0], "/");
		cmd[0] = ft_freejoin(cmd[0], tmp);
		ft_strdel(&tmp);
	}
	i = (!dir[i]) ? -1 : 0;
	ft_strtabdel(dir);
	ft_memdel((void **)&dir);
	return (i);
}
