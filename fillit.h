/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:12:24 by domelche          #+#    #+#             */
/*   Updated: 2017/11/08 17:12:25 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>

# define BUF_SIZE 20
# define EMPT '.'
# define FULL '#'
# define WIDTH 4
# define HEIGHT 4

void		*ft_puterr();
void		ft_init(int *empt, int *full, int *newl, int *i);
void		ft_isvalide_str(char *str);
int			ft_check_around(char **tab, int i, int j);
int			ft_isvalide_tetr(char **tab);

#endif
