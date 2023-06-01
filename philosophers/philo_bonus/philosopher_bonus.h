/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:16:54 by msaritas          #+#    #+#             */
/*   Updated: 2023/05/17 16:27:44 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	int				philo_id;
	int				eat_count;
	long long		last_eat_time;
	int				pid_no;
	struct s_data	*info;
}	t_philo;

typedef struct s_data
{
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			must_eat;
	int			eat_enough;
	int			philo_count;
	long long	start_time;
	int			is_dead;
	sem_t		*eating_sem;
	sem_t		*forks;
	sem_t		*printing_sem;
	t_philo		*philos;
	pthread_t	thread;
}	t_data;

int			ft_atoi(const char *str);
long long	ft_time(void);
int			is_valid(char **argv);

void	take_forks(t_philo *philosophers);
void	*is_died(void	*philosophers);
void	sleep_control(long long time, t_data *data);

void	destroy_processes_exit(t_data *philos);
void	printing_status(t_data *data, int philo_num, char *state);

#endif