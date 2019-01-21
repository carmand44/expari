/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:18:47 by achavy            #+#    #+#             */
/*   Updated: 2019/01/21 00:43:15 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

/*
** 1='&&' 2='||'
*/

static int	ft_check_op(char *str)
{
	if (str[0] == '&' && str[1] == '&')
		return (1);
	if (str[0] == '|' && str[1] == '|')
		return (2);
	return (0);
}

static int  ft_lower_op(char c)
{
	if ((c == '*') || (c == '/') || (c == '%') || (c == '+') || (c == '-'))
		return (1)
	return (0);
}

void		ft_logic_op(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_lower_op(str[i]) && (str[i] < '0' || str[i] > '9'))
		{
			ft_check_op(&str[i]);
		}
		i++;
	}
}
