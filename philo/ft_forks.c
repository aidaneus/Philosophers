#include "philo.h"

static void	fork_mutex(t_philo *philo)
{
	if (philo->turn % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	printf("%lu %d %s\n", get_time() - philo->param2->start,
		philo->turn, "has taken a fork");
	if (philo->turn % 2 != 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
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
	pthread_mutex_unlock(&philo->eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
