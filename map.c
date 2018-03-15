/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:20:47 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 15:43:50 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_mapnew(unsigned int size)
{
	t_map				*map;
	unsigned int		i;
	int					j;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->field = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map->field[i] = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		{
			j = i;
			while (--j != 0)
				ft_memdel((void *)&map->field[j]);
			ft_memdel((void *)&map->field);
			ft_puterr();
		}
		map->field[i] = (char *)ft_memset((void *)map->field[i], '.', size);
		i++;
	}
	return (map);
}
