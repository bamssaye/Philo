/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:29:41 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/31 19:42:13 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct args
{
	size_t	current_time;// current time
	int		n_philo;// number of philo
	int		time_die;// time to die
	int		time_eat;// time to eat
	int		time_sleep;// time to sleep
	int		nubmer_meals;// number of meals
}		t_args;

typedef struct philo
{
	pthread_mutex_t	*r_fork;// right fork
	pthread_mutex_t	*l_fork;// left fork
	pthread_mutex_t	*mutexp;// mutex for print msg
	pthread_mutex_t	*_dead;// mutex to protact the flag dead
	pthread_mutex_t	*tmp_f;// tmp flag to handle error
	pthread_mutex_t	*tmp_s;// tmp to handle the error
	pthread_mutex_t	*m_t;// mutex to protact the eatin meal
	pthread_mutex_t	*e_t;// mutex to protact the eatin meal number
	int				id_ph;// id philo
	int				*dead;// flag for dead philo
	int				eaten_m;// number of eaten meals
	size_t			last_meals;// time of last meal
	t_args			*ginfo;// input args
	pthread_t		idthread;// id thread represent philo
}		t_philo;

//------Parssing
int		ft_atoi(const char *nptr);
int		ft_checkarg(int ac, char **av, t_args *args);
int		ft_init(t_args *args, char **av, int ac);
//------Print Data
void	putstr_pros(t_philo *philo, char *str);
void	putstr_pro(t_philo *philo, char *str);
void	ft_putstr(char *str, int fd);
//------Time
size_t	time_now(void);
size_t	time_update(size_t time);
int		_usleep(size_t mili);
//------Error Msg
void	ft_error(void);
//------Routine
int		_eating(t_philo *philo);
int		_sleeping(t_philo *philo);
int		_thinking(t_philo *philo);
//-----Check  time and meals
int		ft_check(t_philo *ph);
//----Init philos
int		init_philo(t_philo *philo, t_args *args);
////
int		check_meals(t_philo *philo);
int		check_timedie(t_philo *philo);
int		check_dead(t_philo *ph);
///////
int		init_philo(t_philo *ph, t_args *args);
int		init_program(t_philo *philo, t_args *args, int *d);
void	free_data(t_philo *ph, int nb);
void	de_mutex(t_philo *philo);

#endif
