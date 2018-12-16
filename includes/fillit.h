/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/16 13:42:59 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️
** A SUPPRIMER LE stdio.h
**❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️
*/

# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_table
{
	char			**tab;
	int				len;
}					t_table;

typedef struct		s_xy
{
	int				x;
	int				y;
	int				original;
}					t_xy;

typedef struct		s_pnt
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		s_coo
{
	struct s_xy		p[4];
	int				c;
}					t_coo;

t_coo				*g_tetri_lst;
int					g_tetri_total;

int					open_sample(char *filename);
int					check_file(char *filename);
int					ft_sqrt_up(int n);
char				**create_square(int nb_tetri);
void				resize_square(t_table *table);
t_coo				fill_tetri_coo(char *tetri);
void				fill_square(t_coo *lst, t_table *table, int total);
void				place_tetri(t_table *table, t_pnt *coor);
void    			print_map(t_table *tab);
void        		fillit(t_table *table, t_pnt *coor);

#endif
