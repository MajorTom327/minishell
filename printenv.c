#include <unistd.h>

void	putstr(char *str)
{
	int i;

	i = 0;
	write(1, "\e[32m", 5);
	while (str[i])
	{
		if (str[i] == '=')
			write(1, "\e[90m", 5);
		else if (i > 0 && str[i - 1] == '=')
			write(1, "\e[34m", 5);
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\e[0m\n", 5);
}

int main(int ac, char **av, char **environ)
{
	int i;

	i = 0;
	(void)ac;
	(void)av;
	while (environ[i] != NULL)
	{
		putstr(environ[i]);
		i++;
	}
	return (0);
}
