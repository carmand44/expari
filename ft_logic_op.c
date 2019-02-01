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

static void ft_check_logic(char *str, int p, int nb, int n, int i)
{
	if (nb == 1)
	{
		if ((0 != ft_atoi(&str[p])) && (0 != ft_atoi(&str[i + 2])))
			ft_itoa_exp_ari(&str[p], 1, n + 1);
		else
			ft_itoa_exp_ari(&str[p], 0, n + 1);
	}
	if (nb == 2)
	{
		if (ft_atoi(&str[p]) || ft_atoi(&str[i + 2]))
			ft_itoa_exp_ari(&str[p], 1, n + 1);
		else
			ft_itoa_exp_ari(&str[p], 0, n + 1);
	}
}

char		*ft_logic_op(char *str, int size)
{
	int		i;
	int		n;
	int		p;
	int		nb;

	i = 0;
	nb = 0;
	p = -1;
	n = -1;
	while (i < size)
	{
		ft_putendl(str);
		if (0 != (nb = ft_check_op(&str[i])))
		{
			n = i + ft_count_next_num(&str[i + 1]) - 1;
			p = ft_count_prev_num(str, i);
			ft_putnbr(p);
			ft_putnbr(n);
			ft_check_logic(str, p, nb, n , i);
			i = -1;
ft_putendl(str);
			if (!(str = ft_erase_space(str)))
				return (NULL); // malloc error
			size = ft_strlen(str);
			nb = 0;
		}
		i++;
	}
	return (str);
}
