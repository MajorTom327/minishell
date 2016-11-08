#include <unistd.h>

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
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
