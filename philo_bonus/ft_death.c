#include "philo.h"

void	ft_exit(t_param *param)
{
	int	a;
	int	b;
	int	c;

	a = -1;
	while (++a < param->counter)
	{
		waitpid(-1, &b, 0);
		if (b != 0)
		{
			c = -1;
			while (++c < param->counter)
				kill(param->philo[c].pid, 15);
			break ;
		}
	}
	sem_close(param->died);
	sem_close(param->forks);
	sem_unlink("/philo_died");
	sem_unlink("/philo_forks");
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
		{
			sem_post(philo->param2->died);
			exit(1);
		}
		if (philo->param2->number == philo->param2->counter)
		{
			sem_post(philo->param2->died);
			exit(0);
		}
		usleep(1000);
	}
}
