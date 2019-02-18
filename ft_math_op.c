/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:13:55 by achavy            #+#    #+#             */
/*   Updated: 2019/02/19 00:31:56 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

static void		ft_calc(char *str, int i, int j, int n)
{
	if (str[i] == '*')
		ft_itoa_exp_ari(&str[j], ft_atoi(&str[j]) * ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '/')
	{
		if (ft_atoi(&str[i + 1]) == 0)
			ft_exp_ari_error("division by zero");
		ft_itoa_exp_ari(&str[j], ft_atoi(&str[j]) / ft_atoi(&str[i + 1]), i - j + n);
	}
	if (str[i] == '%')
		ft_itoa_exp_ari(&str[j], ft_atoi(&str[j]) % ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '-')
		ft_itoa_exp_ari(&str[j], ft_atoi(&str[j]) - ft_atoi(&str[i + 1]), i - j + n);
	if (str[i] == '+')
		ft_itoa_exp_ari(&str[j], ft_atoi(&str[j]) + ft_atoi(&str[i + 1]), i - j + n);
}

int				ft_count_next_num(char *str)
{
	int i;

	i = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int				ft_count_prev_num(char *str, int m)
{
	int i;

	i = 1;
	while (i <= m && str[m - i] >= '0' && str[m - i] <= '9')
		i++;
	if (i <= m && (str[m - i] == '-'))
		i++;
	return (i - 1);
}

static char		*ft_calc_less_prio(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		if ((i != 0) && (str[i] == '+' || str[i] == '-'))
		{
			ft_calc(str, i, i - ft_count_prev_num(str, i),
			ft_count_next_num(&str[i]));
			i = -1;
			if (!(str = ft_erase_space(str)))
				return (NULL); // malloc error
			n = ft_strlen(str);
		}
		i++;
	}
	return (ft_true_op(str, n));
}

char		*ft_math_op(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			ft_calc(str, i, i - ft_count_prev_num(str, i),
			ft_count_next_num(&str[i]));
			i = -1;
			if (!(str = ft_erase_space(str)))
				return (NULL); // malloc error
			n = ft_strlen(str);
		}
		i++;
	}
	if (!(str = ft_calc_less_prio(str, n)))
		return (NULL);
	return (str);
}
