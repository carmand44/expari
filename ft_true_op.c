#include "ft_exp_ari.h"

//1='<' 2='>' 3='<=' 4='>=' 5='==' 6='!='

static int	ft_check_op(char *str)
{
	if (str[1] == '\0')
		return (0);
	/*if (str[0] == '&' && str[1] == '&')
		return (1);
	if (str[0] == '|' && str[1] == '|')
		return (2);*/
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
	return (0);
}
static int	ft_lower_op(char c)
{
	if ( c == '*' || c == '/' || c == '%' || c == '+' || c == '-' || c =='|' || c == '&')
		return (1)
	return (0);
}

void		ft_true_op(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_lower_op(str[i]) == 0 && (str[i] < '0' || str[i] > '9'))
		{
			ft_check_op(&str[i]);
		}
		i++;
	}
}
