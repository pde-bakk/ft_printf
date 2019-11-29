/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 20:51:26 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/11/29 21:19:19 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagfinder(const char *s, t_map *map, va_list *args)
{
	ft_resetmap(map);
//	printf("map->pos when looking for flags =%c (%i)\n", s[map->pos], map->pos);
	if (s[map->pos] == '-')
	{
		map->min = 1;
		map->pos++;
		printf("Map->min=%d\n", map->min);
	}
	if (s[map->pos] == '+')
	{
		map->plus = 1;
		map->pos++;
		printf("map->plus=%d\n", map->plus);
	}
	if (s[map->pos] == ' ')
	{
		map->spac = 1;
		map->pos++;
		printf("Map->space=%d\n", map->spac);
	}
	if (s[map->pos] == '#')
	{
		map->hash = 1;
		map->pos++;
		printf("Map->hash=%d\n", map->hash);
	}
	if (s[map->pos] == '0')
	{
		map->zero = 1;
		map->pos++;
		printf("Map->zero=%d\n", map->zero);
	}
	while (s[map->pos] >= '0' && s[map->pos] <= '9')
	{
		map->pad = map->pad * 10 + s[map->pos] - 48;
		map->pos++;	
		printf("Map->pad=%d\n", map->pad);
	}
	if (s[map->pos] == '.')
	{
		map->pos++;
		map->prec = 0;
		while (s[map->pos] >= '0' && s[map->pos] <= '9')
		{
			map->prec = map->prec * 10 + s[map->pos] - 48;
			map->pos++;	
			printf("Map->prec=%d\n", map->prec);
		}
		if (s[map->pos] == '*')
		{
			map->prec = va_arg(*args, int);
			printf("Map->prec=%d\n", map->prec);
			map->pos++;
		}
	}
}

int		ft_flagfiller(int length, int fd, t_map *map)
{
	int	fill;

	fill = map->pad - length;
/* Moet nog toevoegen dat hij ook spaties kan printen als er geen flag wordt meegegeven*/
	while (fill > 0 && (map->spac == 1 || map->zero == 1))
	{
		if (map->spac == 1)
			ft_putchar_fd(' ', fd, map, 0);
		if (map->zero == 1)
			ft_putchar_fd('0', fd, map, 0);
		fill--;
	}
	return (fill);
}
