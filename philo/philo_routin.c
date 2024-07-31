/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:06:25 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/31 19:45:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_eating(t_philo *philo)
{
	if (philo->r_fork < philo->l_fork)
	{
		philo->tmp_f = philo->r_fork;
		philo->tmp_s = philo->l_fork;
	}
	else
	{
		philo->tmp_f = philo->l_fork;
		philo->tmp_s = philo->r_fork;
	}
	pthread_mutex_lock(philo->tmp_f);
	putstr_pro(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->tmp_s);
	putstr_pro(philo, "has taken a fork\n");
	putstr_pro(philo, "is eating\n");
	pthread_mutex_lock(philo->m_t);
	philo->last_meals = time_now();
	pthread_mutex_unlock(philo->m_t);
	_usleep(philo->ginfo->time_eat);
	pthread_mutex_unlock(philo->tmp_f);
	pthread_mutex_unlock(philo->tmp_s);
	pthread_mutex_lock(philo->e_t);
	philo->eaten_m++;
	pthread_mutex_unlock(philo->e_t);
	return (0);
}

int	_sleeping(t_philo *philo)
{
	putstr_pro(philo, "is sleeping\n");
	_usleep(philo->ginfo->time_sleep);
	return (0);
}

int	_thinking(t_philo *philo)
{
	putstr_pro(philo, "is thinking\n");
	if ((philo->ginfo->n_philo & 1))
		_usleep(1);
	return (0);
}
