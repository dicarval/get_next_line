/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:59:54 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/08 15:43:24 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_content(t_list **lnklist)
{
	t_list	*current;
	t_list	*tmp;

	if (!lnklist)
		return ;
	current = *lnklist;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->buf);
		free(tmp);
	}
	*lnklist = NULL;
}

size_t	list_len(t_list *lnklist)
{
	size_t	line_len;
	int i;

	i = 0;
	line_len = 0;
	if (lnklist->buf)
		return (0);
	while (lnklist->buf[i] != '\0')
	{
		while (lnklist->buf[i] != '\n' || lnklist->buf[i] != '\0')
			line_len++;
		if ((lnklist->buf[i] == '\n'))
			line_len++;
			return (line_len);
		if (lnklist->next)
			lnklist = lnklist->next;
	}
	return (line_len);
}

int	end_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			i++;
			if (list->buf[i] == '\n')
				return (1);
		}
		list = list->next;
	}
	return (0);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
