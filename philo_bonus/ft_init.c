#include "philo.h"

static void	*ft_inside(void *func)
{
	t_philo			*philo;
	pthread_t		thread;

	philo = (t_philo *) func;
	if (pthread_create(&thread, NULL, (void *) ft_death, func))
		return ((void *) 1);
	pthread_detach(thread);
	while (1)
	{
		ft_forks(philo);
		if (philo->count == philo->param2->eat_count
			&& philo->param2->eat_count != 1)
			break ;
		printf("%lu %d %s\n", get_time() - philo->param2->start,
			philo->turn, "is sleeping");
		wait_for(philo->param2->time_to_sleep);
		printf("%lu %d %s\n", get_time() - philo->param2->start,
			philo->turn, "is thinking");
	}
	exit(0);
}

static int	ft_threads(t_philo *philo, int numb)
{
	int	a;

	a = -1;
	while (++a < numb)
	{
		if (a % 2 == 0 || a % 2 != 0)
		{
			philo[a].pid = fork();
			if (philo[a].pid < 0)
				return (1);
			if (philo[a].pid == 0)
				ft_inside(&(philo[a]));
		}
		usleep(100);
	}
	return (0);
}

static void	ft_init_philo(t_param *param)
{
	int	a;

	param->philo = (t_philo *)malloc((sizeof(t_philo) * param->counter));
	a = -1;
	while (++a < param->counter)
	{
		param->philo[a].turn = a + 1;
		param->philo[a].param2 = param;
		param->philo[a].count = 0;
		param->philo[a].is_eating = -1;
		param->philo[a].last_eat = get_time();
	}
}

static void	ft_init_args(int argc, char **argv, t_param *param)
{
	param->counter = ft_atoi(argv[1]);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_died");
	param->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, param->counter);
	param->died = sem_open("/philo_died", O_CREAT, S_IRWXU, 1);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->start = get_time();
	param->number = 0;
	param->died_flag = 0;
	if (argc == 6)
		param->eat_count = ft_atoi(argv[5]);
	else
		param->eat_count = -1;
}

void	ft_init(int argc, char **argv)
{
	t_param		*param;
	int			a;

	param = NULL;
	param = (t_param *)malloc(sizeof(t_param));
	ft_init_args(argc, argv, param);
	a = -1;
	ft_init_philo(param);
	ft_threads(param->philo, param->counter);
	ft_exit(param);
}
