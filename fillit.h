/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:12:24 by domelche          #+#    #+#             */
/*   Updated: 2017/11/28 15:47:03 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include "Libft/libft.h"

# define BUF_SIZE 20
# define EMPT '.'
# define FULL '#'
# define TMPR '*'
# define TETR_MAX 26
# define WIDTH 4
# define HEIGHT 4

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetr
{
	char			ch;
	t_point			**points;
}					t_tetr;

typedef struct		s_map
{
	char			**field;
	unsigned int	size;
}					t_map;

/*
** main.c
*/

void				*ft_puterr(void);
void				*ft_putusg(void);
t_dlist				*ft_readtetrs(char *file);
t_dlist				*ft_gettetrs(int fd, int i);

/*
** validation.c
*/

void				ft_init(int *empt, int *full, int *newl, int *i);
void				ft_isvalid_str(char *str);
void				ft_istetr(char *str, int i, int *count);
void				ft_isvalid_tetr(char *str);

/*
** point.c
*/

t_point				*ft_pointnew(int x, int y);
t_point				**ft_getpoints(char **tab);
t_point				*ft_pointcpy(t_point *dst, t_point *src);
void				ft_iffull(char ***tab, t_point ***points,
								t_point **point0, t_point **ptr);

/*
** tetr.c
*/

t_tetr				*ft_tetrnew(char ch, t_point **points);
int					ft_isfit(t_map *map, t_dlist *lst,
								unsigned int x, unsigned int y);
t_map				*ft_puttetr(t_map *map, t_dlist *lst,
								unsigned int x, unsigned int y);
void				ft_remtetr(t_map *map, char c);

/*
** map.c
*/

t_map				*ft_mapnew(unsigned int size);

/*
** solve.c
*/

t_map				*ft_backup(t_map *map, t_dlist *lst,
								unsigned int *x, unsigned int *y);
t_map				*ft_fillit(t_map *map, t_dlist *lst,
								unsigned int x, unsigned int y);
t_map				*ft_solve(t_dlist *lst);

#endif
