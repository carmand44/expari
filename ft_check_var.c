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

static char		*ft_replace_var(char *str, t_list_ari *list_var, int *i)
{
	t_list_ari	*l_tmp;	
	char		*tmp;
	char 		*new;
	char		*nb;
	int			j;

	j = 0;
	nb = NULL;
	new = NULL;
	tmp = NULL;
	l_tmp = NULL;
	while (ft_isalpha(str[j + *i]))	
		j++;
	ft_putstr("give me : ");
	write(1, &str[*i], j);
	ft_putstr(" : ");
	get_next_line(0, &nb);
	if (!nb)
		return (0);
ft_putendl(nb);
	l_tmp = list_var;
	if (list_var)
	{
		while (l_tmp->next)
			l_tmp = l_tmp->next;
		if ((!(l_tmp->next = (t_list_ari*)malloc(sizeof(t_list_ari))))
		|| (!(l_tmp->next->var = ft_strdup(nb))))
			return (0);
		l_tmp->next->next = NULL;
	}
	else
	{
		if ((!(list_var = (t_list_ari*)malloc(sizeof(t_list_ari))))
		|| (!(list_var->var = ft_strdup(nb))))
			return (0);
		list_var->next = NULL;
	}
	if (!(tmp = ft_strjoin(nb, &str[j + *i])))
		return (0);
ft_putendl(tmp);
	free(nb);
	nb = NULL;
	if ((!(nb = ft_strndup(str, *i)))
	|| (!(new = ft_strjoin(nb,tmp))))
		return (0);
ft_putendl(nb);
ft_putendl(new);
	free(tmp);
	tmp = NULL;
	free(nb);
	nb = NULL;
	free(str);
	str = NULL;
	get_next_line(-2, NULL);	
	*i = *i + j;
	return (new);
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
			i++;
			str = ft_replace_var(str, list_var, &i);
			if (!str)
				return (NULL);
		}
		if (ft_isalpha(str[i]))
		{
			str = ft_replace_var(str, list_var, &i);
			if (!str)
				return (NULL);
		}
		i++;
	}
	ft_putchar('C');
	ft_putendl(str);
	return (str);
}
