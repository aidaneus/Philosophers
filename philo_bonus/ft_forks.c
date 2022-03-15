#include "philo.h"

static void	fork_mutex(t_philo *philo)
{
	sem_wait(philo->param2->forks);
	printf("%lu %d %s\n", get_time() - philo->param2->start,
		philo->turn, "has taken a fork");
	sem_wait(philo->param2->forks);
	printf("%lu %d %s\n", get_time() - philo->param2->start,
		philo->turn, "has taken a fork");
	printf("%lu %d %s\n", get_time() - philo->param2->start,
		philo->turn, "is eating");
}

void	ft_forks(t_philo *philo)
{
	fork_mutex(philo);
	philo->count += 1;
	philo->is_eating = 1;
	philo->last_eat = get_time();
	wait_for(philo->param2->time_to_eat);
	philo->is_eating = 0;
	sem_post(philo->param2->forks);
	sem_post(philo->param2->forks);
}
