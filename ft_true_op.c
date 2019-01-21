/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:20:31 by achavy            #+#    #+#             */
/*   Updated: 2019/01/21 04:54:21 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

/*
** 1='<' 2='>' 3='<=' 4='>=' 5='==' 6='!='
*/

static int	ft_check_op(char *str)
{
	if (str[1] == '\0')
		return (0);
	if (str[0] == '<' && str[1] != '=')
		return (1);
	if (str[0] == '>' && str[1] != '=')
		return (2);
	if (str[0] == '<' && str[1] == '=')
		return (3);
	if (str[0] == '>' && str[1] == '=')
		return (4);
	if (str[0] == '=' && str[1] == '=')
		return (5);
	if (str[0] == '!' && str[1] == '=')
		return (6);
	return (0); //error op
}

static void ft_check_true(char *str, int p, int nb, int n)
{
	if (nb == 1 && ft_atoi()) // voir si besoin du i de ture op
		ft_itoa_exp_ari(str[p], 1, n)
}

char	*ft_true_op(char *str, int size)
{
	int i;
	int nb;
	int p;
	int n;

	i = 0;
	nb = 0;
	p = -1;
	n = -1;
	while (i < size)
	{
		if (0 != (nb = ft_check_op(&str[i])))
		{
			if (nb < 3)
				n = i + ft_count_next_num(&str[i + 1]);
			else
				n = i + ft_count_next_num(&str[i + 2]);
			p = ft_count_prev_num(str, i);
			ft_check_true(str, p, nb, n);
			i = -1;
			if (!(str = ft_erase_space(str)))
				return (NULL); // malloc error
			size = ft_strlen(str);
			nb = 0;
		}
		i++;
	}
	//ft_logic_op
	return (str);
}
