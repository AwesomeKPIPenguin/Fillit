/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:03:59 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 15:51:20 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init(int *empt, int *full, int *newl, int *i)
{
	*empt = 0;
	*full = 0;
	*newl = 0;
	*i = 0;
}

void		ft_isvalid_str(char *str)
{
	int		empt;
	int		full;
	int		newl;
	int		nrow;

	ft_init(&empt, &full, &newl, &nrow);
	while ((empt + full + newl) < BUF_SIZE)
	{
		nrow = 0;
		while (nrow++ < 4)
		{
			if (str[empt + full + newl] != FULL &&
				str[empt + full + newl] != EMPT)
				ft_puterr();
			(str[empt + full + newl] == FULL) ? full++ : empt++;
			if (full > 4 || empt > 12)
				ft_puterr();
		}
		if (str[empt + full + newl] != '\n')
			ft_puterr();
		newl++;
	}
	if (full != 4 || empt != 12 || newl != 4)
		ft_puterr();
}

void		ft_istetr(char *str, int i, int *count)
{
	*count = *count + 1;
	str[i] = TMPR;
	if (i - 5 >= 0 && str[i - 5] == FULL)
		ft_istetr(str, i - 5, count);
	if (i + 1 < BUF_SIZE && str[i + 1] == FULL)
		ft_istetr(str, i + 1, count);
	if (i + 5 < BUF_SIZE && str[i + 5] == FULL)
		ft_istetr(str, i + 5, count);
	if (i - 1 >= 0 && str[i - 1] == FULL)
		ft_istetr(str, i - 1, count);
}

void		ft_isvalid_tetr(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < BUF_SIZE)
	{
		if (str[i] == FULL)
		{
			ft_istetr(str, i, &count);
			if (count != 4)
				ft_puterr();
		}
		i++;
	}
}
