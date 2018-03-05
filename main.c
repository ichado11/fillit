/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:30:15 by yusong            #+#    #+#             */
/*   Updated: 2017/11/30 11:56:34 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*te_newlist(char **tet, int *n, char val)
{
	t_tet *new;

	new = (t_tet*)malloc(sizeof(t_tet));
	if (new)
	{
		new->tetris = tet;
		new->size[0] = n[0];
		new->size[1] = n[1];
		new->value = val;
		new->next = NULL;
	}
	return (new);
}

void	te_endadd(t_tet **alist, t_tet *ele)
{
	t_tet *temp_list;

	temp_list = *alist;
	while (temp_list->next)
		temp_list = temp_list->next;
	temp_list->next = ele;
}

void	solver(char **map, t_tet *cur, int len, int *flag)
{
	int point[2];

	*flag = 1;
	point[1] = 0;
	while (point[1] + cur->size[1] <= len)
	{
		point[0] = 0;
		while (point[0] + cur->size[0] <= len)
		{
			if (map_check(map, point, cur))
			{
				map = map_putin(map, point, cur, cur->value);
				if (!cur->next)
					return ;
				solver(map, cur->next, len, flag);
				if (!*flag)
					map = map_putin(map, point, cur, '.');
				else
					return ;
			}
			point[0]++;
		}
		point[1]++;
	}
	*flag = 0;
}

void	free_all(char **final, t_tet *telst, int edge)
{
	int		i;
	t_tet	*temp;

	i = 0;
	temp = telst;
	while (i < edge - 1)
	{
		free(final[i]);
		i++;
	}
	free(final);
	while (temp)
	{
		i = 0;
		telst = temp;
		temp = telst->next;
		while (i < telst->size[1])
		{
			free(telst->tetris[i]);
			i++;
		}
		free(telst);
	}
}

int		main(int ac, char **av)
{
	t_tet	*telst;
	int		edge;
	int		count;
	char	**final;

	count = 0;
	edge = 2;
	if (ac != 2)
	{
		write(1, "usage:./fillit source_file\n", 27);
		return (0);
	}
	telst = te_read(av[1], &count);
	while ((edge * edge) < (count * 4))
		edge++;
	count = 0;
	while (!count)
	{
		final = map_blank(edge);
		solver(final, telst, edge, &count);
		edge++;
	}
	print_map(final, (edge - 1));
	free_all(final, telst, edge);
	return (0);
}
