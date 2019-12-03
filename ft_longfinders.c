/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longfinders.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:36:31 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/03 14:49:50 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_longfinder3(const char *s, t_map *map, va_list *args)
{
	long int			*n;

	if (s[map->pos] == 'n')
	{
		n = va_arg(*args, long int*);
		*n = map->size;
		map->pos++;
		return (1);
	}
	return (0);
}

int	ft_longfinder2(const char *s, t_map *map, va_list *args)
{
	char				*string;
	unsigned long int	u;

	if (s[map->pos] == 'o')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 8, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'x' || s[map->pos] == 'X')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 16, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longfinder3(s, map, args));
}

int	ft_longfinder(const char *s, t_map *map, va_list *args)
{
	long int			i;
	unsigned long int	u;
	char				*string;

	if (s[map->pos] == 'd' || s[map->pos] == 'i')
	{
		i = va_arg(*args, long int);
		string = ft_itoa_base(i, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	if (s[map->pos] == 'u')
	{
		u = va_arg(*args, unsigned long int);
		string = ft_itoa_base(u, 10, map, s[map->pos]);
		ft_nbrputter_fd(string, 1, map);
		free(string);
		map->pos++;
		return (1);
	}
	return (ft_longfinder2(s, map, args));
}

int	ft_thebigshort(const char *s, t_map *map, va_list *args)
{
	if (map->l == 1)
		return (ft_longfinder(s, map, args));
	else if (map->ll == 1)
		return (ft_longlongfinder(s, map, args));
	else if (map->h == 1)
		return (ft_shortfinder(s, map, args));
	else if (map->hh == 1)
		return (ft_shortshortfinder(s, map, args));
	else
		return (0);
}