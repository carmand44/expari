/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:18:51 by achavy            #+#    #+#             */
/*   Updated: 2018/09/16 19:55:41 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H

# include <unistd.h>

void	ft_calc(char *str, int n);
void	ft_itoa(char *str, int nbr, int n);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif
