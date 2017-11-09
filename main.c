/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:03:19 by domelche          #+#    #+#             */
/*   Updated: 2017/11/08 17:03:21 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void		*ft_puterr()
{
	ft_putendl("error");
	exit(-1);
}

void		ft_cutlines(char **tab)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
			if (tab[i][j++] == FULL)
				break ;
		if (j == WIDTH)
			ft_memdel(&tab[i]);
		i++;
	}
}

void		ft_cutrow(char **tab, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < HEIGHT)
	{
		tmp = &(tab[i][j]);
		tmp = ft_memmove(tmp, tmp + 1, WIDTH - j);
		i++;
	}
}

void		ft_cutrows(char **tab)
{
	int		i;
	int		j;

	j = 0;
	i = 0;	
	while (j < WIDTH)
	{
		while (i < HEIGHT)
		{
			if (!tab[i])
			{
				i++;
				continue ;
			}
			if (tab[i][j] == FULL)
				break ;
			i++;
		}
		if (i == HEIGHT)
			ft_cutrow(tab, j);
		j++;
	}
}

char		**ft_cuttetr(char **tab)
{
	char	**tetr;
	

}

char		*ft_getstr(int fd)
{
	int		ret;
	char	**tab;
	char	str[BUF_SIZE];
	char	newl;
	t_list	*lst;

	lst = NULL;
	while ((ret = read(fd, str, BUF_SIZE)) == BUF_SIZE)
	{
		ft_isvalide_str(str);
		tab = ft_strsplit(str, '\n');
		newl = '\0';
		if ((ret = read(fd, &newl, 1)) == 0)
			return (str);
		else if (newl != '\n')
			ft_puterr();
		if (ft_isvalide_tetr(tab))
			ft_lstpush(&lst, ft_lstnew(&tab, sizeof(tab)));
	}
	ft_puterr();
	return (NULL);
}

t_list		*ft_getlst(char *file)
{
	int		fd;
	char	**content;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_puterr();
	while ((content = ft_get()))
	{

	}
}

int			main(int ac, char **av)
{
	t_list	*lst;

	lst = ft_getlst(av[1]);
	return (0);
}
