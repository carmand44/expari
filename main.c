#include "ft_exp_ari.h"

static void 	ft_putstrnbendl(char *str, int size)
{
	write(1, str, size);
	ft_putchar('\n');
}

static void		ft_resolve(char *str, int size)
{
	ft_putstrnbendl(str, size);
	ft_true_op(str, size);
	/*ft_logic_op
	ft_math_op*/	
}

static char		*ft_exp_ari(char *str, int size)
{
	int		i;
	int		p;

	i = 0;
	p = -1;
	ft_putstrnbendl(str, size);
	while (i < size)
	{
		if (str[i] == ')' && p == -1)
			return (NULL); //parenthese error
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
				return (0);
			size = ft_strlen(str);
		}
		i++;
	}
	if (p != -1)
		return (NULL); //parenthese error
	ft_resolve(str, size);
	return (str);
}

int				main(int c, char **v)
{
	char	*str;

	str = NULL;
	if (c == 2)
	{
		if (!(str = ft_strdup(v[1])))
			return (0);
		ft_putendl(str);
		if (!(str = ft_erase_space(str)))
			return (0);
		ft_putendl(str);
		if (!(str = ft_exp_ari(str, ft_strlen(str))))
			return (0);
		ft_putendl(str);
	}
	exit(0);
}
