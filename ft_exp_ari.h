/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_ari.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:19:00 by achavy            #+#    #+#             */
/*   Updated: 2019/01/21 03:56:32 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXP_ARI_H
# define FT_EXP_ARI_H

# include "libft.h"

/*
** ft_erase_space.c
*/

char		*ft_erase_space(char *str);

/*
** ft_true_op.c
*/

void		ft_true_op(char *str, int size);

/*
** ft_logic_op.c
*/

void		ft_logic_op(char *str, int size);

/*
** ft_math_op.c
*/

char	*ft_math_op(char *str, int n);

/*
** ft_itoa_exp_ari.c
*/

void	ft_itoa_exp_ari(char *str, int nbr, int n);

#endif
