#include "philo.h"

void	ft_exit(t_param *param)
{
	int	a;

	a = -1;
	pthread_mutex_lock(&param->died);
	pthread_mutex_unlock(&param->died);
	while (++a < param->counter)
	{
		pthread_mutex_destroy(&param->forks[a]);
		pthread_mutex_destroy(&param->philo[a].eat);
	}
	free(param->forks);
	pthread_mutex_destroy(&param->died);
	free(param->philo);
	free(param);
}

static int	ft_death_check(t_philo *philo)
{
	if (philo->is_eating == 0
		&& ((get_time() - philo->last_eat) > philo->param2->time_to_die))
	{
		philo->param2->died_flag += 1;
		if (philo->param2->died_flag == 1)
			printf("%lu %d %s\n",
				get_time() - philo->param2->start, philo->turn, "DIED");
		return (0);
	}
	else if ((philo->param2->time_to_die < philo->param2->time_to_eat
			|| philo->param2->time_to_die < philo->param2->time_to_eat)
		&& get_time() - philo->param2->start >= philo->param2->time_to_die)
	{
		philo->param2->died_flag += 1;
		if (philo->param2->died_flag == 1)
			printf("%lu %d %s\n", get_time() - philo->param2->start,
				philo->turn, "DIED");
		return (0);
	}
	return (1);
}

void	*ft_death(void *func)
{
	t_philo	*philo;

	philo = (t_philo *) func;
	while (1)
	{
		if (ft_death_check(philo) == 0)
			pthread_mutex_unlock(&philo->param2->died);
		usleep(1000);
	}
}
