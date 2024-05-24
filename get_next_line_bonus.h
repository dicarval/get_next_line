/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/24 11:39:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list(t_list **lnklist, int fd);
char	*cpy_line(t_list *lnklist);
void	prep_next_line(t_list **lnklist);
int		end_line(t_list *list);
void	lstadd_back(t_list **lst, t_list *new, int fd);
t_list	*lstlast(t_list *lst);
size_t	list_len(t_list *lnklist);
void	free_content(t_list **lnklist, t_list *char_n_used);

#endif
