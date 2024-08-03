/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:26:45 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/31 20:03:51 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *ph, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philo)
	{
		ph[i].id_ph = i + 1;
		ph[i].ginfo = args;
		ph[i].eaten_m = 0;
		ph[i].last_meals = time_now();
		ph[i].l_fork = ph[(i + 1) % args->n_philo].r_fork;
	}
	return (0);
}

int	init_program(t_philo *ph, t_args *args, int *d)
{
	int				i;

	ph[0].e_t = malloc(sizeof(pthread_mutex_t));
	ph[0].m_t = malloc(sizeof(pthread_mutex_t));
	ph[0].mutexp = malloc(sizeof(pthread_mutex_t));
	ph[0]._dead = malloc(sizeof(pthread_mutex_t));
	ph[0].dead = d;
	if (!ph[0].e_t || !ph[0].m_t || !ph[0].mutexp || !ph[0]._dead)
		return (1);
	if (pthread_mutex_init(ph[0].e_t, NULL) || pthread_mutex_init(ph[0].m_t, NULL)
		|| pthread_mutex_init(ph[0]._dead, NULL)
		|| pthread_mutex_init(ph[0].mutexp, NULL))
		return (1);
	i = 0;
	while (++i < args->n_philo)
	{
		ph[i].mutexp = ph[0].mutexp;
		ph[i]._dead = ph[0]._dead;
		ph[i].m_t = ph[0].m_t;
		ph[i].e_t = ph[0].e_t;
		ph[i].dead = d;
	}
	if (init_philo(ph, args))
		return (1);
	return (0);
}

void	free_data(t_philo *ph, int nb)
{
	int	i;

	i = -1;
	if (!ph)
		return ;
	while (++i < nb)
		if (ph[i].l_fork != NULL)
			free(ph[i].l_fork);
	if (ph->mutexp)
		free(ph->mutexp);
	if (ph->_dead)
		free(ph->_dead);
	if (ph->m_t)
		free(ph->m_t);
	if (ph->e_t)
		free(ph->e_t);
	if (ph)
		free(ph);
}

void	de_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philo->mutexp);
	pthread_mutex_destroy(philo->_dead);
	pthread_mutex_destroy(philo->m_t);
	pthread_mutex_destroy(philo->e_t);
	while (++i < philo->ginfo->n_philo)
		pthread_mutex_destroy(philo[i].r_fork);
}
