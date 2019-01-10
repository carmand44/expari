/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:19:21 by achavy            #+#    #+#             */
/*   Updated: 2018/09/16 17:27:20 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

int		ft_is_blank(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\v')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	ret;

	i = 0;
	neg = 1;
	ret = 0;
	while (ft_is_blank(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = str[i] - 48 + ret * 10;
		i++;
	}
	return (ret * neg);
}
