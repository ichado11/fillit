/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <yusong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:35:04 by yusong            #+#    #+#             */
/*   Updated: 2017/11/16 15:35:05 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

/*
**	use the list to save the element of tetris
**	tetris is the tetris
**	size is the max outline of each tetris
**	value used to print
*/

typedef struct	s_tetris
{
	char				**tetris;
	int					size[2];
	char				value;
	struct s_tetris		*next;
}				t_tet;

void			ft_error(void);
t_tet			*te_newlist(char **tet, int *n, char val);
void			te_endadd(t_tet **alist, t_tet *ele);
void			te_check(char *buf, int count, int i);
void			get_size(int min[2], int max[2], char *str);
t_tet			*get_one(char *str, int i);
t_tet			*te_read(char *file, int *index);
void			count_check(int *j, int *k, char *buf, int count);
char			**map_blank(int i);
char			**map_putin(char **map, int point[2], t_tet *sharp, char val);
void			print_map(char **map, int len);
int				map_check(char **map, int point[2], t_tet *sharp);
void			solver(char **map, t_tet *cur, int len, int *flag);
void			free_all(char **final, t_tet *telst, int edge);
#endif
