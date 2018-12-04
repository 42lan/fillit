/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:29:34 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/04 11:32:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 2);
		return (1);
	}
	if (!(fd = open(av[1], O_RDONLY)))
	{
		ft_putendl_fd("error: while opening file", 2);
		return (1);
	}
	if (!format_check(fd))
	{
		ft_putendl_fd("error: bad format", 2);
		return (1);
	}
	close(fd);
	if (!(fd = open(av[1], O_RDONLY)))
	{
		ft_putendl_fd("error: while opening file", 2);
		return (1);
	}
	if (!pieces_check(fd))
	{
		ft_putendl_fd("error: one or more pieces are invalid", 2);
		return (1);
	}
	close(fd);
	return (0);
}