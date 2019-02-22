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

static int		ft_check_op(char *str, int i)
{
	if (str[i])
	{
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*')
		|| (str[i] == '/') || (str[i] == '%')
		|| (str[i] == '<' && str[i + 1] != '=')
		|| (str[i] == '>' && str[i + 1] != '='))
			return (i + 1);
		if ((str[i] == '&' && str[i + 1] == '&')
		|| (str[i] == '|' && str[i + 1] == '|')
		|| (str[i] == '<' && str[i + 1] == '=')
		|| (str[i] == '>' && str[i + 1] == '=')
		|| (str[i] == '=' && str[i + 1] == '=') 
		|| (str[i] == '!' && str[i + 1] == '='))
			return (i + 2);
	}
	ft_exp_ari_error(ft_strjoin("operator error or missing : ", str));
	return (i);
}

static int		ft_check_num(char *str, int i)
{
	if (ft_isdigit(str[i]))
		return (ft_check_digit(str, i + 1));
	if ((str[i] == '-') || (str[i] == '+'))
	{
		i++;
		if (ft_isdigit(str[i]))
			return (ft_check_digit(str, i + 1));
	}
	ft_exp_ari_error(ft_strjoin("operande error or missing : ", str));
	return (i);
}

static void		ft_check_syntax(char *str)
{
	int i;
	
	i = 0;
	while (str[i] == ' ')
		i++;
	i = ft_check_num(str, i);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		i = ft_check_op(str, i);
		while (str[i] == ' ')
			i++;
		i = ft_check_num(str, i);
	}
}

char			*ft_check_exp_ari(char *str)
{
	ft_check_syntax(str);
	return (str);
}
