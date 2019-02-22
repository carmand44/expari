/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:18:14 by achavy            #+#    #+#             */
/*   Updated: 2019/02/18 23:41:08 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

static void		ft_resolve(char *str, int size)
{
	char *tmp;

	tmp = NULL;
	if (!(tmp = ft_strndup(str, size)))
		ft_exp_ari_error("malloc error");
	if (!(tmp = ft_math_op(tmp, size)))
		ft_exp_ari_error("malloc error");
	ft_itoa_exp_ari(str, ft_atoi(tmp), size);
	ft_strdel(&tmp);
}

static char		*ft_exp_ari(char *str, int size)
{
	int		i;
	int		p;

	i = 0;
	p = -1;
	while (i < size)
	{
		if (str[i] == ')' && p == -1)
			ft_exp_ari_error("parenthese error");
		if (str[i] == '(')
			p = i;
		if (p != -1 && str[i] == ')')
		{
			ft_resolve(&str[p + 1], i - p - 1);
			str[p] = ' ';
			str[i] = ' ';
			p = -1;
			i = -1;
			if (!(str = ft_erase_space(str)))
				ft_exp_ari_error("malloc error");
			size = ft_strlen(str);
		}
		i++;
	}
	if (p != -1)
		ft_exp_ari_error("parenthese error");
	ft_resolve(str, size);
	return (str);
}

int				main(int c, char **v)
{
	char		*str;

	str = NULL;
	if (c == 2)
	{
		if (!(str = ft_strdup(v[1])))
			return (0);
		if (!(str = ft_check_exp_ari(str)))
			return (0);
		if (!(str = ft_erase_space(str)))
			ft_exp_ari_error("malloc error");
		str = ft_exp_ari(str, ft_strlen(str));
		ft_putendl(str);
	}
	exit(0);
}
