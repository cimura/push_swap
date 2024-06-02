#include "libft/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	write(fd, &*s, ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	five_patterns_sort(int *a, int *b, int *c)
{
	if (*a == 1 && *b == 3 && *c == 2)
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("ra\n", 1);
	}
	else if (*a == 2 && *b == 1 && *c == 3)
	{
		ft_putstr_fd("sa\n", 1);
	}
	else if (*a == 2 && *b == 3 && *c == 1)
	{
		ft_putstr_fd("rra\n", 1);
	}
	else if (*a == 3 && *b == 1 && *c == 2)
	{
		ft_putstr_fd("ra\n", 1);
	}
	else if (*a == 3 && *b == 2 && *c == 1)
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
	}
	else
		return ;
}

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);
		int num3 = atoi(argv[3]);
		five_patterns_sort(&num1, &num2, &num3);
	}
}