/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/09 17:12:54 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			*buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list(t_list **lnklist, int fd);
char	*cpy_line(t_list *lnklist);
void	prep_next_line(t_list **lnklist);
int		end_line(t_list *list);
void	lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
size_t	list_len(t_list *lnklist);
void	free_content(t_list **lnklist, t_list *char_n_used);
#endif
