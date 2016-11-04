#include <minishell.h>
#include <unistd.h>
#include <libft.h>
#include <debug.h>

int	cd(t_sh *e, char **cmd)
{
	int		ret;
	char	*path;

	if (cmd[1] == NULL)
		path = ft_strdup(e->home);
	else
	{
		if (cmd[1][0] == '~')
		{
			path = ft_strdup(e->home);
			path = ft_freejoin(path, &cmd[1][1]);
		}
		else
			path = ft_strdup(&cmd[1][0]);
	}
	dbg_var_str("cd", "path", path, 3);
	ret = chdir(path);
	if (ret != 0)
		ft_putendl("An error occured !");
	ft_strdel(&path);
	return (ret);
}
