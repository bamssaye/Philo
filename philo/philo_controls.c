/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:06:25 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/31 19:44:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ph(t_philo *ph, size_t t_die)
{
	pthread_mutex_lock(ph->m_t);
	if (time_now() - ph->last_meals > t_die)
		return (pthread_mutex_unlock(ph->m_t), 1);
	pthread_mutex_unlock(ph->m_t);
	return (0);
}

int	check_timedie(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->ginfo->n_philo)
	{
		if (check_ph(&philo[i], philo->ginfo->time_die))
		{
			pthread_mutex_lock(philo[i]._dead);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[i]._dead);
			putstr_pros(&philo[i], "is died\n");
			return (1);
		}
	}
	return (0);
}

int	check_meals(t_philo *philo)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (philo->ginfo->nubmer_meals == -1)
		return (0);
	while (++i < philo->ginfo->n_philo)
	{
		pthread_mutex_lock(philo->e_t);
		if (philo[i].eaten_m >= philo[i].ginfo->nubmer_meals)
			count++;
		pthread_mutex_unlock(philo->e_t);
	}
	if (count == philo[0].ginfo->n_philo)
	{
		pthread_mutex_lock(philo[0]._dead);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0]._dead);
		return (1);
	}
	return (0);
}
