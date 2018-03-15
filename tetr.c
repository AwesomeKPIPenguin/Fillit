/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:08:27 by domelche          #+#    #+#             */
/*   Updated: 2017/11/13 15:08:28 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*ft_tetrnew(char ch, t_point **points)
{
	t_tetr	*tetr;

	if (points)
	{
		if (!(tetr = (t_tetr *)ft_memalloc(sizeof(t_tetr))))
			return (NULL);
		tetr->ch = ch;
		tetr->points = points;
		return (tetr);
	}
	return (NULL);
}

int		ft_isfit(t_map *map, t_dlist *lst, unsigned int x, unsigned int y)
{
	int		i;
	int		map_x;
	int		map_y;
	t_point	**points;

	i = 0;
	points = ((t_tetr *)lst->content)->points;
	while (i < 4)
	{
		map_x = points[i]->x + x;
		map_y = points[i++]->y + y;
		if (map_x < 0 || map_y < 0 ||
			map_x >= (int)map->size || map_y >= (int)map->size)
			return (0);
		if (map->field[map_y][map_x] != EMPT)
			return (0);
	}
	return (1);
}

t_map	*ft_puttetr(t_map *map, t_dlist *lst, unsigned int x, unsigned int y)
{
	int		i;
	t_point	**points;

	i = 0;
	points = ((t_tetr *)lst->content)->points;
	while (i < 4)
	{
		map->field[points[i]->y + y]
			[points[i]->x + x] = ((t_tetr *)lst->content)->ch;
		i++;
	}
	return (map);
}

void	ft_remtetr(t_map *map, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = map->field;
	i = 0;
	while (i < (int)map->size)
	{
		j = 0;
		while (j < (int)map->size)
		{
			if (tab[i][j] == c)
				tab[i][j] = EMPT;
			j++;
		}
		i++;
	}
}
