/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:09:13 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/06 14:58:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

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

typedef struct	s_list
{
	char			*buffer;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd)

#endif
