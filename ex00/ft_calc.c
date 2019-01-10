/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:13:55 by achavy            #+#    #+#             */
/*   Updated: 2018/09/16 20:02:21 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

void	ft_replace(char *str, int i, int j, int n)
{
	if (str[i] == '*')
		ft_itoa(&str[j], ft_atoi(&str[j]) * ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '/')
		ft_itoa(&str[j], ft_atoi(&str[j]) / ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '%')
		ft_itoa(&str[j], ft_atoi(&str[j]) % ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '-')
		ft_itoa(&str[j], ft_atoi(&str[j]) - ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '+')
		ft_itoa(&str[j], ft_atoi(&str[j]) + ft_atoi(&str[i + 1]), i - j + n);
}

int		ft_count_next_num(char *str)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		ft_count_prev_num(char *str, int m)
{
	int i;

	i = 1;
	while (i <= m && str[m - i] == ' ')
		i++;
	while (i <= m && str[m - i] >= '0' && str[m - i] <= '9')
		i++;
	if (i <= m && (str[m - i] == '+' || str[m - i] == '-'))
		i++;
	return (i - 1);
}

void	ft_calc_less_prio(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == ' '))
		{
			ft_replace(str, i, i - ft_count_prev_num(str, i),
			ft_count_next_num(&str[i]));
			i = -1;
		}
		i++;
	}
}

void	ft_calc(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			ft_replace(str, i, i - ft_count_prev_num(str, i),
			ft_count_next_num(&str[i]));
			i = -1;
		}
		i++;
	}
	ft_calc_less_prio(str, n);
}
