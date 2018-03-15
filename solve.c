/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:28:43 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 16:08:55 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_branch_end(t_map *map, t_dlist *lst)
{
	t_map			*tmp;
	unsigned int	i;

	tmp = NULL;
	i = 0;
	if (lst->prev)
		return (NULL);
	else
	{
		tmp = ft_mapnew(map->size + 1);
		while (i < map->size)
			ft_memdel((void **)&(map->field[i++]));
		ft_memdel((void **)&(map->field));
		ft_memdel((void **)&map);
		return (ft_fillit(tmp, lst, 0, 0));
	}
}

t_map	*ft_fillit(t_map *map, t_dlist *lst, unsigned int x, unsigned int y)
{
	t_map	*tmp;

	if (!lst)
		return (map);
	while (y < map->size)
	{
		while (x < map->size)
		{
			if (ft_isfit(map, lst, x, y))
			{
				tmp = ft_fillit(ft_puttetr(map, lst, x, y), lst->next, 0, 0);
				if (!tmp)
					ft_remtetr(map, ((t_tetr *)(lst->content))->ch);
				else
					return (map);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (ft_branch_end(map, lst));
}

t_map	*ft_solve(t_dlist *lst)
{
	t_map	*map;

	map = ft_mapnew(ft_sqrt_high(ft_dlstlen(&lst) * 4));
	return (ft_fillit(map, lst, 0, 0));
}
