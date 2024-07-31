/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:41:17 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/27 22:59:07 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_onephilo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	putstr_pro(philo, "has taken a frok\n");
	pthread_mutex_unlock(philo->r_fork);
}

int	check_dead(t_philo *ph)
{
	pthread_mutex_lock(ph->_dead);
	if (*ph->dead == 1)
		return (pthread_mutex_unlock(ph->_dead), 1);
	pthread_mutex_unlock(ph->_dead);
	return (0);
}

void	*philoro(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (!ph)
		return (NULL);
	if (ph->ginfo->n_philo == 1)
		return (ft_onephilo(ph), NULL);
	if (!(ph->id_ph & 1))
		_usleep(1);
	while (!check_dead(ph))
	{
		_eating(ph);
		_sleeping(ph);
		_thinking(ph);
	}
	return (ph);
}

t_philo	*ft_syncro(t_args *args)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * args->n_philo + 1);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < args->n_philo)
	{
		philo[i].r_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].r_fork || pthread_mutex_init(philo[i].r_fork, NULL))
			return (NULL);
	}
	return (philo);
}
int join_thread(t_philo *philo, t_args *args)
{
	int i;

	i = -1;
	while (++i < args->n_philo)
		if (pthread_create(&philo[i].idthread, NULL, &philoro,
				(void *)&philo[i]))
			return (1);
	while (1)
		if (check_timedie(philo) || check_meals(philo))
			break ;
	i = -1;
	while (++i < args->n_philo)
		if (pthread_join(philo[i].idthread, NULL))
			return (1);
	return (0);
}
int	main(int ac, char **av)
{
	t_philo	*philo;
	t_args	args;
	int		d;

	d = 0;
	if (ft_checkarg(ac, av, &args))
		return (1);
	philo = ft_syncro(&args);
	if (!philo || init_program(philo, &args, &d))
		return (free_data(philo, args.n_philo), 1);
	if (join_thread(philo, &args))
		return (free_data(philo, args.n_philo), 1);
	de_mutex(philo);
	free_data(philo, args.n_philo);
}
