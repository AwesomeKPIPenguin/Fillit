/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:03:59 by domelche          #+#    #+#             */
/*   Updated: 2017/11/09 15:04:01 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

void		ft_init(int *empt, int *full, int *newl, int *i)
{
	*empt = 0;
	*full = 0;
	*newl = 0;
	*i = 0;
}

void		ft_isvalide_str(char *str)
{
	int		empt;
	int		full;
	int		newl;
	int		nrow;

	printf("\nstr:\n%s", str);
	ft_init(&empt, &full, &newl, &nrow);
	while ((empt + full + newl) < BUF_SIZE)
	{
		printf("empt: %i\n", empt);
		printf("full: %i\n", full);
		printf("newl: %i\n", newl);
		printf("nrow: %i\n\n", nrow);
		nrow = 0;
		while (nrow++ < 4)
		{
			if (str[empt + full + newl] != FULL &&
				str[empt + full + newl] != EMPT)
				ft_puterr();
			(str[empt + full + newl] == FULL) ? full++ : empt++;
			if (full > 4 || empt > 12)
				ft_puterr();
			printf("empt: %i\n", empt);
			printf("full: %i\n", full);
			printf("newl: %i\n", newl);
			printf("nrow: %i\n\n", nrow);
		}
		if (str[empt + full + newl] != '\n')
		{
			printf("%i\n", 1);
			ft_puterr();
		}
		newl++;
	}
	if (full != 4 || empt != 12 || newl != 4)
		ft_puterr();
}

int			ft_check_around(char **tab, int i, int j)
{
	if (i - 1 >= 0 && tab[i - 1][j] == FULL)
		return (1);
	if (j - 1 >= 0 && tab[i][j - 1] == FULL)
		return (1);
	if (i + 1 <= 3 && tab[i + 1][j] == FULL)
		return (1);
	if (j + 1 >= 0 && tab[i][j + 1] == FULL)
		return (1);
	return (0);
}

int			ft_isvalide_tetr(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == FULL && !ft_check_around(tab, i, j))
				ft_puterr();
			j++;
		}
		i++;
	}
}
