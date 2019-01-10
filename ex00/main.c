/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:03:50 by achavy            #+#    #+#             */
/*   Updated: 2018/09/16 20:02:56 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_expr.h"

void	ft_find_next_closing_parenthesis(char *str, int *d, int *i)
{
	*d = *i;
	while (str[*i] && str[*i] != ')')
	{
		if (str[*i] == '(')
			*d = *i;
		*i = *i + 1;
	}
	if (str[*i] == ')')
	{
		ft_calc(&str[*d + 1], *i - *d - 2);
		str[*i] = ' ';
		str[*d] = ' ';
		*d = -1;
		*i = -1;
	}
}

int		eval_expr(char *str)
{
	int	d;
	int	i;

	i = 0;
	d = -1;
	while (str[i])
	{
		if (str[i] == '(')
			ft_find_next_closing_parenthesis(str, &d, &i);
		i++;
	}
	if (d == -1)
		ft_calc(str, ft_strlen(str));
	return (ft_atoi(str));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
