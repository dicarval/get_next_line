/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/24 16:31:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	prep_next_line(t_list **lnklist)
{
	t_list	*last;
	t_list	*char_n_used;
	int		i;
	int		k;

	if (lnklist == NULL)
		return ;
	char_n_used = malloc(sizeof(t_list));
	char_n_used->buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	char_n_used->next = NULL;
	if (char_n_used->buf == NULL)
		return ;
	i = 0;
	k = 0;
	last = lstlast(*lnklist);
	while (last->buf[i] != '\n' && last->buf[i] != '\0')
		i++;
	if (last->buf[i] == '\n')
		i++;
	while (last->buf[i] != '\0')
		char_n_used->buf[k++] = last->buf[i++];
	char_n_used->buf[k] = '\0';
	free_content(lnklist, char_n_used);
}

char	*cpy_line(t_list *lnklist)
{
	int		i;
	int		j;
	char	*new_line;
	size_t	line_len;

	if (lnklist == NULL)
		return (NULL);
	line_len = list_len(lnklist);
	new_line = malloc(sizeof(char) * line_len + 1);
	if (new_line == NULL)
		return (NULL);
	j = 0;
	while (lnklist != NULL)
	{
		i = 0;
		while (lnklist->buf[i] != '\0' && lnklist->buf[i] != '\n')
			new_line[j++] = lnklist->buf[i++];
		if (lnklist->buf[i] == '\n')
			new_line[j++] = lnklist->buf[i];
		lnklist = lnklist->next;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	create_list(t_list **lnklist, int fd)
{
	int		i;
	t_list	*node;

	while (end_line(lnklist[fd]) == 0)
	{
		node = malloc(sizeof(t_list));
		node->buf = malloc(BUFFER_SIZE + 1);
		node->next = NULL;
		if (node->buf == NULL)
			return ;
		i = read(fd, node->buf, BUFFER_SIZE);
		if (i == 0)
		{
			free(node->buf);
			free(node);
			return ;
		}
		node->buf[i] = '\0';
		lstadd_back(lnklist, node, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lnklist[FOPEN_MAX];
	char			*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_list(lnklist, fd);
	if (lnklist[fd] == NULL)
		return (NULL);
	line = cpy_line(lnklist[fd]);
	if (line == NULL)
		return (NULL);
	prep_next_line (&lnklist[fd]);
	return (line);
}
/* int main()
{
	int		fd1, fd2, fd3, fd4;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	printf("line *%s", get_next_line(fd1));
	printf("line *%s", get_next_line(fd2));
	printf("line *%s", get_next_line(fd3));
	printf("line *%s", get_next_line(fd4));
	printf("line *%s", get_next_line(fd1));
	printf("line *%s", get_next_line(fd2));
	printf("line *%s", get_next_line(fd3));
	printf("line *%s", get_next_line(fd4));
	printf("line *%s", get_next_line(fd1));
	printf("line *%s", get_next_line(fd2));
	printf("line *%s", get_next_line(fd3));
	printf("line *%s", get_next_line(fd4));
	printf("line *%s", get_next_line(fd1));
	printf("line *%s", get_next_line(fd2));
	printf("line *%s", get_next_line(fd3));
	printf("line *%s", get_next_line(fd4));
	printf("line *%s", get_next_line(fd1));
	printf("line *%s", get_next_line(fd2));
	printf("line *%s", get_next_line(fd3));
	printf("line *%s", get_next_line(fd4));
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
 */
