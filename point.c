/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:15:55 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 15:58:04 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	*ft_pointnew(int x, int y)
{
	t_point	*point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

t_point	*ft_pointcpy(t_point *dst, t_point *src)
{
	dst->x = src->x;
	dst->y = src->y;
	return (dst);
}

void	ft_iffull(char ***tab, t_point ***points,
			t_point **point0, t_point **ptr)
{
	if ((*tab)[(*ptr)->y][(*ptr)->x] == FULL)
	{
		if ((*point0)->x < 0)
			*point0 = ft_pointcpy(*point0, *ptr);
		else
		{
			(**points) =
				ft_pointnew((*ptr)->x - (*point0)->x, (*ptr)->y - (*point0)->y);
			(*points)++;
		}
	}
	(*ptr)->x++;
}

t_point	**ft_getpoints(char **tab)
{
	t_point	**points;
	t_point	*ptr;
	t_point	*point0;
	int		i;

	if (!(points = (t_point **)ft_memalloc(4 * sizeof(t_point *))))
		ft_puterr();
	*points++ = ft_pointnew(0, 0);
	ptr = ft_pointnew(0, 0);
	point0 = ft_pointnew(-1, -1);
	while (ptr->y < HEIGHT)
	{
		while (ptr->x < WIDTH)
			ft_iffull(&tab, &points, &point0, &ptr);
		ptr->y++;
		ptr->x = 0;
	}
	points -= 4;
	i = 0;
	while (tab[i])
		ft_memdel((void **)&(tab[i++]));
	ft_memdel((void **)&tab);
	free(point0);
	free(ptr);
	return (points);
}
