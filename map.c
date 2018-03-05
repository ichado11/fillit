/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:33:57 by yusong            #+#    #+#             */
/*   Updated: 2017/11/30 11:43:04 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map_blank(int i)
{
	char	**blank;
	int		j;
	int		l;

	blank = (char**)malloc(sizeof(char*) * i);
	j = 0;
	while (j < i)
	{
		blank[j] = ft_strnew(i);
		l = 0;
		while (l < i)
		{
			blank[j][l] = '.';
			l++;
		}
		blank[j][l] = '\0';
		j++;
	}
	return (blank);
}

char	**map_putin(char **map, int point[2], t_tet *sharp, char val)
{
	int i;
	int j;

	i = 0;
	while (i < sharp->size[1])
	{
		j = 0;
		while (j < sharp->size[0])
		{
			if (sharp->tetris[i][j] == '#')
				map[point[1] + i][point[0] + j] = val;
			j++;
		}
		i++;
	}
	return (map);
}

void	print_map(char **map, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, map[i], len);
		write(1, "\n", 1);
		i++;
	}
}

int		map_check(char **map, int point[2], t_tet *sharp)
{
	int i;
	int j;

	i = 0;
	while (i < sharp->size[1])
	{
		j = 0;
		while (j < sharp->size[0])
		{
			if (sharp->tetris[i][j] == '#' &&
					map[point[1] + i][point[0] + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
