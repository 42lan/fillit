/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/16 14:11:44 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** check if all blocs of the given tetri is placable
 ** check if the character is '.' && on the table
 */

//static int		is_tetri_placeable(t_table *table,  int x, int y, int tetr_index)
static int		is_tetri_placeable(t_table *table,  int x, int y, int tetr_index)
{
	//ft_putendl("sta is_tetri");
	int			bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (x + g_tetri_lst[tetr_index].p[bloc_cnt].x >= 0
				&& x + g_tetri_lst[tetr_index].p[bloc_cnt].x < table->len
				&& y + g_tetri_lst[tetr_index].p[bloc_cnt].y >= 0
				&& y + g_tetri_lst[tetr_index].p[bloc_cnt].y < table->len
				&& table->tab[y + g_tetri_lst[tetr_index].p[bloc_cnt].y][x
				+ g_tetri_lst[tetr_index].p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
		{
			//ft_putendl("end is_tetri");
			return (0);
		}
	}
	//ft_putendl("end is_tetri");
	return (1);
}

static void		delete_tetri(t_table *table, int c)
{
	int			x;
	int			y;

	y = -1;
	while (++y < table->len)
	{
		x = -1;
		while (++x < table->len)
		{
			if (table->tab[y][x] == (char)c)
			{
				table->tab[y][x] = '.';
			}
		}
	}
}

static void		print_tetri(t_table *table, int x, int y, int tetri_index)
{
	printf("table_ad: %p\n", table);
	int			bloc_cnt;

	bloc_cnt = -1;
	while (++bloc_cnt < 4)
		table->tab[y + g_tetri_lst[tetri_index].p[bloc_cnt].y]
			[x + g_tetri_lst[tetri_index].p[bloc_cnt].x]
			= g_tetri_lst[tetri_index].c;
}

void		coor_plus(t_pnt *coor, int len)
{
	if (coor->x < len - 1)
	{
		coor->x += 1;
	}
	else if (coor->x == len - 1 && coor->y < len - 1)
	{
		coor->x = 0;
		coor->y += 1;
	}
}

//ONGO
static int	place_letter(t_table *table, int x, int y, int index)
{
	if (is_tetri_placeable(table, x, y, index))
	{
		print_tetri(table, x, y, index);
		return (1);
	}
	return (0);
}

int			try_map(t_table *table, t_pnt *coor, int index)
{
	if (index >= g_tetri_total)
		return (1);
	if (coor->x == table->len - 1 && coor->y == table->len - 1)//
		return (0);//
	//if (is_tetri_placeable(table, coor->x, coor->y, index))
	if (is_tetri_placeable(table, coor->x, coor->y, index))
	{
		print_tetri(table , coor->x, coor->y, index);
		if (try_map(table, coor, ++index))
			return (1);
		delete_tetri(table, g_tetri_lst[index].c);
		coor_plus(coor, table->len);
		//while (table->map[coor->y][coor->x] != '.'//a voir plus tard
		return (try_map(table, coor, index));
	}
	return (0);
}

void		fillit(t_table *table, t_pnt *coor)
{
	//if (i >= g_tetri_total)
		//return ;
	if (try_map(table, coor, 0))
		return ;
	resize_square(table);
	fillit(table, coor);
	return ;
}
