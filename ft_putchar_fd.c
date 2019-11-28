/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/27 22:52:02 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_map *map)
{
	write(fd, &c, 1);
	map->size++;
}

void	ft_putstr_fd(char *s, int fd, t_map *map)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, map);
		map->size++;
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd, t_map *map)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
		{
			write(fd, &s[i], 1);
			map->size++;
			i++;
		}
	write(fd, "\n", 1);
	map->size++;
}

void	ft_putnbr_fd(int n, int fd, t_map *map)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd, map);
		ft_putchar_fd('2', fd, map);
		map->size = map->size + 2;
		ft_putnbr_fd(147483648, fd, map);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, map);
		map->size++;
		ft_putnbr_fd(-n, fd, map);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, map);
		ft_putnbr_fd(n % 10, fd, map);
	}
	else
	{
		ft_putchar_fd(n + 48, fd, map);
		map->size++;
	}
}
