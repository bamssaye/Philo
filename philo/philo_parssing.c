/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parssing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:01:54 by bamssaye          #+#    #+#             */
/*   Updated: 2024/07/24 22:55:47 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		return (-1);
	if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		n = 10 * n + nptr[i++] - 48;
	if (n > 2147483647)
		return (-1);
	if (nptr[i] != '\0')
		return (-1);
	return (n);
}

int	_argnotvalid(t_args *args)
{
	return (args->n_philo > 1000);
}

int	ft_init(t_args *args, char **av, int ac)
{
	args->current_time = time_now();
	args->n_philo = ft_atoi(av[1]);
	args->time_die = ft_atoi(av[2]);
	args->time_eat = ft_atoi(av[3]);
	args->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nubmer_meals = ft_atoi(av[5]);
	else
		args->nubmer_meals = -1;
	if (_argnotvalid(args))
		return (ft_putstr("\n*ARG Not valid... \n", 2), ft_error(), 1);
	return (0);
}

int	ft_checkarg(int ac, char **av, t_args *args)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < 5)
		{
			if (ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0)
				return (ft_error(), 1);
			i++;
		}
		if (av[5] && (ft_atoi(av[5]) == -1 || ft_atoi(av[5]) == 0))
			return (ft_error(), 1);
	}
	else
		return (ft_putstr("\n*Number of ARG Not valid... \n", 2), ft_error(),
			1);
	if (ft_init(args, av, ac))
		return (1);
	return (0);
}
