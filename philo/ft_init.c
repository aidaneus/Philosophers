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
		if (philo->count == philo->param2->eat_count)
			philo->param2->number++;
		if (philo->param2->number == philo->param2->counter)
			pthread_mutex_unlock(&philo->param2->died);
		printf("%lu %d %s\n", get_time() - philo->param2->start,
			philo->turn, "is sleeping");
		wait_for(philo->param2->time_to_sleep);
		printf("%lu %d %s\n", get_time() - philo->param2->start,
			philo->turn, "is thinking");
	}
}

static int	ft_threads(t_philo *philo, int number)
{
	int	a;

	a = -1;
	while (++a < number)
	{
		if (a % 2 == 0 || a % 2 != 0)
		{
			if (pthread_create(&philo[a].tid, NULL, (void *) ft_inside,
					(void *) &philo[a]))
				return (1);
			pthread_detach(philo[a].tid);
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
		param->philo[a].left_fork = &param->forks[a];
		param->philo[a].right_fork = &param->forks[(a + 1) % param->counter];
		param->philo[a].is_eating = -1;
		param->philo[a].last_eat = get_time();
		pthread_mutex_init(&param->philo[a].eat, NULL);
		pthread_mutex_lock(&param->philo[a].eat);
	}
}

static void	ft_init_args(int argc, char **argv, t_param *param)
{
	param->counter = ft_atoi(argv[1]);
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
	param->forks = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t)
				* param->counter));
}

void	ft_init(int argc, char **argv)
{
	t_param		*param;
	int			a;

	param = NULL;
	param = (t_param *)malloc(sizeof(t_param));
	ft_init_args(argc, argv, param);
	a = -1;
	while (++a < param->counter)
		pthread_mutex_init(&param->forks[a], NULL);
	pthread_mutex_init(&param->died, NULL);
	pthread_mutex_lock(&param->died);
	ft_init_philo(param);
	ft_threads(param->philo, param->counter);
	ft_exit(param);
}
