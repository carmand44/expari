#ifndef FT_EXP_ARI_H
# define FT_EXP_ARI_H

# include "libft.h"

typedef struct		s_ari
{
	struct s_ari	left;
	struct s_ari	right;
	char			*str;
	char			*op;
	int				ret;
}					t_ari;

#endif
