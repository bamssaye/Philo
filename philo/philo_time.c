/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:44 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/21 23:04:42 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

size_t	time_update(size_t time)
{
	return (time_now() - time);
}

int	_usleep(size_t mili)
{
	size_t	start;

	start = time_now();
	while (time_now() - start < mili)
		usleep(450);
	return (0);
}
