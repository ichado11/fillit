/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:34:27 by yusong            #+#    #+#             */
/*   Updated: 2017/11/16 15:34:29 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	count_check(int *j, int *k, char *buf, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			ft_error();
		if (buf[i] == '#')
		{
			(*j)++;
			if (i >= 0 && buf[i - 1] == '#')
				(*k)++;
			if (i <= 19 && buf[i + 1] == '#')
				(*k)++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				(*k)++;
			if (i + 5 <= 19 && buf[i + 5] == '#')
				(*k)++;
		}
		i++;
	}
}

void	te_check(char *buf, int count, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	if (i > 25)
		ft_error();
	if (count == 20 && i != 0)
		ft_error();
	count_check(&j, &k, buf, count);
	if ((count == 20 && (k == 8 || k == 6) && j == 4 && buf[4] == '\n' &&
		buf[9] == '\n' && buf[14] == '\n' && buf[19] == '\n'))
		return ;
	else if ((count == 21 && (k == 8 || k == 6) && j == 4 &&
						buf[0] == '\n' && buf[5] == '\n' && buf[10] == '\n' &&
						buf[15] == '\n' && buf[20] == '\n'))
		return ;
	else
		ft_error();
}

void	get_size(int min[2], int max[2], char *str)
{
	int j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '#')
		{
			if (j % 5 > max[0])
				max[0] = j % 5;
			if (j % 5 < min[0])
				min[0] = j % 5;
			if (j / 5 > max[1])
				max[1] = j / 5;
			if (j / 5 < min[1])
				min[1] = j / 5;
		}
		j++;
	}
}

t_tet	*get_one(char *str, int i)
{
	int		min[2];
	int		max[2];
	int		y;
	char	**temp;

	min[0] = 3;
	min[1] = 3;
	max[0] = 0;
	max[1] = 0;
	get_size(min, max, str);
	temp = (char**)malloc(sizeof(char*) * (max[1] - min[1] + 2));
	y = min[1];
	while (y <= max[1])
	{
		temp[y - min[1]] = ft_strsub(
				str, (y * 5 + min[0]), (max[0] - min[0] + 1));
		y++;
	}
	min[0] = max[0] - min[0] + 1;
	min[1] = max[1] - min[1] + 1;
	return (te_newlist(temp, min, i + 'A'));
}

t_tet	*te_read(char *file, int *index)
{
	int		fd;
	int		read_state;
	char	buf[21];
	t_tet	*tempele;

	fd = open(file, O_RDONLY);
	read_state = read(fd, buf, 20);
	te_check(buf, read_state, *index);
	tempele = get_one(buf, 0);
	*index = 1;
	while ((read_state = read(fd, buf, 21)))
	{
		te_check(buf, read_state, *index);
		te_endadd(&tempele, get_one(buf, *index));
		(*index)++;
	}
	return (tempele);
}
