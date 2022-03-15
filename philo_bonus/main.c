#include "philo.h"

static int	ft_check2(char **argv)
{
	if (ft_atoi(argv[1]) == 1)
	{
		printf("1 1 DIED\n");
		return (1);
	}
	return (0);
}

static int	ft_check(int argc, char **argv)
{
	int	a;
	int	b;

	a = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error with arguments\n");
		return (1);
	}
	while (++a < argc)
	{
		b = -1;
		while (argv[a] && argv[a][++b])
		{
			if (!(argv[a][b] >= '0' && argv[a][b] <= '9'))
			{
				printf("Error with symbols\n");
				return (1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if ((ft_check(argc, argv)) || ft_check2(argv))
		return (0);
	ft_init(argc, argv);
	return (0);
}
