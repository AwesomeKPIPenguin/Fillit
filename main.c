/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:03:19 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 15:49:34 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*ft_puterr(void)
{
	ft_putendl("error");
	exit(1);
}

void		*ft_putusg(void)
{
	ft_putendl("usage: ./fillit tetriminos_file");
	exit(1);
}

t_dlist		*ft_gettetrs(int fd, int i)
{
	char	**tab;
	char	str[BUF_SIZE];
	char	newl;
	t_dlist	*lst;
	t_tetr	*tetr;

	lst = NULL;
	while (read(fd, str, BUF_SIZE) == BUF_SIZE)
	{
		newl = 0;
		if (++i > TETR_MAX)
			ft_puterr();
		ft_isvalid_str((char *)str);
		tab = ft_strsplit(str, '\n');
		ft_isvalid_tetr((char *)str);
		tetr = ft_tetrnew('A' + i - 1, ft_getpoints(tab));
		ft_dlstpush(&lst, ft_dlstnew(tetr, sizeof(t_tetr)));
		free(tetr);
		if (read(fd, &newl, 1) == 0)
			return (lst);
		else if (newl != '\n')
			ft_puterr();
	}
	ft_puterr();
	return (NULL);
}

t_dlist		*ft_readtetrs(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_puterr();
	return (ft_gettetrs(fd, 0));
}

int			main(int ac, char **av)
{
	t_dlist			*tetrs;
	t_map			*map;

	if (ac != 2)
		ft_putusg();
	tetrs = ft_readtetrs(av[1]);
	map = ft_solve(tetrs);
	ft_puttab((const char **)(map->field));
	return (0);
}
