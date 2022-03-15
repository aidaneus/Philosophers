#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int					turn;
	struct s_param		*param2;
	unsigned long		last_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	unsigned long		start1;
	pthread_mutex_t		eat;
	pthread_mutex_t		died;
	pthread_t			tid;
	int					is_eating;
	int					count;
}				t_philo;

typedef struct s_param
{
	pthread_mutex_t			*forks;
	pthread_mutex_t			died;
	int						counter;
	unsigned long			time_to_die;
	unsigned long			time_to_sleep;
	unsigned long			time_to_eat;
	unsigned long			start;
	int						number;
	t_philo					*philo;
	int						died_flag;
	int						eat_count;
}				t_param;

void			ft_exit(t_param *param);
long unsigned	get_time(void);
void			wait_for(long unsigned time);
int				ft_atoi(char *str);
void			ft_init(int argc, char **argv);
void			*ft_death(void *one1);
void			ft_forks(t_philo *one);

#endif
