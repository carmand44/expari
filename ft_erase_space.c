/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:18:30 by achavy            #+#    #+#             */
/*   Updated: 2019/01/21 00:18:32 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exp_ari.h"

static int		ft_nb_space(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			nb++;
		i++;
	}
	return (nb);
}

char			*ft_erase_space(char *str)
{
	int		j;
	int		i;
	int		nb;
	char	*new;

	new = NULL;
	nb = 0;
	i = 0;
	j = 0;
	if ((nb = ft_nb_space(str)) == 0)
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - nb)))
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new); 
}
