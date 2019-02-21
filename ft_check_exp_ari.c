/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exp_ari.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:18:14 by achavy            #+#    #+#             */
/*   Updated: 2019/02/18 23:41:08 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"
#include <stdio.h>

static int		ft_check_digit(char *str, int i)
{
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int		ft_check_var(char *str, int i)
{
	int nb;
	int	j;

	j = 0;
	nb = 0;
	ft_putendl("on passe la");
	while (ft_isalpha(str[i + j]))
		j++;
	ft_putstr("give me : ");
	write(1, &str[i], j);
	ft_putchar(':');
	scanf("%d", &nb);
	ft_itoa_exp_ari(&str[i], nb, j);
	return (i + j);
}

static int		ft_check_num(char *str, int i)
{
	if (ft_isdigit(str[i]))
		return (ft_check_digit(str, i + 1));
	if ((str[i] == '-') || (str[i] == '+'))
	{
		i++;
		ft_putendl("on passe la");
		if (ft_isdigit(str[i]))
			return (ft_check_digit(str, i + 1));
		ft_putendl("on passe la");
		ft_putnbr(str[i]);
		if (str[i] == '$')
			return (ft_check_var(str, i + 1));

	}
	return (i);
}

static void		ft_check_syntax(char *str)
{
	int i;
	
	i = 0;
	while (str[i] == ' ')
		i++;
	ft_putendl("on passe la");
	i = ft_check_num(str, i);
	/*if (((str[i] > '9') || (str[i] < '0')) && str[i] != '$' && str[i] != '-'
	&& str[i] != '+')
		 ft_exp_ari_error(ft_strjoin("operande error or missing : ",&str[i]));
	ft_putendl("ok1");*/
	
}

char			*ft_check_exp_ari(char *str)
{
	ft_check_syntax(str);
	return (str);
}
