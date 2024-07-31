/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:39:06 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/27 23:21:29 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putstr_pro(t_philo *philo, char *str)
{
	size_t	ct;

	pthread_mutex_lock(philo->mutexp);
	ct = time_update(philo->ginfo->current_time);
	if (!check_dead(philo))
		printf("[%zu] PHILO [%d] %s", ct, philo->id_ph, str);
	pthread_mutex_unlock(philo->mutexp);
}
void	putstr_pros(t_philo *philo, char *str)
{
	size_t	ct;
	pthread_mutex_lock(philo->mutexp);
	ct = time_update(philo->ginfo->current_time);
	printf("[%zu] PHILO [%d] %s", ct, philo->id_ph, str);
	pthread_mutex_unlock(philo->mutexp);

}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_error(void)
{
	ft_putstr("\n+------------------------------------------------+\n", 2);
	ft_putstr("|                  Parameter                     |\n", 2);
	ft_putstr("+------------------------------------------------+\n", 2);
	ft_putstr("| [1] Number of Philosophers MAX [400]           |\n", 2);
	ft_putstr("| [2] Time to Die (ms)                           |\n", 2);
	ft_putstr("| [3] Time to Eat (ms)                           |\n", 2);
	ft_putstr("| [4] Time to Sleep (ms)                         |\n", 2);
	ft_putstr("| [5] Number of times each philosopher must eat. |\n", 2);
	ft_putstr("+------------------------------------------------+\n", 2);
}
