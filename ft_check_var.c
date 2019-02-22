/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:18:14 by achavy            #+#    #+#             */
/*   Updated: 2019/02/18 23:41:08 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

static int		ft_replace_var(char *str, t_list_ari *list_var, int i)
{	
	char	*tmp;
	char 	*new;
	char	*nb;
	int		j;

	j = 0;
	nb = NULL;
	new = NULL;
	tmp = NULL;

	while (ft_isalpha(str[j + i]))	
		j++;
	ft_putstr("give me :");
	write(1, &str[i], j);
	ft_putstr(" :");
	get_next_line(0, &nb);
	if (!nb)
		return (0);
	if (!(tmp = ft_strjoin(nb, &str[j + i + 1])))
		return (0);
	free(nb);
	nb = NULL;
	
	get_next_line(-2);	
	return (i);
}

char 			*ft_check_var(char *str, t_list_ari *list_var)
{
	int i;


	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && ft_isalpha(str[i + 1]))
		{
			str[i] = ' ';
			i = ft_replace_var(str, list_var, i + 1);
		}
		if (ft_isalpha(str[i]))
		i++;
	}
}
